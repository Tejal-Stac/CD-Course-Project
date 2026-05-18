#include <stdio.h>
#include <string.h>
#include "symtab.h"

static Symbol table[MAX_SYMBOLS];
static int    sym_count = 0;

void symtab_init(void) {
    sym_count = 0;
    memset(table, 0, sizeof(table));
}

int symtab_insert(const char *name, SymType type, SymKind kind,
                  int scope, int line) {
    for (int i = 0; i < sym_count; i++)
        if (strcmp(table[i].name, name) == 0 && table[i].scope == scope) {
            table[i].type = type; table[i].line = line; return i;
        }
    if (sym_count >= MAX_SYMBOLS) return -1;
    strncpy(table[sym_count].name, name, MAX_NAME - 1);
    table[sym_count].type  = type;
    table[sym_count].kind  = kind;
    table[sym_count].scope = scope;
    table[sym_count].line  = line;
    return sym_count++;
}

Symbol *symtab_lookup(const char *name, int scope) {
    for (int i = sym_count - 1; i >= 0; i--)
        if (strcmp(table[i].name, name) == 0 && table[i].scope == scope)
            return &table[i];
    return NULL;
}

Symbol *symtab_lookup_any(const char *name) {
    for (int i = sym_count - 1; i >= 0; i--)
        if (strcmp(table[i].name, name) == 0) return &table[i];
    return NULL;
}

const char *type_to_str(SymType t) {
    switch(t) {
        case SYM_INT:   return "int";
        case SYM_FLOAT: return "float";
        case SYM_CHAR:  return "char";
        case SYM_VOID:  return "void";
        default:        return "unknown";
    }
}

SymType str_to_type(const char *s) {
    if (strcmp(s,"int")  ==0) return SYM_INT;
    if (strcmp(s,"float")==0) return SYM_FLOAT;
    if (strcmp(s,"char") ==0) return SYM_CHAR;
    if (strcmp(s,"void") ==0) return SYM_VOID;
    return SYM_UNKNOWN;
}

int symtab_count(void) { return sym_count; }

void symtab_print(void) {
    printf("[\n");
    for (int i = 0; i < sym_count; i++) {
        printf("  {\"name\":\"%s\",\"type\":\"%s\",\"kind\":\"%s\","
               "\"scope\":%d,\"line\":%d}%s\n",
               table[i].name, type_to_str(table[i].type),
               table[i].kind==KIND_FUNC  ? "function"  :
               table[i].kind==KIND_PARAM ? "parameter" : "variable",
               table[i].scope, table[i].line,
               i < sym_count-1 ? "," : "");
    }
    printf("]\n");
}