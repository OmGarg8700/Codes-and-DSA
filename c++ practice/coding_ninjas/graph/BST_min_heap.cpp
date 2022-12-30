#include<iostream>
using namespace std;

class BinaryTreeNode {

	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
};


// This is only a basic structure
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	if(root == NULL){
        return NULL;
    }

    // finding childeren and making it a heapify code
    BinaryTreeNode* left = root->left;
    BinaryTreeNode* right = root->right;

    int smallest = root->data;
    int left_v = left->data;
    int right_v = right->data;

    if(smallest > left_v && left != NULL){
        smallest = left_v;
    }
    if(smallest > right_v && right != NULL){
        smallest = right_v;
    }

    if(smallest != root->data){
        if(smallest == left_v){
            left->data = root->data;
            root->data = smallest;
            root = convertBST(root->left);
        }
        else{
            right->data = root->data;
            root->data = smallest;
            root = convertBST(root->right);
        }
    }

    return root;
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    return 0;
}

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
