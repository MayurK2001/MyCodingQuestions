#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
  
};
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
// void insertAtTail(Node* &head, int val){
//    Node* node = newNode(val);
//    if(head == NULL){
//        head = node;
//        return;
//     }
//     Node* temp = head;
//     while(temp->next != NULL){
//         temp = temp->next;
//     }
//     temp->next = node;
// }
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// void insertAtHead(Node* &head, int val){
//     Node* node = newNode(val);
//     node->next = head;
//     head = node;
// }
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
Node* reversal(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* nxt;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

void Rearrange(Node* &head){
    Node* slow = head;
    Node* fast = slow->next;
    while(fast || fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* head1 = head;
    Node* head2 = slow->next;
    slow->next = NULL;

    reversal(head2);
    head = newNode(0);
    Node* curr = head;
    while(head1 || head2){
        if(head1){
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if(head2){
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
head = head->next;
}
int main(){
    
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);
 
    
     Rearrange(head);
    display(head);
return 0;
}