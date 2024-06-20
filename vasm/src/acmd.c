#include "acmd.h"

int get_command_code(const char *instr) {
    if (strcmp(instr, "MOV") == 0) return MOV;
    if (strcmp(instr, "ADD") == 0) return ADD;
    if (strcmp(instr, "SUB") == 0) return SUB;
    if (strcmp(instr, "MUL") == 0) return MUL;
    if (strcmp(instr, "DIV") == 0) return DIV;
    if (strcmp(instr, "PUSH") == 0) return PUSH;
    if (strcmp(instr, "POP") == 0) return POP;
    if (strcmp(instr, "LRC") == 0) return LRC;
    if (strcmp(instr, "RRC") == 0) return RRC;
    if (strcmp(instr, "JMP") == 0) return JMP;
    if (strcmp(instr, "NOP") == 0) return NOP;
    if (strcmp(instr, "HLT") == 0) return HLT;
    if (strcmp(instr, "OUT") == 0) return OUT;
    if (strcmp(instr, "LOAD") == 0) return LOAD;
    if (strcmp(instr, "STORE") == 0) return STORE;
    return -1;
}