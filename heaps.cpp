#include<iostream>
using namespace std;

// 1 based indexing
typedef struct Node{
    int data;
    int distance;
}Node;

Node allocate_Node(int data, int distance){
    Node n;
    n.data = data;
    n.distance = distance;
    return n;
}

typedef struct heap{
    Node* arr;
    int size;
    int top;
}heap;

heap* allocate_heap(int size){
    heap* h = (heap*)malloc(sizeof(heap));
    h->arr = (Node*)malloc(sizeof(Node)*size);
    h->size = size;
    h->top = 0;
    return h;
}

// creating min heap
void heapify(heap* h, int index){
    if(h->top == 0){
        return;
    }
    int smallest = index;
    int left = 2*smallest;
    int right = 2*smallest + 1;

    if(left <= h->top && h->arr[left].distance < h->arr[smallest].distance){
        smallest = left;
    }
    if(right <= h->top && h->arr[right].distance < h->arr[smallest].distance){
        smallest = right;
    }

    if(smallest != index){
        swap(h->arr[smallest], h->arr[index]);
        heapify(h, smallest);
    }
    else{
        return;
    }
}
void insert_heap(heap* h, int data, int distance){
    if(h == NULL){
        return;
    }

    h->top++;
    h->arr[h->top] = allocate_Node(data, distance);
    int index = h->top;
    int parent = index/2;

    while(parent > 0){
        if(h->arr[parent].distance > h->arr[index].distance){
            swap(h->arr[parent], h->arr[index]);
            index = parent;
            parent = index/2;
        }
        else{
            break;
        }
    }
    return;
}

void delete_heap(heap* h){
    if(h == NULL){
        return;
    }

    swap(h->arr[1], h->arr[h->top]);
    h->top--;

    heapify(h, 1);
}

// void print_heap(heap* h){
//     for(int  i = 1;i<=h->top;i++){
//         cout<<h->arr[i].data + 1<<" "<<h->arr[i].distance<<endl;
//     }
// }


int check_heap(heap* h, int data){
    for(int i=1;i<=h->top;i++){
        if(h->arr[i].data == data){
            return 1;
        }
    }

    return 0;
}

void update_heap(heap* h, int data, int new_val){
    for(int i=1;i<=h->top;i++){
        if(h->arr[i].data == data){
            h->arr[i].distance = new_val;
            heapify(h, 1);

            return;
        }
    }

    return;
}

// int main(){
//     heap* h = allocate_heap(5);
//     for(int i=0;i<5;i++){
//         int data;
//         cin>>data;
//         insert_heap(h,data);
//     }
    
//     delete_heap(h);

//     print_heap(h);
//     return 0;
// }