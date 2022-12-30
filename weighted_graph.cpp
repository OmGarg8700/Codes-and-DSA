#include<iostream>
#include<stack>
#include<queue>
#include<queue>
#include<bits/stdc++.h>
#include "heaps.cpp"
using namespace std;

struct node{
    int data;
    int weight;
    node* next;
};

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


void insert_graph(graph* g, int size, int u, int v, int weight){
    g->edges[u].head = insert_node(g->edges[u].head, v, weight);
    return;
}

void print_graph(graph* g){
    for(int i=0;i<g->nodes;i++){
        cout<<i+1<<" -> ";
        node* temp = g->edges[i].head;
        while(temp != NULL){
            cout<<temp->data+1<<" "<<temp->weight<<endl;
            temp = temp->next;
        }
        cout<<endl;
    }
}

void print_LL(node* head){
    if(head == NULL){
        cout<<"Linked list is empty";
        return;
    }

    while (head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return;
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

bool cycle_detection_dfs(graph* g, int value, int visited[], int dfs_visited[]){
    if(g == NULL){
        return;
    }
    if(visited[value] == 1 && dfs_visited[value] == 1){
        cout<<"Cycle present at: "<<value;
        return true;
    }
    if(visited[value] != 1){
        visited[value] = 1;
        dfs_visited[value] = 1;

        // calling dfs
        bool ans = false;
        node* temp = g->edges[value].head;
        while(temp != NULL){
            ans = cycle_detection_dfs(g, temp->data, visited, dfs_visited);
            if(ans == true){
                return true;
            }
            temp = temp->next;
        } 
        dfs_visited[value] = 0;
    }

    return false;
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
    }
    cout<<value<<" ";
    s[top++] = value;

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
void Kjistra_s(graph* g, int source, int visited[]){
    int distance[g->nodes];
    for(int i=0;i<g->nodes;i++){
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
    heap* h = allocate_heap(g->nodes);
    insert_heap(h, source, distance[source]);

    while(h->top != 0){
        Node n = h->arr[1];
        delete_heap(h);

        if(visited[n.data] != 1){
            
            visited[n.data] = 1;
            node* temp = g->edges[n.data].head;
            while(temp != NULL){
                if(visited[temp->data] != 1){
                    // changing the distance values which are not visited
                    if(n.distance + temp->weight < distance[temp->data]){
                        distance[temp->data] = n.distance + temp->weight;
                    }
                    // insertion of nodes which are not present or if present updating it
                    if(check_heap(h, temp->data) == 1){
                        // updation
                        update_heap(h, temp->data, distance[temp->data]);
                    }
                    else{
                        // insertion if not present
                        insert_heap(h, temp->data, distance[temp->data]);
                    }
                }
                temp = temp->next;
            }
        }
    }

    for(int i=0;i<g->nodes;i++){
        cout<<distance[i]<<" ";
    }    
}

node* find_minimum_edge(graph* g, node* head, int visited[]){
    node* temp = g->edges[head->data].head;

    int min_we = 2147483647;
    int value = -1;

    while(temp != NULL){
        if(temp->weight < min_we && visited[temp->data] != 1){
            visited[temp->data] = 1;
            min_we = temp->weight;
            value = temp->data;
        }
        temp = temp->next;
    }
    
    if(value == -1){
        return NULL;
    }
    node* node1 =  allocate(value, min_we);
    // cout<<node1->data<<" ";
    node1->next = find_minimum_edge(g, node1, visited);
    return node1;

}

node* prims_algo(graph* g){
    if(g == NULL){
        return NULL;
    }

    int visited[g->nodes] = {-1};

    // finding minimum edge
    int first;
    int second;
    int min_edge = 2147483647;

    for(int i=0;i<g->nodes;i++){
        node* temp = g->edges[i].head;
        int count = 0;
        while(temp != NULL){
            if(temp->weight < min_edge){
                first = i;
                second = temp->data;
                min_edge = temp->weight;
            }
            count++;
            temp = temp->next;
        }
    }  

    // now making the first edge
    int min_dist = 2147483647;
    int value;
    node* temp = g->edges[first].head;
    while(temp != NULL){
        if(temp->weight < min_dist){
            value = first;
        }
        temp = temp->next;
    }
    temp = g->edges[second].head;
    while(temp != NULL){
        if(temp->weight < min_dist){
            value = second;
        }
        temp = temp->next;
    }
    node* head = NULL;
    if(value == first){
        head = allocate(second, 0);
        head->next = allocate(first, min_edge);
        
    }
    else{
        head = allocate(first, 0);
        head->next = allocate(second, min_edge);
    }

    // now we will be making recursive calls
    visited[first] = 1;
    visited[second] = 1;
    
    head->next->next = find_minimum_edge(g, head->next, visited);

    return head;
}

// Kruskal's Algo   -- starting -----------------------------

void merge_arrays(int arr[][3], int start, int end){
    int mid = (start + end)/2;
    int main_index = start;
    // making two arrays and assigning
    int size1 = mid-start + 1;
    int size2 = end - mid;
    int arr1[size1][3];
    int arr2[size2][3];
    
    for(int i=0;i<size1;i++){
        arr1[i][0] = arr[main_index][0];
        arr1[i][1] = arr[main_index][1];
        arr1[i][2] = arr[main_index][2];
        main_index++;
    }
    for(int i=0;i<size2;i++){
        arr2[i][0] = arr[main_index][0];
        arr2[i][1] = arr[main_index][1];
        arr2[i][2] = arr[main_index][2];
        main_index++;
    }

    // now merging two sorted arrays
    int i=0, j=0;
    main_index = start;
    while(i<size1 && j<size2){
        if(arr1[i][0] < arr2[j][0]){
            arr[main_index][0] = arr1[i][0];
            arr[main_index][1] = arr1[i][1];
            arr[main_index][2] = arr1[i][2];
            i++;
            main_index++;
        }
        else{
            arr[main_index][0] = arr2[j][0];
            arr[main_index][1] = arr2[j][1];
            arr[main_index][2] = arr2[j][2];
            j++;
            main_index++;
        }
    }
    while(i<size1){
        arr[main_index][0] = arr1[i][0];
        arr[main_index][1] = arr1[i][1];
        arr[main_index][2] = arr1[i][2];
        i++;
        main_index++;
    }
    while(j<size2){
        arr[main_index][0] = arr2[j][0];
        arr[main_index][1] = arr2[j][1];
        arr[main_index][2] = arr2[j][2];
        j++;
        main_index++;
    }
}

void merge_sort(int arr[][3], int start, int end){
    if(start >= end){
        return;
    }

    int mid = (start+end)/2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);

    merge_arrays(arr, start, end);
}

int find_parent(int a, int parent[]){
    if(a == parent[a]){
        return a;
    }

    parent[a] = find_parent(parent[a], parent);
    return parent[a];
}

void union_set(int a, int b, int parent[], int rank[]){
    int parent_a = a;
    int parent_b = b;
    
    if(rank[parent_a] < rank[parent_b]){
        parent[parent_a] = parent_b;
    }
    else if(rank[parent_b] < rank[parent_a]){
        parent[parent_b] = parent_a;
    }
    else{
        parent[parent_b] = parent_a;
        rank[parent_a]++;
    }
}

void kruskals_Algo(graph* g, int edges, int sorted_graph[][3]){
    int parent[g->nodes];
    int rank[g->nodes];

    for(int i=0;i<g->nodes;i++){
        parent[i] = i;
        rank[i] = 0;
    }

    int cost = 0;
    for(int i=0;i<edges;i++){
        int a = find_parent(sorted_graph[i][1], parent);
        int b = find_parent(sorted_graph[i][2], parent);
        cout<<a<<" "<<b<<endl;
        // does not belong to same component
        if(a != b){
            cost += sorted_graph[i][0];
            union_set(a, b, parent, rank);
        }
    }

    cout<<cost;
}
// Kruskal's Ending -----------------------------------------------

int main(){
    int nodes, edges;
    cin>>nodes>>edges;
    graph* g = allocate_graph(nodes);
    // making list to store edges
    int j = 0;
    int sorted_graph[edges][3];

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        int w;
        cin>>w;
        insert_graph(g, nodes, u-1, v-1, w);
        insert_graph(g, nodes, v-1, u-1, w);
 
        sorted_graph[j][0] = w;
        sorted_graph[j][1] = u-1;
        sorted_graph[j][2] = v-1;
        j++;

    }

    cout<<endl;
    print_graph(g);

    cout<<endl;
    int visited[nodes] = {-1};
    // bfs(g, nodes, visited);
    // dfs(g, 0, visited);
    // short_path_un(g, nodes, 0, 2);
    // short_path_DAG(g, nodes, 0, 0);
    // node* head = prims_algo(g);
    
    merge_sort(sorted_graph, 0, edges-1);
    kruskals_Algo(g, edges, sorted_graph);
    return 0;
}
// int main(){
//     int nodes, edges;
//     cin>>nodes>>edges;
//     graph* g = allocate_graph(nodes);
 
//     for(int i=0;i<edges;i++){
//         int u,v;
//         cin>>u>>v;
//         int w;
//         cin>>w;
//         insert_graph(g, nodes, u-1, v-1, w);
//         insert_graph(g, nodes, v-1, u-1, w);

//     }

//     cout<<endl;
//     print_graph(g);

//     cout<<endl;
//     int visited[nodes] = {-1};

//     Kjistra_s(g, 5-1, visited);
//     return 0;
// }

// int main(){
//     int nodes, edges;
//     scanf("%d %d", &nodes, &edges);
//     graph* g = allocate_graph(nodes);
 
//     for(int i=0;i<edges;i++){
//         int u, v, w;
//         scanf("%d %d %d", &u, &v, &w);
//         insert_graph(g, nodes, u, v, w);
//         // insert_graph(g, nodes, v, u, w);
//     }

//     // prims_algo(g);
//     int stack[g->nodes*2];
//     int top = 0;

//     int visited[g->nodes];
//     for(int i=0;i<g->nodes;i++){
//         visited[i] = -1;
//     }

//     topological_sort_dfs(g, 0, visited, stack, top);
//     return 0;
// }