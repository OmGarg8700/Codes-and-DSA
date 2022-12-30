#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // This is a fibonacci type of question
    int fib(int n, vector<int> cost, int i){
        // starting from bottom

        // base case
        if(i == n){
            return 1;
        }

        if(i > n){
            return 0;
        }

                

        
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
    }
};

int main(){
    // fib_2 approach
    int n;
    cin>>n;
    int dp[n+1] = {-1};

    return 0;
}