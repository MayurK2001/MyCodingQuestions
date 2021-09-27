#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int>s1;
    stack<int>s2;
    int n;
    public:
    void enqueue(int x){
        s1.push(x); 
    }
    int dequeue(){
        if(s1.empty() and s2.empty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        }
        int topElem = s2.top();
        s2.pop();
        return topElem;
    }
    bool isEmpty(){
        if(s2.empty()){
           return true;
        }
        return false;
    }
    int Peek(){
        if(s2.empty()){
            while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
     }
     if(s2.empty()){
         cout << "Cannot peek from emtpy queue";
         return -1;
     }
      return s2.top();
    }
    void printQ(){
        if(s2.empty()){
            while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
     }
      while(!s2.empty()){
            cout << s2.top() << " ";
            s2.pop();
        }
    }
};
int main(){
    
    Queue q;
    q.dequeue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    // q.printQ();

   cout <<  q.Peek();
return 0;
}