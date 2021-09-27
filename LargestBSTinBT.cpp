#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
struct Info{
int size;
int max;
int min;
int ans;
bool isBST;
};
Info largestBSTinBT(Node* root){
   if(!root) return {0, INT_MIN, INT_MAX, 0, true};
   if(!root->left and !root->right) return {1,root->data, root->data, 1, true};
   
   Info leftInfo = largestBSTinBT(root->left);
   Info rightInfo = largestBSTinBT(root->right);
   int sum = 0;
   Info curr;
   curr.size = 1+leftInfo.size+rightInfo.size;
   if(leftInfo.isBST and rightInfo.isBST and (leftInfo.max < root->data and rightInfo.min > root->data)){
       sum += root->data;
       curr.min = min(leftInfo.min, root->data);
       curr.max = max(rightInfo.max, root->data);
       curr.ans = curr.size;
       curr.isBST = true;
       return curr;
   }
   curr.ans=  max(leftInfo.ans, rightInfo.ans);
   curr.isBST = false;
   return curr;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(6);
    if(largestBSTinBT(root).isBST){
        cout << "largestBST size is " << largestBSTinBT(root).ans;
    }
    else{
        cout << largestBSTinBT(root).ans;
    }
return 0;
}