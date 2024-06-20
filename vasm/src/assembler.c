#include "assembler.h"

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
            memory[pc++] = get_command_code(instr);
            memory[pc++] = reg1;
            memory[pc++] = reg2;
        } else if (sscanf(line, "%s %d", instr, &reg1) == 2) {
            memory[pc++] = get_command_code(instr);
            memory[pc++] = reg1;
        } else if (sscanf(line, "%s", instr) == 1) {
            memory[pc++] = get_command_code(instr);
        }
    }

    fwrite(memory, sizeof(unsigned char), pc, output);

    fclose(input);
    fclose(output);
}
