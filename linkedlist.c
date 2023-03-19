#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


typedef struct ListNode {
    int data;
    Node* prev;
    Node* next;
float answer;
} Node;


Node* create_node(data) {
    Node* res = (Node*) malloc (sizeof(Node));
    assert(res);
    res->data = data;
    return res;
}


void free_node(Node* node) {
    free(node->prev);
    free(node->next); 
    free(node);
}


void bypass_node(Node* node) {
    Node* prev_node = node->prev;
    Node* next_node = node->next;
    prev_node->next = next_node;
    next_node->prev = prev_node;
    free_node(node);
}


Node* get_ith_node(Node* head, int i) {
    Node* cur = head;
    for (int j=0; j<i; j++){
        assert(cur);
        cur = cur->next;
    }
    return cur;
}


void insert_after_ith_node(Node* head, Node* new_node, int i) {
    if (i == 0) {
        head->prev = new_node;
        new_node
    }
    Node* cur = get_ith_node(head, i);
    Node* next_node = cur->next

}


void print_lst(Node* head){
    Node* cur = head;
    printf('[');
    while (cur != NULL){
        printf("%d", cur->data); 
        if (cur->next != NULL){
            printf(", ");
        }
        cur = cur->next;
    }
    printf(']\n');
}