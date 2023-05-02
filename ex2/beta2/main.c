#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "grep_flags.h"
#include "reader_utils.h"
#include "regex_utils.h"
#include "print_utils.h"


void execute_grep(Flags* flags, Regex* regexx, Reader* reader){
    char* regex = get_str_flags(flags, pattern_flag);
    char* line = NULL;
    long match_counter = 0;
    while (read_next_line(reader, &line) != -1) {
        if (is_matching(flags, regex, line)) {
            match_counter++;
            print_matched_line(flags, reader, line);
        }
    }
    print_matches_counter(flags, match_counter);
    free(line);
    line = NULL;
    assert(regexx);
}

int main(int argc, char *argv[]) {
    Flags* flags = get_flags(argc, argv);
    Regex* regex =   get_regex(     get_str_flags(flags, pattern_flag)  );
    Reader* reader = get_reader(    get_str_flags(flags, file_flag)     );

    execute_grep(flags, regex, reader);

    free_flags(flags);    
    free_regex(regex);
    free_reader(reader);
    return 0;
}
