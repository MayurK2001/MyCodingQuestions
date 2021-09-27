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
Node* reverseLLRecursive(Node* head){
    if(head == NULL or head->next == NULL){
        return head;
    }
    Node* newHead = reverseLLRecursive(head->next);
    Node* headNxt = head->next;
    headNxt->next = head;
    head->next = NULL;
    return newHead;
}
void printList(Node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "->NULL" << endl;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    printList(head);
    Node* newHead = reverseLLRecursive(head);
    printList(newHead);

return 0;
}