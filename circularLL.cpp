#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};

void insertNode(node* head, int element, int position){
    node* node1 = new node(element);

    while(head->data != position){
        head = head->next;
    }

    node1->next = head->next;
    head->next = node1;
}

int lengthCLL(node* head){
    node* value = head;
    int length = 1;
    head = head->next;
    while(head != value){
        head = head->next;
        length++;
    }

    return length;
}

int main(){
    node* node1 = new node(5);
    node1->next = node1;
    node* head = node1;
    return 0;
}