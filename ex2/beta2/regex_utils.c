#include "regex_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

bool is_matching_letter(char reg_letter, char line_letter) {
    if (reg_letter=='\0') {
        return true;
    }
    if (reg_letter==line_letter) {
        return true;
    }
    return false;
}


bool is_matching_rec(char* reg, char* line, int i, int j) {
    if (!is_matching_letter(reg[i], line[j])) {
        return false;
    }
    if (reg[i]=='\0') {
        return true;
    }
    if (is_matching_rec(reg, line, i+1, j+1)) {
        return true;
    }
    if (is_matching_rec(reg, line, i+1, j)) {
        return true;
    }
    if (is_matching_rec(reg, line, i, j+1)) {
        return true;
    }
    return false;
}


bool is_matching_regex(char* reg, char* line) {
    return (strstr(line, reg) != NULL);
}


bool is_matching(char* reg, char* line) {
    char* line_copy = (char*) calloc (strlen(line)+1, sizeof(char));
    assert(line_copy);
    strcpy(line_copy, line);
    bool res = is_matching_regex(reg, line_copy);
    free(line_copy);
    line_copy = NULL;
    return res;
}

