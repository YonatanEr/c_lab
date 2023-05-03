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

#define or 124                         //   '|'



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
                if(pattern[i]<33) {
                    return len;
                }
                break;
        }
        len++;
    }
    return len;
}


void set_regex(Regex* regex, char* pattern) {
    union RegexLetter* reg = init_regex_letter();
    int j=0;
    for (int i=0; i<strlen(pattern); i++) {
        switch (pattern[i]) {
            case DOT:
                reg.dot = true;
                break;
            case BACKSLASH:
                i++;
                reg.c = pattern[i];
                break;
            default:
                reg.c = pattern[i];
                break;
        }
        regex->reg[j] = reg;
        j++;
    }
}


Regex* get_regex(char* pattern) { 
    Regex* regex = init_regex(pattern);
    regex->len = get_regex_len(pattern);
    regex->reg_arr = (union RegexLetter*) malloc (regex->len * sizeof(union RegexLetter));
    assert(regex->reg_arr);
    return regex;
}


void free_regex(Regex* regex) { 
    free(regex);
    regex = NULL;
}

