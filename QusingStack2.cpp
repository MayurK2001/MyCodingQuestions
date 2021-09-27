#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s;
    public:
    void Enqueue(int x){
        s.push(x);
    }
    int Dequeue(){
        if(s.empty()){
            cout << "can't dequeue from empty stack" << endl;
            return -1;
        }
        int x = s.top();
        s.pop();
        if(s.empty()){
            return x;
        }
        int res = Dequeue();
        s.push(x);
        return res;

    }
   
    bool Empty(){
        if(s.empty()){
            cout << "can't peek from empty stack" << endl;
            return true;
        }
        return false;
    }
   
};
int main(){
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
   cout << q.Empty();
    
        

return 0;
}