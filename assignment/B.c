#include<stdio.h>

int toffees(int arr[], int n, int k){
    int element = arr[0];
    int person = 1;
    for(int i=1;i<n;i++){
        int value = (arr[i] - element);
        if(value == 0){
            person++;
        }
        else{
            if((k/person)>=value){
                k = (k/person) - value;
                person++;
                element += value;
            }
            else{
                break;
            }
        }
    }

    return person;
    // return 0;
}

int reverse_toffees(int arr[], int n, int k){
    int element = arr[0];
    int person = 1;
    return person;
}

void merge(int arr[], int s, int e){
    int mid = (s+e)/2;

    // now making two arrays
    int size1 = mid - s + 1, size2 = e - mid;
    int arr1[size1]; //= (int*)malloc(sizeof(int)*size1);
    int arr2[size2]; //= (int*)malloc(sizeof(int)*size2);

    int main_index = s;
    for(int i=0;i<size1;i++){
        arr1[i] = arr[main_index++];
    }
    for(int i=0;i<size2;i++){
        arr2[i] = arr[main_index++];
    }
    main_index = s;

    // now merging arrays
    int i=0,j=0;
    while(i<size1 && j<size2){
        if(arr1[i] <= arr2[j]){
            arr[main_index++] = arr1[i++];
        }
        else{
            arr[main_index++] = arr2[j++];
        }
    } 
    while(i<size1){
        arr[main_index++] = arr1[i++];
    }
    while(j<size2){
        arr[main_index++] = arr2[j++];
    }

    // free(arr1);
    // free(arr2);
}

void merge_sort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;

    // for left part
    merge_sort(arr, s, mid);

    // for right part
    merge_sort(arr, mid+1, e);

    // now merge two arrays
    merge(arr, s, e);
}

int main(){
    int n,k;
    int same = 1;
    int ans = 0;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
    // do some compuation before -- here can be error
    for(int i=0;i<n/2;i++){
        if(arr[i] != arr[n-1-i]){
            same = 0;
            break;
        }
    }
    
    if(same == 1 && k>=n){
        ans = n;
    }
    else{
        // do sorting - merge sort
        merge_sort(arr, 0, n-1);
        ans = toffees(arr, n, k);
    }
    
    printf("%d", ans);

    return 0;
}