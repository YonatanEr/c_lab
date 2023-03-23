#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MEMSIZE 100

/*
get user input ant return string
turn string to lower case
than master IO:
    gets lower case string
    uses pars input command to get the command
    than depending on command:
        uses pars input num for one number
            or
        uses pars input nums for two number        
    
    than calls the correct command from link list...
    and returns exit value if needed

    if i have time:
        make a struct called command:
        char* text
        int i
        int j
*/

char* get_user_input(){
     char* input1 = (char*) malloc ((MEMSIZE)*sizeof(char));
     assert(input1);
     scanf("%s", &input1);
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
    strtok(str, ' ');
}

int pars_input_numbers(char* str, bool first){

}

int turn_input_to_command(char* str, int i_in, int j_in){
    
    return 0;
}

int master_io(){
    char* str, cmd;
    int i_in, j_in;
    bool exit = false;
    str = get_user_input();
    str = turn_to_lower_case(str);
    cmd = pars_input_command(str);
    i_in = pars_input_numbers(str, true);
    if(cmd == "A"){
        /*call the relevant function from linkedlist.h*/;
    }
    else if(cmd == "B"){
        j_in = pars_input_numbers(str, false);
        /*call the relevant function from linkedlist.h*/;     
    }
    else if(cmd == "C"){
        exit = true;
        /*call the relevant function from linkedlist.h*/;
    }
    /*...*/

    return exit;
}