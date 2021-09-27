#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data  = data;
        next = NULL;
    }
};
//1->2->3->4->NULL
void insertAtTail(node* &head, int val){
    node* n = new node(val);
     if(head == NULL){
       head = n;
       return;
    }
     node*temp = head;
     while(temp->next != NULL){
           temp = temp->next;
     }
      temp->next = n;
}
void displayLL(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
}
// 1->2->3->4->5
node* reverseLl(node* & head){
    node* prev = NULL;
    node* curr = head;
    node* nxt;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
node* reverseLLRecursion(node* & head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newHead = reverseLLRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
node* reverseKNodes(node* &head, int k){
    node* prev = NULL;
    node* curr = head;
    node* nxt;
    int count = 0;
    while(curr != NULL && count < k){
           nxt = curr->next;
           curr->next = prev;
           prev = curr;
           curr = nxt;
           count ++;
    }
      if(nxt != NULL){
          head->next = reverseKNodes(nxt, k);
      }
      return prev;
}

int main(){
    
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    displayLL(head);
    node* newHead = reverseKNodes(head,2);
        displayLL(newHead);
return 0;
}

