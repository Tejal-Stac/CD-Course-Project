#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"

static TACInstr instrs[MAX_TAC];
static int      instr_count = 0;
static int      temp_count  = 0;
static int      label_count = 0;

void tac_init(void) {
    instr_count = temp_count = label_count = 0;
    memset(instrs, 0, sizeof(instrs));
}

void tac_emit(TACOp op, const char *result,
              const char *arg1, const char *arg2)
{
    if (instr_count >= MAX_TAC) return;
    instrs[instr_count].op = op;
    strncpy(instrs[instr_count].result, result ? result : "", MAX_TAC_STR-1);
    strncpy(instrs[instr_count].arg1,   arg1   ? arg1   : "", MAX_TAC_STR-1);
    strncpy(instrs[instr_count].arg2,   arg2   ? arg2   : "", MAX_TAC_STR-1);
    instr_count++;
}

char *tac_new_temp(void) {
    static char buf[16];
    snprintf(buf, sizeof(buf), "t%d", ++temp_count);
    return buf;
}

char *tac_new_label(void) {
    static char buf[16];
    snprintf(buf, sizeof(buf), "L%d", ++label_count);
    return buf;
}

int tac_count(void) { return instr_count; }

/* ── Plain text print ── */
static const char *op_sym(TACOp op) {
    switch(op) {
        case TAC_ADD: return "+";  case TAC_SUB: return "-";
        case TAC_MUL: return "*";  case TAC_DIV: return "/";
        case TAC_MOD: return "%";
        case TAC_LT:  return "<";  case TAC_GT:  return ">";
        case TAC_LTE: return "<="; case TAC_GTE: return ">=";
        case TAC_EQ:  return "=="; case TAC_NEQ: return "!=";
        case TAC_AND: return "&&"; case TAC_OR:  return "||";
        default: return "?";
    }
}

void tac_print(void) {
    for (int i = 0; i < instr_count; i++) {
        TACInstr *t = &instrs[i];
        switch(t->op) {
            case TAC_ASSIGN:
                printf("%2d:  %s = %s\n", i+1, t->result, t->arg1); break;
            case TAC_ADD: case TAC_SUB: case TAC_MUL: case TAC_DIV:
            case TAC_MOD: case TAC_LT:  case TAC_GT:  case TAC_LTE:
            case TAC_GTE: case TAC_EQ:  case TAC_NEQ: case TAC_AND:
            case TAC_OR:
                printf("%2d:  %s = %s %s %s\n", i+1,
                       t->result, t->arg1, op_sym(t->op), t->arg2); break;
            case TAC_UMINUS:
                printf("%2d:  %s = -%s\n", i+1, t->result, t->arg1); break;
            case TAC_NOT:
                printf("%2d:  %s = !%s\n", i+1, t->result, t->arg1); break;
            case TAC_LABEL:
                printf("%2d:  %s:\n", i+1, t->result); break;
            case TAC_GOTO:
                printf("%2d:  goto %s\n", i+1, t->result); break;
            case TAC_IF_FALSE:
                printf("%2d:  if_false %s goto %s\n",
                       i+1, t->arg1, t->result); break;
            case TAC_PARAM:
                printf("%2d:  param %s\n", i+1, t->arg1); break;
            case TAC_CALL:
                printf("%2d:  %s = call %s, %s\n",
                       i+1, t->result, t->arg1, t->arg2); break;
            case TAC_RETURN:
                printf("%2d:  return %s\n", i+1, t->arg1); break;
            case TAC_FUNC_BEGIN:
                printf("%2d:  func_begin %s\n", i+1, t->arg1); break;
            case TAC_FUNC_END:
                printf("%2d:  func_end %s\n", i+1, t->arg1); break;
        }
    }
}

/* ── JSON print ── */
void tac_print_json(void) {
    printf("[\n");
    for (int i = 0; i < instr_count; i++) {
        TACInstr *t = &instrs[i];
        printf("  {\"index\":%d,\"op\":%d,"
               "\"result\":\"%s\",\"arg1\":\"%s\",\"arg2\":\"%s\"}%s\n",
               i+1, t->op, t->result, t->arg1, t->arg2,
               i < instr_count-1 ? "," : "");
    }
    printf("]\n");
}