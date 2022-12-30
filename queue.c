#include<stdio.h>
#include<stdlib.h>

typedef struct QUEUE{
    int size;
    int front;
    int rear;
    int* arr;
}queue;

queue* allocate(int size1){
    queue* q1 = (queue*)malloc(sizeof(queue));
    q1->size = size1;
    q1->front = 0;
    q1->rear = 0;
    q1->arr = (int*)malloc(sizeof(int)*q1->size);
    return q1;
}

void ENQUEUE(queue* q, int element){
    if(q->rear != q->size){
        q->arr[q->rear] = element;
        q->rear++;
        return;
    }
    else{
        printf("OVERFLOW \n");
        return;
    }
}

void DEQUEUE(queue* q){
    if(q->front != q->rear){
        q->arr[q->front] = 0;
        q->front++;

        if(q->front == q->rear){
            q->front = 0;
            q->rear = 0;
        }
    }
    else{
        printf("UNDERFLOW \n");
    }
}

void print(queue* q){
    for(int i=q->front; i<q->rear;i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
    return;
}

int main(){
    queue* q1 = allocate(5);

    ENQUEUE(q1, 5);
    ENQUEUE(q1, 6);
    ENQUEUE(q1, 7);
    ENQUEUE(q1, 7);
    ENQUEUE(q1, 8);
    DEQUEUE(q1);
    print(q1);
    return 0;
}