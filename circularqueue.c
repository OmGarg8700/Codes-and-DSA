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
    if(q->front == ((q->rear)%(q->size)) && q->rear > 0){     // is full
        printf("OVERFLOW \n");
        return;
    }
    else{
        if(q->rear>=q->size){
            q->arr[((q->rear)%(q->size))] = element;
            q->rear++;
        }
        else if(q->front == -1){
            q->front = 0;
            q->rear = 0;
            q->arr[0] = element;
            q->rear++;
        }
        else{
            q->arr[q->rear] = element;
            q->rear++;
        }
    }
    return;
}

void DEQUEUE(queue* q){
    if(q->front == -1)
}

int main(){
    queue* q1 = allocate(5);

    return 0;
}