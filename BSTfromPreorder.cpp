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

Node* ConstructBST(int arr[], int* preorderIdx, int key, int min, int max, int n){
    if(*preorderIdx >= n){
        return NULL;
    }
    Node* root = NULL;
    if(key > min and key < max){
         root = new Node(key);
       *preorderIdx = *preorderIdx + 1;
       if(*preorderIdx < n){
           root->left = ConstructBST(arr, preorderIdx, arr[*preorderIdx], min, key, n);
       }
       if(*preorderIdx < n){
           root->right = ConstructBST(arr, preorderIdx, arr[*preorderIdx], key , max, n);
       }
    }
    return root;
}	
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    int arr[] = {7,5,2,6,8,9};
    int n = 6;
    int preorderIdx = 0;
   Node* root = ConstructBST(arr, &preorderIdx, arr[preorderIdx], INT_MIN, INT_MAX, n);
   inorder(root);
return 0;
}