#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "grep_flags.h"
#include "print_utils.h"
#include "reader_utils.h"
#include "regex_utils.h"


void handle_matched_line(Flags* flags, Reader* reader, char* line, long* match_count, long* last_match)
{
    *match_count = (*match_count) + 1;
    *last_match = reader->lines_counter;
    if (get_bool_flags(flags, c_flag)) {
        return;
    }
    print_matched_line(flags, reader, line);
}


void handle_unmatched_line(Flags* flags, Reader* reader, char* line, long last_matched_line)
{
    long A = get_long_flags(flags, A_flag);
    if (get_bool_flags(flags, c_flag)) {
        return;
    }
    if (A == 0) {
        return;
    }
    if (last_matched_line == -1) {
        return;
    }
    if (reader->lines_counter-last_matched_line==A+1 && A!=0) {
        printf("--\n");
    }
    if (reader->lines_counter-last_matched_line > A) {
        return;
    }
    print_unmatched_line(flags, reader, line);
}


void execute_grep(Flags* flags, Regex* regexx, Reader* reader) 
{
    char* regex = get_str_flags(flags, pattern_flag);
    char* line = NULL;
    long match_count = 0;
    long last_match = -1;
    while (read_next_line(reader, &line) != -1) {   
        if (is_matching(flags, regex, line)) {
            handle_matched_line(flags, reader, line, &match_count, &last_match);
        }
        else {
            handle_unmatched_line(flags, reader, line, last_match);
        }
        free(line);
        line = NULL;
    }
    free(line);
    line = NULL;    
    if (get_bool_flags(flags, c_flag)) {
        printf("%ld\n", match_count);
    }
    assert(regexx);
}


int main(int argc, char *argv[]) 
{
    Flags*  flags  = get_flags(argc, argv);
    Regex*  regex  = get_regex(     get_str_flags(flags, pattern_flag)  );
    Reader* reader = get_reader(    get_str_flags(flags, file_flag)     );
    execute_grep(flags, regex, reader);
    free_flags(flags);    
    free_regex(regex);
    free_reader(reader);
    return 0;
}
