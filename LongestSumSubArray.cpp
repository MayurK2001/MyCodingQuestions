#include<bits/stdc++.h>
using namespace std;
int longestSumSubArr(int arr[], int n){
       int maxSum = 0; 
       int min = INT_MIN;
       int currSum = 0;
       bool zero = false;
       for(int i = 0 ; i < n ; i ++){
           currSum += arr[i];
           if(currSum > maxSum){
               maxSum = currSum;
           }
           if(arr[i] == 0){
               zero = true;
           }
           if(currSum < 0){
               currSum = 0;
               if( arr[i] > min){
                   min = arr[i];
               }
           }
       }
       if( !zero and maxSum == 0){
           return min;
       }
       else return maxSum;
}
int main(){
    int arr[] = {-5,-4,6,-3,-4,0};
    int n = 6;
    cout << longestSumSubArr(arr, n);
return 0;
}