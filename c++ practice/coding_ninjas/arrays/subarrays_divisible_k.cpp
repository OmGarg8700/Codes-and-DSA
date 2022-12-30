#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int subArrayCount(vector<int> &arr, int k) {
    int count = 0;
    vector<int> ans;

    for(int i=0;i<arr.size();i++){
        int sum = 0;
        for(int j=0;j<arr.size();j++){
            sum += arr[j];
            ans.push_back(sum);        
        }
    }

    for(int i=0;i<ans.size();i++){
        if(ans[i] < 0){
            ans[i] = abs(ans[i]);
        }
        if(ans[i]%k == 0){
            count++;
        } 
    }

    return count;
}
