#include<stdio.h>

struct Stack{
    int size;
    int top;
    int* arr;
};

int is_Empty(struct Stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_Full(struct Stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct Stack *ptr, int element){
    if(is_Full(ptr)){
        printf("Overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

void pop(struct Stack *ptr){
    if(is_Empty(ptr)){
        printf("Overflow");
        return -1;
    }
    else{
        return ptr->arr[ptr->top--];
    }
};

void peak_element(struct Stack *ptr){
    for(int i=0;i<=ptr->top;i++){
        printf("%d ", ptr->arr[i]);
    }
    return;
}

int main(){
    // struct Stack s;
    // s.top = -1;
    // s.size = 5;
    // s.arr = (int*)malloc(sizeof(int)*s.size);
    struct Stack *s;
    s->top = -1;
    s->size = 5;
    s->arr = (int*)malloc(sizeof(int)*s->size);

    printf("%d", is_Empty(s));
    printf("%d", is_Full(s));

    push(s, 5);
    pop(s);

    printf("%d", is_Empty(s));
    printf("%d", is_Full(s));
    return 0;
}
