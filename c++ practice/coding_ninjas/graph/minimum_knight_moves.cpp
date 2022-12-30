#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void knight_moves(vector<vector<char>> &graph, vector<vector<int>> &visited, int pos_x, int pos_y){
    if(pos_x == 100 && pos_y == 100){
        return;
    }

    queue<int> q_x;
    queue<int> q_y;
    q_x.push(100);
    q_y.push(100);
    

    while(!q_x.empty()){
        int x = q_x.front();
        int y = q_y.front();
        q_x.pop();
        q_y.pop();


        if(x == pos_x && y == pos_y){
            return;
        }

        if(visited[y][x] == -1){
            visited[y][x] = 1;


            // for up
            if(visited[y-1][x] == -1){
                if(graph[y-1][x]== '#'){
                    graph[y-1][x] = 'U';
                }
                if(y-1 == pos_y && x == pos_x){
                    return;
                }
                q_x.push(x);
                q_y.push(y-1);
            }

            // for left
            if(visited[y][x-1] == -1){
                if(graph[y][x-1]== '#'){
                    graph[y][x-1] = 'L';
                }
                if(y == pos_y && x-1 == pos_x){
                    return;
                }
                q_x.push(x-1);
                q_y.push(y);
            }

            // for right
            if(visited[y][x+1] == -1){
                if(graph[y][x+1]== '#'){
                    graph[y][x+1] = 'R';
                }
                if(y == pos_y && x+1 == pos_x){
                    return;
                }
                q_x.push(x+1);
                q_y.push(y);
            }

            // for down
            if(visited[y+1][x] == -1){
                if(graph[y+1][x]== '#'){
                    graph[y+1][x] = 'D';
                }
                if(y+1 == pos_y && x == pos_x){
                    return;
                }
                q_x.push(x);
                q_y.push(y+1);
            }

        }
    }

}

void calculate_steps(vector<vector<char>> &graph, int &steps, int pos_x, int pos_y){
    if(pos_x == 100 && pos_y == 100){
        return;
    }

    steps += 1;
    if(graph[pos_y][pos_x] == 'U'){
        calculate_steps(graph, steps, pos_x, pos_y +1);
    }
    else if(graph[pos_y][pos_x] == 'R'){
        calculate_steps(graph, steps, pos_x-1, pos_y);
    }
    else if(graph[pos_y][pos_x] == 'L'){
        calculate_steps(graph, steps, pos_x+1, pos_y);
    }
    else if(graph[pos_y][pos_x] == 'D'){
        calculate_steps(graph, steps, pos_x, pos_y-1);
    }
    return;
}

int main(){
    vector<vector<char>> graph;
    vector<vector<int>> visited;
    for(int i=0;i<202;i++){
        vector<char> vec1;
        vector<int> vec2;
        for(int j=0;j<202;j++){
            vec1.push_back('#');
            vec2.push_back(-1);
        }
        graph.push_back(vec1);
        visited.push_back(vec2);
    }

    int pos_x, pos_y;
    cin>>pos_x>>pos_y;

    graph[100][100] = 's';

    knight_moves(graph, visited, pos_x + 100, pos_y + 100);


    // now the matrix is formed
    // let calculate the steps

    int steps = 0;
    calculate_steps(graph, steps, pos_x+100, pos_y+100);

    cout<<steps;

    return 0;
}