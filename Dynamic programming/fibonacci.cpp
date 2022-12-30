#include<iostream>
using namespace std;

// recursion
int fib_1(int n){
    if(n == 0 || n == 1){
        return n;
    }

    return fib_1(n-1) + fib_1(n-2);
}

// recursion + memoization

int fib_2(int n, int dp[]){
    if(n == 1 || n == 0){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = fib_2(n-1, dp) + fib_2(n-2, dp);
    return dp[n];
}

// tabulation

int fib_3(int n, int dp[]){
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<n;i++){
        dp[n] = dp[n-1] + dp[n-2];
    }

    return dp[n];
}

// space optimizaion

int fib_4(int n){
    int prev1 = 0;
    int prev2 = 1;

    for(int i=2;i<n;i++){
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

int main(){
    int n;
    cin>>n;
    int dp[n+1] = {-1};     // n+1 : we treat 0 1 1 2 3 from 0 based indexing

    return 0;
}