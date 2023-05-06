#ifndef GREP_FLAGS_H
#define GREP_FLAGS_H

#define long_flags_amount 1
#define bool_flags_amount 7
#define string_flags_amount 2

#include<stdbool.h>


enum long_flags_names {A_flag};
enum boolean_flags_names {E_flag, b_flag, c_flag, i_flag, n_flag, v_flag, x_flag};
enum string_flags_names {pattern_flag, file_flag};


typedef struct GrepFlags {
    long long_flags[long_flags_amount];
    bool boolean_flags[bool_flags_amount];
    char* string_flags[string_flags_amount];
} Flags;


void free_flags(Flags* flags);

long get_long_flags(Flags* flags, int ind);

bool get_bool_flags(Flags* flags, int ind);

char* get_str_flags(Flags* flags, int ind);

Flags* get_flags(int argc, char *argv[]);

void print_flags(Flags* flags); 


#endif