#include<iostream>
#include<vector>
using namespace std;

void permutations(vector<int> arr, vector<vector<int>> &ans, int i){
        if(i == arr.size()){
            ans.push_back(arr);
            return;
        }

        vector<int> initial = arr;

        for(int j = i;j<arr.size();j++){
            swap(arr[i], arr[j]);
            permutations(arr, ans, i+1);
            arr = initial;    
        }
        return;
    }

class Solution {
public:
    
    void permutations(vector<int> arr, vector<vector<int>> &ans, int i){
        if(i == arr.size()){
            ans.push_back(arr);
            return;
        }

        vector<int> initial = arr;

        for(int j = i;j<arr.size();j++){
            swap(arr[i], arr[j]);
            permutations(arr, ans, i+1);
            arr = initial;    
        }
        return;
    }

    bool check_power_of_two(int n){
        while(n != 1){
            if(n%2 != 0){
                return false;
            }

            n = n/2;
        }

        return true;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> digits;

        while(n != 0){
            int digit = n%10;
            digits.push_back(digit);
            n = n/10;
        }

        vector<vector<int>> permutations;
        
    }
};

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;

    permutations(arr, ans, 0);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}