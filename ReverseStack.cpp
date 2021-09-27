#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int topElem){
if(st.empty()){
    st.push(topElem);
    return;
}
    int top = st.top();
    st.pop();
    insertAtBottom(st, topElem);
    st.push(top);
}
void reversal(stack<int> &st){
if(st.empty()){
    return;
}
    int topElem = st.top();
    st.pop();
    reversal(st); // here all elements (except top elem) goes to call stack.
    insertAtBottom(st, topElem);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reversal(st);
    while(!st.empty()){
        cout << st.top() << " " ;
        st.pop();
    }
return 0;
}