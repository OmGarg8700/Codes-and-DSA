#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> num, int i, int &taken){
    if(i >= num.size()){
        return 0;
    }

    // we will not take last element if firt element is taken
    if(i == num.size() -1 && taken == 1){
        return 0;
    }

    // we have taken the number
    if(i == 0){
        taken = 1;
    }
    int sum1 = num[i] + solve(num, i+2, taken);

    // we have not taken the number
    taken = 0;
    int sum2 = solve(num, i+1, taken);

    return max(sum1, sum2);
}

//  recursion + memoization
int solve2(vector<int> num, int i, int dp[]){
    if(i >= num.size()){
        return 0;
    }

    // we have taken the number
    int sum1 = num[i];
    int sum2 = 0;
    if(dp[i+2] != -1){
        sum1 += dp[i+2];
    }
    else{
        sum1 += solve2(num, i+2, dp);
    }

    // we have not taken the number
    if(dp[i+1] != -1){
        sum2 += dp[i+1];
    }
    else{
        sum2 += solve2(num, i+1, dp);
    }

    dp[i] = max(sum1, sum2);
    return dp[i];
}

long long int houseRobber(vector<int>& valueInHouse){
    
}

int main(){
    return 0;
}