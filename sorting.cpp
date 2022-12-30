#include<iostream>
using namespace std;

void insertion_sort(int arr[], int size){
    for(int i=1;i<size;i++){
        if(arr[i] < arr[i-1]){
            int j=i;
            while(j>0){
                if(arr[j] < arr[j-1]){
                    swap(arr[j], arr[j-1]);
                }
                j--;
            }
        }
    }
}

void bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
  
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void merge(int arr[],int s,int e){
    int mid = (s+e)/2;

    // first make two arrays
    int len1 = mid-s+1;
    int len2 = e-mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int main_index = s;

    for(int i=0;i<len1;i++){
        first[i] = arr[main_index++];
    }
    for(int i=0;i<len2;i++){
        second[i] = arr[main_index++];
    }

    // Now Merge arrays
    int i=0,j=0,main_index=s;
    while(i<len1 && j<len2){
        if(first[i]<second[j]){
            arr[main_index++] = first[i++];
        }
        else{
            arr[main_index++] = second[j++];
        }
    }
    while(i<len1){
        arr[main_index++] = first[i++];
    }
    while(j<len2){
        arr[main_index++] = second[j++];
    }

    // free up the memory
    delete [] first;
    delete [] second;
}

void merge_sort(int arr[], int s, int e){
    if (s>=e){
        return;
    }
    int mid = (s+e)/2;

    //for left part 
    merge_sort(arr, s,mid);
    //for right part 
    merge_sort(arr,mid+1,e);

    merge(arr,s,e);
}

// Quick sort
int partition(int arr[], int s, int e){
    int pivot = arr[s];
    
    // counting elements less than pivot
    int count = 0;
    for(int i=s; i<=e; i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    // placing pivot to right position
    swap(arr[s], arr[s+count]);
    
    // now making the partition 
    int start = s, end = e;
    while(start<end){
        if(arr[start] <= pivot){
            start++;
        }
        else if (arr[end] > pivot){
            end--;
        }
        else if((arr[start]>pivot) && (arr[end]<pivot)){
            swap(arr[start], arr[end]);
        }
        
    }
    return s+count;
}

void quicksort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    // making partition
    int p = partition(arr, s, e);
    
    quicksort(arr, s, p-1);
    quicksort(arr, p+1, e);
    
}

int main(){
    int arr[] = {5, 7, 9, 0, 1};

    insertion_sort(arr, 5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}