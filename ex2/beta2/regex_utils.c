#include "regex_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


Regex* init_regex(char* pattern) { 
    assert(pattern);
    Regex* regex = (Regex*) malloc (1*sizeof(Regex));
    assert(regex);
    return regex;
}

Regex* get_regex(char* pattern) { 
    return init_regex(pattern);
}

void free_regex(Regex* regex) { 
    free(regex);
    regex = NULL;
}


char to_lower_case(char c) {
    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}


bool is_matching_letter(Flags* flags, char reg_letter, char line_letter) {
    if (reg_letter<32 && line_letter<32) {
        return true;
    }
    if (reg_letter=='.') {
        return true;
    }
    if (reg_letter==line_letter) {
        return true;
    }
    if (get_bool_flags(flags, i_flag)) {
        return to_lower_case(reg_letter) == to_lower_case(line_letter);
    }
    return false;
}


bool is_matching_rec(Flags* flags, char* regex, char* line, int i, int j) {
    if (regex[i]=='\0') {
        return true;
    }
    if (!is_matching_letter(flags, regex[i], line[j])) {
        return false;
    }
    if (is_matching_rec(flags, regex, line, i+1, j+1)) {
        return true;
    }
    if (is_matching_rec(flags, regex, line, i+1, j)) {
        return true;
    }
    if (is_matching_rec(flags, regex, line, i, j+1)) {
        return true;
    }
    return false;
}


bool is_equal_regex_string(Flags* flags, char* regex, char* line) {
    int len = strlen(line);
    for (int i=0; i<len; i++) {
        if (!is_matching_letter(flags, regex[i], line[i])) {
            return false;
        }
    }
    return true;
}


bool is_matching_regex_string(Flags* flags, char* regex, char* line) {
    if (get_bool_flags(flags, x_flag)) {
        return is_equal_regex_string(flags, regex, line);
    }
    return (strstr(line, regex) != NULL);
}


bool is_matching(Flags* flags, char* regex, char* line) {
    bool res = is_matching_regex_string(flags, regex, line);
    if (get_bool_flags(flags, v_flag)) {
        return !res;
    }
    return res;
}

