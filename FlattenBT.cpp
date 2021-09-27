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

void flatten(Node* root){
    if(root == NULL or (root->left == NULL and root->right == NULL)){
        return;
    }
    if(root->left != NULL){
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        Node* t = root->right;
        while(t->right != NULL){
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    inorder(root);
    cout << endl;
    flatten(root);
    inorder(root);

return 0;
}