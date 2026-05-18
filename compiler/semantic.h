#ifndef SEMANTIC_H
#define SEMANTIC_H

/* ============================================================
   semantic.h  —  Semantic Analysis
   Checks performed DURING parsing via Bison actions:

   Inherited attributes  (parent → child):
     - declared type flows down into variable declarations
     - current function return type flows into return statements
     - scope level flows into all declarations

   Synthesised attributes (child → parent):
     - expression type bubbles up for type-compatibility checks
     - function call argument count bubbles up for arity check

   Errors reported via SEM_ERR() → collected in error.h
   ============================================================ */

#include "symtab.h"
#include "ast.h"

/* ── Current function context (inherited by return-stmt rules) ── */
extern char    sem_current_func[128];
extern SymType sem_current_return_type;
extern int     sem_current_scope;

/* ── Init / scope management ── */
void sem_init         (void);
void sem_enter_scope  (void);
void sem_exit_scope   (void);

/* ── Declaration checks ── */
void sem_declare_func (const char *name, SymType ret_type, int line);
void sem_declare_var  (const char *name, SymType type, int line);
void sem_declare_param(const char *name, SymType type, int line);

/* ── Use checks ── */
SymType sem_check_var  (const char *name, int line);  /* returns type or SYM_UNKNOWN */
SymType sem_check_call (const char *name, int argc, int line);

/* ── Type compatibility ── */
SymType sem_check_binop (SymType left, SymType right,
                          const char *op, int line);
void    sem_check_assign(SymType lhs, SymType rhs,
                          const char *varname, int line);
void    sem_check_return(SymType expr_type, int line);
void    sem_check_cond  (SymType cond_type, int line);

#endif /* SEMANTIC_H */