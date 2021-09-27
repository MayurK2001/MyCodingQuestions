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
void insertAtHead(Node* &head, int val){
    Node* node = new Node(val);
    if(head == NULL){
        node->next = node;
        head = node;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = node;
    node->next = head;
    head = node;
}

void insertAtTail(Node* &head, int val){
    Node* node = new Node(val);
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = node;
    node->next = head;
}
void display(Node* head){
    Node* tmep = head;
    do{
        cout << tmep->data << " ";
        tmep = tmep->next;
    }while (tmep != head);
    cout << endl;
    
}
//1->2->3->4->5
void deletion(Node* &head, int val){
    if(head == NULL){
        return;
    }
    Node* tmep = head;
   
    while(tmep->next != head){
       if(tmep->next->data == val){
           tmep->next = tmep->next->next;
           return;
       }
       tmep = tmep->next;
    }
    if(head->data == val){
        head = head->next;
        tmep->next = head;
    }
}
int main(){
      Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    insertAtHead(head,9);
    deletion(head,7);
    display(head);
return 0;
}