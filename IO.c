#include <stdio.h>
#include <string.h>

#define MEMSIZE 100

char* initial_user_input(){
     char* input1 = (char*) malloc ((MEMSIZE)*sizeof(char));
     assert(input1);
     scanf("%s", &input1);
     return input1;
}


char* to_lower_case(char* str){
    int i;
    int len = strlen(str);
    char* res = (char*) malloc ((len+1)*sizeof(char));
    assert(res);
    for (i=0; i<len; i++){
        char x = str[i];
        if ('a' <= x && x <= 'z'){
            res[i] = x;
        }
        elif ('A' <= x && x <= 'Z'){
            x+=32; turns uppercase to lowercase
            res[i] = x;
        }
        else{
             res[i] = x;
        }       
    } 
    res[len] = '\0';
    return res;
}

char* get_nums_from_input(char* str){
    strtok()

}

