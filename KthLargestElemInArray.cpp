#include<bits/stdc++.h>
using namespace std;

int kthMinElem(vector<int> v, int k){
       priority_queue<int> pq;
       for(int i = 0; i < k ;i ++){
           pq.push(v[i]);
       }
       for(int i = k ; i < v.size(); i ++){
           if(pq.top() > v[i]){
               pq.pop();
               pq.push(v[i]);
           }
       }
    return pq.top();
}
int main(){
    //in cpp, priority queue uses maxHeap
    priority_queue<int> pq;
    vector<int> v;
    v.push_back(-10);
    v.push_back(-20);
    v.push_back(-45);
    v.push_back(-30);
    v.push_back(-68);
    v.push_back(-23);
    v.push_back(-49);
     int n = v.size();
    int k = 7;
     for(int i = 0 ; i < k ; i ++){
         pq.push(v[i]);
     }
     for(int i = k ; i < n ; i ++){
         if(pq.top() > v[i]){
             pq.pop();
             pq.push(v[i]);
         }
     }
     cout << (pq.top()*(-1)) << endl; 
    // cout << kthMinElem(v, k); // here for k min, change the sign of vector elememnts to positive.
return 0;
}