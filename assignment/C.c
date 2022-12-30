#include<stdio.h>

// int is_negative(int arr[], int n){
//     int result = 1;
//     for(int i=0;i<n;i++){
//         if(arr[i]>=0){
//             result = 0;
//             break;
//         }
//     }
//     return result;
// }

int arr_min(int arr[], int n, int ans){
    // int index = -1;
    // if(is_negative(arr, n) == 1){
    //     return -1;
    // }
    // else{
        int min_element = 1000000000,index;
        for(int i=0;i<n;i++){
            arr[i] -= ans;
            if(arr[i]<min_element && arr[i]>=0){
                min_element = arr[i];
                index = i;
            }
        }
        if(min_element == 1000000000){
            return -1;
        }
        else{
            return index;
        }
    // }
    
}


int main(){
    int t;
    scanf("%d", &t);
    for(int j=0;j<t;j++){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        int operations = 0;
        int value = 0, m = 0;
        int min_index = arr_min(arr, n, value*m);
        while(min_index != -1){
            // while(arr[min_index] >=0){
            //     for(int i=0;i<n;i++){
            //         arr[i] -= (min_index+1);
            //     }
            //     operations++;
            // }
            value = min_index+1;
            m = arr[min_index]/value + 1;
            // for(int i=0;i<n;i++){
            //     arr[i] -= value*m;
            // }
            operations += m;
            
            min_index = arr_min(arr, n, value*m);
        }
        // printf("%d", min_element);

        printf("%d \n", operations);
        
        


    }
    return 0;
}