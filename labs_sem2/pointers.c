#include<stdio.h>

int main(){
    char arr[4] = "abc";
    char *ptr = &arr[0];
    printf("%x", ptr);
    return 0;
}