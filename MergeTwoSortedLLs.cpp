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

Node* mergeTwoSortedLLs(Node* &head1, Node* &head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummyNode = new Node(-1);
    Node* ptr = dummyNode;
    while(t1 != NULL && t2 != NULL){
         if(t1->data < t2->data){
             ptr->next = t1;
             t1 = t1->next;
         }
         else{
             ptr->next = t2;
             t2 = t2->next;
         }
           ptr = ptr->next;
    }
    while (t1 != NULL){
        ptr->next = t1;
        ptr = ptr->next;
        t1 = t1->next;
    }
    while (t2 != NULL){
        ptr->next = t2;
        ptr = ptr->next;
        t2 = t2->next;
    }
    
    return dummyNode->next;
}
Node* mergeTwoSortedLLsRecursion(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
Node* result;
if(head1->data < head2->data){
    result = head1;
    result->next = mergeTwoSortedLLsRecursion(head1->next, head2);
}
else{
    result = head2;
    result->next = mergeTwoSortedLLsRecursion(head1, head2->next);
}
    return result;
}
int main(){
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    Node* head2 = NULL;
    insertAtTail(head2, 2);
    insertAtTail(head2, 4);
    insertAtTail(head2, 10);
    Node* newNode = mergeTwoSortedLLsRecursion(head, head2);
    display(newNode);
return 0;
//Time complexity of program is O(m+n), where m and n are lengths of linked list 1 and 2 respectively.
}