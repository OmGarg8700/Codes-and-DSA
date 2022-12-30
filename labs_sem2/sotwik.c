#include<stdio.h>
int present = -1;
int main(){
    int n;
    int sum=0;
    int present = -1;
    scanf("%d", &n);
    int arr[3];
    for (int i=0;i<n;i++){
        // int arr[3];
        
        for (int j=0;j<3;j++){
            scanf("%d", &arr[j]);
        }
        // for (int j=0;j<3;j++){
        //     printf("%d ", arr[j]);
        // }
        
        int max_element = -10000;
        
        printf("%d %d \n", arr[present], present);
        for (int j=0;j<3;j++){
            if (j!=present){
                if (arr[j]>max_element){
                    printf("Helo");
                    max_element = arr[j];
                    present = j;
                    printf("%d", present);
                }
            }
        }
        printf("%d %d \n", arr[present], present);
        sum += arr[present];

    }

    printf("%d", sum);
    return 0;
 }