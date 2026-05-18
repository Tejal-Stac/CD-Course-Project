#ifndef ERROR_H
#define ERROR_H

#define MAX_ERRORS 256

typedef enum {
    ERR_LEXICAL,
    ERR_SYNTAX,
    ERR_SEMANTIC
} ErrKind;

typedef struct {
    ErrKind kind;
    int     line;
    char    message[256];
} CompileError;

void error_init  (void);
void error_add   (ErrKind kind, int line, const char *fmt, ...);
void error_print (void);
int  error_count (void);
int  has_errors  (void);

#define LEX_ERR(line, ...)  error_add(ERR_LEXICAL,  line, __VA_ARGS__)
#define SYN_ERR(line, ...)  error_add(ERR_SYNTAX,   line, __VA_ARGS__)
#define SEM_ERR(line, ...)  error_add(ERR_SEMANTIC,  line, __VA_ARGS__)

#endif