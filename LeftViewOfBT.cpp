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
void leftView(Node* root){
    
    if(root == NULL){
        return ;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        int n = q.size();
        for(int i = 1 ; i <= n ; i ++){
            Node* temp = q.front();
            q.pop();
         if(temp != NULL) {
             if(i == 1){
              cout << temp->data << " ";
          }
          if(temp->left){
              q.push(temp->left);
          }
          if(temp->right){
              q.push(temp->right);
          }
          }
          else if(!q.empty()){
              q.push(NULL);
          }
        }
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
//    root->left->right->left = new Node(5);
   leftView(root);
   

return 0;
}