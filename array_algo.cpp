#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Kandane's Algo
int max_subarray_sum(int arr[], int size){
	long long sum = 0, max_sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        max_sum = max(max_sum,sum);
        if (sum<0){
            sum=0;
        }
    }
	return max_sum;
}

void DNF_sort(int arr[], int n)
{
   	int low = 0;
	int present = 0;
	int high = n-1;
	
	while(present<=high){
		if(arr[present] == 0){
			swap(arr[present++], arr[low++]);
		}
		else if(arr[present]==1){
			present++;
		}
		else if(arr[present] == 2){
			swap(arr[present], arr[high--]);
		}
	}
}

int main(){
    int arr[] = {1,2,3,4,5};

    
    return 0;
}