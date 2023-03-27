#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#ifndef LINKEDLIST_C
#define LINKEDLIST_C

typedef struct ListNode {
    int data;
    struct ListNode* next;
} Node;

void print_list(Node* head);

Node* create_node(int data) {
    Node* new_node = (Node*) malloc (sizeof(Node));
    new_node->data = data;
    assert(new_node);
    new_node->next = NULL;
    return new_node;
}


void free_node(Node* node) {
    free(node->next);
    node->next = NULL;
    free(node);
    node = NULL;
}


int list_len(Node* head) {
    Node* cur = head;
    int len = 0;
    while (cur != NULL){
        cur = cur->next;
        len++;
    }
    return len;
}


Node* get_ith_node(Node* head, int i) {
    int len = list_len(head), j;
    if (i >= len){
        return NULL;
    }
    Node* cur = head;
    for (j=0; j<i; j++) {
        cur = cur->next;
    }
    return cur;
}


Node* get_end(Node* head) {
    assert(head);
    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    return cur;
}


void push_to_start(Node** head_ptr, int data) {
    Node* new_node = create_node(data);
    new_node->next = (Node*) malloc (sizeof(Node));
    assert(new_node->next);
    new_node->next = *head_ptr;
    *head_ptr = new_node;
}


void push_after(Node** node_ptr, int data) {
    Node* node = *node_ptr;
    Node* new_node = create_node(data);
    new_node->next = (Node*) malloc (sizeof(Node));
    assert(new_node->next);
    new_node->next = node->next;
    node->next = new_node;
}


void push_to_end(Node** head_ptr, int data) {
    Node* head = *head_ptr;
    if (head == NULL) {
        push_to_start(head_ptr, data);
        return;
    }
    Node* cur_end = get_end(head);
    push_after(&cur_end, data);
}


void delete_head(Node** head_ptr) {
    Node* cur_head = *head_ptr;
    *head_ptr = cur_head->next;
    free_node(cur_head);
}


void delete_end(Node** head) {
    Node* cur_end = get_end(*head);
    free_node(cur_end);
    Node* new_end = get_end(*head);
    free(new_end->next);
    new_end->next = NULL;
}


void bypass_node(Node* head, int i) {
    Node* prev_node = get_ith_node(head, i-1);
    Node* cur_node = prev_node->next;
    Node* next_node = cur_node->next;
    assert(prev_node && cur_node && next_node);
    prev_node->next = next_node;
    free_node(cur_node);
}


void delete_index(Node** head_ptr, int i) {
    int len = list_len(*head_ptr);
    assert(i<len && "index is out of range\n");
    if (i == 0){
        delete_head(head_ptr);
        return;
    }
    if (i == len-1){
        delete_end(head_ptr);
        return;
    }
    bypass_node(*head_ptr, i);
}


void free_list(Node* head) {
    Node* cur;
    while (head != NULL) {
        cur = head;
        head = head->next;
        free_node(cur);
    }
}


//      FUNCTIONS REQUIRED      //


void add_end(Node* head, int data) {
    push_to_end(&head, data);
}


void add_start(Node* head, int data) {
    push_to_start(&head, data);
}


void add_after(Node* head, int new_data, int cur_data) {
    int len = list_len(head);
    Node* cur = head;
    while (cur != NULL){
        if (cur->data == cur_data){
            push_after(cur, new_data);
            return;
        }
        cur = cur->next;
    }
    assert(NULL && "index is out of range\n");
}


void print_index(Node* head, int data) {
    Node* cur = head;
    int i=0;
    while (cur != NULL){
        if (cur->data == data){
            printf("%d", i);
            return;
        }
        i++;
        cur = cur->next;
    }
    printf("%d", -1);
}

void del_index(Node* head, int i) {
    delete_index(&head, i); 
}

void print_list(Node* head) {
    Node* cur = head;
    printf("[");
    while (cur != NULL){
        printf("%d", cur->data);
        if (cur->next != NULL){
            printf(", ");
        }
        cur = cur->next;
    }
    printf("]\n");
}


void terminate(Node* head) {
    free_list(head);
}


int main () {
    Node* head = NULL;
    for (int i=1; i<5; i++){
        push_to_start(&head, -i);
        push_to_end(&head, i);
    }
    print_list(head);
    return 0;
}

#endif