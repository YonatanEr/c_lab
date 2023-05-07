#include "grep_flags.h"
#include "reader_utils.h"
#include "regex_utils.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LF 10     //   'LF'
#define DASH 45   //   "-"
#define COLON 58  //   ':'

bool is_matching(Flags *flags, Regex *regex, char *line);

void print_format(Flags *flags, Reader *reader, char *line, char delimiter)
{
  long cur_lines_counter = reader->lines_counter;
  long cur_bytes_counter = reader->bytes_counter - strlen(line);
  if (get_bool_flags(flags, n_flag)) {
    printf("%ld%c", cur_lines_counter, delimiter);
  }
  if (get_bool_flags(flags, b_flag)) {
    printf("%ld%c", cur_bytes_counter, delimiter);
  }
  printf("%s", line);
  if (line[strlen(line + 1)] != '\n') {
    printf("\n");
  }
}

void matched_line(Flags *flags, Reader *reader, char *line, long *match_count, long *last_match, bool *dash)
{
  *match_count = (*match_count) + 1;
  *last_match = reader->lines_counter;
  if (get_bool_flags(flags, c_flag)) {
    return;
  }
  if (*dash) {
    printf("--\n");
    *dash = false;
  }
  print_format(flags, reader, line, COLON);
}

void unmatched_line(Flags *flags, Reader *reader, char *line, long last_matched_line, bool *dash)
{
  long A = get_long_flags(flags, A_flag);
  if (get_bool_flags(flags, c_flag)) {
    return;
  }
  if (A == -1) {
    return;
  }
  if (last_matched_line == -1) {
    return;
  }
  if (reader->lines_counter - last_matched_line == A + 1) {
    *dash = true;
  }
  if (reader->lines_counter - last_matched_line > A) {
    return;
  }
  print_format(flags, reader, line, DASH);
}

void execute_grep(Flags *flags, Regex *regex, Reader *reader)
{
  char *line = NULL;
  long match_count = 0;
  long last_match = -1;
  bool dash = false;
  while (read_next_line(reader, &line) != -1) {
    if (is_matching(flags, regex, line)) {
      matched_line(flags, reader, line, &match_count, &last_match, &dash);
    } else {
      unmatched_line(flags, reader, line, last_match, &dash);
    }
    free(line);
    line = NULL;
  }
  free(line);
  line = NULL;
  if (get_bool_flags(flags, c_flag)) {
    if (regex->len != 0 || !get_bool_flags(flags, v_flag)) {
      printf("%ld\n", match_count);
    }
  }
}

char to_lower_case(char c)
{
  if ('A' <= c && c <= 'Z') {
    return c - 'A' + 'a';
  }
  return c;
}

bool case_sensative_compare(Flags *flags, char x, char y)
{
  if (get_bool_flags(flags, i_flag)) {
    return (to_lower_case(x) == to_lower_case(y));
  }
  return (x == y);
}

bool is_in_interval(Flags *flags, union RegexLetter reg, char x)
{
  char left = reg.interval[0], right = reg.interval[1];
  if (get_bool_flags(flags, i_flag)) {
    return ((to_lower_case(left) <= to_lower_case(x)) && (to_lower_case(x) <= to_lower_case(right)));
  }
  return (left <= x && x <= right);
}

bool is_matching_str(Flags *flags, char *str, char *line, int line_ind)
{
  int str_len = strlen(str);
  for (int i = 0; i < str_len; i++) {
    if (!case_sensative_compare(flags, str[i], line[line_ind + i])) {
      return false;
    }
  }
  return true;
}

bool is_matching_reg_letter(Flags *flags, Regex *regex, char *line, int regex_ind, int line_ind)
{
  switch (regex->type_arr[regex_ind]) {
    case c_type:
      return case_sensative_compare(flags, regex->reg_arr[regex_ind].c, line[line_ind]);
    case dot_type:
      return true;
    case interval_type:
      return is_in_interval(flags, regex->reg_arr[regex_ind], line[line_ind]);
    default:
      assert(NULL);
  }
}

bool is_matching_rec(Flags *flags, Regex *regex, char *line, int regex_ind, int line_ind)
{
  int line_ind0 = 0, line_ind1 = 0, len = strlen(line);
  bool op0 = false, op1 = false;
  if (regex->len < regex_ind || len < line_ind) {
    return false;
  }
  if (regex->len == regex_ind) {
    if (get_bool_flags(flags, x_flag)) {
      return line[line_ind] == '\0';
    }
    return true;
  }
  if (regex->type_arr[regex_ind] == or_str_type) {
    if (is_matching_str(flags, regex->reg_arr[regex_ind].or_str[0], line, line_ind)) {
      line_ind0 = line_ind + strlen(regex->reg_arr[regex_ind].or_str[0]);
      op0 = is_matching_rec(flags, regex, line, regex_ind + 1, line_ind0);
    }
    if (is_matching_str(flags, regex->reg_arr[regex_ind].or_str[1], line, line_ind)) {
      line_ind1 = line_ind + strlen(regex->reg_arr[regex_ind].or_str[1]);
      op1 = is_matching_rec(flags, regex, line, regex_ind + 1, line_ind1);
    }
    return (op0 || op1);
  }
  if (!is_matching_reg_letter(flags, regex, line, regex_ind, line_ind)) {
    return false;
  }
  return is_matching_rec(flags, regex, line, regex_ind + 1, line_ind + 1);
}

bool is_matching_env(Flags *flags, Regex *regex, char *line)
{
  if (regex->len == 0) {
    return line[0] == '\0';
  }
  int i = 0, len = strlen(line);
  if (len > 0 && line[len - 1] == LF) {
    line[len - 1] = '\0';
  }
  if (get_bool_flags(flags, x_flag)) {
    return is_matching_rec(flags, regex, line, 0, 0);
  } else {
    for (i = 0; i < len; i++) {
      if (is_matching_rec(flags, regex, line, 0, i)) {
        return true;
      }
    }
    return false;
  }
}

bool is_matching(Flags *flags, Regex *regex, char *line)
{
  bool res = false;
  int len = strlen(line), i = 0;
  char *line_copy = (char *)calloc(len + 1, sizeof(char));
  assert(line_copy);
  for (i = 0; i < len; i++) {
    line_copy[i] = line[i];
  }
  if (get_bool_flags(flags, v_flag)) {
    res = !is_matching_env(flags, regex, line_copy);
  } else {
    res = is_matching_env(flags, regex, line_copy);
  }
  free(line_copy);
  line_copy = NULL;
  return res;
}

int main(int argc, char *argv[])
{
  Flags *flags = get_flags(argc, argv);
  Regex *regex = get_regex(get_str_flags(flags, pattern_flag));
  Reader *reader = get_reader(get_str_flags(flags, file_flag));
  execute_grep(flags, regex, reader);
  free_flags(flags);
  free_regex(regex);
  free_reader(reader);
  return 0;
}
