#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}node;

typedef struct Queue{
    int size;
    int front;
    int rear;
    node** arr;
}queue;

queue* allocate_q(int length){
    queue* q = (queue*)malloc(sizeof(queue));
    q->size = length;
    q->front = 0;
    q->rear = 0;
    q->arr = (node**)malloc(sizeof(node)*length);

    return q;
}

void push_element(queue* q, node* element){
    q->arr[q->rear] = element;
    q->rear++;
}

void pop_element(queue* q){
    q->arr[q->front] = NULL;
    q->front++;
}

int isEmpty(queue* q){
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

node* allocate(int element){
    node* node1 = (node*)malloc(sizeof(node));
    node1->data = element;
    node1->left = NULL;
    node1->right = NULL;

    return node1;
};

node* insert_level_node(int arr[], int size, node* root){
    root = allocate(arr[0]);
    queue* q = allocate_q(size);
    push_element(q, root);

    int j=1;
    while(isEmpty(q) == 0 && j<size){
        node* temp = q->arr[q->front];

        temp->left = allocate(arr[j++]);
        push_element(q, temp->left);
        if(j<size){

        temp->right = allocate(arr[j++]);
        push_element(q, temp->right);
        pop_element(q);
        }
        else{
            break;
        }

    }

    return root;
}

node* searchTree(node* root, int element){
    if(root == NULL){
        return NULL;
    }
    if(root->data == element){
        return root;
    }

    node* ans_left = searchTree(root->left, element);
    node* ans_right = searchTree(root->right, element);
    if(ans_left == NULL){
        return ans_right;
    }
    else{
        return ans_left;
    }
    
}

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m];

    for(int i=0;i<m;i++){
        scanf("%d", &arr[i]);
    }    
    // for(int i=0;i<n;i++){
    //     int first, second;
    //     scanf("%d %d", &first, &second);
    //     int ans = 0;

    //     node* first_node = searchBST(root, first);
    //     if(first_node == NULL){
    //         printf("YES");
    //     }
    //     if(first_node != NULL){
    //         node* second_node = searchBST(first_node, second);
    //         if(second_node != NULL){
    //             ans = 1;
    //         }
    //     }

    //     if(ans == 0){
    //         printf("NO");
    //     }
    //     else{
    //         printf("YES");
    //     }
    //     printf("\n");
    // }

    return 0;
}