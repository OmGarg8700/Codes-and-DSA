#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int* arr;
};

void push(struct Stack *ptr, int element){
    if(ptr->top == ptr->size-1){
        printf("Overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(struct Stack *ptr){
    if(ptr->top == -1){
        printf("Overflow \n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top--];
    }
}

void printStack(struct Stack* ptr){
    if(ptr->top == -1){
        printf("-1");
    }
    else{
        for(int i=0;i<=ptr->top;i++){
            printf("%d ", ptr->arr[i]);
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    struct Stack* arr[n];
    for(int i=0;i<n;i++){
        struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
        s->top = -1;
        s->size = m;
        s->arr = (int*)malloc(sizeof(int)*(s->size));
        s->arr[0] = -1;
        arr[i] = s;
    }
    for(int i=0;i<m;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u = u-1;
        push(arr[u], v);
    }
    
    for(int i=0;i<n;i++){
        printStack(arr[i]);
        printf("\n");
    }
    return 0;
}