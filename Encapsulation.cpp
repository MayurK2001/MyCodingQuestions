// encapsulation is to hide sensitive data from user.
#include<bits/stdc++.h>
using namespace std;
//hierarchical inheritance:

class A{
    public:
    int rollno;
    string name;
    bool gender;
};
class B: public A{

};
class C: public A{

};
class D: public B{

};
class E: public B{

};
class F: public C{

};
class G: public C{

};
int main(){
 C c;
 c.name = "level 2 2";
 c.gender = 1;
 c. rollno = 34;
 
}