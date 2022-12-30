#include<iostream>
#include<queue>
using namespace std;

typedef struct graph{
    int nodes;
    int** edges;
}graph;

graph* allocate(int nodes){
    graph* g = (graph*)malloc(sizeof(graph));
    g->nodes = nodes;
    g->edges = (int**)malloc(sizeof(int*)*nodes);
    for(int i=0;i<nodes;i++){
        g->edges[i] = (int*)malloc(sizeof(int)*nodes);
    }

    return g;
}

void insert_graph(graph* g, int u, int v){
    // for directed graph
    g->edges[u][v] = 1;
}

void print_graph(graph* g, int size){
    if(g == NULL){
        cout<<"Graph is empty"<<endl;
        return;
    }

    // int size = sizeof(g[0])/sizeof(g[0][0]);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(g->edges[i][j] == 1){
                cout<<i<<" -> "<<j<<endl;
            }
        }
    }
}

int is_visited(int visited[], int size){
    for(int i=0;i<size/2;i++){
        if((visited[i] == -1) || (visited[size - i - 1] == -1)){
            return -1;  // false
        }
    }
    return 1;   // true
}

void bfs(graph* g, int size, int visited[]){
    if(g == NULL){
        return;
    }
    
    // making queue structure here only
    int q[size*size];
    int top = 0;
    int front = 0;
    // finding first element
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(g->edges[i][j] == 1){
                q[top++] = i;
                break;   
            }
        }
        if(top != front){
            break;
        }
    }
    
    while((top != front) && is_visited(visited, size) == -1){
        int element = q[front];
        front++;
        for(int i=0;i<size;i++){
            if(g->edges[element][i] == 1){
                q[top++] = i;
            }
        }
        
        if(visited[element] == -1){
            cout<<element<<endl;
            visited[element] = 1;
        }
        // make_visited(visited, element);
    }
}

void dfs(graph* g, int element, int visited[], int size){
    if(is_visited(visited, size) == 1){
        return;
    }

    if(visited[element] == 1){
        return;
    }
    // make element visited
    else{
        cout<<element<<" ";
        visited[element] = 1;
        for(int i=0;i<size;i++){
            if(g->edges[element][i] == 1){
                if(visited[i] != 1){
                    dfs(g, i, visited, size);
                }
            }
        }
    }
}

int main(){
    
    graph* g = allocate(6);
    insert_graph(g, 0, 4);
    insert_graph(g, 1, 4);
    insert_graph(g, 1, 5);
    insert_graph(g, 2, 3);
    insert_graph(g, 2, 4);
    insert_graph(g, 3, 2);
    insert_graph(g, 3, 5);
    insert_graph(g, 4, 1);
    insert_graph(g, 4, 2);
    insert_graph(g, 5, 1);
    insert_graph(g, 5, 3);

    int visited[6];
    for(int i=0;i<6;i++){
        visited[i] = -1;
    }
    
    // bfs(g, 6, visited);
    dfs(g, 0, visited, 6);
    cout<<endl;
    print_graph(g, 6);
    return 0;
}