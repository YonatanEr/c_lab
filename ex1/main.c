#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

#define MaxSize 100


void to_lower_case(char* str){
    // change in place, changes the same char* in runs on
    int i=0;
    char x;
    while (str[i] != '\0') {
        if ('A' <= x && x <= 'Z'){
            x = x - 'A' + 'a';
            str[i] = x;
        }
    } 
}


void parse_line(char* line, char* instruction, int* num1, int* num2) { 
            /// VALIDATE!
            /// VALIDATE!
            /// VALIDATE!
            /// VALIDATE!
            /// VALIDATE!
            /// VALIDATE!
    // line = add_after 5 10   ->   instruction = add_afrer, num1 = 5, num2 = 10
    // line = add_start 123    ->   instruction = add_start, num1 = 123
    // line = print_lst    ->   instruction = print_lst
    char *token;
    token = strtok(line, " ");
    strcpy(instruction, token);
    while( token != NULL ) {
        printf( " %s\n", token );
        token = strtok(NULL, " ");
   }
   to_lower_case(instruction);
   *num1 = 1;
   *num2 = 2;
}


int main()
{
    Node* head = NULL;
    char new_line[MaxSize];
    char instruction[MaxSize];
    int num1, num2;
    while (true) {              // consider changing to while (strcmp(new_line,EOF) != 0)
        scanf("%s", new_line);
        parse_line(new_line, instruction, &num1, &num2);    
        if (strcmp(instruction, "add_end")==0){
            add_end(&head, num1);
        }
        else if (strcmp(instruction, "add_start")==0){
            add_start(&head, num1);
        }
        else if (strcmp(instruction, "add_after")==0){
            add_after(&head, num1, num2);
        }
        else if (strcmp(instruction, "index")==0){
            print_index(&head, num1);
        }
        else if (strcmp(instruction, "del")==0){
            delete_index(&head, num1);
        }
        else if (strcmp(instruction, "print")==0){
            print_list(&head);
        }
        else if (strcmp(instruction, "exit")==0){
            free_linked_list(&head);
            break;
        }
    }
    exit(0);
    return 0;
}

