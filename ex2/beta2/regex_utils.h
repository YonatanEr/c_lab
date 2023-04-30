#ifndef REGEX_UTILS_H
#define REGEX_UTILS_H

#include<stdbool.h>
#include "grep_flags.h"

union RegexLetter {
   char c;
   bool dot;
};

typedef struct RegexWord {
   union RegexLetter regex;
   int len;
} Regex;


bool is_matching(Flags* flags, char* reg, char* line); 
// TO BE REPLACED BY 
//bool is_matching(Regex reg, char* line);


#endif