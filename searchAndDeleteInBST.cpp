#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left; Node* right;
    Node(int data){
      this->data = data;
      left = right = NULL;
    }
};
bool searchInBST(Node* root, int x){
    bool ans = false;
    if(root == NULL) {
        return false;
    }
    if(root->data == x){
        return true;
    }
    if(x > root->data){
        ans = searchInBST(root->right, x);      
    }
    else{
        ans = searchInBST(root->left, x);
    }
    return ans;
}
Node* InorderSucc(Node* root){
    Node* curr = root;
    while(curr and curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
Node* deleteFromBST(Node* root, int key){
  if(key < root->data){
       root->left = deleteFromBST(root->left, key);
  }
  else if(key > root->data){
      root->right = deleteFromBST(root->right, key);
  }
  else{
      if(root->left == NULL){
          Node* temp = root->right;
          free(root);
          return temp;
      }
      else if(root->right == NULL){
          Node* temp = root->left;
          free(root);
          return temp;
      }
      Node* temp = InorderSucc(root);
     root->data = temp->data;
     root->right = deleteFromBST(root->right, temp->data);
  }
  return root;
}
Node* insertInBST(Node* root, int data){
    if( root == NULL){
        return new Node(data);
    }
    if( data > root->data){
        root->right = insertInBST(root->right, data);
    }
    else{
        root->left = insertInBST(root->left, data);
    }
    return root;
}
void inorder(Node* root){
    if(root == NULL) return ;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    Node*root = NULL;
    root = insertInBST(root, 6);
    insertInBST(root,5);
    insertInBST(root,10);
    insertInBST(root,3);
    insertInBST(root,4);
    insertInBST(root,1);
    insertInBST(root,2);
    insertInBST(root,8);
    insertInBST(root,7);
    insertInBST(root,9);
inorder(root);
cout << endl;
root = deleteFromBST(root, 5);
inorder(root);

return 0;
}