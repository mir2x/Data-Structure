#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} node_t;



void push(node_t **head_ref, int value) 
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node -> data = value;
    new_node -> next = NULL;
    
    if(*head_ref == NULL) 
    {
        *head_ref = new_node; 
        return;
    }
   
    node_t *temp = *head_ref;
    while(temp -> next != NULL)
    {
        temp = temp -> next; 
    }
    temp -> next = new_node; 
}

void print(node_t *head)
{
    if(head == NULL) printf("List is empty.");
    node_t *temp = head;
    while(temp != NULL)
    {
       printf("%d ", temp -> data);
       temp = temp -> next; 
    }
}

int main() 
{
    node_t *head = NULL;
    push(&head, 10); 
    push(&head, 20); 
    push(&head, 30); 
    push(&head, 40); 
    print(head);
    printf("\n");
    return 0;
}