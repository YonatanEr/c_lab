#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string.h"
#include "grep_flags.h"

void set_long_flags(Flags* flags, int ind, int val);
void set_bool_flags(Flags* flags, int ind, bool val);
void set_str_flags(Flags* flags, int ind, char* val);


Flags* init_flags() {
    int i;
    Flags* flags = (Flags*) malloc (1*(sizeof(Flags)));
    assert(flags);
    for (i=0; i<long_flags_amount; i++) {
        set_long_flags(flags, i, 0);
    }
    for (i=0; i<bool_flags_amount; i++) {
        set_bool_flags(flags, i, false);
    }
    for (i=0; i<string_flags_amount; i++) {
        set_str_flags(flags, i, NULL);
    }
    return flags;
} 

void free_flags(Flags* flags) {
    for (int i=0; i<string_flags_amount; i++) {
        free(flags->string_flags[i]);
        set_str_flags(flags, i, NULL);
    }
    free(flags);
    flags = NULL;
}


void set_long_flags(Flags* flags, int ind, int val) {
    flags->long_flags[ind] = val;
}

void set_bool_flags(Flags* flags, int ind, bool val) {
    flags->boolean_flags[ind] = val;
}

void set_str_flags(Flags* flags, int ind, char* val) {
    if (val == NULL) {
        flags->string_flags[ind] = NULL;
        return;
    }
    flags->string_flags[ind] = (char*) calloc (1+strlen(val), sizeof(char));
    assert(flags->string_flags[ind]);
    strcpy(flags->string_flags[ind], val);
}


long get_long_flags(Flags* flags, int ind) {
    return flags->long_flags[ind];
}

bool get_bool_flags(Flags* flags, int ind) {
    return flags->boolean_flags[ind];
}

char* get_str_flags(Flags* flags, int ind) {
    return flags->string_flags[ind];
}


bool is_flag(char* arg){
    if (arg == NULL) {
        return false;
    }
    if (strlen(arg) != 2) {
        return false;
    }
    if (arg[0] != '-') {
        return false;
    }
    return true;
}

int get_long_flag_index(char* arg){
    if (!is_flag(arg)){
        return -1;
    }
    switch(arg[1]) {
        case 'A':
            return A_flag;
        default:
            return -1;
    }
}

int get_bool_flag_index(char* arg){
    if (!is_flag(arg)){
        return -1;
    }
    switch(arg[1]) {
        case 'E':
            return E_flag;
        case 'b':
            return b_flag;
        case 'c':
            return c_flag;
        case 'i':
            return i_flag;
        case 'n':
            return n_flag;
        case 'v':
            return v_flag;
        case 'x':
            return x_flag;
        default:
            return -1;
    }
}

void handle_long_flag(Flags* flags, char *argv[], int i, int long_flag) {
    set_long_flags(flags, long_flag, atoi(argv[i+1]));
    argv[i] = NULL;
    argv[i+1] = NULL;
}

void handle_bool_flag(Flags* flags, char *argv[], int i, int bool_flag) {
    if (bool_flag == E_flag) {
        set_str_flags(flags, pattern_flag, argv[i+1]);
        argv[i+1] = NULL;
    }
    set_bool_flags(flags, bool_flag, true);
    argv[i] = NULL;
}

int get_first_not_null_index(int argc, char *argv[]) {
    for (int i=1; i<argc; i++) {
        if (argv[i] != NULL) {
            return i;
        }
    }
    return -1;
}

void update_flags(Flags* flags, int argc, char *argv[]) {
    int int_flag, bool_flag, i, j, k;
    for (i=0; i<argc; i++) {
        int_flag = get_long_flag_index(argv[i]);
        if (int_flag != -1) {
            handle_long_flag(flags, argv, i, int_flag);
            continue;
        }
        bool_flag = get_bool_flag_index(argv[i]);
        if (bool_flag != -1) {
            handle_bool_flag(flags, argv, i, bool_flag);
            continue;
        }
    }
    if (!get_bool_flags(flags, E_flag)) {
        j = get_first_not_null_index(argc, argv);
        if (j!=-1) {
            set_str_flags(flags, pattern_flag, argv[j]);
            argv[j] = NULL;
        }
    }
    k = get_first_not_null_index(argc, argv);
    if (k!=-1) {
        set_str_flags(flags, file_flag, argv[k]);
        argv[k] = NULL;
    }
}

Flags* get_flags(int argc, char *argv[]) {
    Flags* flags = init_flags();
    update_flags(flags, argc, argv);
    return flags;
}

// DEBUG PURPOSESS TO BE DELETED

void print_flags(Flags* flags) {
    printf("\n");
    printf("A_flag = %ld\n",get_long_flags(flags, A_flag));
    printf("\n");
    printf("E_flag = %d\n",get_bool_flags(flags, E_flag));
    printf("b_flag = %d\n",get_bool_flags(flags, b_flag));
    printf("c_flag = %d\n",get_bool_flags(flags, c_flag));
    printf("i_flag = %d\n",get_bool_flags(flags, i_flag));
    printf("n_flag = %d\n",get_bool_flags(flags, n_flag));
    printf("v_flag = %d\n",get_bool_flags(flags, v_flag));
    printf("x_flag = %d\n",get_bool_flags(flags, x_flag));
    printf("\n");
    printf("pattern_flag = %s\n",get_str_flags(flags, pattern_flag));
    printf("file_flag = %s\n",get_str_flags(flags, file_flag));
    printf("\n");
}

