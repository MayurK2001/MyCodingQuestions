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
int heightOfBT(Node* root){
    if(root == NULL) return 0;
    int lh = heightOfBT(root->left);
    int rh = heightOfBT(root->right);
    return max(lh, rh) +1;
}
bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }
    if(!isBalanced(root->left)) return false;
    if(!isBalanced(root->right)) return false;
    int ls = heightOfBT(root->left);
    int rs = heightOfBT(root->right);
    if(abs(ls-rs) <= 1){
        return true;
    }
    else return false;

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << isBalanced(root);
return 0;
}