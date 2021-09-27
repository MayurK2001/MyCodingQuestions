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
vector<vector<int>> zigzag(Node* root){
   
    vector<vector<int>> v;
    vector<int> em;
     if(root == NULL) return v;
    
   stack<Node*> cl;
   stack<Node*> nl;
   stack<Node*> e;
   cl.push(root);
   bool ltr = true;
   while(!cl.empty()){
       vector<int> x;
       while(!cl.empty()){ 
           Node* curr = cl.top();
           cl.pop();
           x.push_back(curr->data);
        //    cout << curr->data << " ";
          if(ltr) {
               if(curr->left){
               nl.push(curr->left);
           }
           if(curr->right){
               nl.push(curr->right);
           }
        }
        else{
              if(curr->right){
               nl.push(curr->right);
           }
             if(curr->left){
               nl.push(curr->left);
           }
        }
       }
       v.push_back(x);
       ltr = !ltr;
        cl = nl;
        nl = e;
        x = em;
   }
   return v;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
   vector<vector<int>> v = zigzag(root);
   for(int i = 0 ; i < v.size () ; i ++){
       for(auto it = v[i].begin(); it != v[i].end(); it++){
           cout << *it << " ";
       }
   }

   
return 0;
}