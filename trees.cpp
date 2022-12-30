#include<iostream>
#include<queue>
using namespace std;

struct root{
    int data;
    root* left;
    root* right;
};

root* allocate(int value){
    root* r = new root();
    r->data = value;
    r->left = NULL;
    r->right = NULL;

    return r;
}

root* buildTree(root* r){
    int value;
    cin>>value;
    if(value == -1){
        return NULL;
    }

    root* temp = allocate(value);
    r = temp;

    r->left = buildTree(r->left);
    r->right = buildTree(r->right);

    return r;
}

// this is pre order
void printTree(root* r){
    if(r == NULL){
        cout<<"-1 ";
        return;
    }
    cout<<r->data<<" ";

    printTree(r->left);
    printTree(r->right);
}

void inorder(root* r){
    if(r == NULL){
        return;
    }

    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void postorder(root* r){
    if(r == NULL){
        return;
    }

    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}

void level_traversal(root* r){
    // 1st type
    // if(level == 1){
    //     if(r != NULL){
    //         cout<<r->data<<" ";
    //     }
    //     return;
    // }
    

    // level_traversal(r->left, level-1);
    // level_traversal(r->right, level-1);

    // 2nd type 
    queue<root*> q;
    if(r == NULL){
        return;
    }
    q.push(r);
    q.push(NULL);

    while(!q.empty()){
        root* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

void levelorder_buildTree(root* r){
    int val;
    cout<<"Enter the value of root: ";
    cin>>val;
    root* r1 = allocate(val);
    r = r1;

    queue<root*> q;



    q.push(r);

    while(!q.empty()){
        root* temp =q.front();

        // for left
        cout<<"Enter the value of left for "<<temp->data<<": ";
        cin>>val;
        if(val != -1){
            temp->left = allocate(val);
            q.push(temp->left);
        }

        // for right
        cout<<"Enter the value of right for "<<temp->right<<": ";
        cin>>val;
        if(val != -1){
            temp->right = allocate(val);
            q.push(temp->right);
        }

        q.pop();
    }
}

int heightTree(root* r){
    if(r == NULL){
        return 0;
    }

    return 1 + max(heightTree(r->left), heightTree(r->right));
}

int leafnodes(root* r){
    if(r == NULL){
        return 0;
    }

    return 1 + leafnodes(r->left) + leafnodes(r->right);
}

// search tree a particular node


// delete a node from tree

int main(){
    root* r = NULL;
    r = buildTree(r);

    // printTree(r);
    // print level by level
    // for(int i=1;i<heightTree(r)+1;i++){
    //     level_traversal(r, i);
    //     cout<<endl;
    // }

    // level_traversal(r);

    // printTree(r);
    // cout<<endl;

    // inorder(r);
    // cout<<endl;

    // postorder(r);
    // return 0;

    // cout<<leafnodes(r);
}

// 5 4 -1 3 -1 -1 2 -1 -1