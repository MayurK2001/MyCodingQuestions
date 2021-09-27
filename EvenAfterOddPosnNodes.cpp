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

void evenAfterOdd(Node* head){
    Node* temp = head;
    Node* odd = head;
    Node* even = head->next;
    Node* firsteven = even;
    // Node* lasteven;
    while(even->next != NULL && odd->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
 }
     odd->next = firsteven;
    if(odd->next != NULL){
        even->next = NULL;
    }
}

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
int main(){
     Node* head = NULL;
     insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 8);
    evenAfterOdd(head);
   
    display(head);
return 0;
}