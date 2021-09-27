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
// 1->2->3->4->5->6->7->8->9 after append for k = 3, 7->8->9->1->2->3->4->5->6
void AppendLastKNodes(Node* &head, int k){
    
    Node* temp = head;
    Node* tail;
    Node* newTail;
   Node* newHead;
    int len = 1;
    while(temp->next != NULL){
        temp = temp->next;
        len ++;
    }
    if(k >= len){ 
        cout << "here, k is not less than length of linked list, so append k nodes at head is not possible" << endl;
        return;
        }
   tail = temp;
   temp = head;
   for(int i = 1; i < len - k ; i ++){
       temp = temp->next;
   }
   newTail = temp;
   
   newHead = temp->next;
   newTail->next = NULL;
    tail->next = head;
    head = newHead;

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
    insertAtTail(head, 9);
    AppendLastKNodes(head, 5);
    display(head);
return 0;
}