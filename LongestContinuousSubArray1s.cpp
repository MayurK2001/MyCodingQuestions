#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {0,1,1,0,0,1,1,1,1,0,1};
    int n = 11;
    int i = 0;
    int zc = 0, k = 2;
    int maxLen = 0;
    for(int j = 0; j < n ; j++){
        if(arr[j] == 0){
            zc++;
        }
        while(zc > k){
            if( arr[i] == 0){
                zc--;
            }
            i++;
        }
        if((j-i+1) > maxLen) maxLen = j-i+1;
    }
    cout << maxLen;
return 0;
}