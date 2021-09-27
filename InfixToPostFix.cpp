#include<bits/stdc++.h>
using namespace std;
int precidence(char x){
    if(x == '^'){
        return 3;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    else if(x == '+' || x == '-'){
        return 1;
    }
 else return -1;
}
// (a-b/c)*(a/k-l)
string infixToPostfix(string s){
    stack<char> st;
    string res;
    for(int i = 0; i < s.length(); i ++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
           res += s[i];
        }
        else if( s[i] == '('){
           st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
                
            }
            if(!st.empty()){                                   // (a-b/c)*(a/k-l)
                st.pop();
            }
        }
        else{ // operator
           while (!st.empty() && precidence(st.top()) > precidence(s[i]) ){
               res += st.top();
               st.pop();
           }
          st.push(s[i]);    // ## imp for me.
        }
    }
    while(!st.empty()){
        res+= st.top();
        st.pop();
    }
    return res;
}
int main(){
    string s = "(a-b/c)*(a/k-l)";
    cout << infixToPostfix(s);
return 0;
}