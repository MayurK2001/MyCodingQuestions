#include<bits/stdc++.h>
using namespace std;

class Node{

    public: 
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        prev = next = NULL;
    }
};
void insertAtHead(Node* &head, int val){
    Node* node = new Node(val);
    node->next = head;
    if(head != NULL){
        head->prev = node;
    }

    head = node;
}
//1->2->3->4->5
void deleteNode(Node* head, int val){
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->data == val){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            return;
        }
        temp = temp->next;
    }
}
void insertAtTail(Node* &head, int val){
     if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    Node* node = new Node(val);
   
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
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
    
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtHead(head, 10);
    deleteNode(head, 3);
    display(head);
return 0;
}