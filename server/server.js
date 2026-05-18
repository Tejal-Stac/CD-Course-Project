const express      = require('express');
const cors         = require('cors');
const { execFile } = require('child_process');
const path         = require('path');
const fs           = require('fs');
const os           = require('os');

const app  = express();
const PORT = 3000;

app.use(cors());
app.use(express.json());
app.use(express.static(path.join(__dirname, '../frontend')));

const COMPILER = 'C:\\Users\\TEJAL\\OneDrive\\Desktop\\TY SEM 2\\CD Course Project\\Project\\compiler\\minicc.exe';

app.post('/compile', (req, res) => {
    const { code } = req.body;
    if (!code || !code.trim())
        return res.status(400).json({ error: 'No code provided' });

    const tmpFile = path.join(os.tmpdir(), `minicc_${Date.now()}.c`);
    fs.writeFileSync(tmpFile, code, 'utf8');

    execFile(COMPILER, [tmpFile], { timeout: 10000 }, (err, stdout, stderr) => {
        try { fs.unlinkSync(tmpFile); } catch(e) {}

        console.log('--- RAW STDOUT ---');
        console.log(stdout);
        console.log('--- RAW STDERR ---');
        console.log(stderr);

        /* ── Extract ONLY the JSON block from stdout ──
           The compiler prints JSON then a plain-text tree to stderr.
           Sometimes they get mixed. We find the first { and last }
           to isolate the pure JSON object.                         */
        let jsonStr = '';
        try {
            const start = stdout.indexOf('{');
            const end   = stdout.lastIndexOf('}');
            if (start === -1 || end === -1)
                throw new Error('No JSON object found in compiler output');
            jsonStr = stdout.substring(start, end + 1);
        } catch(e) {
            return res.status(500).json({
                error: 'Could not extract JSON: ' + e.message,
                raw:   stdout.substring(0, 500)
            });
        }

        let result;
        try {
            result = JSON.parse(jsonStr);
        } catch(e) {
            return res.status(500).json({
                error: 'JSON parse failed: ' + e.message,
                raw:   jsonStr.substring(0, 500)
            });
        }

        res.json(result);
    });
});

app.listen(PORT, () => {
    console.log(`Server at http://localhost:${PORT}`);
    console.log(`Compiler exists: ${fs.existsSync(COMPILER)}`);
});