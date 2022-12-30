#include<iostream>
using namespace std;

int horner(int arr[], int n, int x){
    int p = 0;
    for(int i=0;i<n;i++){
        p = x*p + arr[i];
    }
    return p;
}

int main(){
    // Horner's Algorihms
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the coffcient of x^"<<(n-i-1)<<" ";
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<horner(arr, n, x);
    return 0;
}