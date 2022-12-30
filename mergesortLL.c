#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;

}node;

// constructor
node* allocate(int data){
    node* s1= (struct node*)malloc(sizeof(node));
    s1 -> data = data;
    s1 -> next = NULL;
    return s1;
}

// merge ll in c

// mergesort function
node* mergeLL(node* head1, node* head2){
    node* dummy = allocate(0); // this is a dummy node

    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            dummy->next = head1;
            head1 = head1->next;
            dummy = dummy->next;
        }
        else{
            dummy->next = head2;
            head2 = head2->next;
            dummy = dummy->next;
        }
    }

    while(head1 != NULL){
        dummy->next = head1;
        head1 = head1->next;
        dummy = dummy->next;
    }
    while(head2 != NULL){
        dummy->next = head2;
        head2 = head2->next;
        dummy = dummy->next;
    }

    return dummy->next; 
}
node* find_mid(node* head){
    node* slow = head;
    node* fast = head->next;

    while(fast != NULL || fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}
node* mergesort(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* mid = find_mid(head);

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    node* left = mergesort(left);
    node* right = mergesort(right);

    
    return merge_LL(left, right);
}