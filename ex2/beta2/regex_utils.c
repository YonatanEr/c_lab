#include "regex_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define DOT 46                         //   '.'

#define BACKSLASH 92                   //   '\'

#define LEFT_ROUND_BRACKET 40          //   '('
#define RIGHT_ROUND_BRACKET 41         //   ')'

#define LEFT_SQUARE_BRACKET 91         //   '['
#define RIGHT_SQUARE_BRACKET 93        //   ']'

#define LEFT_CURLY_BRACKET 123         //   '{'
#define RIGHT_CURLY_BRACKET 125        //   '}'

#define OR 124                         //   '|'



union RegexLetter* init_regex_letter() {
    union RegexLetter* reg;
    reg->c = 0;
    reg->dot = 0;
    reg->interval[0] = 0;
    reg->interval[1] = 0;
    reg->or_str = NULL;
    reg->which_letter = -1;
    return reg;
}


Regex* init_regex(char* pattern) { 
    assert(pattern);
    Regex* regex = (Regex*) malloc (1*sizeof(Regex));
    assert(regex);
    return regex;
}


void free_regex(Regex* regex) { 
    union RegexLetter* reg;
    for (int i=0; i<regex->len; i++) {
        reg = &regex->reg_arr[i];
        free(reg);
    }
    free(regex);
    regex = NULL;
}


int get_closing_bracket_ind(char* pattern, char closing_bracket, int start) {
    int len = strlen(pattern);
    for (int i=start+1; i<len; i++) {
        if (pattern[i] == BACKSLASH) {
            i++;
        }
        if (pattern[i] == closing_bracket) {
            return i;
        }
    }
    return -1;
}


int get_regex_len(char* pattern) {
    int len=0, pattern_len=strlen(pattern);
    for (int i=0; i<pattern_len; i++) {
        switch (pattern[i]) {
            case BACKSLASH:
                i++;
                break;
            case LEFT_ROUND_BRACKET:
                i = get_closing_bracket_ind(pattern, RIGHT_ROUND_BRACKET, i);
                break;
            case LEFT_SQUARE_BRACKET:
                i = get_closing_bracket_ind(pattern, RIGHT_SQUARE_BRACKET, i);
                break;
            default:
                if(pattern[i]<32) {
                    return len;
                }
                break;
        }
        len++;
    }
    return len;
}


void set_regex(Regex* regex, char* pattern) {
    int j=0, ind=0;
    for (int i=0; i<regex->len; i++) {
        switch (pattern[i]) {
            case BACKSLASH:
                i++;
                regex->reg_arr[i].c = pattern[i];
                break;
            case DOT:
                regex->reg_arr[i].dot = true;
                break;
            case LEFT_ROUND_BRACKET:
                j = get_closing_bracket_ind(pattern, RIGHT_ROUND_BRACKET, i);
                break;
            case LEFT_SQUARE_BRACKET:
                j = get_closing_bracket_ind(pattern, RIGHT_SQUARE_BRACKET, i);
                if (pattern[i] == OR) 
                break;
            default:
                regex->reg_arr[i].c = pattern[i];
                break;
        }
        ind++;
    }
}


Regex* get_regex(char* pattern) { 
    Regex* regex = init_regex(pattern);
    regex->len = get_regex_len(pattern);
    regex->reg_arr = (union RegexLetter*) malloc (regex->len * sizeof(union RegexLetter));
    assert(regex->reg_arr);
    set_regex(regex, pattern);
    return regex;
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

