#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> xorQuery(vector<vector<int>> &queries)
{
    vector<int> ans;

	for(int i=0;i<queries.size();i++){
        int first = queries[i][0], second = queries[i][1];
        if(first == 1){
            ans.push_back(second);
        }
        else if(first == 2){
            for(int j=0;j<ans.size();j++){
                ans[j] = ans[j]^second;
            }
        }
    }
    
    return ans;
}