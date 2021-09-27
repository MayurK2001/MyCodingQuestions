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
int BottomOfLeftTreeVal(Node* root){
    if(root == NULL){
        return -1;
    }
    stack<Node*> st;
       queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* temp;
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
    }
}

int main(){
       Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
return 0;
}