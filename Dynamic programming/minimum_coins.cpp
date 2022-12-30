#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int min_coins(vector<int> &num, int &x){
    if(x == 0){
        return 0;
    }

    int initial = x;
    vector<int> vec1;
    
    for(int j=num.size()-1; j>=0; j--){
        if(x - num[j] >= 0){
            x = x - num[j];
            int ans = 1 + min_coins(num, x);
            vec1.push_back(ans);

            x = initial;
        }
    }

    int min_element = 214783647;
    for(int i=0;i<vec1.size();i++){
        if(vec1[i] < min_element && vec1[i] != -1){
            min_element = vec1[i];
        }
    }


    if(min_element == 214783647){
        return -2;
    }
    
    return min_element;
}


int main(){
    int n, x;
    cin>>n>>x;
    vector<int> num;
    for(int i=0;i<n;i++){
        int el;
        cin>>el;

        num.push_back(el);
    }

    int ans = min_coins(num, x);
    if(ans == -2){
        cout<<"-1";
    }
    else{
        cout<<ans;
    }
    return 0;
}