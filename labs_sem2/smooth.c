#include<stdio.h>

void sort_merge(int arr[],int s, int e,int k, int option, int* operation){
    int mid = (s+e)/2;
    int size1 = mid -s +1;
    int size2 = e - mid;
    int i=0,j=0;
    if(option == 0){
        while(i<size1 && j<size2){
            if(arr[i] != k){
                if(arr[j] == k){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                *operation++;
                i++;
                j++;
            }
            else{
                j++;     
            }
            }
            else{
                i++;
            }
        }
    }
    else{
        while(i<size1 && j<size2){
            if(arr[j] != k){
                if(arr[i] == k){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                *operation++;
                i++;     
                j++;
            }
            else{
                i++;
            }
            }
            else{
                j++;
            }
        }
    }
    // while(i<size1-1){
    //     if(arr[i] > arr[i+1]){
    //         int temp = arr[i];
    //         arr[i] = arr[i+1];
    //         arr[i+1] = temp;
    //         *operation++;
    //     }
    // }
    // while(j<size2-1){
    //     if(arr[j] > arr[j+1]){
    //         int temp = arr[j];
    //         arr[j] = arr[j+1];
    //         arr[j+1] = temp;
    //         *operation++;
    //     }
    // }
}

void minimum_k(int arr[], int s,int e, int k, int* operations){
    if(s>=e){
        return;
    }

    // sort_merge(arr, s, e, k, 0, operations);
    // int mid = (s+e)/2;
    if(arr[s] == k){
        sort_merge(arr, s, e, k,0, operations);
    }
    else if (arr[e] == k){
        sort_merge(arr, s, e, k, 1, operations);
    }
    else{
        int length1 = 0,length2 = 0;
        
    }
    return 0;
}

int main(){

    return 0;
}