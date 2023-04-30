#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file_reader.h"
#include "grep_flags.h"


void print_line(Flags* flags, char* line, long bytes_counter, long line_counter, char c) {
    if (get_bool_flags(flags, b_flag)) {
        printf("%ld%c", bytes_counter, c);
    }
    if (get_bool_flags(flags, n_flag)) {
        printf("%ld%c", line_counter, c);
    }
    if (get_bool_flags(flags, c_flag)) {
        printf("%ld", line_counter);
    }
    else {
        printf("%s", line);
    }
}


void print_format(Flags* flags, char* line, Reader* fr) {
    print_line(flags, line, fr->bytes_counter-strlen(line)-1, fr->line_counter-1, ':');
    long saved_bytes_counter = fr->bytes_counter;
    long saved_line_counter = fr->line_counter;
    char* next_line = NULL;
    for (int i=0; i<get_int_flags(flags, A_flag); i++) {
        read_next_line(fr, &next_line);
        print_line(flags, line, fr->bytes_counter, fr->line_counter, '-');
        free(next_line);
        next_line = NULL;
    }
    long jump_back = -(fr->bytes_counter - saved_bytes_counter);
    move_file_pointer(fr, jump_back);
    fr->bytes_counter = saved_bytes_counter;
    fr->line_counter = saved_line_counter;
}