#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "abbabccb";
    vector<int> v(256,-1);
    int maxLen = 0, st = -1;
     
    for(int i = 0; i < s.length() ; i ++){
        if(v[s[i]] > st)
            st = v[s[i]];
        v[s[i]] = i;
        maxLen = max(maxLen, i-st);
    }
    cout << maxLen << endl;
  
    
return 0;
}