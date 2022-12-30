#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int s,int e){
    int mid = (s+e)/2;

    // first make two arrays
    int len1 = mid-s+1;
    int len2 = e-mid;

    int* first = (int*)malloc(sizeof(int)*len1);
    int* second = (int*)malloc(sizeof(int)*len2);
    

    int main_index = s;

    for(int i=0;i<len1;i++){
        first[i] = arr[main_index++];
    }
    for(int i=0;i<len2;i++){
        second[i] = arr[main_index++];
    }

    // Now Merge arrays
    int i=0,j=0;
    main_index=s;
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
    // free(first);
    // free(second);
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

int main(){
    int q;
    scanf("%d", &q);

    for(int j=0;j<q;j++){
        int n,health;
        scanf("%d %d", &n,&health);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        if(n==1){
            printf("%d", health);
        }
        else{
            merge_sort(arr, 0, n-1);

        int difference[n-1];
        for(int i=0;i<n-1;i++){
            difference[i] = arr[i+1] - arr[i];
        }

        int count = 0;
        int k = health/n;
        while(count<health){
            count = 0;
            for(int i=0;i<n-1;i++){
                if(k<=difference[i]){
                    count+=k;
                }
                else{
                    count += difference[i];
                }
            }
            count += k;
            k++;
        }

        printf("%d", --k);
        }
    }
    return 0;
}