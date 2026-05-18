%{
/* ============================================================
   parser.y  —  Bison Parser for Mini C Compiler
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"          
#include "ast.h"
#include "semantic.h"
#include "tac.h"
#include "error.h"

extern int  yylineno;
extern int  token_count;
extern int  get_token_count(void);
int yylex(void);
void yyerror(const char *msg);

ASTNode *parse_tree_root = NULL; 
static int param_count = 0;

/* forward declare the helper so mid-rule actions can call it */

static void begin_function(const char *name, const char *type_str);
%}

%union {
    int      ival;        /* integer LITERALS*/
    char    *str;        /*identifiers/keywords*/
    struct {
        ASTNode *node;      /*AST NOde*/
        char     temp[64];
        int      type;
    } expr;
}

/* ── Tokens ── */
%token <str>  KW_INT KW_FLOAT KW_CHAR KW_VOID
%token <str>  KW_RETURN KW_IF KW_ELSE KW_WHILE
%token <str>  KW_FOR KW_DO KW_BREAK KW_CONT
%token <str>  IDENTIFIER
%token <ival> INT_LITERAL
%token <str>  FLOAT_LITERAL CHAR_LITERAL STRING_LITERAL

%token OP_PLUS OP_MINUS OP_MUL OP_DIV OP_MOD
%token OP_EQ OP_NEQ OP_LT OP_GT OP_LTE OP_GTE
%token OP_AND OP_OR OP_NOT
%token OP_ASSIGN OP_PLUSEQ OP_MINEQ OP_MULEQ OP_DIVEQ
%token OP_INC OP_DEC
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA

/* ── Rule types ── */
%type <expr>  expression assignment_expr unary_expr postfix_expr
%type <expr>  additive_expr multiplicative_expr relational_expr
%type <expr>  equality_expr logical_and_expr logical_or_expr
%type <expr>  primary_expr
%type <str>   type_spec
%type <expr>  statement compound_stmt expr_stmt return_stmt
%type <expr>  if_stmt while_stmt for_stmt
%type <expr>  declaration param param_list arg_list
%type <expr>  func_header_with_params func_header_no_params

/* ── Precedence ── */
%right OP_ASSIGN OP_PLUSEQ OP_MINEQ OP_MULEQ OP_DIVEQ
%left  OP_OR
%left  OP_AND
%left  OP_EQ OP_NEQ
%left  OP_LT OP_GT OP_LTE OP_GTE
%left  OP_PLUS OP_MINUS
%left  OP_MUL OP_DIV OP_MOD
%right OP_NOT UMINUS
%left  OP_INC OP_DEC

%nonassoc LOWER_THAN_ELSE
%nonassoc KW_ELSE

%%

/* ════════════════════════════════════════════════
   PROGRAM
   ═══════════════════════════════════════════════ */

program
    : function_list
    ;

function_list
    : function_def
        {
            parse_tree_root = $<expr>1.node;
        }
    | function_list function_def
        {
            ASTNode *prog = ast_new_node("Program", yylineno);
            ast_add_child(prog, parse_tree_root);
            ast_add_child(prog, $<expr>2.node);
            parse_tree_root = prog;
        }
    ;

/* ════════════════════════════════════════════════
   FUNCTION HEADER HELPERS
   Split into two separate non-terminals to avoid
   mid-rule action reduce/reduce conflict.
   The header non-terminal fires sem_declare_func
   and sem_enter_scope BEFORE the body is parsed —
   this is the INHERITED ATTRIBUTE mechanism.
   ════════════════════════════════════════════════ */

func_header_with_params
    : type_spec IDENTIFIER LPAREN param_list RPAREN
        {
            /* Inherited attribute: type flows down into function body */
            begin_function($2, $1);
            ASTNode *hdr = ast_new_node("FuncHeader", yylineno);
            ast_add_child(hdr, ast_new_node($1, yylineno));
            ast_add_child(hdr, ast_new_node($2, yylineno));
            if ($<expr>4.node) ast_add_child(hdr, $<expr>4.node);
            $<expr>$.node = hdr;
            strncpy($<expr>$.temp, $2, 63);
            free($1); free($2);
        }
    ;

func_header_no_params
    : type_spec IDENTIFIER LPAREN RPAREN
        {
            /* Inherited attribute: type flows down into function body */
            begin_function($2, $1);
            ASTNode *hdr = ast_new_node("FuncHeader", yylineno);
            ast_add_child(hdr, ast_new_node($1, yylineno));
            ast_add_child(hdr, ast_new_node($2, yylineno));
            ast_add_child(hdr, ast_new_node("(no params)", yylineno));
            $<expr>$.node = hdr;
            strncpy($<expr>$.temp, $2, 63);
            free($1); free($2);
        }
    ;

/* ════════════════════════════════════════════════
   FUNCTION DEFINITION
   ════════════════════════════════════════════════ */

function_def
    : func_header_with_params compound_stmt
        {
            ASTNode *fn = ast_new_node("FunctionDef", yylineno);
            /* pull children from header node */
            ASTNode *hdr = $<expr>1.node;
            for (int i = 0; i < hdr->child_count; i++)
                ast_add_child(fn, hdr->children[i]);
            if ($<expr>2.node) ast_add_child(fn, $<expr>2.node);

            tac_emit(TAC_FUNC_BEGIN, "", $<expr>1.temp, "");
            tac_emit(TAC_FUNC_END,   "", $<expr>1.temp, "");

            $<expr>$.node = fn;
            sem_exit_scope();
        }
    | func_header_no_params compound_stmt
        {
            ASTNode *fn = ast_new_node("FunctionDef", yylineno);
            ASTNode *hdr = $<expr>1.node;
            for (int i = 0; i < hdr->child_count; i++)
                ast_add_child(fn, hdr->children[i]);
            if ($<expr>2.node) ast_add_child(fn, $<expr>2.node);

            tac_emit(TAC_FUNC_BEGIN, "", $<expr>1.temp, "");
            tac_emit(TAC_FUNC_END,   "", $<expr>1.temp, "");

            $<expr>$.node = fn;
            sem_exit_scope();
        }
    ;

/* ════════════════════════════════════════════════
   TYPE SPECIFIER  — synthesised upward
   ════════════════════════════════════════════════ */

type_spec
    : KW_INT   { $$ = strdup("int");   }
    | KW_FLOAT { $$ = strdup("float"); }
    | KW_CHAR  { $$ = strdup("char");  }
    | KW_VOID  { $$ = strdup("void");  }
    ;

/* ════════════════════════════════════════════════
   PARAMETERS  — inherited: scope from enter_scope
   ════════════════════════════════════════════════ */

param_list
    : param
        {
            ASTNode *pl = ast_new_node("ParamList", yylineno);
            ast_add_child(pl, $<expr>1.node);
            $<expr>$.node = pl;
        }
    | param_list COMMA param
        {
            ast_add_child($<expr>1.node, $<expr>3.node);
            $<expr>$.node = $<expr>1.node;
        }
    ;

param
    : type_spec IDENTIFIER
        {
            SymType t = str_to_type($1);
            sem_declare_param($2, t, yylineno);
            ASTNode *p = ast_new_node("Param", yylineno);
            ast_add_child(p, ast_new_node($1, yylineno));
            ast_add_child(p, ast_new_node($2, yylineno));
            $<expr>$.node = p;
            free($1); free($2);
        }
    ;

/* ════════════════════════════════════════════════
   COMPOUND STATEMENT  { stmts }
   Scope for nested blocks (if/while bodies)
   ════════════════════════════════════════════════ */

compound_stmt
    : LBRACE stmt_list RBRACE
        {
            ASTNode *blk = ast_new_node("Block", yylineno);
            if ($<expr>2.node) ast_add_child(blk, $<expr>2.node);
            $<expr>$.node = blk;
        }
    | LBRACE RBRACE
        {
            $<expr>$.node = ast_new_node("Block(empty)", yylineno);
        }
    ;

stmt_list
    : statement
        {
            ASTNode *sl = ast_new_node("StmtList", yylineno);
            if ($<expr>1.node) ast_add_child(sl, $<expr>1.node);
            $<expr>$.node = sl;
        }
    | stmt_list statement
        {
            if ($<expr>2.node)
                ast_add_child($<expr>1.node, $<expr>2.node);
            $<expr>$.node = $<expr>1.node;
        }
    ;

/* ════════════════════════════════════════════════
   STATEMENTS
   ════════════════════════════════════════════════ */

statement
    : declaration   { $<expr>$ = $<expr>1; }
    | expr_stmt     { $<expr>$ = $<expr>1; }
    | return_stmt   { $<expr>$ = $<expr>1; }
    | if_stmt       { $<expr>$ = $<expr>1; }
    | while_stmt    { $<expr>$ = $<expr>1; }
    | for_stmt      { $<expr>$ = $<expr>1; }
    | compound_stmt { $<expr>$ = $<expr>1; }
    | KW_BREAK SEMICOLON
        {
            $<expr>$.node = ast_new_node("break", yylineno);
            tac_emit(TAC_GOTO, "BREAK_TARGET", "", "");
        }
    | KW_CONT SEMICOLON
        {
            $<expr>$.node = ast_new_node("continue", yylineno);
            tac_emit(TAC_GOTO, "CONT_TARGET", "", "");
        }
    ;

/* ════════════════════════════════════════════════
   DECLARATION
   Inherited: type_spec → sem_declare_var
   Synthesised: parse tree node bubbles up
   ════════════════════════════════════════════════ */

declaration
    : type_spec IDENTIFIER SEMICOLON
        {
            SymType t = str_to_type($1);
            sem_declare_var($2, t, yylineno);

            ASTNode *decl  = ast_new_node("CodeStatement", yylineno);
            ASTNode *data  = ast_new_node("Data",          yylineno);
            ASTNode *ident = ast_new_node("Identifier",    yylineno);
            ast_add_child(data,  ast_new_node($1, yylineno));
            ast_add_child(ident, ast_new_node($2, yylineno));
            ast_add_child(decl, data);
            ast_add_child(decl, ident);
            $<expr>$.node = decl;
            free($1); free($2);
        }
    | type_spec IDENTIFIER OP_ASSIGN expression SEMICOLON
        {
            SymType t = str_to_type($1);
            sem_declare_var($2, t, yylineno);
            sem_check_assign(t, (SymType)$4.type, $2, yylineno);
            tac_emit(TAC_ASSIGN, $2, $4.temp, "");

            ASTNode *decl  = ast_new_node("CodeStatement", yylineno);
            ASTNode *data  = ast_new_node("Data",          yylineno);
            ASTNode *ident = ast_new_node("Identifier",    yylineno);
            ASTNode *eq    = ast_new_node("(=)",           yylineno);
            ASTNode *expr_n= ast_new_node("(Expression)",  yylineno);
            ast_add_child(data,   ast_new_node($1, yylineno));
            ast_add_child(ident,  ast_new_node($2, yylineno));
            ast_add_child(expr_n, $4.node);
            ast_add_child(eq,     expr_n);
            ast_add_child(decl, data);
            ast_add_child(decl, ident);
            ast_add_child(decl, eq);
            $<expr>$.node = decl;
            free($1); free($2);
        }
    ;

/* ════════════════════════════════════════════════
   EXPRESSION STATEMENT
   ════════════════════════════════════════════════ */

expr_stmt
    : expression SEMICOLON
        {
            ASTNode *es = ast_new_node("ExprStmt", yylineno);
            ast_add_child(es, $1.node);
            $<expr>$.node = es;
            $<expr>$.type = $1.type;
        }
    | SEMICOLON
        {
            $<expr>$.node = ast_new_node("EmptyStmt", yylineno);
        }
    ;

/* ════════════════════════════════════════════════
   RETURN  — uses inherited sem_current_return_type
   ════════════════════════════════════════════════ */

return_stmt
    : KW_RETURN expression SEMICOLON
        {
            sem_check_return((SymType)$2.type, yylineno);
            tac_emit(TAC_RETURN, "", $2.temp, "");
            ASTNode *ret = ast_new_node("ReturnStmt", yylineno);
            ast_add_child(ret, $2.node);
            $<expr>$.node = ret;
        }
    | KW_RETURN SEMICOLON
        {
            sem_check_return(SYM_VOID, yylineno);
            tac_emit(TAC_RETURN, "", "", "");
            $<expr>$.node = ast_new_node("ReturnStmt(void)", yylineno);
        }
    ;

/* ════════════════════════════════════════════════
   IF / WHILE / FOR
   ════════════════════════════════════════════════ */

if_stmt
    : KW_IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
        {
            sem_check_cond((SymType)$3.type, yylineno);
            char *lend = tac_new_label();
            tac_emit(TAC_IF_FALSE, lend, $3.temp, "");
            tac_emit(TAC_LABEL,    lend, "",       "");
            ASTNode *ifs = ast_new_node("IfStmt", yylineno);
            ast_add_child(ifs, $3.node);
            if ($<expr>5.node) ast_add_child(ifs, $<expr>5.node);
            $<expr>$.node = ifs;
        }
    | KW_IF LPAREN expression RPAREN statement KW_ELSE statement
        {
            sem_check_cond((SymType)$3.type, yylineno);
            char *lfalse = tac_new_label();
            char *lend   = tac_new_label();
            tac_emit(TAC_IF_FALSE, lfalse, $3.temp, "");
            tac_emit(TAC_GOTO,     lend,   "",       "");
            tac_emit(TAC_LABEL,    lfalse, "",       "");
            tac_emit(TAC_LABEL,    lend,   "",       "");
            ASTNode *ifs = ast_new_node("IfElseStmt", yylineno);
            ast_add_child(ifs, $3.node);
            if ($<expr>5.node) ast_add_child(ifs, $<expr>5.node);
            if ($<expr>7.node) ast_add_child(ifs, $<expr>7.node);
            $<expr>$.node = ifs;
        }
    ;

while_stmt
    : KW_WHILE LPAREN expression RPAREN statement
        {
            sem_check_cond((SymType)$3.type, yylineno);
            char *lstart = tac_new_label();
            char *lend   = tac_new_label();
            tac_emit(TAC_LABEL,    lstart, "",        "");
            tac_emit(TAC_IF_FALSE, lend,   $3.temp,   "");
            tac_emit(TAC_GOTO,     lstart, "",        "");
            tac_emit(TAC_LABEL,    lend,   "",        "");
            ASTNode *ws = ast_new_node("WhileStmt", yylineno);
            ast_add_child(ws, $3.node);
            if ($<expr>5.node) ast_add_child(ws, $<expr>5.node);
            $<expr>$.node = ws;
        }
    ;

for_stmt
    : KW_FOR LPAREN expr_stmt expression SEMICOLON expression RPAREN statement
        {
            sem_check_cond((SymType)$4.type, yylineno);
            char *lstart = tac_new_label();
            char *lend   = tac_new_label();
            tac_emit(TAC_LABEL,    lstart, "",       "");
            tac_emit(TAC_IF_FALSE, lend,   $4.temp,  "");
            tac_emit(TAC_GOTO,     lstart, "",       "");
            tac_emit(TAC_LABEL,    lend,   "",       "");
            ASTNode *fs = ast_new_node("ForStmt", yylineno);
            if ($<expr>3.node) ast_add_child(fs, $<expr>3.node);
            ast_add_child(fs, $4.node);
            ast_add_child(fs, $6.node);
            if ($<expr>8.node) ast_add_child(fs, $<expr>8.node);
            $<expr>$.node = fs;
        }
    ;

/* ════════════════════════════════════════════════
   EXPRESSIONS — each layer synthesises .node .temp .type
   ════════════════════════════════════════════════ */

expression
    : assignment_expr { $$ = $1; }
    ;

assignment_expr
    : logical_or_expr { $$ = $1; }
    | IDENTIFIER OP_ASSIGN expression
        {
            SymType lhs = sem_check_var($1, yylineno);
            sem_check_assign(lhs, (SymType)$3.type, $1, yylineno);
            tac_emit(TAC_ASSIGN, $1, $3.temp, "");
            ASTNode *as = ast_new_node("Assignment", yylineno);
            ASTNode *eq = ast_new_node("(=)", yylineno);
            ast_add_child(eq, $3.node);
            ast_add_child(as, ast_new_node($1, yylineno));
            ast_add_child(as, eq);
            $$.node = as;
            strncpy($$.temp, $1, 63);
            $$.type = lhs;
            free($1);
        }
    | IDENTIFIER OP_PLUSEQ expression
        {
            SymType lhs = sem_check_var($1, yylineno);
            char *t = tac_new_temp();
            tac_emit(TAC_ADD,    t,  $1, $3.temp);
            tac_emit(TAC_ASSIGN, $1, t,  "");
            ASTNode *as = ast_new_node("CompoundAssign(+=)", yylineno);
            ast_add_child(as, ast_new_node($1, yylineno));
            ast_add_child(as, $3.node);
            $$.node = as; strncpy($$.temp, $1, 63); $$.type = lhs;
            free($1);
        }
    | IDENTIFIER OP_MINEQ expression
        {
            SymType lhs = sem_check_var($1, yylineno);
            char *t = tac_new_temp();
            tac_emit(TAC_SUB,    t,  $1, $3.temp);
            tac_emit(TAC_ASSIGN, $1, t,  "");
            ASTNode *as = ast_new_node("CompoundAssign(-=)", yylineno);
            ast_add_child(as, ast_new_node($1, yylineno));
            ast_add_child(as, $3.node);
            $$.node = as; strncpy($$.temp, $1, 63); $$.type = lhs;
            free($1);
        }
    ;

logical_or_expr
    : logical_and_expr { $$ = $1; }
    | logical_or_expr OP_OR logical_and_expr
        {
            SymType t = sem_check_binop((SymType)$1.type,(SymType)$3.type,"||",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_OR, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(||)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
        }
    ;

logical_and_expr
    : equality_expr { $$ = $1; }
    | logical_and_expr OP_AND equality_expr
        {
            SymType t = sem_check_binop((SymType)$1.type,(SymType)$3.type,"&&",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_AND, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(&&)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
        }
    ;

equality_expr
    : relational_expr { $$ = $1; }
    | equality_expr OP_EQ relational_expr
        {
            SymType t = sem_check_binop((SymType)$1.type,(SymType)$3.type,"==",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_EQ, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(==)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
        }
    | equality_expr OP_NEQ relational_expr
        {
            SymType t = sem_check_binop((SymType)$1.type,(SymType)$3.type,"!=",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_NEQ, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(!=)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
        }
    ;

relational_expr
    : additive_expr { $$ = $1; }
    | relational_expr OP_LT additive_expr
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_LT, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(<)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=SYM_INT;
        }
    | relational_expr OP_GT additive_expr
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_GT, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(>)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=SYM_INT;
        }
    | relational_expr OP_LTE additive_expr
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_LTE, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(<=)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=SYM_INT;
        }
    | relational_expr OP_GTE additive_expr
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_GTE, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(>=)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=SYM_INT;
        }
    ;

additive_expr
    : multiplicative_expr { $$ = $1; }
    | additive_expr OP_PLUS multiplicative_expr
        {
            SymType t = sem_check_binop((SymType)$1.type,(SymType)$3.type,"+",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_ADD, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(+)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
        }
    | additive_expr OP_MINUS multiplicative_expr
        {
            SymType t = sem_check_binop((SymType)$1.type,(SymType)$3.type,"-",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_SUB, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(-)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
        }
    ;

multiplicative_expr
    : unary_expr { $$ = $1; }
    | multiplicative_expr OP_MUL unary_expr
        {
            SymType t = sem_check_binop((SymType)$1.type,(SymType)$3.type,"*",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_MUL, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(*)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
        }
    | multiplicative_expr OP_DIV unary_expr
        {
            SymType t = sem_check_binop((SymType)$1.type,(SymType)$3.type,"/",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_DIV, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(/)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
        }
    | multiplicative_expr OP_MOD unary_expr
        {
            SymType t = sem_check_binop((SymType)$1.type,(SymType)$3.type,"%",yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_MOD, tmp, $1.temp, $3.temp);
            ASTNode *n = ast_new_node("(%)", yylineno);
            ast_add_child(n,$1.node); ast_add_child(n,$3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
        }
    ;

unary_expr
    : postfix_expr { $$ = $1; }
    | OP_MINUS unary_expr %prec UMINUS
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_UMINUS, tmp, $2.temp, "");
            ASTNode *n = ast_new_node("(unary-)", yylineno);
            ast_add_child(n,$2.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=$2.type;
        }
    | OP_NOT unary_expr
        {
            char *tmp = tac_new_temp();
            tac_emit(TAC_NOT, tmp, $2.temp, "");
            ASTNode *n = ast_new_node("(!)", yylineno);
            ast_add_child(n,$2.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=$2.type;
        }
    | OP_INC IDENTIFIER
        {
            SymType t = sem_check_var($2, yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_ADD,    tmp, $2, "1");
            tac_emit(TAC_ASSIGN, $2,  tmp, "");
            ASTNode *n = ast_new_node("(++pre)", yylineno);
            ast_add_child(n, ast_new_node($2, yylineno));
            $$.node=n; strncpy($$.temp,$2,63); $$.type=t;
            free($2);
        }
    | OP_DEC IDENTIFIER
        {
            SymType t = sem_check_var($2, yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_SUB,    tmp, $2, "1");
            tac_emit(TAC_ASSIGN, $2,  tmp, "");
            ASTNode *n = ast_new_node("(--pre)", yylineno);
            ast_add_child(n, ast_new_node($2, yylineno));
            $$.node=n; strncpy($$.temp,$2,63); $$.type=t;
            free($2);
        }
    ;

postfix_expr
    : primary_expr { $$ = $1; }
    | IDENTIFIER OP_INC
        {
            SymType t = sem_check_var($1, yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_ASSIGN, tmp, $1, "");
            tac_emit(TAC_ADD,    $1,  $1, "1");
            ASTNode *n = ast_new_node("(post++)", yylineno);
            ast_add_child(n, ast_new_node($1, yylineno));
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
            free($1);
        }
    | IDENTIFIER OP_DEC
        {
            SymType t = sem_check_var($1, yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_ASSIGN, tmp, $1, "");
            tac_emit(TAC_SUB,    $1,  $1, "1");
            ASTNode *n = ast_new_node("(post--)", yylineno);
            ast_add_child(n, ast_new_node($1, yylineno));
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
            free($1);
        }
    | IDENTIFIER LPAREN arg_list RPAREN
        {
            SymType t = sem_check_call($1, param_count, yylineno);
            char *tmp = tac_new_temp();
            char cnt[8]; snprintf(cnt,sizeof(cnt),"%d",param_count);
            tac_emit(TAC_CALL, tmp, $1, cnt);
            param_count = 0;
            ASTNode *n = ast_new_node("FunctionCall", yylineno);
            ast_add_child(n, ast_new_node($1, yylineno));
            if ($<expr>3.node) ast_add_child(n, $<expr>3.node);
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
            free($1);
        }
    | IDENTIFIER LPAREN RPAREN
        {
            SymType t = sem_check_call($1, 0, yylineno);
            char *tmp = tac_new_temp();
            tac_emit(TAC_CALL, tmp, $1, "0");
            ASTNode *n = ast_new_node("FunctionCall", yylineno);
            ast_add_child(n, ast_new_node($1, yylineno));
            $$.node=n; strncpy($$.temp,tmp,63); $$.type=t;
            free($1);
        }
    ;

arg_list
    : expression
        {
            tac_emit(TAC_PARAM, "", $1.temp, "");
            param_count = 1;
            ASTNode *al = ast_new_node("ArgList", yylineno);
            ast_add_child(al, $1.node);
            $<expr>$.node = al;
        }
    | arg_list COMMA expression
        {
            tac_emit(TAC_PARAM, "", $3.temp, "");
            param_count++;
            ast_add_child($<expr>1.node, $3.node);
            $<expr>$.node = $<expr>1.node;
        }
    ;

primary_expr
    : INT_LITERAL
        {
            char buf[32];
            snprintf(buf, sizeof(buf), "%d", $1);
            ASTNode *lit = ast_new_node("(Literal)", yylineno);
            ast_add_child(lit, ast_new_node(buf, yylineno));
            $$.node=lit; strncpy($$.temp,buf,63); $$.type=SYM_INT;
        }
    | FLOAT_LITERAL
        {
            ASTNode *lit = ast_new_node("(Literal)", yylineno);
            ast_add_child(lit, ast_new_node($1, yylineno));
            $$.node=lit; strncpy($$.temp,$1,63); $$.type=SYM_FLOAT;
            free($1);
        }
    | CHAR_LITERAL
        {
            ASTNode *lit = ast_new_node("(Literal)", yylineno);
            ast_add_child(lit, ast_new_node($1, yylineno));
            $$.node=lit; strncpy($$.temp,$1,63); $$.type=SYM_CHAR;
            free($1);
        }
    | IDENTIFIER
        {
            SymType t = sem_check_var($1, yylineno);
            ASTNode *id = ast_new_node("Identifier", yylineno);
            ast_add_child(id, ast_new_node($1, yylineno));
            $$.node=id; strncpy($$.temp,$1,63); $$.type=t;
            free($1);
        }
    | LPAREN expression RPAREN
        {
            ASTNode *grp = ast_new_node("(grouped)", yylineno);
            ast_add_child(grp, $2.node);
            $$.node=grp; strncpy($$.temp,$2.temp,63); $$.type=$2.type;
        }
    ;

%%

/* ── Helper: declare function + enter scope ── */
static void begin_function(const char *name, const char *type_str) {
    SymType rt = str_to_type(type_str);
    sem_declare_func(name, rt, yylineno);
    sem_enter_scope();
}

/* ── Syntax error ── */
void yyerror(const char *msg) {
    SYN_ERR(yylineno, "%s", msg);
}
