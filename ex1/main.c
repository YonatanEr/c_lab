#include <stdio.h>
#include "linkedlist.c"

int main () {
    printf("TESTING\n");
    Node* head = NULL;
    add_end(&head, 1);
    print_list(&head);
    add_start(&head, 2);
    print_list(&head);
    add_after(&head, 3, 2);
    print_list(&head);
    print_index(&head, 3);
    delete_index(&head, 2);
    print_list(&head);   
    terminate(&head);
    return 0;
}

