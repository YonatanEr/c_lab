#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"


int main(){
    printf("Hello!\n");
    Node* head = NULL;
    print_list(&head);
    add_start(&head, 0);
    print_list(&head);
    add_start(&head, 10);
    print_list(&head);
    free_linked_list(&head);
    print_list(&head);
    return 0;
}