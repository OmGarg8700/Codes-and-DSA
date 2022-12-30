#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* allocate(int value){
    node* root = new node();
    root->data = value;
    root->left = NULL;
    root->right = NULL;

    return root;
}

// Iterative approach
// void buildBST(node* &root, int element){
//     if(root == NULL){
//         root = allocate(element);
//         return;
//     }
    
//     node* prev = NULL;
//     node* temp = root;
//     while(temp != NULL){
//         prev = temp;
//         if(element < temp->data){
//             temp = temp->left;
//         }
//         else{
//             temp = temp->right;
//         }
//     }

//     node* insert_node = allocate(element);
//     if(prev->left == temp){
//         prev->left = insert_node;
//     }
//     else{
//         prev->right = insert_node;
//     }

//     free(temp);
//     return ;
// }

// Recurive approach
node* insertNode(node* &root, int element){
    if(root == NULL){
        root = allocate(element);
        return root;
    }

    if(root->data <= element){
        root->right = insertNode(root->right, element);
    }
    else{
        root->left = insertNode(root->left, element);
    }

    return root;
}

node* searchBST(node* root, int element){
    if(root == NULL){
        return root;
    }

    node* temp = root;
    while(temp != NULL){
        if (root->data < element){
            temp = temp->right;
        }
        else if (root->data == element){
            return temp;
        }
        else{
            temp = temp->left;
        }
    }

    return NULL;
}

//Recursive approach
node* searchBST(node* root, int element){
    if(root == NULL || root->data == element){
        return root;
    }

    if(element < root->data){
        searchBST(root->left, element);
    }
    else{
        searchBST(root->right, element);
    }

    return root;
}


// Inorder of BST is sorted
int nodes_at_node(node* temp){
    int ans = 0;
    if(temp->left){
        ans++;
    }
    if(temp->right){
        ans++;
    }
    return ans;
}

void delete_node(node* root, node* temp){
    int nodes = nodes_at_node(temp);
    if(nodes == 0){
        free(temp);
    }
    else if(nodes == 1){
        while(root->left != temp || root->right != temp){
            if(root->data <= temp->data){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }

        if(root->left == temp){
            if(temp->left){
                root->left = temp->left;
            }
            else{
                root->left = temp->right;
            }
        }
        else{
            if(temp->left){
                root->left = temp->left;
            }
            else{
                root->left = temp->right;
            }
        }
        free(temp);
    }

    else if(nodes == 2){
        node* final = temp->right;
        int value;
        while(final->left != NULL){
            final = final->left;
        }
        value = final->data;
        delete_node(root, final);
        temp->data = value;
    }
}

// different approach to delete a node
node* delete_node(node* root, int x){
    if(root == NULL){
        return NULL;
    }

    if(x == root->data){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        // 1 child
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

        // 2 child
        else{
            // minimum value in right subtree;
            int value;
            node* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            value = temp->data;

            // processing
            root->data = value;
            root->right = delete_node(root->right, value);
            return root;
        }
    }
    else if(x > root->data){
        root->right = delete_node(root->right, x);
    }
    else{
        root->left = delete_node(root->left, x);
    }

    return root;
}

void printBST(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    printBST(root->left);
    printBST(root->right);
}

node* InOrderSuccessor(node* root, node* x){
          node* successor=NULL;
          while(root!=NULL){
             if(root->data <= x->data){
                  root=root->right;
              } //end of if loop
           else{
           //root->data>x->data
           successor=root;
           root=root->left;
            } //end of else loop
        }  // end of while loop
    return successor;
}

node* InOrderPredecessor(node* root, node* x){
    node* predecessor = NULL;
    while(root != NULL){
        if(root->data > x->data){
            root = root->left;
        }
        else{
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    node* root = NULL;
    
    for(int i=0;i<n;i++){
        // buildBST(root, arr[i]);
        insertNode(root, arr[i]);
    }

    printBST(root);
    return 0;
}