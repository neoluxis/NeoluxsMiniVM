#ifndef __VMEC_H__
#define __VMEC_H__

#include "main.h"
#include "vcmd.h"

typedef struct {
    int registers[NUM_REGISTERS];
    int stack[STACK_SIZE];
    unsigned char memory[MEMORY_SIZE];
    int pc;
    int sp;
    int running;
} VM;

extern void init_vm(VM *vm);
extern void execute(VM *vm);

#endif