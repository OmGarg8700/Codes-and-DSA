#include<stdio.h>

int person = 1;

int min_difference(int arr[], int n,int index){
    int min_difference = 2000000000;
    int r_index = -1;
    for(int i=index;i<n-1;i++){
        if((arr[i+1]-arr[i])<min_difference && (arr[i+1]-arr[i])>0){
            // if((arr[i+1]-arr[i]) == 0){
            //     *person++;
            // }
            
            min_difference = arr[i+1]-arr[i];
            r_index = i;
                // printf("HElo %d", r_index);
            
        }
    }
    if(r_index == -1){
        person = 1;
    int j = index;
    while(j>0){
        if(arr[j] == arr[j-1]){
            person++;
        }
        j--;
    }
    printf("%d \n", person);
    }
    else{
        person = 1;
    int j = r_index;
    while(j>0){
        if(arr[j] == arr[j-1]){
            person++;
        }
        j--;
    }
    // printf("%d \n", person);
    }
    // for(int i=0;i<n;i++){
    //     // printf("%d", arr[i]);
    // }
    return r_index;
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
    int ans = 0 ;
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

    
    
    if(same == 0){
        // do sorting - merge sort
        merge_sort(arr, 0, n-1);
        
        // for(int i=0;i<n-1;i++){
        //     if((arr[i+1]-arr[i])==0){
        //         person++;
        //     }
        // }
        int index = min_difference(arr, n ,0);
        int difference = arr[index+1]-arr[index];
        
        // printf("%d %d %d %d \n", person, difference, index, arr[0]);
        while((k/person)>=difference && index != -1){
            // person++;
            // arr[index] += difference;
            int j = index-1;
            while(j>=0){
                if(arr[index] == arr[j]){
                    arr[j]+=difference;
                }
                j--;
            }
            arr[index] += difference;
            k -= difference*person;
            index = min_difference(arr, n, index+1);
            difference = arr[index+1]-arr[index]; 
            // printf("%d %d %d %d \n", person, difference, index, arr[0]);
        }
    }
    else{
        person = n;
    }
    // int person = 1;
    // for(int i=0;i<n;i++){
    //     if(arr[i+1])
    // }
    // int index = min_difference(arr, n,&person, 0);
    // int difference = arr[index+1]-arr[index];
    // if(difference==0){
    //     person++;
    // }
    // else{
    //     while((k/person)>=difference && index!= -1){
    //         arr[index] += difference;
    //         person++;
    //         k = k/person - difference;
    //         index = min_difference(arr, n, &person, index+1);
    // }
    // }


    
    printf("%d", person);

    return 0;
}