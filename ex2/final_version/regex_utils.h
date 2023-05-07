#ifndef REGEX_UTILS_H
#define REGEX_UTILS_H

#include <stdbool.h>

enum RegexLetterType { c_type, dot_type, interval_type, or_str_type };

union RegexLetter {
  char c;
  bool dot;
  char interval[2];
  char *or_str[2];
};

typedef struct RegexWord {
  int len;
  union RegexLetter *reg_arr;
  int *type_arr;
} Regex;

Regex *get_regex(char *pattern);

void free_regex(Regex *regex);

#endif
