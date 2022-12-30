#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    // Implementation of stack using queue
    queue<int> q1;

    // for push operation
    int element;
    q1.push(element);

    // for pop operation
    // 1. make new queue and store elements till last-1 and return the result as last 
    // 2. swap names of q1 and q2 
    queue<int> q2;
    int count = q1.size();
    while(count-1 > 0){
        int x = q1.front();
        q1.pop();
        q2.push(x);
        count--;
    }
    int result = q1.front();
    q1.pop();

    q1 = q2;


    return 0;
}

int main(){
    // Implementation of queue using stack
    stack<int> s1;

    // for push operation
    int element;
    s1.push(element);

    // for pop operation
    // 1. make new stack and push elements till last-1 and store results as last 
    // 2. then again pop elements from second ans store in first one 
    stack<int> s2;
    int count = s1.size();
    while(count-1 > 0){
        int x = s1.top();
        s1.pop();
        s2.push(x);
        count--;
    }
    int result = s1.top();
    s1.top();

    count = s2.size();
    while(count-1 > 0){
        int x = s2.top();
        s2.pop();
        s1.push(x);
        count--;
    }
    
    return 0;
}