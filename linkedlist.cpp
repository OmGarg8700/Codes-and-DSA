#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* add;

    // constructor
    node(int d){
        data = d;
        add = NULL;
    }

    ~node(){
        this->add = NULL;

        cout<<this->data;
        this->data = 0;
    }
};

void insertAtTail(node* head, int element){
    node* node2 = new node(element);

    node* temp = head;
    while(temp->add != NULL){
        temp = temp->add;
    }
    temp->add = node2;
}

void insertAtHead(node* &head, int element){
    node* node2 = new node(element);

    node2->add = head;
    head = node2; 
}

void insert(node* head, int position, int element){
    if(position ==  1){
        insertAtHead(head, element);
        return;
    }

    node* node2 = new node(element);

    node* temp = head;
    int pos = 1;
    while(pos != position - 1){
        temp = temp->add;
        pos++;
    }

    node2->add = temp->add;
    temp->add = node2;

}

void printLL(node* head){
    while(head->add != NULL){
        cout<<head->data<<" ";
        head = head->add;
    }
}

void deleteLL(node* head, int position){
    if(position == 1){
        node* temp = head;
        head = head->add;
        delete temp;
        return;
    }

    // without using current 
    // node* temp = head;
    // int pos = 1;
    // while(pos != position-1){
    //     temp = temp->add;
        
    //     pos++;
    // }

    // temp->add = temp->add->add;
    // temp = temp->add;
    // delete temp;

    // using current 
    node* temp = head;
    node* current = head->add;
    int pos = 1;
    while(pos != position-1){
        temp = temp->add;
        current = current->add;
        pos++;
    }
    temp->add = current->add;
    delete current;
    
}


node* reverseLL(node* &head){
    node* new_head = reverseLL(head->add);
}

int main(){
    node* node1 = new node(5);
    node* head = node1;
    return 0;
}