#ifndef AST_H
#define AST_H

/* ============================================================
   ast.h  —  Parse Tree (AST) Node Definition
   Every grammar rule in parser.y creates one of these nodes.
   The tree is printed in the style shown in your reference
   image — plain text, indented, no colours.
   ============================================================ */

#define MAX_CHILDREN 8
#define MAX_LABEL    128

typedef struct ASTNode {
    char            label[MAX_LABEL];   /* e.g. "Code Statement", "int", "x" */
    struct ASTNode *children[MAX_CHILDREN];
    int             child_count;
    int             line;               /* source line for error messages     */
} ASTNode;

/* ── Node creation ── */
ASTNode *ast_new_node   (const char *label, int line);
void     ast_add_child  (ASTNode *parent, ASTNode *child);

/* ── Tree printing (plain text, like your reference image) ── */
void     ast_print      (ASTNode *root);   /* calls ast_print_indent internally */
void     ast_print_json (ASTNode *root);   /* JSON for frontend rendering       */

/* ── Cleanup ── */
void     ast_free       (ASTNode *root);

#endif /* AST_H */