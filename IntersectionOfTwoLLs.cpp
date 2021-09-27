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
void intersection(Node* &head1, Node* &head2, int posn){
    Node* temp = head1;
    Node* temp2 = head2;
    
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    
    while(temp->next != NULL){
        if(temp->data == posn){
         temp2->next = temp;
         return;
        }
        temp = temp->next;
    }
}
int len(Node* &head){
    Node* temp = head;
    int count = 1;
    while(temp->next != NULL){
        temp = temp->next;
        count ++;
     }
     return count;
}
int intersectionPt(Node* &head1, Node* &head2){
   int l1 = len(head1);
   int l2 = len(head2);
   
   Node* ptr1;
   Node* ptr2;
   int stL = 0;
   if(l1 > l2){
       stL = l1-l2;
       ptr1 = head1;
       ptr2 = head2;
   }
   else{
        stL = l2-l1;
       ptr1 = head2;
       ptr2 = head1;
   }
   for(int i = 0; i < stL; i ++){
       ptr1 = ptr1->next;
   }
   while(ptr1->next != NULL || ptr2->next != NULL){
       if(ptr1->next == ptr2->next){
           return ptr1->next->data;
       }
       ptr1 = ptr1->next;
       ptr2 = ptr2->next;
   }
   return -1;
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
    Node* head2 = NULL;
    insertAtTail(head2, 8);
    insertAtTail(head2, 9);
    insertAtTail(head2, 10);
    intersection(head, head2, 5);
     display(head);
     display(head2);
     cout << intersectionPt(head, head2);
return 0;
}