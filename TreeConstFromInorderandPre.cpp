#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data =data;
        left = right = NULL;
    }
};
int search(int inorder[], int st, int en, int curr){
    for(int i = st ; i <= en ; i ++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}
Node* ConstructFromInorderAndPreorder(int preorder[], int inorder[], int start, int end){
    static int ind = 0;
    if( start > end){
        return NULL;
    }
    int curr = preorder[ind];
    ind++;
    int posn = search(inorder, start, end, curr);
    Node* node = new Node(curr);
    if(start == end){
        return node;
    }
    node->left = ConstructFromInorderAndPreorder(preorder, inorder, start, posn-1);
    node->right = ConstructFromInorderAndPreorder(preorder, inorder, posn+1, end);
 return node;
}
void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
void printPostOrder(Node* root){
    if(root == NULL){
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


int main(){
    int preorder[] = {3,9,20,15,7};
    int inorder [] = {9,3,15,20,7};
    Node* root = ConstructFromInorderAndPreorder(preorder, inorder, 0, 4);
    printInorder(root);
    cout << endl;
    printPostOrder(root);

return 0;
}