#include<bits/stdc++.h>
using namespace std;
class Stack{
  queue<int> q1;
  queue<int> q2;

  public:
  
  void Push(int x){
      q2.push(x);
     while(!q1.empty()){
         q2.push(q1.front());
         q1.pop();
     }

     queue<int> temp = q1;
     q1 = q2;
     q2 = temp;
  }
  void Pop(){
      q1.pop();
  }
 int Top(){
      return q1.front();
  }
};

int main(){
    Stack s;      // 1 2 3 
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Pop();
    s.Pop();
    s.Push(6);
    s.Pop();
    cout << s.Top();
return 0;
}