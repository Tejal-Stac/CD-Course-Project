#include <stdio.h>
#include <string.h>
#include "semantic.h"
#include "error.h"
#include "symtab.h"

/* ── Current function context ── */
char    sem_current_func[128]  = "";
SymType sem_current_return_type = SYM_VOID;
int     sem_current_scope       = 0;

void sem_init(void) {
    sem_current_scope = 0;
    memset(sem_current_func, 0, sizeof(sem_current_func));
    sem_current_return_type = SYM_VOID;
}

/* ── Scope management ── */
void sem_enter_scope(void) { sem_current_scope++; }
void sem_exit_scope (void) { if (sem_current_scope > 0) sem_current_scope--; }

/* ── Declare a function ── */
void sem_declare_func(const char *name, SymType ret_type, int line) {
    /* always insert/update at global scope */
    int idx = symtab_insert(name, ret_type, KIND_FUNC, 0, line);
    Symbol *s = symtab_lookup(name, 0);
    if (s) {
        s->kind       = KIND_FUNC;
        s->type       = ret_type;
        s->is_defined = 1;
    }
    /* set inherited context for body rules */
    strncpy(sem_current_func, name, 127);
    sem_current_return_type = ret_type;
}

/* ── Declare a variable ── */
void sem_declare_var(const char *name, SymType type, int line) {
    if (type == SYM_VOID) {
        SEM_ERR(line, "Variable '%s' cannot be declared as void", name);
        return;
    }
    Symbol *existing = symtab_lookup(name, sem_current_scope);
    if (existing) {
        SEM_ERR(line, "Redeclaration of variable '%s' in same scope"
                " (first at line %d)", name, existing->line);
        return;
    }
    symtab_insert(name, type, KIND_VAR, sem_current_scope, line);
}

/* ── Declare a parameter ── */
void sem_declare_param(const char *name, SymType type, int line) {
    if (type == SYM_VOID) {
        SEM_ERR(line, "Parameter '%s' cannot be void", name);
        return;
    }
    symtab_insert(name, type, KIND_PARAM, sem_current_scope, line);
}

/* ── Check variable is declared before use ── */
SymType sem_check_var(const char *name, int line) {
    Symbol *s = symtab_lookup_any(name);
    if (!s) {
        SEM_ERR(line, "Undeclared identifier '%s'", name);
        return SYM_UNKNOWN;
    }
    return s->type;
}

/* ── Check function call ── */
SymType sem_check_call(const char *name, int argc, int line) {
    Symbol *s = symtab_lookup(name, 0);  /* functions always global scope */
    if (!s || s->kind != KIND_FUNC) {
        SEM_ERR(line, "Call to undeclared function '%s'", name);
        return SYM_UNKNOWN;
    }
    return s->type;  /* return type of function */
}

/* ── Binary operator type checking ── */
SymType sem_check_binop(SymType left, SymType right,
                         const char *op, int line)
{
    if (left == SYM_UNKNOWN || right == SYM_UNKNOWN)
        return SYM_UNKNOWN;

    /* void is never valid in an expression */
    if (left == SYM_VOID || right == SYM_VOID) {
        SEM_ERR(line, "Invalid use of void type in '%s' expression", op);
        return SYM_UNKNOWN;
    }

    /* char is compatible with int */
    if (left == SYM_CHAR)  left  = SYM_INT;
    if (right == SYM_CHAR) right = SYM_INT;

    /* float wins over int (implicit widening) */
    if (left == SYM_FLOAT || right == SYM_FLOAT)
        return SYM_FLOAT;

    return SYM_INT;
}

/* ── Assignment type checking ── */
void sem_check_assign(SymType lhs, SymType rhs,
                       const char *varname, int line)
{
    if (lhs == SYM_UNKNOWN || rhs == SYM_UNKNOWN) return;

    if (lhs == SYM_VOID || rhs == SYM_VOID) {
        SEM_ERR(line, "Cannot assign void type to '%s'", varname);
        return;
    }
    /* int = float  →  warn (narrowing) */
    if (lhs == SYM_INT && rhs == SYM_FLOAT) {
        SEM_ERR(line, "Possible loss of data: assigning float to int '%s'",
                varname);
    }
    /* float = char is fine (widening), char = float is narrowing */
    if (lhs == SYM_CHAR && rhs == SYM_FLOAT) {
        SEM_ERR(line, "Possible loss of data: assigning float to char '%s'",
                varname);
    }
}

/* ── Return statement type checking (uses inherited return type) ── */
void sem_check_return(SymType expr_type, int line) {
    if (sem_current_return_type == SYM_VOID && expr_type != SYM_VOID) {
        SEM_ERR(line, "Function '%s' declared void but returns a value",
                sem_current_func);
        return;
    }
    if (sem_current_return_type != SYM_VOID && expr_type == SYM_VOID) {
        SEM_ERR(line, "Function '%s' must return a value of type '%s'",
                sem_current_func,
                type_to_str(sem_current_return_type));
        return;
    }
    /* narrowing return */
    if (sem_current_return_type == SYM_INT && expr_type == SYM_FLOAT) {
        SEM_ERR(line, "Return type mismatch in '%s': float returned as int",
                sem_current_func);
    }
}

/* ── Condition type check (if / while / for) ── */
void sem_check_cond(SymType cond_type, int line) {
    if (cond_type == SYM_VOID) {
        SEM_ERR(line, "Condition expression cannot be void");
    }
}