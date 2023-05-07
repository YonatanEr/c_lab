#include "regex_utils.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE 32                 //   ' '
#define LEFT_ROUND_BRACKET 40    //   '('
#define RIGHT_ROUND_BRACKET 41   //   ')'
#define DOT 46                   //   '.'
#define LEFT_SQUARE_BRACKET 91   //   '['
#define BACKSLASH 92             //   '\'
#define RIGHT_SQUARE_BRACKET 93  //   ']'
#define OR 124                   //   '|'

int get_regex_len(char *pattern);
char *get_substring(const char *str, int start, int stop);
int get_next_char_occurence_index(char *pattern, char c, int start);

Regex *init_regex(char *pattern)
{
  int len = get_regex_len(pattern);
  Regex *regex = (Regex *)malloc(1 * sizeof(Regex));
  assert(regex);
  regex->len = len;
  if (len == 0) {
    return regex;
  }
  regex->reg_arr = (union RegexLetter *)calloc(len, sizeof(union RegexLetter));
  assert(regex->reg_arr);
  regex->type_arr = (int *)calloc(len, sizeof(int));
  assert(regex->type_arr);
  return regex;
}

Regex *get_regex(char *pattern)
{
  Regex *regex = init_regex(pattern);
  if (regex->len == 0) {
    return regex;
  }
  int pattern_len = strlen(pattern), regex_ind = 0, j = 0, k = 0;
  for (int i = 0; i < pattern_len; i++) {
    switch (pattern[i]) {
      case BACKSLASH:
        i++;
        regex->reg_arr[regex_ind].c = pattern[i];
        regex->type_arr[regex_ind] = c_type;
        break;
      case LEFT_SQUARE_BRACKET:
        i++;
        regex->reg_arr[regex_ind].interval[0] = pattern[i];
        i = i + 2;
        regex->reg_arr[regex_ind].interval[1] = pattern[i];
        i++;
        regex->type_arr[regex_ind] = interval_type;
        break;
      case LEFT_ROUND_BRACKET:
        j = get_next_char_occurence_index(pattern, OR, i);
        k = get_next_char_occurence_index(pattern, RIGHT_ROUND_BRACKET, j);
        regex->reg_arr[regex_ind].or_str[0] = get_substring(pattern, i + 1, j);
        regex->reg_arr[regex_ind].or_str[1] = get_substring(pattern, j + 1, k);
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

void free_regex(Regex *regex)
{
  for (int i = 0; i < regex->len; i++) {
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

int get_next_char_occurence_index(char *pattern, char c, int start)
{
  int len = strlen(pattern);
  for (int i = start + 1; i < len; i++) {
    if (pattern[i] == c) {
      return i;
    }
  }
  return -1;
}

int get_regex_len(char *pattern)
{
  int len = 0, pattern_len = strlen(pattern);
  for (int i = 0; i < pattern_len; i++) {
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
        if (pattern[i] < SPACE) {
          return len;
        }
        break;
    }
    len++;
  }
  return len;
}

char *get_substring(const char *str, int start, int stop)
{
  char *res = (char *)calloc(stop - start + 1, sizeof(char));
  assert(res);
  for (int i = start; i < stop; i++) {
    res[i - start] = str[i];
  }
  return res;
}
