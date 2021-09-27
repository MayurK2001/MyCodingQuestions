#include<bits/stdc++.h>
using namespace std;
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
vector<int> ans(queries.size(), 0);
int count = 0;
for(int i = 0 ; i < queries.size() ; i ++){
       string curr = queries[i];
       
       for(int j = 0 ; j < strings.size() ;  j ++){
           if(strings[j] == curr){
               count ++;
           }
       }
       ans[i] = count;
       count = 0;
}
return ans;
}

int main(){
    vector<string> v1;
    vector<string> v2;
    v1.push_back("abc");
    v1.push_back("bc");
    v1.push_back("ac");
    v1.push_back("abc");
     
     v2.push_back("abc");
     v2.push_back("bc");
     v2.push_back("bac");
     vector<int> ans = matchingStrings(v1,v2);
     for(int i = 0 ; i < ans.size() ; i ++){
         cout << ans[i] << " ";
     }
  
return 0;
}