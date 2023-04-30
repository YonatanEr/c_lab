#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "grep_flags.h"
#include "file_reader.h"
#include "regex_utils.h"


void run_stdin_grep(Flags* flags) {
    assert(flags);
    return;
}


void run_file_grep(Flags* flags) {
    Reader* fr = get_file_reader(get_str_flags(flags, file_flag));
    char* reg = get_str_flags(flags, word_flag);
    char* line = NULL;
    while (read_next_line(fr, &line) != -1) {
        if (is_matching(reg, line)) {
            printf("%s\n", line);
        }
    }
    free_file_reader(fr);
    free(line);
    line = NULL;
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
