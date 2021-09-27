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

int search(int in[], int st, int en, int curr){
    for(int i = st ; i <= en ; i ++ ){
        if( in[i] == curr){
            return i;
        }
    }
    return -1;
}
Node* TreeFromPostIn(int post[], int in[], int st, int en){
    static int ind = en;
    if(st > en){
        return NULL;
    }
    
    int curr = post[ind];
    ind--;
    Node* node = new Node(curr);
    if(st == en){
        return node;
    }
    int posn = search(in, st, en, curr);
    node->right = TreeFromPostIn(post, in, posn+1, en);
    node->left = TreeFromPostIn(post, in, st, posn-1);
 return node;

}
void printInorder(Node* root){
    if( root == NULL){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right); 
}


int main(){
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};
    Node* root = TreeFromPostIn(postorder, inorder, 0,4);
    printInorder(root);
return 0;
}