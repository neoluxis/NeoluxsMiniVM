#ifndef __ACMD_H__
#define __ACMD_H__

#include "main.h"

typedef enum {
    MOV, ADD, SUB, MUL, DIV, PUSH, POP, LRC, RRC, JMP, NOP, HLT, OUT, LOAD, STORE
} Command;

extern int get_command_code(const char *cmd);

#endif