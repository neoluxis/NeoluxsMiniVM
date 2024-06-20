#include "main.h"
#include "assembler.h"
#include "acmd.h"

int main(int argc, char const *argv[])
{    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.asm> <output.bin>\n", argv[0]);
        return EXIT_FAILURE;
    }

    assemble(argv[1], argv[2]);
    return EXIT_SUCCESS;
    return 0;
}
