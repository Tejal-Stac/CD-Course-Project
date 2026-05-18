#ifndef SYMTAB_H
#define SYMTAB_H

#define MAX_SYMBOLS 512
#define MAX_NAME    128

typedef enum { SYM_INT, SYM_FLOAT, SYM_CHAR, SYM_VOID, SYM_UNKNOWN } SymType;
typedef enum { KIND_VAR, KIND_FUNC, KIND_PARAM } SymKind;

typedef struct {
    char    name[MAX_NAME];
    SymType type;
    SymKind kind;
    int     scope;
    int     line;
    int     is_defined;
} Symbol;

void    symtab_init       (void);
int     symtab_insert     (const char *name, SymType type,
                            SymKind kind, int scope, int line);
Symbol *symtab_lookup     (const char *name, int scope);
Symbol *symtab_lookup_any (const char *name);
void    symtab_print      (void);
int     symtab_count      (void);

const char *type_to_str (SymType t);
SymType     str_to_type (const char *s);

#endif