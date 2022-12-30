#include<iostream>
using namespace std;



int main(){
    // malloc
    int size = 6;
    int* ptr = (int*)malloc(sizeof(int)*size);
    // define a block of memory -- contiguos

    // calloc
    int* ptr1 = (int*)calloc(sizeof(int), size);
    // define 6 chunks of memory -- contiguos

    // realloc
    int* ptr2 = (int*)realloc(ptr, 7);
    // adds one xtra block of memeory without changing previous ones


    int arr[] = {1,2,3,4}; // memeory allocating static
    int* arr1 = (int*)malloc(sizeof(int)*5);
    for(int i=1;i<6;i++){
        arr1[i-1] = i;
    }

    // updating the size of array
    arr1 = (int*)realloc(arr1, sizeof(int)*6);
    arr1[5] = 6;

    arr1 = (int*)realloc(arr1, sizeof(int)*4);
    //printing
    for(int i=0;i<5;i++){
        cout<<arr1[i]<<" ";
    }
}