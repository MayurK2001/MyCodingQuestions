#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
    Node(int val, Node* left, Node* right){
        data = val;
        this->left = left;
        this->right = right;
    }
};
int NoOfNodesInTree(Node* root){
    
    if(root == NULL) return 0;
    return NoOfNodesInTree(root->left)+NoOfNodesInTree(root->right) + 1;
}
int SumOfNodesAtkthPosition(Node* root, int k){
    if(root == NULL){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
             if(level == k){
          sum += node->data;
        }
            if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
       
     }
     else if(!q.empty()){
         q.push(NULL);
         level++;
     }
    }
    return sum;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3, NULL, NULL);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // cout << NoOfNodesInTree(root);
    cout << SumOfNodesAtkthPosition(root, 2);

return 0;
}