#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
     Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Queue{
    Node* front;
    Node* rear;
    public:
    Queue(){
        front = rear = NULL;
    }
    void enque(int val){
        Node *node = new Node(val);
          if(front == NULL){
            front = node;
            rear = node;
            return;
          }
        rear->next = node;
        rear = node;
    }
    void dequeue(){
         if(front == NULL ){
             cout << "can't dequeue from empty queue" << endl;
             return;
         }
         Node* temp = front;
         front = front->next;
         delete temp;
    }
    bool isEmpty(){
        if( front == NULL || front > rear){
            return true;
        }
        return false;
    }
    void printQ(){
        Node* temp = front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    int peek(){
         if(front == NULL ){
             cout << "can't peek from empty queue" << endl;
             return -1;
         }
  return front->data;
    }
};

int main(){
    
    Queue q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(5);
    q.enque(6);
    q.dequeue();
    q.dequeue();
    q.enque(10);
    cout << q.peek() << endl;
    q.printQ();
    
return 0;
}