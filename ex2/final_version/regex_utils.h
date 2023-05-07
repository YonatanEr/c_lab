#ifndef REGEX_UTILS_H
#define REGEX_UTILS_H

#include <stdbool.h>
#include "grep_flags.h"

union RegexLetter {
   char c;
   bool dot;
   char interval[2];
   char* or_str[2];
};

typedef struct RegexWord {
   int len;
   union RegexLetter* reg_arr;
   int* type_arr;
} Regex;


Regex* get_regex(char* pattern);

void free_regex(Regex* regex);

bool is_matching(Flags* flags, Regex* regex, char* line); 


#endif