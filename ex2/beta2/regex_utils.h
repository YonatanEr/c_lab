#ifndef REGEX_UTILS_H
#define REGEX_UTILS_H

#include<stdbool.h>

union RegexLetter {
   char c;
   bool dot;
};

typedef struct RegexWord {
   union RegexLetter regex;
   int len;
} Regex;


bool is_matching(char* reg, char* line); 
// TO BE REPLACED BY 
//bool is_matching(Regex reg, char* line);


#endif