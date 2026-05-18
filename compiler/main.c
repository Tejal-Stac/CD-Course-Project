#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "ast.h"
#include "semantic.h"
#include "tac.h"
#include "error.h"

/* from lexer / parser */
extern FILE    *yyin;
extern int      yyparse(void);
extern int      get_token_count(void);
extern ASTNode *parse_tree_root;

int main(int argc, char *argv[]) {

    /* ── 1. Open input file ── */
    if (argc < 2) {
        fprintf(stderr, "Usage: minicc <source.c>\n");
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        return 1;
    }

    /* ── 2. Initialise all modules ── */
    error_init();
    symtab_init();
    sem_init();
    tac_init();

    /* ── 3. Parse (drives lexer internally) ── */
    yyparse();
    fclose(yyin);

    /* ── 4. Emit single JSON object to stdout ── */
    printf("{\n");

    /* — token count — */
    printf("  \"token_count\": %d,\n", get_token_count());

    /* — symbol table — */
    printf("  \"symbol_table\": ");
    symtab_print();
    printf(",\n");

    /* — parse tree — */
    printf("  \"parse_tree\": ");
    if (parse_tree_root)
        ast_print_json(parse_tree_root);
    else
        printf("null");
    printf(",\n");

    /* — three address code — */
    printf("  \"tac\": ");
    tac_print_json();
    printf(",\n");

    /* — errors — */
    printf("  \"errors\": ");
    error_print();
    printf("\n}\n");

    /* ── 5. Print plain text parse tree to stderr
            (visible in terminal during development) ── */
    fprintf(stderr, "\n── Parse Tree ──\n");
    if (parse_tree_root)
        ast_print(parse_tree_root);
    else
        fprintf(stderr, "(no tree)\n");

    fprintf(stderr, "\n── Three Address Code ──\n");
    tac_print();

    /* exit code: 0 = success (even with semantic errors),
       1 = hard failure (file not found etc.)            */
    return 0;
}