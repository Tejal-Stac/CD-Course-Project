#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

/* ── Create a new node ── */
ASTNode *ast_new_node(const char *label, int line) {
    ASTNode *n = (ASTNode *)calloc(1, sizeof(ASTNode));
    if (!n) { fprintf(stderr, "ast: out of memory\n"); exit(1); }
    strncpy(n->label, label, MAX_LABEL - 1);
    n->child_count = 0;
    n->line        = line;
    return n;
}

/* ── Attach a child ── */
void ast_add_child(ASTNode *parent, ASTNode *child) {
    if (!parent || !child) return;
    if (parent->child_count >= MAX_CHILDREN) {
        fprintf(stderr, "ast: too many children for node '%s'\n", parent->label);
        return;
    }
    parent->children[parent->child_count++] = child;
}

/* ── Plain-text tree printer (like your reference image) ──
   Output looks like:
       Code Statement
       ├── Data
       │   └── int
       ├── Identifier
       │   └── x
       └── (=)
           └── (Expression)
               └── (Literal)
                   └── 10
   ──────────────────────────────────────────────────────── */

static void print_indent(ASTNode *node, char *prefix, int is_last) {
    if (!node) return;

    /* print current line */
    printf("%s", prefix);
    printf("%s", is_last ? "└── " : "├── ");
    printf("%s\n", node->label);

    /* build prefix for children */
    char new_prefix[1024];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s",
             prefix, is_last ? "    " : "│   ");

    for (int i = 0; i < node->child_count; i++) {
        int last_child = (i == node->child_count - 1);
        print_indent(node->children[i], new_prefix, last_child);
    }
}

void ast_print(ASTNode *root) {
    if (!root) { printf("(empty tree)\n"); return; }
    printf("%s\n", root->label);          /* root has no prefix/connector */
    for (int i = 0; i < root->child_count; i++) {
        int last = (i == root->child_count - 1);
        print_indent(root->children[i], "", last);
    }
}

/* ── JSON tree printer (for frontend D3 / recursive rendering) ── */
static void json_node(ASTNode *node, int depth) {
    if (!node) return;

    /* indentation */
    for (int i = 0; i < depth * 2; i++) printf(" ");

    printf("{\"label\":\"%s\",\"line\":%d", node->label, node->line);

    if (node->child_count > 0) {
        printf(",\"children\":[\n");
        for (int i = 0; i < node->child_count; i++) {
            json_node(node->children[i], depth + 1);
            if (i < node->child_count - 1) printf(",\n");
            else printf("\n");
        }
        for (int i = 0; i < depth * 2; i++) printf(" ");
        printf("]");
    }
    printf("}");
}

void ast_print_json(ASTNode *root) {
    json_node(root, 0);
    printf("\n");
}

/* ── Free entire tree ── */
void ast_free(ASTNode *root) {
    if (!root) return;
    for (int i = 0; i < root->child_count; i++)
        ast_free(root->children[i]);
    free(root);
}