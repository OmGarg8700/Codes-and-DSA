#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;

}node;

// constructor
node* allocate(int data){
    node* s1= (node*)malloc(sizeof(node));
    s1 -> data = data;
    s1 -> next = NULL;
    return s1;
}

typedef struct Stack{
    int size;
    int top;
    node* head;
    node* tail;
}stack;

stack* allocate_stack(int size){
    stack* s1 = (stack*)malloc(sizeof(stack));
    s1->size = size;
    s1->top = -1;
    s1->head = NULL;
    s1->tail = NULL;
}

void push(stack* s1, int element){
    if(s1->top == s1->size){
        return;
    }
    node* node1 = allocate(element);
    if(s1->top == -1){
        s1->top++;
        s1->head = node1;
        s1->tail = node1;
        return;
    }

    s1->top++;
    s1->tail->next = node1;
    s1->tail = node1;
    return;
}

void pop(stack* s1){
    if(s1->top == -1){
        return;
    }

    int count = 1;
    node* temp = s1->head;
    while(count != s1->top-1){
        temp = temp->next;
        count++;
    }

    node* deletenode = temp->next;
    temp->next = deletenode->next;

    free(deletenode);
}

int main(){

}