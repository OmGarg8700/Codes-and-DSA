#include<stdio.h>

int rectangle(int a,int b){
    return a*b;
}

int main(){
    // printf("Hello google");
    int arr[5] = {1,2,3};
    // in this way we can add position to 0
    // arr[3] = 0 and arr[4]==0

    // %x can be used for hexadecimal

    // int a[3][3] = {1,2,3,4,5,6,7,8,9}; we can also assign values like this 

    // we can also declare functions without any int ,void,or anything  but we have to declare in main
    
    // int arr2[5];
    // printf("%d", arr[3]);
    // int a[5];
    // scanf("%d", &a[0]);
    // printf("%d", a[0]);
    // printf("%d", a[1]);

    // int a[3][3] = {1,2,3,6,8,0,7,11,9};
    // for (int i=0;i<3;i++){
    //     for (int j=0;j<3;j++){
    //         scanf("%d", &a[i][j]);
    //     }
    // };
    // for (int i=0;i<3;i++){
    //     for (int j=0;j<3;j++){
    //         printf("%d ", a[j][i]);
    //     }
    //     printf("\n");
    // }
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d", rectangle(a,b));
    
    return 0;
}