#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdbool.h>

char* get_user_input();

char* turn_to_lower_case(char* str);

char* pars_input_command(char* str);

int pars_input_numbers(char* str, int int_number);

bool str_cmp(char* str1, char* str2);

int master_io();

#endif