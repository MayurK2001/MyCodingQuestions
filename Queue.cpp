#include<bits/stdc++.h>
using namespace std;
#define n 10
class Queue{
   int *arr;
   int front;
   int back;
   public:
   Queue(){
     arr = new int[n];
     front = back = -1;
   }
void enqueue(int x){
    if(back == n-1){
        cout << "limit exceeded" << endl;
        return;
    }
    if(front == -1){
        front ++; back++;
        arr[front] = x;
         return;
    }
    back ++;
    arr[back] = x;
 
}
void dequeue(){
    if(front == -1 || front > back){
        cout << "dequeue not possible from empty queue" << endl;
        return;
    }
    front ++;
}
bool isEmpty(){
    return (front > back) || (front = -1);
}
void peek(){
    if(front == -1 || front > back){
        cout << "Peek not possible" << endl;
        return;
    }
    cout << arr[front] << endl;
}
void printQ(){
    for(int i = front; i <= back; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(9);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.printQ();
    
    q.peek();
    
    cout << q.isEmpty();
return 0;
}