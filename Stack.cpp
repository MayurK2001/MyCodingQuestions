#include<bits/stdc++.h>
using namespace std;
#define n 10
class Stack{
    int * arr;
    int top;
    public: 
    Stack(){
        arr = new int[n];
        top = -1;
    }
    void push(int x){
    if(top == n-1){
        cout << "stack overflow" << endl;
        return;
    }
    top++;
    arr[top] = x;
}
void pop(){
    if(top == -1){
        cout << "stack underflow" << endl;
        return;
    }
    top --;
}
int Top(){
    if(top == -1){
        cout << "stack underflow"<<endl;
        return -1;
    }
    return arr[top];
}
bool isEmpty(){
    return top == -1;
}
};

int main(){
    
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5); 
 cout << s.isEmpty();
return 0;
}