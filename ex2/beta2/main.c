#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "grep_flags.h"
#include "file_reader.h"


void run_stdin_grep(Flags* flags) {
    return;
}

void run_file_grep(Flags* flags) {
    Reader* fr = get_file_reader(get_str_flags(flags, file_flag));
    
    free_file_reader(fr);
    return;
}



int main(int argc, char *argv[]) {
    Flags* flags = get_flags(argc, argv);
    char* input_file = get_str_flags(flags, file_flag);
    if (input_file == NULL) {
        run_stdin_grep(flags);
    }
    else {
        run_file_grep(flags);
    }
    free_flags(flags);
    return 0;
}
