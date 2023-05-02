#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "grep_flags.h"
#include "print_utils.h"
#include "reader_utils.h"
#include "regex_utils.h"


void handle_following_lines(Flags* flags, char* regex, Reader* reader, long* match_counter_ptr);
void handle_line(Flags* flags, char* regex, Reader* reader, long* match_counter_ptr, char* line);
void execute_grep(Flags* flags, Regex* regexx, Reader* reader);


void handle_following_lines(Flags* flags, char* regex, Reader* reader, long* match_counter_ptr) {
    printf("AAA\n\n\n");
    char* line = NULL;
    for (int i=0; i<get_long_flags(flags, A_flag); i++) {
        if (read_next_line(reader, &line) == -1) {
            break;
        }
        if (is_matching(flags, regex, line)) {
            handle_line(flags, regex, reader, match_counter_ptr, line);
            break;
        }
        print_unmatched_line(flags, reader, line);
        free(line);
        line = NULL;
    }
    free(line);
    line = NULL;
    printf("BBB\n\n\n");
    return;
}

void handle_line(Flags* flags, char* regex, Reader* reader, long* match_counter_ptr, char* line) {
    long match_counter = *match_counter_ptr;
    if (is_matching(flags, regex, line)) {
        match_counter++;
        print_matched_line(flags, reader, line);
        free(line);
        line = NULL;
        handle_following_lines(flags, regex, reader, &match_counter);
    }
    *match_counter_ptr = match_counter;
}

void execute_grep(Flags* flags, Regex* regexx, Reader* reader) {
    char* regex = get_str_flags(flags, pattern_flag);
    char* line = NULL;
    long match_counter = 0;
    while (read_next_line(reader, &line) != -1) {
        handle_line(flags, regex, reader, &match_counter, line);
        printf("CCC\n");
        free(line);
        line = NULL;
        printf("DDD\n");
    }
    print_match_counter(flags, match_counter);
    assert(regexx);
}


int main(int argc, char *argv[]) {
    Flags* flags =   get_flags(     argc, argv);
    Regex* regex =   get_regex(     get_str_flags(flags, pattern_flag)  );
    Reader* reader = get_reader(    get_str_flags(flags, file_flag)     );

    execute_grep(flags, regex, reader);

    free_flags(flags);    
    free_regex(regex);
    free_reader(reader);
    return 0;
}
