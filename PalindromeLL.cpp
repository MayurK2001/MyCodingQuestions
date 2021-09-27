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
Node* reverse(Node* head){
    
    Node* curr = head;
    Node* prev = NULL;
    Node* nxt;
    while(curr != NULL){
          nxt = curr->next;
          curr->next = prev;
          prev = curr;
          curr = nxt;
    }
    return prev;
}
Node* middle(Node* head){
    Node* hare = head;
    Node* tor = head;
    while(hare != NULL and hare->next != NULL) {
        hare = hare->next->next;
        tor = tor->next;
    }
    return tor;
}
bool isPalindrome(Node* head){
    if(head == NULL) return 1;
    Node* mid = middle(head);
    Node* last = reverse(mid->next);
    Node* curr = head;
    while (last != NULL)
    {
        /* code */
        if(last->data != curr->data) return false;
        last = last->next;
        curr = curr->next;
    }
    return 1;
    

}
void printList(Node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
//  1->2->3->4->5->4->3->2->1
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next->next = new Node(1);
    cout << isPalindrome(head);
    
return 0;
}