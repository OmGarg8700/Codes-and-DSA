#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count = 0;

void merge(int arr[], int s, int e){
    // make two arrays 
    int mid = (s+e)/2;
    int len1 = mid-s+1, len2 = e-mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int index = s;
    // copy the values
    for(int i=0;i<len1;i++){
        first[i] = arr[index++];
    }
    for(int i=0;i<len2;i++){
        second[i] = arr[index++];
    }

    // now merging and calcuating number of inversions
    int i=0, j=0;
    index = s;

    while(i<len1 && j<len2){
        if(first[i] <= second[j]){
            arr[index++] = first[i++];
        }
        else{
            //for inverions
            ::count += len1-i;
            arr[index++] = second[j++];
        }
    }

    while(i<len1){
        arr[index++] = first[i++];
    }
    while(j<len2){
        arr[index++] = second[j++];
    }
}

void mergesort(int arr[], int s, int e){
    if(s>=e){
        return;
    }

    int mid=(s+e)/2;
    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);

    merge(arr, s, e);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergesort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<::count;

    return 0;
}