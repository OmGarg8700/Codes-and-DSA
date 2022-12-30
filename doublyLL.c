#include<stdio.h>
#include<stdlib.h>

typedef struct doublyLL{
    int n;
    struct doublyLL* next;
    struct doublyLL* prev;
}node;

node* allocate_node(int element){
    node* node1 = (node*)malloc(sizeof(node));

    node1->n = element;
    node1->next = NULL;
    node1->prev = NULL;

    return node1;
}

void insertAtHead(node** head, int element){
    node* node1 = (node*)malloc(sizeof(node));

    node1->next = *head;
    (*head)->prev = node1;
    *head = node1;
}

void insertAtTail(node* head, int element){
    node* node1 = (node*)malloc(sizeof(node));

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node1;
    node1->prev = temp;
}

void insertAtPosition(node** head, int element, int position){
    if(position == 1){
        insertAtHead(head, element);
        return;
    }
    int count = 1;
    node* temp = *head;
    while(count != position-1){
        temp = temp->next;
    }

    node* node1 = (node*)malloc(sizeof(node));
    node1->next = temp->next;
    temp->next->prev = node1;
    temp->next = node1;
    node1->prev = temp;

}

void printLL(node* head){
    node* tmp = head;

    while(tmp != NULL){
        printf("%d ", tmp->n);
        tmp = tmp->next;
    }
    printf("\n%d", head->n);
}

void deleteLL(node** head, int position){
    if(position == 1){
        node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    int count = 1;
    node* temp = *head;
    while(count != position-1){
        temp = temp->next;
        count++;
    }

    node* del_node = temp->next;
    temp->next = del_node->next;
    del_node->next->prev = temp;
    free(del_node);
}

node* search(node* head, int element){
    node* temp = head;
    
    while(temp->n != element && temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

int main(){
    printf("%d", 56);
    return 0;
}