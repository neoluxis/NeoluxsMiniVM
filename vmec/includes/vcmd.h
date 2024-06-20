#ifndef __VCMD_H__
#define __VCMD_H__

#include "main.h"

typedef enum {
    MOV, ADD, SUB, MUL, DIV, PUSH, POP, LRC, RRC, JMP, NOP, HLT, OUT, LOAD, STORE
} Command;

#endif