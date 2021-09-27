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
vector<int> solve(Node* root){
    // vector contains: isBST, size, min, max
    if(!root) return {1,0,INT_MAX, INT_MIN};
    if(!root->left and !root->right) return {1,1, root->data, root->data};
    vector<int> l = solve(root->left);
    vector<int> r = solve(root->right);
    
    if(l[0] and r[0]){

        if(root->data > l[3] and root->data < r[2]){
            int x = l[2];
            int y = r[3];
            if(x == INT_MAX) x = root->data;
            if(y == INT_MIN) y = root->data;
            return {1,l[1]+r[1]+1,x,y};
        }
    }
    return {0, max(l[1],r[1]), 0,0};
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
    vector<int> ans = solve(root);
    cout << ans[1];
return 0;
}