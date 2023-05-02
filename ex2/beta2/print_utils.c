#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "reader_utils.h"
#include "grep_flags.h"


void print_line(Flags* flags, char* line, long bytes_counter, long line_counter, char c) {
    if (get_bool_flags(flags, c_flag)) {
        return;
    }
    if (get_bool_flags(flags, n_flag)) {
        printf("%ld%c", line_counter, c);
    }
    if (get_bool_flags(flags, b_flag)) {
        printf("%ld%c", bytes_counter, c);
    }
    if (!get_bool_flags(flags, c_flag)) {
        printf("%s", line);
    }
}


void print_format(Flags* flags, Reader* reader, char* line, char delimiter) {
    long cur_bytes_counter = reader->bytes_counter-strlen(line);
    long cur_lines_counter = reader->lines_counter;
    print_line(flags, line, cur_bytes_counter, cur_lines_counter, delimiter);
}


void print_matched_line(Flags* flags, Reader* reader, char* line) {
    print_format(flags, reader, line, ':');
}


void print_unmatched_line(Flags* flags, Reader* reader, char* line) {
    print_format(flags, reader, line, '-');
}


void print_match_counter(Flags* flags, long match_counter) {    
    if (get_bool_flags(flags, c_flag)) {
        printf("%ld\n", match_counter);
    }
}




