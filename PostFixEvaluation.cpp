#include<bits/stdc++.h>
using namespace std;
int power(int a, int b){
    int ans = 1;
    for(int i = 1; i <= b; i ++){
            ans *= a;
    }
    return ans;
}
int postFixEvaluation(string s){
   stack<int> st;
   for(int i = 0 ; i < s.length() ; i ++){
         if(s[i] >= '0' && s[i] <= '9'){
             st.push(s[i] - '0');
         }
         else{
             int b = st.top();
             st.pop();
             int a = st.top();
             st.pop();
             switch (s[i])
             {
             case '+':
                 st.push(a+b);
                 break;
             case '-':
                 st.push(a-b);
                 break;
             case '*':
                 st.push(a*b);
                 break;
             case '/':
                 st.push(a/b);
                 break;
             case '^':
                 st.push(power(a,b));
                 break;
             
             }
         }
    
   }
   return st.top();
}


int main(){
    string s = "32+2^3+9-32^+";
    cout << postFixEvaluation(s);
    
    
return 0;
}