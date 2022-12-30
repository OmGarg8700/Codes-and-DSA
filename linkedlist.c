#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList{
    int n;
    struct LinkedList *ptr;
 
}LL;

LL* allocate_Node(int element){
    LL* node = (LL*)malloc(sizeof(LL));

    node->n = element;
    node->ptr = NULL;   
    return node;
}

void insertAtHead(LL **head, int element){
    LL* node2 = allocate_Node(element);

    node2->ptr = *head;
    *head = node2;
}

void insertAtTail(LL *head, int element){
    LL* node2 = allocate_Node(element);
    while(head->ptr != NULL){
        head = head->ptr;
    }
    head->ptr = node2;
}

void insertAtPosition(LL* head, int element, int position){
    LL* node2 = allocate_Node(element);
    LL* temp = head;
    int i=1;
    while(i != position-1){
        temp = temp->ptr;
        i++;
    }
    LL* add = temp->ptr;
    temp->ptr = node2;
    node2->ptr = add;
}

void printLL(LL* head){
    LL* tmp = head;

    while(tmp != NULL){
        printf("%d ", tmp->n);
        tmp = tmp->ptr;
    }
    printf("\n%d", head->n);
}

void deleteLL(LL* head, int position){
    LL* tmp = head;
    if(position == 1){
        head = tmp->ptr;
        free(tmp);
        return;
    }
    int count = 1;
    while(count != position-1){
        tmp = tmp->ptr;
        count++;
    }

    LL* del_node = tmp->ptr;
    tmp->ptr = del_node->ptr;
    free(del_node);
    // free(tmp);
}

LL* search(LL* head, int element){
    LL* temp = head;
    
    while(temp->n != element && temp->ptr != NULL){
        temp = temp->ptr;
    }
    return temp;
}

int main(){
    LL* node1 = allocate_Node(5);
    LL* head = node1;

    insertAtTail(head, 6);
    insertAtHead(&head, 7);
    insertAtPosition(head, 9, 2);
    printLL(head);

    deleteLL(head, 2);
    printLL(head);
    return 0;
}