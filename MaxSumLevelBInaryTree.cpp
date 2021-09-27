#include<bits/stdc++.h>
using namespace std;
  class Node {
      public:
      int data;
      Node *left;
      Node *right;
      Node(int x){
          data = x;
          left = right = NULL;
      }
  };
 

    int maxLevelSum(Node* root)
{
    // Base case
    if (root == NULL)
        return 0;
 
    // Initialize result
    int result = root->data;
 
    // Do Level order traversal keeping track of number
    // of nodes at every level.
    vector<int> v;
    int maxx = INT_MIN;
    int ans = 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        // Get the size of queue when the level order
        // traversal for one level finishes
        int count = q.size();
 
        // Iterate for all the nodes in the queue currently
        int sum = 0;
        while (count--)
        {
            // Dequeue an node from queue
            Node* temp = q.front();
            q.pop();
 
            // Add this node's value to current sum.
            sum = sum + temp->data;
 
            // Enqueue left and right children of
            // dequeued node
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
 
        // Update the maximum node count value
        result = max(sum, result);
        v.push_back(result);
        
    }
     for(int j = 0 ; j < v.size() ; j ++){
         if(v[j] > maxx){
             maxx = v[j];
             ans = j;
         }
     }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(-3);
    root->left->left = new   Node(4);
    root->left->right = new  Node(5);
    root->right->left = new  Node(-6);
    root->right->right = new Node(-7);
     cout << maxLevelSum(root);
return 0;
}