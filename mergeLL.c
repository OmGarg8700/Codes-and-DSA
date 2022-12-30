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

Node* mergeLL(Node* head1, Node* head2){
    Node* dummy = allocate(0);
    Node* temp = dummy;

    while(head1 != NULL && head2 != NULL){
        if(head1->data <= head2->data){
            dummy->next = head1;
            dummy = dummy->next;
            head1 = head1->next;
        }
        else{
            dummy->next = head2;
            dummy = dummy->next;
            head2 = head2->next;
        }
    }

    while(head1 != NULL){
        dummy->next = head1;
        dummy = dummy->next;
        head1 = head1->next;
    }
    while(head2 != NULL){
        dummy->next = head2;
        dummy = dummy->next;
        head2 = head2->next;
    }

    return temp->next;
}
// void insertAtHead(Node** tail,Node** head,int d){
//     if (*head ==NULL){
//         Node* temp= allocate(d);
//         *tail= temp;
//         *head= temp;
//     }
//     else{
//     Node* temp= allocate(d);
//     temp-> next= *head;
//     *head= temp;
                
//     }

        
// }

void print(Node* head){
    Node* temp= head;
    while(temp != NULL){
        printf("%d ", temp-> data);
        temp= temp-> next;
    }
    printf("\n");

}

void insertAtTail(Node** tail,Node** head, int d){
    if (*tail ==NULL){
        Node* temp= allocate(d);
        *tail= temp;
        *head= temp;
    }
    else{
        Node* temp= allocate(d);
        (*tail) -> next= temp;
        (*tail)= temp;
   
    }
    
}

// void insertAtPosition(Node** tail,Node** head, int position , int d){
//     if(position== 1){
//         insertAtHead(*tail,*head, d);
//         return;
//     }

//     Node* temp= head;
//     int count =1;
//     while(count < position- 1){
//         temp = temp-> next;
//         count++;
//     }
//     // insert at last position
//     if(temp-> next ==NULL){
//         insertAtTail(*tail,*head ,d);
//         return;
//     }
//     Node* nodeToInsert= allocate(d);
//     nodeToInsert -> next= temp ->next;
//     temp -> next= nodeToInsert;

// }
// void deleteNode(int position, Node** head){
//     // delete first node 
//     if (position ==1){
//         Node* temp= *head;
//         (*head)= (*head) -> next;
//         // memory free 
//         temp-> next =NULL;
//         free(temp);
//     }
//     else{
//         // deleting middle or last node 
//         Node* curr= *head;
//         Node* prev= NULL;
//         int count =1;
//         while (count< position){
//             prev= curr;
//             curr= curr -> next;
//             count++;        
//         }
//         prev-> next = curr -> next;
//         curr -> next= NULL;
//         free(curr);


//     }

// }

int main(){
    int size1, size2;
    scanf("%d %d", &size1, &size2);
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    for(int i=0;i<size1;i++){
        int element;
        scanf("%d", &element);
        insertAtTail(&tail1, &head1, element);
    }
    for(int i=0;i<size2;i++){
        int element;
        scanf("%d", &element);
        insertAtTail(&tail2, &head2, element);
    }
    print(head1);
    print(head2);
    print(mergeLL(head1, head2));
    return 0;
}
