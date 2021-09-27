#include<bits/stdc++.h>
using namespace std;

bool balanceParanthesis(string s){
    stack<char> st;
    // {[()]}
    for(int i = 0; i < s.length() ; i ++){
        if(s[i] == '{' or s[i] == '[' or s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!st.empty() and st.top() == '('){
                st.pop();
            }
            else return false;
            
        }
        else if(!st.empty() and s[i] == ']'){
            if(st.top() == '['){
                st.pop();
            }
            else return false;
            
        }
        else if(!st.empty() and s[i] == '}'){
            if(st.top() == '{'){
                st.pop();
            }
            else return false;
            
        }
    }
    if(!st.empty() and !s.empty()){
       return false;
    }
    else return true;

}
int main(){
    string s = "{[()]}";
     if(balanceParanthesis(s)){
         cout << "Valid string";
     }
     else{
         cout << "Invalid string";
     }
return 0;
}