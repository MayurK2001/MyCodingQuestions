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

void SumReplacement(Node* root){
     if(root == NULL){
         return ;
     }
     SumReplacement(root->left);
     SumReplacement(root->right);
    if(root->left){
        root->data += root->left->data;
    }
    if(root->right){
        root->data += root->right->data;
    }
}
void inorder(Node* root){
    if(root == NULL)return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    root->right->right = new Node(5);
    SumReplacement(root);
    inorder(root);
return 0;
}
/*              1
               / \
              2   3
             / \  /\
            4   5 6 7
*/
            
