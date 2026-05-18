/* ════════════════════════════════════════════
   Mini C Compiler — Frontend app.js
   ════════════════════════════════════════════ */

/* ── Tab switching ── */
document.querySelectorAll('.tab').forEach(tab => {
    tab.addEventListener('click', () => {
        document.querySelectorAll('.tab').forEach(t => t.classList.remove('active'));
        document.querySelectorAll('.tab-content').forEach(c => c.classList.remove('active'));
        tab.classList.add('active');
        document.getElementById('tab-' + tab.dataset.tab).classList.add('active');
    });
});

/* ── Clear button ── */
document.getElementById('clearBtn').addEventListener('click', () => {
    document.getElementById('codeInput').value = '';
    resetOutputs();
});

/* ════════════════════════════════════════════
   TAC op → human readable instruction
   ════════════════════════════════════════════ */
function tacToText(instr) {
    const { op, result, arg1, arg2 } = instr;
    switch (op) {
        case 0:  return `${result} = ${arg1}`;
        case 1:  return `${result} = ${arg1} + ${arg2}`;
        case 2:  return `${result} = ${arg1} - ${arg2}`;
        case 3:  return `${result} = ${arg1} * ${arg2}`;
        case 4:  return `${result} = ${arg1} / ${arg2}`;
        case 5:  return `${result} = ${arg1} % ${arg2}`;
        case 6:  return `${result} = -${arg1}`;
        case 7:  return `${result} = ${arg1} < ${arg2}`;
        case 8:  return `${result} = ${arg1} > ${arg2}`;
        case 9:  return `${result} = ${arg1} <= ${arg2}`;
        case 10: return `${result} = ${arg1} >= ${arg2}`;
        case 11: return `${result} = ${arg1} == ${arg2}`;
        case 12: return `${result} = ${arg1} != ${arg2}`;
        case 13: return `${result} = ${arg1} && ${arg2}`;
        case 14: return `${result} = ${arg1} || ${arg2}`;
        case 15: return `${result} = !${arg1}`;
        case 16: return `${result}:`;
        case 17: return `goto ${result}`;
        case 18: return `if_false ${arg1} goto ${result}`;
        case 19: return `${result} = call ${arg1}, ${arg2}`;
        case 20: return `param ${arg1}`;
        case 21: return `return ${arg1}`;
        case 22: return `func_begin ${arg1}`;
        case 23: return `func_end ${arg1}`;
        default: return `op_${op} ${result} ${arg1} ${arg2}`;
    }
}

function tacRowClass(op) {
    if (op === 16) return 'tac-label-row';
    if (op === 22 || op === 23) return 'tac-func-row';
    if (op === 21) return 'tac-return-row';
    return '';
}

/* ════════════════════════════════════════════
   Parse tree: JSON → plain text with connectors
   ════════════════════════════════════════════ */
function jsonTreeToText(node, prefix, isLast) {
    if (!node) return '';
    const connector = isLast ? '└── ' : '├── ';
    let out = prefix + connector + node.label + '\n';
    const childPrefix = prefix + (isLast ? '    ' : '│   ');
    if (node.children && node.children.length > 0) {
        node.children.forEach((child, i) => {
            out += jsonTreeToText(child, childPrefix, i === node.children.length - 1);
        });
    }
    return out;
}

/* ════════════════════════════════════════════
   RENDER FUNCTIONS
   ════════════════════════════════════════════ */

function renderTokens(count) {
    document.getElementById('tokenCount').textContent = count;
    document.getElementById('tokenNote').textContent =
        `${count} token${count !== 1 ? 's' : ''} recognised by the Flex lexer`;
}

function renderSymtab(symbols) {
    const tbody = document.getElementById('symtabBody');
    if (!symbols || symbols.length === 0) {
        tbody.innerHTML = '<tr><td colspan="6" class="empty-row">No symbols found</td></tr>';
        return;
    }
    tbody.innerHTML = symbols.map((s, i) => {
        const kindBadge =
            s.kind === 'function'  ? `<span class="badge badge-func">function</span>`  :
            s.kind === 'parameter' ? `<span class="badge badge-param">parameter</span>` :
                                     `<span class="badge badge-var">variable</span>`;
        const typeClass =
            s.type === 'int'   ? 'type-int'   :
            s.type === 'float' ? 'type-float' :
            s.type === 'char'  ? 'type-char'  :
            s.type === 'void'  ? 'type-void'  : 'type-unknown';
        return `<tr>
            <td>${i + 1}</td>
            <td><strong>${s.name}</strong></td>
            <td><span class="${typeClass}">${s.type}</span></td>
            <td>${kindBadge}</td>
            <td>${s.scope}</td>
            <td>${s.line}</td>
        </tr>`;
    }).join('');
}

function renderParseTree(parseTreeJson) {
    const out = document.getElementById('parseTreeOut');
    if (!parseTreeJson) {
        out.textContent = '(no parse tree generated)';
        return;
    }
    /* build plain text from JSON tree — no garbled Windows chars */
    let text = parseTreeJson.label + '\n';
    if (parseTreeJson.children && parseTreeJson.children.length > 0) {
        parseTreeJson.children.forEach((child, i) => {
            text += jsonTreeToText(child, '', i === parseTreeJson.children.length - 1);
        });
    }
    out.textContent = text;
}

function renderTAC(tac) {
    const wrap = document.getElementById('tacOut');
    if (!tac || tac.length === 0) {
        wrap.innerHTML = '<p class="empty-row">No TAC generated</p>';
        return;
    }
    wrap.innerHTML = tac.map(instr => {
        const text = tacToText(instr);
        const cls  = tacRowClass(instr.op);
        return `<div class="tac-row ${cls}">
            <span class="tac-idx">${instr.index}.</span>
            <span class="tac-instr">${text}</span>
        </div>`;
    }).join('');
}

function renderErrors(errors) {
    const out    = document.getElementById('errorsOut');
    const banner = document.getElementById('errorBanner');
    const errTab = document.querySelector('[data-tab="errors"]');

    if (!errors || errors.length === 0) {
        out.innerHTML = `<p class="empty-row" style="color:#4caf7d;font-style:normal;font-size:1rem">
            ✓ No errors detected — code compiled successfully
        </p>`;
        banner.classList.add('hidden');
        errTab.textContent = '🚨 Errors';
        return;
    }

    /* show top banner */
    banner.classList.remove('hidden');
    banner.textContent = `⚠  ${errors.length} error${errors.length > 1 ? 's' : ''} found — see Errors tab`;

    /* update tab label */
    errTab.textContent = `🚨 Errors (${errors.length})`;

    /* switch to errors tab automatically */
    switchTab('errors');

    out.innerHTML = errors.map(e => `
        <div class="err-card ${e.kind}">
            <span class="err-badge ${e.kind}">${e.kind}</span>
            <span class="err-line">Line ${e.line}</span>
            <span class="err-msg">${e.message}</span>
        </div>
    `).join('');
}

/* ════════════════════════════════════════════
   HELPERS
   ════════════════════════════════════════════ */

function switchTab(name) {
    document.querySelectorAll('.tab').forEach(t => t.classList.remove('active'));
    document.querySelectorAll('.tab-content').forEach(c => c.classList.remove('active'));
    const tab = document.querySelector(`[data-tab="${name}"]`);
    const content = document.getElementById(`tab-${name}`);
    if (tab)     tab.classList.add('active');
    if (content) content.classList.add('active');
}

function resetOutputs() {
    document.getElementById('tokenCount').textContent   = '—';
    document.getElementById('tokenNote').textContent    = 'Compile your code to see the token count.';
    document.getElementById('symtabBody').innerHTML     = '<tr><td colspan="6" class="empty-row">Compile to see symbol table</td></tr>';
    document.getElementById('parseTreeOut').textContent = 'Compile to see parse tree';
    document.getElementById('tacOut').innerHTML         = '<p class="empty-row">Compile to see three address code</p>';
    document.getElementById('errorsOut').innerHTML      = '<p class="empty-row">No errors yet</p>';
    document.getElementById('errorBanner').classList.add('hidden');
    document.querySelector('[data-tab="errors"]').textContent = '🚨 Errors';
    switchTab('tokens');
}

/* ════════════════════════════════════════════
   COMPILE BUTTON
   ════════════════════════════════════════════ */
document.getElementById('compileBtn').addEventListener('click', async () => {
    const code = document.getElementById('codeInput').value.trim();
    if (!code) {
        alert('Please enter some C code first!');
        return;
    }

    /* show loading state */
    const btn     = document.getElementById('compileBtn');
    const btnText = document.getElementById('btnText');
    const spinner = document.getElementById('btnSpinner');
    btn.disabled        = true;
    btnText.textContent = 'Compiling...';
    spinner.classList.remove('hidden');

    try {
        const res = await fetch('/compile', {
            method:  'POST',
            headers: { 'Content-Type': 'application/json' },
            body:    JSON.stringify({ code })
        });

        const data = await res.json();

        if (!res.ok || data.error) {
            alert('Server error: ' + (data.error || 'Unknown error'));
            return;
        }

        /* ── render all 5 panels ── */
        renderTokens(data.token_count  || 0);
        renderSymtab(data.symbol_table || []);
        renderParseTree(data.parse_tree || null);
        renderTAC(data.tac             || []);
        renderErrors(data.errors       || []);

        /* switch to tokens tab if clean compile */
        if (!data.errors || data.errors.length === 0) {
            switchTab('tokens');
        }

    } catch (err) {
        alert('Network error: ' + err.message);
    } finally {
        btn.disabled        = false;
        btnText.textContent = '▶ Compile';
        spinner.classList.add('hidden');
    }
});