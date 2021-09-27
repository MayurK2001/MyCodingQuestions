#include<bits/stdc++.h>
using namespace std;

void reverseSent(string st){
    stack<string> s;
    string temp = "";
    // all the way
    for(int i = 0; i < st.length(); i ++){
        if(st[i] == ' '){
            s.push(temp);
            temp = "";
        }
        else{
            temp = temp+st[i];
        }
    }
    s.push(temp);

    while(!s.empty()){
       string tm = s.top();
       cout << tm << " ";
       s.pop();
    }
cout << endl;
}
int main(){
    string st = "all the way";
    string st2 = "yes bank maximum";
    string st3 = "I am the one";
    reverseSent(st);
    reverseSent(st2);
    reverseSent(st3);
return 0;
}