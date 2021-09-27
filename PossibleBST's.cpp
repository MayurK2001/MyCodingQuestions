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
vector<Node*> bsts(int st, int en){
    vector<Node*> trees;
    if(st > en) {
        trees.push_back(NULL);
        return trees;
    }
    for(int i = st; i  <= en ; i ++){
        vector<Node*>leftSubtree = bsts(st, i-1);
        vector<Node*>rightSubtree = bsts(i+1, en);
        for(int j = 0 ; j < leftSubtree.size() ; j ++){
            Node* left = leftSubtree[j];
            for(int k = 0 ; k < rightSubtree.size() ; k ++){
                Node* right = rightSubtree[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int st = 1; int en = 2;
    vector<Node*> res = bsts(st, en);
    for(int i = 0 ; i < res.size() ; i ++){
        cout << (i+1) << " : ";
        preorder(res[i]);
        cout << endl;
    }
return 0;
}