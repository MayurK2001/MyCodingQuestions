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
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void insertAtHead(Node* &head, int val){
    Node* node = new Node(val);
    node->next = head;
    head = node;
}
void deleteAtHead(Node* &head){
    head = head->next;
}
void deleteAtTail(Node* &head){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    
}
//1->2->|3|->4
void deletionAtI(Node* &head, int value){
 Node* temp = head;
 if(head == NULL){
     return;   
 }
 if(temp->next == NULL){
      head = NULL;
     return;
 }
 while(temp != NULL){
     if(temp->next->data == value){
         temp->next = temp->next->next;
         
         return;
     
     }
     temp = temp->next;
 }
}
//1->|2|->n->->3->4
void AddNode(Node* &head,int index, int value){
    Node* node = new Node(value);
Node* temp = head;
while(temp != NULL){
    if(temp->data == index){
        temp->next = node;
        node->next = temp->next->next;
        return;
    }
    temp = temp->next;
}
}

int main(){
 Node* head = NULL;
insertAtTail(head, 1);
insertAtTail(head, 2);
insertAtTail(head, 3);
insertAtTail(head, 4);
insertAtHead(head,9);

AddNode(head, 2, 5);
display(head);

return 0;
}