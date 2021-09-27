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
bool checkForBST(Node* root, int min, int max){
    if(root == NULL) return true;
    if(root->data <= min or root->data >= max) return false;
    return (checkForBST(root->left, min, root->data) and checkForBST(root->right, root->data, max));
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
  cout << checkForBST(root, INT_MIN, INT_MAX) << endl;
    Node* root2 = new Node(7);
    root2->left = new Node(2);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);
    root2->right = new Node(9);
    root2->right->left = new Node(8);
    root2->right->right = new Node(10);
    cout << checkForBST(root2, INT_MIN, INT_MAX);

return 0;
}   