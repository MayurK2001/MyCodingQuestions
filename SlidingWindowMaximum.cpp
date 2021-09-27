#include<bits/stdc++.h>
using namespace std;
 void slidingWindowMax(int arr[], int k, int n){
   if(n <= 1) return ;
   deque<int> dq;
   int sol[n-k+1];
   int i = 0;
   for(; i < k ; i ++){                  // eg.arr[]= 2 1 6 3 4 -7 8 6 ,n=8,k=3 sol.size=n-k+1=8-3+1=6
       while(!dq.empty() and arr[dq.back()] <= arr[i]){
           dq.pop_back();
       }
       dq.push_back(i);
   }
   for( ; i < n ; i++){
       sol[i-k] = arr[dq.front()];
       while(!dq.empty() and dq.front() <= i-k){
           dq.pop_front();
       }
      while(!dq.empty() and arr[dq.back()] <= arr[i]){
           dq.pop_back();
       }
       dq.push_back(i);
   }
    sol[i-k] = arr[dq.front()];
    for(i = 0 ; i < n-k+1; i ++){
        cout << sol[i] << " ";
    }
}
int main(){
    
  int arr[] = {1,3,-1,-3,5,3,6,7};
  int n = 8;
 slidingWindowMax(arr, 3, n);
return 0;
}