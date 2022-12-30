#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}node;

node* allocate(int value){
    node* node1 = (node*)malloc(sizeof(node));
    node1->val = value;
    node1->left = NULL;
    node1->right = NULL;

    return node1;
}

// to calculate the height of tree
int height_tree(node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height_tree(root->left), height_tree(root->right));
}

// Rotations
node* LL_Rotation(node* root){
    node* middle = root->left;
    node* last = middle->left;

    // performing roatation
    root->left = middle->right;
    middle->right = root;

    return middle;
}

node* RR_Rotation(node* root){
    node* middle = root->right;
    node* last = middle->right;
    // performing rotation
    root->right = middle->left;
    middle->left = root;

    return middle;
}

node* RL_Rotation(node* root){
    node* middle = root->left;
    node* last = middle->left;

    // performing only half roatation
    root->right = last;
    middle->left = last->right;
    last->right = middle;

    return RR_Rotation(root);
}

node* LR_Rotation(node* root){
    node* middle = root->left;
    node* last = middle->left;

    // performing only half roatation
    root->left = last;
    middle->right = last->left;
    last->left = middle;

    return LL_Rotation(root);
}

// Just to calculate balance factor
int balance_factor(node* root){
    return height_tree(root->left) - height_tree(root->right);
}

// Main roattion function
node* Rotations(node* root){

    if(balance_factor(root) == 2 && balance_factor(root->left) == 1){
        root = LL_Rotation(root);
    }
    else if(balance_factor(root) == 2 && balance_factor(root->left) == -1){
        root = LR_Rotation(root);
    }
    else if(balance_factor(root) == -2 && balance_factor(root->right) == 1){
        root = RL_Rotation(root);
    }
    else if(balance_factor(root) == -2 && balance_factor(root->right) == -1){
        root = RR_Rotation(root);
    }

    return root;
}

// Insert into Binary tree
node* insert_into_AVL(node* root, int element){
    if(root == NULL){
        node* node1 = allocate(element);
        return node1;
    }

    if(root->val < element){
        root->right = insert_into_AVL(root->right, element);
    }
    else{
        root->left = insert_into_AVL(root->left, element);
    }

    if(balance_factor(root) < -1 || balance_factor(root) > 1 ){
        root = Rotations(root);
    }

    return root;
}

int min_BST(node* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root->val;
}

// This is here to delete the node from BST --- used in deletion of avl
node* delete_BST(node* root, int element){
    if(root == NULL){
        return root;
    }
    if(root->val == element){
        // 0
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        // 1
        else if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }

        // 2
        else{
            int value = min_BST(root->right);
            // node* temp = root->right;
            root->val = value;
            root->right = delete_BST(root->right, value);
            return root;

         }
    }
    else if(element > root->val){
        root->right == delete_BST(root->right, element);
    }
    else{
        root->left = delete_BST(root->left, element);
    }

    return root;
}

//Delete AVL --- top node

node* conversion_tree_AVL(node* root){
    if(root == NULL){
        return NULL;
    }
    if(balance_factor(root) < -1 || balance_factor(root) > 1){
        root = Rotations(root);
    }

    root->left = conversion_tree_AVL(root->left);
    root->right = conversion_tree_AVL(root->right);

    return root;
}

node* delete_AVL(node* root, int element){
    if(root == NULL){
        return root;
    }
    // same deletion of BST
    root = delete_BST(root, element);

    // now to set the tree as avl
    root = conversion_tree_AVL(root);

    return root;

}

int main(){
    node* root = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        root = insert_into_AVL(root, element);
        // cout<<element;
    }

    delete_AVL(root, 2);
    cout<<root->val;
    cout<<(root->left)->val;
    cout<<(root->right)->val;
    
    return 0;
}

