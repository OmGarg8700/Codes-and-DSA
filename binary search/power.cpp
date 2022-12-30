#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int power_number(int n, int power){
    if(power == 0){
        return 1;
    }

    int temp = power_number(n, power/2);

    if(power%2 == 0){
        return temp*temp;
    }
    return n * temp * temp;
}

int main(){
    int n, power;
    cin>>n>>power;

    cout<<power_number(n, power);
    return 0;
}