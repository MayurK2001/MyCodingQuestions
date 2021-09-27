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
int search(int in[], int st, int en , int curr){
    for(int i = st; i <= en ; i ++){
        if( in[i] == curr){
            return i;
        }
    }
    return -1;
}
Node* buildTreePreIn(int pre[], int in[], int st, int en){
  static int ind = 0;
    if( st > en){
        return NULL;
    }
    int curr = pre[ind];
    ind++;
    int posn = search(in, st, en, curr);
    Node* node = new Node(curr);
    if(st == en){
        return node;
    }
     node->left = buildTreePreIn(pre, in, st, posn-1);
     node->right = buildTreePreIn(pre, in , posn+1, en);
     return node;
}
void LevelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            cout << node->data << " ";
            if(node->left){
                q.push(node->left);
               
            }
             if(node->right){ 
                 q.push(node->right);
            }  
            
        }
        else if(!q.empty()){
         
            q.push(NULL);
        }
    }
}

int main(){
    int preorder[] = {1,2,3,4,5};
    int inorder [] = {2,1,4,3,5};
    Node* root = buildTreePreIn(preorder, inorder, 0, 4);
    LevelOrderTraversal(root);
return 0;
}