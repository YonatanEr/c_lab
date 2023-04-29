#ifndef COMPARE_UTILS_H
#define COMPARE_UTILS_H

#include<stdbool.h>

union Regex {
   char c;
   bool dot;
   char str[20];
};


bool is_matching(char* line, union Regex reg);

#endif