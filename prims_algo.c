#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    int distance;
}Node;

void swap(Node* a, Node* b){
    Node temp = *a;
    *a = *b;
    *b = temp;
}

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

void print_heap(heap* h){
    for(int  i = 1;i<=h->top;i++){
        printf("%d %d \n", h->arr[i].data, h->arr[i].distance);
    }
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
        swap(&h->arr[smallest], &h->arr[index]);
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
            swap(&h->arr[parent], &h->arr[index]);
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

    swap(&h->arr[1], &h->arr[h->top]);
    printf("%d", h->top);
    h->top--;
    
    heapify(h, 1);
}


typedef struct node{
    int data;
    int weight;
    struct node* next;
}node;

node* allocate(int data, int weight){
    node* node1 = (node*)malloc(sizeof(node));
    node1->data = data;
    node1->weight = weight;
    node1->next = NULL;  
}

node* insert_node(node* head, int data, int weight){
    if(head == NULL){
        return allocate(data, weight);
    }

    node* temp = head;
    if(temp->data == data){
        return head;
    }
    while(temp->next != NULL){
        if(temp->data == data){
            return head;
        }
        temp = temp->next;
    }
    temp->next = allocate(data, weight);
    return head;
}

typedef struct List{
    node* head;
}List;

List allocate_List(){
    List l;
    l.head = NULL;
    return l;
}

typedef struct graph{
    int nodes;
    List* edges;
    // int top;
}graph;

graph* allocate_graph(int nodes){
    graph* g = (graph*)malloc(sizeof(graph));
    g->nodes = nodes;
    g->edges = (List*)malloc(sizeof(List)*nodes);
    for(int i=0;i<nodes;i++){
        g->edges[i] = allocate_List();
    }
    // g->top = nodes;
    return g;
}


void insert_graph(graph* g, int size, int u, int v, int weight){
    g->edges[u].head = insert_node(g->edges[u].head, v, weight);
    return;
}

void print_graph(graph* g){
    for(int i=0;i<g->nodes;i++){
        // cout<<i+1<<" -> ";
        node* temp = g->edges[i].head;
        while(temp != NULL){
            // cout<<temp->data+1<<" "<<temp->weight<<endl;
            temp = temp->next;
        }
        // cout<<endl;
    }
}

void print_LL(node* head){
    if(head == NULL){
        // cout<<"Linked list is empty";
        return;
    }

    while (head != NULL){
        // cout<<head->data<<" ";
        head = head->next;
    }
    return;
}

void prims_algo(graph* g){
    if(g == NULL){
        return;
    }

    int key[g->nodes];
    int MST[g->nodes];
    int parent[g->nodes];

    for(int i=0;i<g->nodes;i++){
        key[i] = 1000000;
        MST[i] = -1;
        parent[i] = -1;
    }

    // setting source
    key[0] = 0;
    parent[0] = -1;

    while(1){
        int min_element = 2147483647;
        
        for(int i=0;i<g->nodes;i++){
            if(MST[i] == -1 && key[i] < min_element){
                min_element = i;
            }
        }

        // to break the loop
        if(min_element == 2147483647){
            break;
        }

        MST[min_element] = 1;
        node* temp = g->edges[min_element].head;
        while(temp != NULL){
            if(temp->weight < key[temp->data]){
                key[temp->data] = temp->weight;
                parent[temp->data] = min_element;
            }
            temp = temp->next;
        }
    }

    for(int i=0;i<g->nodes;i++){
        printf("%d ", key[i]);
    }
}

// prim's Algorithm using min heap
void prim_algo_minheap(graph* g){
    if(g == NULL){
        return;
    }

    int visited[g->nodes];
    for(int i=0;i<g->nodes;i++){
        visited[i] = -1;
    }

    int cost = 0;
    heap* h = allocate_heap(g->nodes*g->nodes);
    insert_heap(h, 0, 0);
    
    while(h->top != 0){
        Node element = h->arr[1];
        delete_heap(h);
        // print_heap(h);
        if(visited[element.data] != 1){

            cost += element.distance;
            visited[element.data] = 1;

            // processing
            node* temp = g->edges[element.data].head;
            while(temp != NULL){
                // adding elements to heap which are not visited
                if(visited[temp->data] != 1){
                    // printf("%d ", temp->data);
                    insert_heap(h, temp->data, temp->weight);
                    // printf("printsd");
                    // print_heap(h);
                }
                temp = temp->next;
            }
            print_heap(h);
        }
    }

    printf(" so this is cost %d", cost);
}

int main(){
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);
    graph* g = allocate_graph(nodes);
 
    for(int i=0;i<edges;i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        insert_graph(g, nodes, u, v, w);
        insert_graph(g, nodes, v, u, w);
    }

    // prims_algo(g);
    prim_algo_minheap(g);
    return 0;
}

// 9 14
// 0 1 4
// 0 8 8
// 1 8 11
// 1 3 8
// 3 4 7
// 4 5 9
// 5 6 10
// 6 7 2
// 7 8 1
// 4 6 14
// 3 6 4
// 3 2 2
// 2 7 6
// 2 8 7