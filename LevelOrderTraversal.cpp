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
vector<vector<int>> LevelOrderTraversalTree(Node* root){
    vector<vector<int>> v;
    if( root == NULL){
        return v;
    }
    vector<int> x;
    vector<int> em;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if( node != NULL){
            x.push_back(node->data);
            if(node->left){
                q.push(node->left);
            }
            if( node->right ){
                q.push(node->right);
            }
        }
        
        else if(!q.empty()){
             v.push_back(x);
            x = em;
            q.push(NULL);
        }
        else {
             v.push_back(x);
            x = em;
            break;
        }
    }
    return v;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);;
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<vector<int>> v = LevelOrderTraversalTree(root);
       for(int i = 0 ; i < v.size () ; i ++){
       for(auto it = v[i].begin(); it != v[i].end(); it++){
           cout << *it << " ";
       }
   }

return 0;
}