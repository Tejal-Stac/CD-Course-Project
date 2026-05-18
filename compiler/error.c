#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "error.h"

static CompileError errors[MAX_ERRORS];
static int          err_count = 0;

void error_init(void) {
    err_count = 0;
    memset(errors, 0, sizeof(errors));
}

void error_add(ErrKind kind, int line, const char *fmt, ...) {
    if (err_count >= MAX_ERRORS) return;
    errors[err_count].kind = kind;
    errors[err_count].line = line;
    va_list args;
    va_start(args, fmt);
    vsnprintf(errors[err_count].message,
              sizeof(errors[err_count].message), fmt, args);
    va_end(args);
    const char *ks = kind == ERR_LEXICAL  ? "LEXICAL"  :
                     kind == ERR_SYNTAX   ? "SYNTAX"   : "SEMANTIC";
    fprintf(stderr, "[%s ERROR] Line %d: %s\n",
            ks, line, errors[err_count].message);
    err_count++;
}

int  error_count(void) { return err_count; }
int  has_errors (void) { return err_count > 0; }

void error_print(void) {
    printf("[\n");
    for (int i = 0; i < err_count; i++) {
        const char *ks = errors[i].kind == ERR_LEXICAL  ? "LEXICAL"  :
                         errors[i].kind == ERR_SYNTAX   ? "SYNTAX"   : "SEMANTIC";
        printf("  {\"kind\":\"%s\",\"line\":%d,\"message\":\"%s\"}%s\n",
               ks, errors[i].line, errors[i].message,
               i < err_count - 1 ? "," : "");
    }
    printf("]\n");
}