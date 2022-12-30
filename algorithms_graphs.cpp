#include<iostream>
#include<stack>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

node* allocate(int data){
    node* node1 = (node*)malloc(sizeof(node));
    node1->data = data;
    node1->next = NULL;  
}

node* insert_node(node* head, int data){
    if(head == NULL){
        return allocate(data);
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
    temp->next = allocate(data);
    return head;
}

struct List{
    node* head;
};

List allocate_List(){
    List l;
    l.head = NULL;
    return l;
}

struct graph{
    int nodes;
    List* edges;
    // int top;
};

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


void insert_graph(graph* g, int size, int u, int v){
    g->edges[u].head = insert_node(g->edges[u].head, v);
    return;
}

void print_graph(graph* g){
    for(int i=0;i<g->nodes;i++){
        cout<<i<<" -> ";
        node* temp = g->edges[i].head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

// algorithms
void bfs(graph* g, int size, int visited[]){
    if(g == NULL){
        return;
    }

    int q[size*size];
    int top = 0;
    int front = 0;

    for(int i=0;i<size;i++){
        if(g->edges[i].head != NULL){
            q[top++] = i;
            break;
        }
    }

    while(top != front){
        int element = q[front];
        front++;

        if(visited[element] != 1){
            cout<<element<<" ";
            visited[element] = 1;
            node* temp = g->edges[element].head;
            while(temp != NULL){
                q[top++] = temp->data;
                temp = temp->next;
            }
        }
    }
}

void dfs(graph* g, int value, int visited[]){
    if(g == NULL){
        return;
    }

    if(visited[value] != 1){
        visited[value] = 1;
        cout<<value<<" ";
        node* temp = g->edges[value].head;
        while(temp != NULL){
            dfs(g, temp->data, visited);
            temp = temp->next;
        }
    }

    return;
}

void cycle_detection_dfs(graph* g, int value, int visited[], int dfs_visited[]){
    if(g == NULL){
        return;
    }
    if(visited[value] == 1 && dfs_visited[value] == 1){
        cout<<"Cycle present at: "<<value;
        return;
    }
    if(visited[value] != 1){
        visited[value] = 1;
        dfs_visited[value] = 1;

        // calling dfs
        node* temp = g->edges[value].head;
        while(temp != NULL){
            cycle_detection_dfs(g, temp->data, visited, dfs_visited);
            dfs_visited[value] = 0;
            temp = temp->next;
        } 
    }

    return;
}

void topological_sort_dfs(graph* g, int value, int visited[], int s[], int top){
    if(g == NULL){
        return;
    }

    if(visited[value] != 1){
        visited[value] = 1;

        // calling dfs
        node* temp = g->edges[value].head;
        while(temp != NULL){
            topological_sort_dfs(g, temp->data, visited, s, top);
            
            temp = temp->next;
        }
        cout<<value;
        s[top++] = value;
    }

    return;
}

// Kahn's Algorithm
// here indegree in a array means the nodes are numbered from 0
void topological_sort_bfs(graph* g, int size, int visited[], int indegree[]){
    if(g == NULL){
        return;
    }

    int q[size*size];
    int top = 0;
    int front = 0;

    // main program starting
    for(int i=0;i<size;i++){
        if(indegree[i] == 0){
            q[top++] = i;
        }
    }    

    while(top != front){
        int element = q[front];
        front++;

        if(visited[element] != 1){
            visited[element] = 1;

            node* temp = g->edges[element].head;
            while(temp != NULL){
                indegree[temp->data]--;
                if(indegree[temp->data] == 0){
                    q[top++] = temp->data;
                }
                temp = temp->next;
            }
        }
    }
    return;
}

//shortest path algorithms

// undirected algorithms
void short_path_un(graph* g, int nodes, int source, int destination){
    if(g == NULL){
        return;
    }

    // visited array
    int visited[nodes] = {0};
    int parent[nodes];
    for(int i=0;i<nodes;i++){
        parent[i] = INT_MAX;
    }
    queue<int> q;

    q.push(source);
    parent[source] = -1;

    while(!q.empty()){
        int element = q.front();
        q.pop();

        if(visited[element] != 1){
            visited[element] = 1;

            // now setting parent of nodes
            node* temp = g->edges[element].head;
            while(temp != NULL){
                q.push(temp->data);

                if(parent[temp->data] > element){
                    parent[temp->data] = element;
                }

                temp = temp->next;
            }
            
        }
    }
    cout<<endl;
    // now calculating and finding the path

    int s = destination;
    while(s != source){
        cout<<s<<" ";
        s = parent[s];
    }
    cout<<source;
}

// shortest path in directed graph
void short_path_DAG(graph* g, int nodes, int source, int destination){
    int visited[nodes] = {0};
    int s[nodes] = {5,4,3,2,1,0};
    int top = nodes;

    // doing topological sort
    // topological_sort_dfs(g, source, visited, s, 0);

    int distance[nodes];
    for(int i=0;i<nodes;i++){
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    while(top != 0){
        int element = s[--top];

        if(distance[element] != INT_MAX){
            int initial = distance[element];

            node* temp = g->edges[element].head;
            while(temp != NULL){
                int final = initial + 1;        // here value can be changed if the graph is weighted
                if(final < distance[temp->data]){
                    distance[temp->data] = final;
                }
                temp = temp->next;
            }
        }
    }

    // here we can print or return parent array
    for(int i=0;i<nodes;i++){
        cout<<distance[i]<<" ";
    }

    cout<<endl;
}


// Kjistra's Algorithm
void Kjistra_s(graph* g, int source){
    int distance[g->nodes] = {INT_MAX};
    distance[source] = 0;

    queue<int> q;
    node* temp = g->edges[source].head;
    while(temp != NULL){
        q.push(temp->data);
        distance[temp->data] = 1;
        temp = temp->next;
    }
}

void prims_algo(graph* g){
    if(g == NULL){
        return;
    }
}
int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    graph* g = allocate_graph(nodes);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        insert_graph(g, nodes, u, v);
        insert_graph(g, nodes, v, u);
    }

    cout<<endl;
    print_graph(g);

    cout<<endl;
    int visited[nodes] = {-1};
    // bfs(g, nodes, visited);
    // dfs(g, 0, visited);
    // short_path_un(g, nodes, 0, 2);
    short_path_DAG(g, nodes, 0, 0);
    return 0;
}