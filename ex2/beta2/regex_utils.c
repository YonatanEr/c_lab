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
    if (reg_letter=='\0') {
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


bool is_matching_rec(Flags* flags, char* reg, char* line, int i, int j) {
    if (reg[i]=='\0') {
        return true;
    }
    if (!is_matching_letter(flags, reg[i], line[j])) {
        return false;
    }
    if (is_matching_rec(flags, reg, line, i+1, j+1)) {
        return true;
    }
    if (is_matching_rec(flags, reg, line, i+1, j)) {
        return true;
    }
    if (is_matching_rec(flags, reg, line, i, j+1)) {
        return true;
    }
    return false;
}


bool is_matching_regex(Flags* flags, char* reg, char* line) {
    assert(flags);
    //printf("reg = %s\n",reg);
    //printf("line = %s\n",line);
    if (reg[0] == '\0') {
        return true;
    }
    return (strstr(line, reg) != NULL);
}


bool is_matching(Flags* flags, char* reg, char* line) {
    if (reg==NULL || line==NULL) {
        return false;
    }
    char* line_copy = (char*) calloc (strlen(line)+1, sizeof(char));
    assert(line_copy);
    strcpy(line_copy, line);
    char* reg_copy = (char*) calloc (strlen(reg)+1, sizeof(char));
    assert(reg);
    strcpy(reg_copy, reg);
    bool res = is_matching_regex(flags, reg_copy, line_copy);
    free(line_copy);
    line_copy = NULL;
    free(reg_copy);
    line_copy = NULL;
    if (get_bool_flags(flags, v_flag)) {
        return !res;
    }
    return res;
}

