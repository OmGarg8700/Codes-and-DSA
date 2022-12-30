#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;

}Node;

// constructor
Node* allocate(int data){
    struct Node* s1= (struct Node*)malloc(sizeof(struct Node));
    s1 -> data = data;
    s1 -> next = NULL;
    return s1;
}

void reverse(Node** head, Node* ptr, int n){
    int count = 1;

    Node* prev = ptr;
    Node* curr = *head;
    while(curr != ptr){
        curr = curr->next;
        (*head)->next = prev;
        prev = head;
        *head = curr;
    }

    *head = prev;
}

void k_group(Node** head, int k){
    int count = 1;
    Node* temp = *head;
    Node* first = *head;
    // Node* last = *head;
    while(temp != NULL){
        if(count%k == 0 &&  count/k == 1){
            reverse(head, temp->next, k);
        }
        else if(count%k == 0 && (count/k)%2 == 1){
            reverse(first, temp->next, k);
        }
        else if(count%k == 0 && (count/k)%2 == 0){
            first = temp->next;
        }
        temp = temp->next;
        count++;
    }
}