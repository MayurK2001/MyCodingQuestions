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
bool isIdentical(Node* roota, Node* rootb){
    if(!roota and !rootb){
        return true;
    }
    else if((!roota and rootb) or (roota and !rootb)){
        return false;
    }
    if(roota->data != rootb->data) return false;
    
     else{
         bool checkrootd = (roota->data == rootb->data);
        bool lst = isIdentical(roota->left, rootb->left);
        bool rst = isIdentical(roota->right, rootb->right);
  return checkrootd and lst and rst;
    }
    return false;
}   
int main(){
    Node* root1 = new Node(6);
    root1->left = new Node(5);
    root1->right = new Node(4);
    Node* root2 = new Node(6);
    root2->left = new Node(5);
    root2->right = new Node(4);
    // root2->right->right = new Node(3);

    if(isIdentical(root1, root2)){
        cout << "BST's are identical";
    }
    else cout << "BST's are not identical";
return 0;
}