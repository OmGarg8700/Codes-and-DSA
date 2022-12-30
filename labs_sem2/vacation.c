#include<stdio.h>

int main(){
    int n;
    int sum=0,present = 0;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        int arr[3];
        
        for (int j=0;j<3;j++){
            scanf("%d", &arr[i]);
        }
        for (int j=0;j<3;j++){
            printf("%d ", arr[i]);
        }
        
        int max_element = arr[0];
        
        for (int j=0;j<n;j++){
            if (arr[j]>max_element && i!=present){
                printf("Helo");
                max_element = arr[j];
                present = j;
                
            }
        }
        printf("%d %d \n", arr[present], present);
        sum += arr[present];

    }

    printf("%d", sum);
    return 0;
}