#include "regex_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


#define LF 10                          //   'LF'
#define SPACE 32                       //   ' '
#define LEFT_ROUND_BRACKET 40          //   '('
#define RIGHT_ROUND_BRACKET 41         //   ')'
#define DOT 46                         //   '.'
#define LEFT_SQUARE_BRACKET 91         //   '['
#define BACKSLASH 92                   //   '\'
#define RIGHT_SQUARE_BRACKET 93        //   ']'
#define LEFT_CURLY_BRACKET 123         //   '{'
#define OR 124                         //   '|'
#define RIGHT_CURLY_BRACKET 125        //   '}'


enum RegexLetterType {c_type, dot_type, interval_type, or_str_type};


int get_regex_len(char* pattern);
char* get_substring(char* str, int start, int stop);
int get_next_char_occurence_index(char* pattern, char c, int start);
char to_lower_case(char c);



Regex* init_regex(char* pattern) {
    int len=get_regex_len(pattern);
    Regex* regex = (Regex*) malloc (1*sizeof(Regex));
    assert(regex);
    regex->len = len;
    regex->reg_arr = (union RegexLetter*) calloc (len, sizeof(union RegexLetter));
    assert(regex->reg_arr);
    regex->type_arr = (int*) calloc (len, sizeof(int));
    assert(regex->type_arr);
    return regex;
}


Regex* get_regex(char* pattern) { 
    Regex* regex = init_regex(pattern);
    int pattern_len=strlen(pattern), regex_ind=0, j=0, k=0;
    for (int i=0; i<pattern_len; i++) {
        switch (pattern[i]) {
        case BACKSLASH:
            i++;
            regex->reg_arr[regex_ind].c = pattern[i];
            regex->type_arr[regex_ind] = c_type;
            break;
        case LEFT_SQUARE_BRACKET:
            i++;
            regex->reg_arr[regex_ind].interval[0] = pattern[i];
            i = i+2;
            regex->reg_arr[regex_ind].interval[1] = pattern[i];
            i++;
            regex->type_arr[regex_ind] = interval_type;
            break;
        case LEFT_ROUND_BRACKET:
            j = get_next_char_occurence_index(pattern, OR, i);
            k = get_next_char_occurence_index(pattern, RIGHT_ROUND_BRACKET, j);
            regex->reg_arr[regex_ind].or_str[0] = get_substring(pattern, i+1, j);
            regex->reg_arr[regex_ind].or_str[1] = get_substring(pattern, j+1, k);
            regex->type_arr[regex_ind] = or_str_type;
            i = k;
            break;        
        case DOT:
            regex->reg_arr[regex_ind].dot = true;
            regex->type_arr[regex_ind] = dot_type;
            break;
        default:
            regex->reg_arr[regex_ind].c = pattern[i];
            regex->type_arr[regex_ind] = c_type;                                                                        
            break;
        }
        regex_ind++;
    }
    return regex;
}


void free_regex(Regex* regex) {
    for (int i=0; i<regex->len; i++) {
        if (regex->type_arr[i] == or_str_type) {
            free(regex->reg_arr[i].or_str[0]);
            free(regex->reg_arr[i].or_str[1]);
            regex->reg_arr[i].or_str[0] = NULL;
            regex->reg_arr[i].or_str[1] = NULL;
        }
    }
    free(regex->reg_arr);
    free(regex->type_arr);
    free(regex);
    regex = NULL;
}


int get_next_char_occurence_index(char* pattern, char c, int start) {
    int len = strlen(pattern);
    for (int i=start+1; i<len; i++) {
        if (pattern[i] == c) {
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
            case LEFT_SQUARE_BRACKET:
                i = get_next_char_occurence_index(pattern, RIGHT_SQUARE_BRACKET, i);
                break;
            case LEFT_ROUND_BRACKET:
                i = get_next_char_occurence_index(pattern, RIGHT_ROUND_BRACKET, i);
                break;
            default:
                if(pattern[i]<SPACE) {
                    return len;
                }
                break;
        }
        len++;
    }
    return len;
}


char* get_substring(char* str, int start, int stop) {
    char* res = (char*) calloc (stop-start+1, sizeof(char));
    assert(res);
    for (int i=start; i<stop; i++) {
        res[i-start] = str[i];
    }
    return res;
}



char to_lower_case(char c) {
    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}


bool case_sensative_compare(Flags* flags, char x, char y) {
    if (get_bool_flags(flags, i_flag)) {
        return (to_lower_case(x) == to_lower_case(y));
    }
    return (x==y);
}


bool is_in_interval(Flags* flags, union RegexLetter reg, char x) {
    char left = reg.interval[0], right = reg.interval[1];
    if (get_bool_flags(flags, i_flag)) {
        return ((to_lower_case(left)<=to_lower_case(x)) && (to_lower_case(x)<=to_lower_case(right)));
    }
    return (left<=x && x<=right);
}


bool is_matching_str(Flags* flags, char* str, char* line, int line_ind) {
    int str_len = strlen(str);
    for (int i=0; i<str_len; i++) {
        if (!case_sensative_compare(flags, str[i], line[line_ind+i])){
            return false;
        }
    }
    return true;
}


bool is_matching_reg_letter(Flags* flags, Regex* regex, char* line, int regex_ind, int line_ind) {
    switch (regex->type_arr[regex_ind])
    {
        case c_type:
            return case_sensative_compare(flags, regex->reg_arr[regex_ind].c, line[line_ind]);
        case dot_type:
            return true;
        case interval_type:
            return is_in_interval(flags, regex->reg_arr[regex_ind], line[line_ind]);
        default:
            assert(NULL);
    }
    assert(NULL);
}


bool is_matching_rec(Flags* flags, Regex* regex, char* line, int regex_ind, int line_ind) {
    int line_ind0 = 0, line_ind1 = 0, len = strlen(line);  
    bool op0 = false, op1 = false;
    if (regex->len <regex_ind || len <line_ind) {
        return false;
    }
    if (regex->len == regex_ind) {
        if (get_bool_flags(flags, x_flag)) {
            return line[line_ind]=='\0';
        }
        return true;
    }
    if (regex->type_arr[regex_ind] == or_str_type) {
        if (is_matching_str(flags, regex->reg_arr[regex_ind].or_str[0], line, line_ind)){
            line_ind0 = line_ind + strlen(regex->reg_arr[regex_ind].or_str[0]);
            op0 = is_matching_rec(flags, regex, line, regex_ind+1, line_ind0);
        }
        if (is_matching_str(flags, regex->reg_arr[regex_ind].or_str[1], line, line_ind)){
            line_ind1 = line_ind + strlen(regex->reg_arr[regex_ind].or_str[1]);
            op1 = is_matching_rec(flags, regex, line, regex_ind+1, line_ind1);
        }
        return (op0 || op1);
    }
    if (!is_matching_reg_letter(flags, regex, line, regex_ind, line_ind)) {
        return false;
    }
    return is_matching_rec(flags, regex, line, regex_ind+1, line_ind+1);
}


bool is_matching_env(Flags* flags, Regex* regex, char* line) {
    if (regex->len==0) {
        return line[0]=='\0';
    }
    int i=0, len=strlen(line);
    if (len>0 && line[len-1]==LF) {
        line[len-1] = '\0';
    }
    if (get_bool_flags(flags, x_flag)) {
        return is_matching_rec(flags, regex, line, 0, 0);
    }
    else {
        for (i=0; i<len; i++) {
            if (is_matching_rec(flags, regex, line, 0, i)) {
                return true;
            }
        }
        return false;
    }
}


bool is_matching(Flags* flags, Regex* regex, char* line) {
    bool res = false;
    char* line_copy = (char*) calloc (strlen(line)+1, sizeof(char));
    assert(line_copy);
    strcpy(line_copy, line);           
    if (get_bool_flags(flags, v_flag)) {
        res = !is_matching_env(flags, regex, line_copy);
    }
    else {
        res = is_matching_env(flags, regex, line_copy);
    }
    free(line_copy);
    line_copy = NULL;
    return res;
}