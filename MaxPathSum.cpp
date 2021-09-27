#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
int maxPathSumUtil(Node* root, int &ans){
    if(root == NULL) return 0;
    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);
    int ms = max(max(left, right)+root->data, root->data);
    int m21 = max(ms, left+right+root->data);
    ans = max(m21, ans);
    return m21;
}

int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(-12);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(-6);
    cout << maxPathSum(root);
return 0;
}

