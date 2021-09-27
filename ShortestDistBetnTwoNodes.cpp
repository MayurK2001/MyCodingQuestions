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
Node* LCA(Node* root, int n1, int n2){
    if(!root) return NULL;
    if(root->data == n1 or root->data == n2){
        return root;
    }
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    
    if(left and right) return root;
    if(!left and !right) return NULL;
    if(left) return left;
    else return right;
}
int findDist(Node* root, int k , int dist){
    if(root == NULL){
        return -1;
    }
    if(root->data == k) return dist;
    int left = findDist(root->left, k, dist+1);
    if(left != -1) return left;
    return findDist(root->right, k, dist +1);
}
int DistBetnTwoNodes(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1,n2);
    int d1 = findDist(lca, n1,0);
    int d2 = findDist(lca, n2, 0);

    return d1+d2;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(10);
    cout << DistBetnTwoNodes(root, 10,7) ;
    
return 0;
}