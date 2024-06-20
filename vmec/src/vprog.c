#include "vprog.h"

void load_program(VM *vm, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open program file");
        exit(EXIT_FAILURE);
    }
    fread(vm->memory, 1, MEMORY_SIZE, file);
    fclose(file);
}