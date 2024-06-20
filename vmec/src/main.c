#include "main.h"
#include "vmec.h"
#include "vcmd.h"
#include "vprog.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <program.bin>\n", argv[0]);
        return EXIT_FAILURE;
    }

    VM vm;
    init_vm(&vm);
    load_program(&vm, argv[1]);
    execute(&vm);

    return EXIT_SUCCESS;
    return 0;
}
