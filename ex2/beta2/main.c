#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "grep_flags.h"

int main(int argc, char *argv[]) {
    Flags* flags = init_flags();
    update_flags(flags, argc, argv);
    print_flags(flags);
    free_flags(flags);
}
