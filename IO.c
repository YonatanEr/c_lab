#ifndef IO_C
#define IO_C

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "linkedlist.h"
#include "linkedlist.c"

#define MEMSIZE 100

char* get_user_input(){
     char* input1 = (char*) malloc ((MEMSIZE)*sizeof(char));
     assert(input1);
     scanf("%s", &input1);
     int len1 = strlen(input1);
     input1 = (char*)realloc(input1, len1);
     return input1;
}


char* turn_to_lower_case(char* str){
    int len = strlen(str);
    char* res = (char*) malloc ((len+1)*sizeof(char));
    assert(res);
    for (int i=0; i<len; i++){
        char x = str[i];
        /*we chose turning all chars to lower case*/
        if ('A' <= x && x <= 'Z'){
            x+=32 /*changes ASCII upper case char to lower case*/;
            res[i] = x;
        }
        else{
            res[i] = x /*the rest will stay the same*/;
        }       
    } 
    res[len] = '\0';
    return res;
}


char* pars_input_command(char* str){
    char* end_of_cmd = strchr(str, ' ');
    int cmd_size = end_of_cmd - str;
    char* cmd = (char*) malloc((cmd_size+1)*sizeof(char));
    assert(cmd);

    for(int i=0; i < cmd_size; i++){
        *(cmd+i) = *(str+i);
    }
    *(cmd+cmd_size) = '\0';
    return cmd;
}


int pars_input_numbers(char* str, int int_number){
    // int_number is 1 if we need i, and is 2 if we want j //
    char* number_str;
    char* space = strchr(str, ' ');

    for(int i=0; i < int_number; i++){
        number_str = space+1;
        space = strchr(number_str, ' ');
    }

    int number_size = space - number_str;
    char* res = (char*)malloc((number_size+1)*sizeof(char));
    assert(res);

    for(int i=0; i < number_size; i++){
        *(res+i) = *(str+i);
    }
    *(res+number_size) = '\0';
    return res;
}

bool str_cmp(char* str1, char* str2){
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    if(str1_len != str2_len){
        return false;
    }
    for(int i=0; i<str1_len; i++){
        char char1, char2;
        char1 = *(str1+i);
        char2 = *(str2+i);
        if(char1 != char2){
            return false;
        }
    }
    return true;
}

//      MAIN IO FUNCTION      //

int master_io(){
    char* str, cmd;
    int i_in, j_in;
    bool exit = false;
    str = get_user_input();
    str = turn_to_lower_case(str);
    cmd = pars_input_command(str);
    i_in = pars_input_numbers(str, 1);
    if(str_cmp(cmd, "")){
        /*call the relevant function from linkedlist.h*/;
    }
    else if(str_cmp(cmd, "")){
        j_in = pars_input_numbers(str, 2);

    }
    else if(cmd == "C"){
        exit = true;
        /*call the relevant function from linkedlist.h*/;
    }
    /*...*/

    return exit;
}

#endif