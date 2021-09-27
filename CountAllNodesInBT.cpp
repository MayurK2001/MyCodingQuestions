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
int NoOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return NoOfNodes(root->left) + NoOfNodes(root->right) + 1;
}
int sumOfAllNodeData(Node* root){
    if(root == NULL){
        return 0;
    }
    return sumOfAllNodeData(root->left) + sumOfAllNodeData(root->right) + root->data;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // cout << NoOfNodes(root);
    cout << sumOfAllNodeData(root);
return 0;
}