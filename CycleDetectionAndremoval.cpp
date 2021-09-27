#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
//1->2->3->4->5
void insertAtTail(Node* &head, int val){
      Node* node = new Node(val);
       if(head == NULL){
       head = node;
       return;
    }
      Node* temp = head;
      while (temp->next!= NULL){
          temp = temp->next;
      }
      temp->next = node;   
}
void makeCycle(Node* &head, int posn){
    Node* temp = head;
    Node* startCycle;
    int count = 0;
    while(temp->next != NULL){
         if(count == posn){
             startCycle = temp;
         }
         temp = temp->next;
         count ++;
    }
    temp->next = startCycle;
}
void removeCycle(Node* &head){
    Node* tor = head;
    Node* rabb = head;

    do{
        tor = tor->next;
        rabb = rabb->next->next;
    }
    while(rabb != tor);
    rabb = head;
    while(rabb->next != tor->next){
        rabb = rabb->next;
        tor = tor->next;
    }
    tor->next = NULL; 

}
bool cycleDetection(Node* &head){
    Node* tor = head;
    Node* rabb = head;
    while(rabb != NULL && rabb->next != NULL){
        tor = tor->next;
        rabb = rabb->next->next;
        if(rabb == tor){
            return true;
        }
    }
    return false;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    makeCycle(head, 3);
    
    cout << cycleDetection(head) << endl;
    removeCycle(head);
    cout << cycleDetection(head) << endl;
    display(head);
return 0;
}