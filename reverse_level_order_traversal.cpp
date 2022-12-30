#include<iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}node;

node* allocate(int element){
    node* node1 = (node*)malloc(sizeof(node));
    node1->data = element;
    node1->left = NULL;
    node1->right = NULL;

    return node1;
};

void nodes_at_level(node* root, int level){
    if(level == 1){
        cout<<root->data<<" ";
    }

    nodes_at_level(root->left, level--);
    nodes_at_level(root->right, level--);

}

int main(){
    
    return 0;
}