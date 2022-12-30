#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double multiply(double n, int power){
    double temp = 1;
    for(int i=0;i<power;i++){
        temp  = temp * n;
    }

    return temp;
}

map<int, int> mp;

double power_number(double n, int power){
    if(power == 0){
        return 1;
    }

    int temp = 0;
    if(mp.count(power)){
        temp = mp[power];
    }
    else{
        temp = power_number(n, power/2);
    }

    if(power%2 == 0){
        return temp*temp;
    }
    return n * temp * temp;
}

double finding_root(double power, double n){
    double low = 0, high = n;

    while(high - low > 1e-6){

        double mid = low + (high-low)/2.0;
        double temp = multiply(mid, power);

        if(temp < n){
            low = mid;
        }
        else if(temp > n){
            high = mid;
        }
        else{
            return mid;
        }
    }

    return high;
}

int main(){
    double n, power;
    cin>>n>>power;

    cout<<finding_root(power, n);
    return 0;
}