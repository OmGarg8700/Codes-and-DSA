#include<iostream>
#include<vector>
using namespace std;

bool is_safe(vector<vector<int>> board, int n, int row, int col){

    if((row>=0 && row<n) && (col>=0 && col<n)){
        // for row check
        for(int i=col;i>=0;i--){
            if(board[row][i] == 1){
                return false;
            }
        }

        // for right directions :: we have not filled in right so we don't check

        // for left up direction
        int ini_row = row;
        int ini_col = col;

        while((ini_col >= 0 && ini_col < n) && (ini_row >= 0 && ini_row < n)){
            if(board[ini_row][ini_col] == 1){
                return false;
            }

            ini_row--;
            ini_col--;
        }

        // for left down direction
        ini_row = row;
        ini_col = col;

        while((ini_col >= 0 && ini_col < n) && (ini_row >= 0 && ini_row < n)){
            if(board[ini_row][ini_col] == 1){
                return false;
            }

            ini_row++;
            ini_col--;
        }

        return true;

    }
}

void solve(vector<vector<int>> &board, vector<vector<vector<int>>> &ans, int n, int cols){
    // now fill the value of queens
    if(cols == n){
        ans.push_back(board);
        return;
    }

    for(int i=0;i<n;i++){
        if(is_safe(board, n, i, cols)){
            board[i][cols] = 1;

            cols += 1;
            solve(board, ans, n, cols);
            cols -= 1;
            board[i][cols] = 0;
        }
    }
}

// opimization : using map

int main(){
    int n;
    cin>>n;

    int rows = n, cols = n;

    vector<vector<int>> board;
    for(int i=0;i<rows;i++){
        vector<int> vec1;
        for(int j=0;j<cols;j++){

            vec1.push_back(0);
        }
        board.push_back(vec1);
    }

    vector<vector<vector<int>>> ans;

    solve(board, ans, n, 0);

    // This prints the different solution of board
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cout<<ans[i][j][k]<<" ";
            }
            cout<<endl;
        }

        cout<<endl;
    }

    return 0;
}