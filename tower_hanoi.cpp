#include<iostream>
using namespace std;

void tower_of_hanoi(int i, char s, char help, char dest){
    if (i==0){
        return;
    }
    tower_of_hanoi(i-1, s, dest, help);
    cout<<"moved lower disc("<<s<<") to destination"<<dest<<endl;
    tower_of_hanoi(i-1, help, s, dest);
    // cout<<"moved left part to destination";
}