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
void insertAtTail(Node* & head, int val){
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
    while( temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}
Node* reversal(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* nxt;
    while (curr != NULL){
     nxt = curr->next;
     curr->next = prev;
     prev = curr;
     curr = nxt;
    }
   return prev;
}
void amazn1(Node* &head){
    Node* dummyNode = new Node(-1);
    Node* ptr = dummyNode;
    Node* even = head->next;
    Node* odd = head;
    Node* firstEven = head->next;
   while(odd->next != NULL && even->next != NULL){
       ptr->next = even;
       odd->next = even->next;
       odd = odd->next;
       even->next = odd->next;
       even = even->next;
       ptr = ptr->next;
   }
   
 odd->next = reversal(dummyNode->next);

}
int main(){
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
   amazn1(head);
 display(head);
return 0;
}