#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MEMORY_SIZE 256

typedef enum {
    MOV, ADD, SUB, MUL, DIV, PUSH, POP, LRC, RRC, JMP, NOP, HLT, OUT, LOAD, STORE
} Instruction;

int get_instruction_code(const char *instr) {
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

void assemble(const char *input_filename, const char *output_filename) {
    FILE *input = fopen(input_filename, "r");
    if (!input) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_filename, "wb");
    if (!output) {
        perror("Failed to open output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    unsigned char memory[MEMORY_SIZE] = {0};
    int pc = 0;

    while (fgets(line, sizeof(line), input)) {
        char instr[10];
        int reg1, reg2, value;

        if (sscanf(line, "%s %d %d", instr, &reg1, &reg2) == 3) {
            memory[pc++] = get_instruction_code(instr);
            memory[pc++] = reg1;
            memory[pc++] = reg2;
        } else if (sscanf(line, "%s %d", instr, &reg1) == 2) {
            memory[pc++] = get_instruction_code(instr);
            memory[pc++] = reg1;
        } else if (sscanf(line, "%s", instr) == 1) {
            memory[pc++] = get_instruction_code(instr);
        }
    }

    fwrite(memory, sizeof(unsigned char), pc, output);

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.asm> <output.bin>\n", argv[0]);
        return EXIT_FAILURE;
    }

    assemble(argv[1], argv[2]);
    return EXIT_SUCCESS;
}
