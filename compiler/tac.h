#ifndef TAC_H
#define TAC_H

/* ============================================================
   tac.h  —  Three Address Code (TAC) Generator
   Each instruction is:   result = arg1  op  arg2
   or a unary / jump / label / call / return form.
   ============================================================ */

#define MAX_TAC     1024
#define MAX_TAC_STR 64

typedef enum {
    TAC_ASSIGN,    /* x = y            */
    TAC_ADD,       /* x = y + z        */
    TAC_SUB,       /* x = y - z        */
    TAC_MUL,       /* x = y * z        */
    TAC_DIV,       /* x = y / z        */
    TAC_MOD,       /* x = y % z        */
    TAC_UMINUS,    /* x = -y           */
    TAC_LT,        /* x = y < z        */
    TAC_GT,        /* x = y > z        */
    TAC_LTE,       /* x = y <= z       */
    TAC_GTE,       /* x = y >= z       */
    TAC_EQ,        /* x = y == z       */
    TAC_NEQ,       /* x = y != z       */
    TAC_AND,       /* x = y && z       */
    TAC_OR,        /* x = y || z       */
    TAC_NOT,       /* x = !y           */
    TAC_LABEL,     /* L1:              */
    TAC_GOTO,      /* goto L1          */
    TAC_IF_FALSE,  /* if_false x goto L */
    TAC_CALL,      /* x = call f, n    */
    TAC_PARAM,     /* param x          */
    TAC_RETURN,    /* return x         */
    TAC_FUNC_BEGIN,/* func_begin f     */
    TAC_FUNC_END   /* func_end f       */
} TACOp;

typedef struct {
    TACOp op;
    char  result[MAX_TAC_STR];
    char  arg1  [MAX_TAC_STR];
    char  arg2  [MAX_TAC_STR];
} TACInstr;

/* ── API ── */
void  tac_init         (void);
void  tac_emit         (TACOp op, const char *result,
                         const char *arg1, const char *arg2);
char *tac_new_temp     (void);   /* t1, t2, t3 … */
char *tac_new_label    (void);   /* L1, L2, L3 … */
void  tac_print        (void);   /* plain text    */
void  tac_print_json   (void);   /* JSON for frontend */
int   tac_count        (void);

#endif /* TAC_H */