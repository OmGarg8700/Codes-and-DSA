#include<stdio.h>
#include<stdlib.h>
int inversions = 0;
void merge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int* first = (int *)malloc(sizeof(int)*len1);
    int* second = (int *)malloc(sizeof(int)*len2);

    // copying the values
    int i=s;
    for (int j=0;j<len1;j++){
        first[j] = arr[i++];
    }
    for (int j=0;j<len2;j++){
        second[j] = arr[i++];
    }

    // now merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    i = s;

    while(index1 < len1 && index2 < len2){
        if (first[index1] > second[index2]){
            if (arr[i] != second[index2]){
                arr[i++] = second[index2++];
                inversions++;
            }
            else{
                i++;
                index2++;
            }
            
        }
        else{
            if (arr[i] != first[index1]){
                arr[i++] = first[index1++];
                inversions++;
            }
            else{
                i++;
                index1++;
            }
        }
    }

    while(index1<len1){
        arr[i++] = first[index1++];
    }
    while(index2<len2){
        arr[i++] = second[index2++];
    }

    free(first);
    free(second);
    
}
void mergesort(int arr[], int s, int e){

    if (s>=e){
        return;
    }
    int mid = (s+e)/2;
  
    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);

    merge(arr, s,e);
};

int main(){
    // merge sort

    int arr[3] = {3, 1, 2};

    mergesort(arr, 0,2);

    for(int i= 0;i<3;i++){
        printf("%d ", arr[i]);
    };

    printf("%d", inversions);
    return 0;
}