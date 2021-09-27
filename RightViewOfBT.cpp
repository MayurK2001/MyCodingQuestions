#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
void rightViewOfBT(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr != NULL){
            
            if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
         }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
        if(q.front() == NULL){
            cout << curr->data << " ";
        }
    }
} // 1 3 7
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    rightViewOfBT(root);
return 0;
}