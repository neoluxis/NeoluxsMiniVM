#include "vmec.h"

void init_vm(VM *vm) {
    memset(vm, 0, sizeof(VM));
    vm->sp = -1;
    vm->running = 1;
}

void execute(VM *vm) {
    while (vm->running) {
        Command instr = (Command)vm->memory[vm->pc];
        int reg1, reg2, value, addr;
        switch (instr) {
            case MOV:
                reg1 = vm->memory[vm->pc + 1];
                value = vm->memory[vm->pc + 2];
                vm->registers[reg1] = value;
                vm->pc += 3;
                break;
            case ADD:
                reg1 = vm->memory[vm->pc + 1];
                reg2 = vm->memory[vm->pc + 2];
                vm->registers[reg1] += vm->registers[reg2];
                vm->pc += 3;
                break;
            case SUB:
                reg1 = vm->memory[vm->pc + 1];
                reg2 = vm->memory[vm->pc + 2];
                vm->registers[reg1] -= vm->registers[reg2];
                vm->pc += 3;
                break;
            case MUL:
                reg1 = vm->memory[vm->pc + 1];
                reg2 = vm->memory[vm->pc + 2];
                vm->registers[reg1] *= vm->registers[reg2];
                vm->pc += 3;
                break;
            case DIV:
                reg1 = vm->memory[vm->pc + 1];
                reg2 = vm->memory[vm->pc + 2];
                if (vm->registers[reg2] != 0) {
                    vm->registers[reg1] /= vm->registers[reg2];
                } else {
                    printf("Division by zero error\n");
                    vm->running = 0;
                }
                vm->pc += 3;
                break;
            case PUSH:
                reg1 = vm->memory[vm->pc + 1];
                vm->stack[++vm->sp] = vm->registers[reg1];
                vm->pc += 2;
                break;
            case POP:
                reg1 = vm->memory[vm->pc + 1];
                if (vm->sp >= 0) {
                    vm->registers[reg1] = vm->stack[vm->sp--];
                } else {
                    printf("Stack underflow error\n");
                    vm->running = 0;
                }
                vm->pc += 2;
                break;
            case LRC:
                reg1 = vm->memory[vm->pc + 1];
                value = vm->registers[reg1];
                vm->registers[reg1] = (value >> 1) | ((value & 1) << 31);
                vm->pc += 2;
                break;
            case RRC:
                reg1 = vm->memory[vm->pc + 1];
                value = vm->registers[reg1];
                vm->registers[reg1] = (value << 1) | ((value & 0x80000000) >> 31);
                vm->pc += 2;
                break;
            case JMP:
                value = vm->memory[vm->pc + 1];
                vm->pc = value;
                break;
            case NOP:
                vm->pc += 1;
                break;
            case HLT:
                vm->running = 0;
                break;
            case OUT:
                reg1 = vm->memory[vm->pc + 1];
                printf("%c", vm->registers[reg1]);
                vm->pc += 2;
                break;
            case LOAD:
                reg1 = vm->memory[vm->pc + 1];
                addr = vm->memory[vm->pc + 2];
                vm->registers[reg1] = vm->memory[addr];
                vm->pc += 3;
                break;
            case STORE:
                reg1 = vm->memory[vm->pc + 1];
                addr = vm->memory[vm->pc + 2];
                vm->memory[addr] = vm->registers[reg1];
                vm->pc += 3;
                break;
            default:
                printf("Unknown instruction %d at address %d\n", instr, vm->pc);
                vm->running = 0;
                break;
        }
    }
}
