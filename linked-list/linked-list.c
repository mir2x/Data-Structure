#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node_t;

// size of the list
int size(node_t *head) {
    if(head == NULL) return 0;
    int count = 0;
    node_t *temp = head;
    while(temp != NULL) {
       count ++;
       temp = temp -> next; 
    }
    return count;
}

// add new element at the beginning
void unshift(struct Node **head_ref, int value) {
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node -> data = value;
	new_node -> next = *head_ref;
	*head_ref = new_node;
}

// add new element at the end
void push(node_t **head_ref, int value) {

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node -> data = value;
    new_node -> next = NULL;
    
    if(*head_ref == NULL) {
        *head_ref = new_node; 
        return;
    }
   
    node_t *temp = *head_ref;
    while(temp -> next != NULL) {
        temp = temp -> next; 
    }
    temp -> next = new_node; 
}

// insert new element at the given position
void insert(node_t **head_ref, int position, int value) {

    if(position > size(*head_ref)) {
        printf("Invalid position.\n");
        return;
    }
        
    if(position == 1) {
        unshift(head_ref, value);
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node -> data = value;
	node_t *temp = *head_ref;
    int i;
    for(i = 0; i < position - 2; i++) {
        temp = temp -> next;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;
}


// print all elements of list
void print(node_t *head) {
    if(head == NULL) printf("List is empty.");
    node_t *temp = head;
    while(temp != NULL) {
       printf("%d ", temp -> data);
       temp = temp -> next; 
    }
}

int main() {
    node_t *head = NULL;
    push(&head, 10); 
    push(&head, 20); 
    push(&head, 30); 
    push(&head, 40);
    unshift(&head, 0); 
    insert(&head, 2, 5);
    print(head);
    printf("\nSize of the list : %d\n", size(head));
    return 0;
}