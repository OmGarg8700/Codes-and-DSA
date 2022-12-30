#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> num, int i){
    if(i >= num.size()){
        return 0;
    }

    // we have taken the number
    int sum1 = num[i] + solve(num, i+2);

    // we have not taken the number
    int sum2 = solve(num, i+1);

    return max(sum1, sum2);
}

//  recursion + memoization
int solve2(vector<int> num, int i, int dp[]){
    if(i >= num.size()){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    // we have taken the number
    int sum1 = num[i] + solve2(num, i+2, dp);

    // we have not taken the number
    int sum2 = solve2(num, i+1, dp);

    dp[i] = max(sum1, sum2);
    return dp[i];
}

// tabulation approach

int solve3(vector<int> num){
    int n = num.size();

    if(n == 1){
        return num[0];
    }

    int dp[n];
    for(int i=0;i<n;i++){
        dp[i] = -1;
    }
    
    int sum1 = 0;
    int sum2 = 0;

    for(int i=0;i<n;i++){
        // present
        if(i+2 < n){
            sum1 += num[i] + dp[i+2];
        }
        // absent
        if(i+1 < n){
            sum2 += dp[i+1];
        }
    }

    return max(sum1, sum2);
}

// ** for now we can apply tabulation to backward recursion only

int maximumNonAdjacentSum(vector<int> &nums){
    // int ans = solve(nums, 0);

    int dp[nums.size()];
    int ans = solve2(nums, 0, dp);
    return ans;
}

int main(){
    return 0;
}
