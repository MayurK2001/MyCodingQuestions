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
 void removeCycle(Node* &head){
     Node* rabb = head;
     Node* tor = head;
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
 bool CycleDetection(Node* &head){
     Node* rabb = head;
     Node* tor = head;
     while(rabb != NULL && rabb->next != NULL){
         tor = tor->next;
         rabb = rabb->next->next;
         if(rabb == tor){
             return true;
         }
     }
     return false;
 }
 void makeCycle(Node* &head, int posn){
        Node* temp = head;
        Node* startC;
        while (temp->next != NULL){
            if(temp->data == posn){
                startC = temp;
            }
            temp = temp->next;
        }
    temp->next = startC;
        
 }
 void insertAtTail(Node* &head, int val){
     Node* node = new Node(val);
     if(head == NULL){
         head = node;
         return;
     }
     Node* temp = head;
     while(temp->next != NULL){
         temp = temp->next;
     }
     temp->next = node;
 }
 void display(Node* head){
     Node* tmep = head;
     while(tmep != NULL){
         cout << tmep->data << "->";
         tmep = tmep->next;
     }
     cout << "NULL" << endl;
 }
int main(){
    Node * head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    makeCycle(head, 4);
    cout << CycleDetection(head) << endl;
    removeCycle(head);
    cout << CycleDetection(head) << endl;
    display(head);
return 0;
}