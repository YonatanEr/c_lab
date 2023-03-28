#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

#define MAX_LINE_SIZE 100
#define CONTINUE 0
#define EXIT 1


void to_lower_case(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
        i++;
    }
}


void parse_line(char string[], char** instruction_ptr, int* num1_ptr, int* num2_ptr) {
    char* token = strtok(string, " ");
    *instruction_ptr = token;
    to_lower_case(*instruction_ptr);
    token = strtok(NULL, " ");
    if (token != NULL) {
        *num1_ptr = atoi(token);
        token = strtok(NULL, " ");
        if (token != NULL) {
            *num2_ptr = atoi(token);
        }
    }
}


int execute_action(Node* head, char* instruction, int num1, int num2) {
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
        return EXIT;
    }
    return CONTINUE;
}


int main() {
    Node* head = NULL;
    char new_line[MAX_LINE_SIZE];
    char* instruction;
    int num1, num2, status=CONTINUE;
    while (status == CONTINUE) {
        fgets(new_line, MAX_LINE_SIZE, stdin);
        parse_line(new_line, &instruction, &num1, &num2);
        status = execute_action(head, instruction, num1, num2);
    }
    exit(0);
    return 0;
}

