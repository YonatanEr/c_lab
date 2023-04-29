#ifndef GREP_FLAGS_H
#define GREP_FLAGS_H

#define int_flags_amount 1
#define bool_flags_amount 6
#define string_flags_amount 2

#include<stdbool.h>

enum integer_flags_names {A_flag};
enum boolean_flags_names {E_flag, b_flag, c_flag, i_flag, n_flag, v_flag, x_flag};
enum string_flags_names {word_flag, file_flag};


typedef struct GrepFlags {
    int integer_flags[int_flags_amount];
    bool boolean_flags[bool_flags_amount];
    char* string_flags[string_flags_amount];
} Flags;

int get_int_flags(Flags* flags, int ind);

bool get_bool_flags(Flags* flags, int ind);

char* get_str_flags(Flags* flags, int ind);

Flags* init_flags();

void free_flags(Flags* flags);

void print_flags(Flags* flags); // DEBUG PURPOSESS TO BE DELETED


#endif