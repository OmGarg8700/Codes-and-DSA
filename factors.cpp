#include<iostream>
using namespace std;

int main(){
    
    // here we find factors
    // by iterating through n/2 operations or by root(n) operations 

    // optimized approach for finding factors in a given range: 

    // this is pre processing of code
    int arr[214748364 + 1];

    for(int i = 0; i<= 214748364; i++){
        arr[i] = 0;
    }

    for(int i = 1; i<= 214748364; i++){
        for (int j = i; j<= 214748364; j += i){
            arr[j]++;
        }
    }

    int n;
    cout<<"Enter the number you want: ";
    cin>>n;

    cout<<"Number of factors are: "<<arr[n];
    return 0;
}