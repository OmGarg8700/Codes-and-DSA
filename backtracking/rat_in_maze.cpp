#include<iostream>
#include<vector>
using namespace std;

bool is_safe(vector<vector<int>> board, vector<vector<int>> visited, int x, int y, int rows, int cols){
    if((x>=0 && x<cols) && (y>=0 && y<rows) && board[y][x] == 1 && visited[y][x] == -1){
        return true;
    }

    return false;
};

void number_of_paths(vector<vector<int>> board, vector<vector<int>> &visited, int x, int y, int rows, int cols, vector<string> &ans, string &path){
    if(x == rows-1 && y == cols-1){
        ans.push_back(path);
    }

    string initial = path;

    // Down
    if(is_safe(board, visited, x, y+1, rows, cols)){
        path += "D";
        visited[y+1][x] = 1;

        number_of_paths(board, visited, x, y+1, rows, cols, ans, path);

        visited[y+1][x] = -1;
        path = initial;

    }
    

    // Left
    if(is_safe(board, visited, x-1, y, rows, cols)){
        path += "L";
        visited[y][x-1] = 1;

        number_of_paths(board, visited, x-1, y, rows, cols, ans, path);

        visited[y][x-1] = -1;
        path = initial;

    }
    
    // Right
    if(is_safe(board, visited, x+1, y, rows, cols)){
        path += "R";
        visited[y][x+1] = 1;

        number_of_paths(board, visited, x+1, y, rows, cols, ans, path);

        visited[y][x+1] = -1;
        path = initial;

    }
    
    // Up
    if(is_safe(board, visited, x, y-1, rows, cols)){
        path += "U";
        visited[y-1][x] = 1;

        number_of_paths(board, visited, x, y-1, rows, cols, ans, path);

        visited[y-1][x] = -1;
        path = initial;

    }

    return;
}



int main(){
    int rows, cols;
    cin>>rows>>cols;

    vector<vector<int>> board;
    vector<vector<int>> visited;
    for(int i=0;i<rows;i++){
        vector<int> vec1;
        vector<int> vec2;
        for(int j=0;j<cols;j++){
            int element;
            cin>>element;

            vec1.push_back(element);
            vec2.push_back(-1);
        }
        board.push_back(vec1);
        visited.push_back(vec2);
    }

    string path = "";
    vector<string> ans;

    number_of_paths(board, visited, 0, 0, rows, cols, ans, path);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}