#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;



vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    vector<long long> prefix_sum;
    long long sum = 0;
    for(int i=0;i<100000;i++){
        sum += arr[i%n];
        prefix_sum.push_back(sum);
    }

    vector<int> ans;
    for(int i=0;i<q;i++){
        long long start = queries[i][0] - 1, end = queries[i][1] - 1;

        if(start < 1){
            sum = prefix_sum[end];
        }
        else{
            sum = prefix_sum[end] - prefix_sum[start-1];
        }
        ans.push_back(sum%1000000007);
    }
    return ans;
}

int main(){
    vector<int> vec1{5,2,6,9};
    vector<vector<long long>> vec2{{10,13}};

    sumInRanges(vec1, 4, vec2, 1);

    return 0;
}