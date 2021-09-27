#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
    int data;
    Node* left;
    Node* right;
    Node( int data){
        this->data = data;
        left = right = NULL;
    }
};
Node* insertBST(Node* root, int data){
    if(root == NULL){
        return new Node(data);
    }
    if(data > root->data){
        root->right = insertBST(root->right, data);
    }
    else{
        //ie. if data < root->data
        root->left = insertBST(root->left, data);
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}
int main(){
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 2);
    insertBST(root, 9);
    insertBST(root, 7);
    inorder(root);

return 0;
}