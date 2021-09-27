#include<bits/stdc++.h>
using namespace std;
void slidingwin(int arr[], int n, int k){
   if(n <= 1) return;
priority_queue<int>pq;
int sol[n-k+1];
int i = 0;
for( ; i < n ; i ++){
    for(int j = 0 ; j < k ; j ++){
        pq.push(arr[i+j]);
    }
    sol[i] = pq.top();
    for(int j = 0 ; j < k ; j ++){
        pq.pop();
    }
}
for(int e: sol){
    cout << e << " ";
}
}
int main(){
 int a = 9;
int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
slidingwin(arr, a, 3);
 
return 0;
}