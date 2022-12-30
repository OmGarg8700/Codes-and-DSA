#include<stdio.h>
#include<stdlib.h>

// for 0 based i-ndexing

typedef struct node{
    int data;
    int weight;
    struct node* next;
}node;

node* allocate(int data, int weight){
    node* node1 = (node*)malloc(sizeof(node));
    node1->data = data;
    node1->next = NULL;
    node1->weight = weight;
    return node1;
}

node* insert_LL(node* head, int data, int weight){
    if(head == NULL){
        return allocate(data, weight);
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = allocate(data, weight);
    return head;
}

typedef struct graph{
    int nodes;
    node** edges;
}graph;

graph* allocate_graph(int nodes){
    graph* g = (graph*)malloc(sizeof(graph));
    g->nodes = nodes;
    g->edges = (node**)malloc(sizeof(node*)*nodes);
    for(int i=0;i<nodes;i++){
        g->edges[i] = NULL;
    }
    return g;
}

void insert_graph(graph* g, int u, int v, int weight){
    g->edges[u] = insert_LL(g->edges[u], v, weight);
}

void print_graph(graph* g){
    for(int i=0;i<g->nodes;i++){
        printf("%d -> ");
        node* temp = g->edges[i];
        while(temp != NULL){
            printf("\t %d %d", temp->data, temp->weight);
            printf("\n");
        }
        printf("\n");
    }
}

// BFS Algo
void BFS(graph* g, int value, int visited[]){
    int queue[g->nodes];
    int top = 0, front = 0;

    queue[top++] = value;

    while(top != front){
        int element = queue[front];
        front++;

        if(visited[element] != 1){
            visited[element] = 1;

            node* temp = g->edges[element];
            while(temp != NULL){
                if(visited[temp->data] != 1){
                    queue[top++] = temp->data; 
                }
                temp = temp->next;
            }
        }
    }
}

// cycle detection in DAG
// int cycle_detection_DAG(graph* g, int value, int visited[], int dfs_visited[]){

//     printf("Hello");
//     if(visited[value] == 1 && dfs_visited[value] == 1){
//         return 1;
//         printf("Cycle is present");
//     }

//     if(visited[value] != 1){
//         visited[value] = 1;

//         node* temp = g->edges[value];
//         while(temp != NULL){
//             if(visited[temp->data] != 1){
//                 dfs_visited[temp->data] = 1;
//                 return cycle_detection_DAG(g, temp->data, visited, dfs_visited);
//                 dfs_visited[temp->data] = -1;
//             }
//             temp = temp->next;
//         }
//     }
//     // dfs_visited[value] = -1;
//     return 0;
// }

int cycle_detection_DAG(graph* g, int value, int visited[], int dfs_visited[]){

    if(visited[value] != 1){
        visited[value] = 1;
        dfs_visited[value] = 1;

        node* temp = g->edges[value];
        while(temp != NULL){
            if(visited[temp->data] != 1){
                if(cycle_detection_DAG(g, temp->data, visited, dfs_visited) == 1){
                    return 1;
                }
            }
            else if(dfs_visited[temp->data] == 1 && visited[temp->data] == 1){
                // means cycle present 
                return 1;
            }
            temp = temp->next;
        }
    }
    dfs_visited[value] = -1;
    return 0;
}

// Is a connected component
int is_connected(graph* g, int c1, int c2){
    int visited[g->nodes];
    for(int i=0;i<g->nodes;i++){
        visited[i] = -1;
    }

    BFS(g, c1, visited);

    return visited[c2];
}
// Dijkstra’s Algo : greedy algo 7
int find_min_dist(graph* g, int distance[], int visited[]){
    int index = -1;
    int min_dist = 2147483647;

    for(int i=0;i<g->nodes;i++){
        if(visited[i] == -1 && distance[i] < min_dist){
            index = i;
            min_dist = distance[i];
        }
    }

    return index;
}
void algo7(graph* g, int source){
    if(g == NULL){
        return;
    }

    int distance[g->nodes];
    int visited[g->nodes];
    for(int i=0;i<g->nodes;i++){
        distance[i] = 2147483647;
        visited[i] = -1;
    }

    distance[source] = 0;

    for(int i=0;i<g->nodes;i++){
        // finding minimum distance and making them visited
        int index = find_min_dist(g, distance, visited);
        visited[index] = 1;

        // traversing while adjcency list
        node* temp = g->edges[index];
        while(temp != NULL){
            if(visited[temp->data] == -1){
                if(distance[index] + temp->weight < distance[temp->data]){
                    distance[temp->data] = distance[index] + temp->weight;
                }
            }
            temp = temp->next;
        }
    }

    for(int i=0;i<g->nodes;i++){
        printf("%d ", distance[i]);
    }
}

// topological sort
void topological_sort(graph* g, int value, int visited[], int stack[], int top){
    if(visited[value] != 1){
        visited[value] = 1;

        node* temp = g->edges[value];
        while(temp != NULL){
            topological_sort(g, temp->data, visited, stack, top);
            temp = temp->next;
        }

        stack[top++] = value;
    }
}

// is cycle present in graph -- it is for undirected graphs
int is_cycle_present(graph* g, int source, int visited[]){
    int queue[g->nodes];
    int top = 0, front = 0;

    queue[top++] = source;

    while(top != front){
        int element = queue[front];
        front++;

        if(visited[element] != 1){
            visited[element] = 1;

            node* temp = g->edges[element];
            while(temp != NULL){
                if(visited[temp->data] != 1){
                    // adding elements who are not visited
                    queue[top++] = temp->data;
                }
                temp = temp->next;
            }
        }
        else{
            // now cycle is present
            return 1;
        }
    }

    return -1;
}
int iscycle(graph* g){
    if(g == NULL){
        return -1;
    }

    int visited[g->nodes];
    for(int i=0;i<g->nodes;i++){
        visited[i] = -1;
    }

    int ans = 0;
    for(int i=0;i<g->nodes;i++){
        ans = is_cycle_present(g, i, visited);
        if(ans == 1){
            return ans;
        }
    }

    return ans;
}

// shortest path in undirected graph :: by parent array
// for unweighted graph
void shortest_path_unweight(graph* g, int source, int destination){
    if(g == NULL){
        return;
    }

    int parent[g->nodes];
    int visited[g->nodes];
    for(int i=0;i<g->nodes;i++){
        parent[i] = -1;
        visited[i] = -1;
    }

    int queue[g->nodes];
    int top = 0, front = 0;

    queue[top++] = source;
    parent[source] = -1;
    
    while(top != front){
        int element = queue[front];
        front++;

        if(visited[element] != 1){
            visited[element] = 1;

            node* temp = g->edges[element];
            while(temp != NULL){
                if(parent[temp->data] == -1){
                    parent[temp->data] = element;
                    queue[top++] = temp->data;
                }
                // stop at destination
                if(temp->data == destination){
                    return;
                } 
                temp = temp->next;
            }
        }
    }

    for(int i=0;i<g->nodes;i++){
        printf("%d ", parent[i]);
    }
}

// prim's Algo -- Minimum spanning tree
void min_spanning_tree(graph* g, int source){
    if(g == NULL){
        return;
    }

    int key[g->nodes];
    int MST[g->nodes];
    int parent[g->nodes];
    for(int i=0;i<g->nodes;i++){
        key[i] = 2147483647;
        MST[i] = -1;
        parent[i] = -1;
    }

    // setting source
    key[source] = 0;
    while(1){

        int index = -1, min_ele = 2147483647;
        for(int i=0;i<g->nodes;i++){
            if(MST[i] == -1 && key[i] < min_ele){
                min_ele = key[i];
                index = i;
            }
        }

        if(min_ele == 2147483647){
            break;
        }

        MST[index] = 1;
        node* temp = g->edges[index];
        while(temp != NULL){
            if(temp->weight < key[temp->data]){
                key[temp->data] = temp->weight;
                parent[temp->data] = index;
            }
            temp = temp->next;
        }
    }

    for(int i=0;i<g->nodes;i++){
        printf("%d ", key[i]);
    }

}


// cycle detecion in dag
int is_cycle_DAG(graph* g, int value, int visited[], int dfs_visited[]){
    visited[value] = 1;
    dfs_visited[value] = 1;

    node* temp = g->edges[value];
    while(temp != NULL){
        if(visited[temp->data] != 1){
            if(is_cycle_DAG(g, temp->data, visited, dfs_visited) == 1){
                return 1;
            }
        }
        else if(dfs_visited[temp->data] == 1){
            return 1;
        }
    }

    dfs_visited[value] = 0;
    return 0;
}

int main(){
    int nodes;
    scanf("%d", &nodes);
    graph* g = allocate_graph(nodes);
    int edges;
    scanf("%d", &edges);
    for(int i=0;i<edges;i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        insert_graph(g, u, v, w);
        insert_graph(g, v, u, w);
    }

    int visited[g->nodes];
    int dfs_visited[g->nodes];
    for(int i=0;i<g->nodes;i++){
        dfs_visited[i] = -1;
        visited[i] = -1;
    }
    dfs_visited[0] = 1;
    // printf("%d", is_cycle_present(g, 0, visited));
    printf("%d", cycle_detection_DAG(g, 0, visited, dfs_visited));
    return 0;
}