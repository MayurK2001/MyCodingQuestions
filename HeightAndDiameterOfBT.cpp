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
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightOfBT(root->left);
    int rightHeight = heightOfBT(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int diameterOfBT(Node* root){  // O(n^2)
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightOfBT(root->left);
    int rightHeight = heightOfBT(root->right);
    int currDiameter = leftHeight+rightHeight+1;
    int leftDiam = diameterOfBT(root->left);
    int rightDiam = diameterOfBT(root->right);
    return max(currDiameter, max(leftDiam, rightDiam));
}
int heightSuperb(Node* root, int &d){ // O(n)
    
    if(root == NULL)return -1;
    int lh = heightSuperb(root->left, d);
    int rh = heightSuperb(root->right,d );
    d = max(d, lh+rh+2);
    return max(lh,rh)+1;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->left->right = new Node(10);
    // cout << heightOfBT(root);
    cout << diameterOfBT(root) << endl;
    int d = 0;
    heightSuperb(root, d);
    cout << d;
return 0;
}