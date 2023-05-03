#ifndef REGEX_UTILS_H
#define REGEX_UTILS_H

#include <stdbool.h>
#include "grep_flags.h"

union RegexLetter {
   char c;
   bool dot;
   char interval[2];
   char* or_str;
   char which_letter;
};

typedef struct RegexWord {
   int len;
   union RegexLetter* reg_arr;
} Regex;


Regex* get_regex(char* pattern);

void free_regex(Regex* regex);


bool is_matching(Flags* flags, char* regex, char* line); 
// TO BE REPLACED BY 
//bool is_matching(Regex reg, char* line);


#endif