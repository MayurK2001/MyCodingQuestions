#include<bits/stdc++.h>
using namespace std;
class Complex{
   private:
    int real;
    int img;
     public:
    Complex(int r, int i){
       real = r;
       img = i;
    }
   
     Complex operator + (Complex const &obj){
           Complex res(0,0);
           res.img = img + obj.img;
           res.real = real + obj.real;
           return res;
    }
     void print(){
        cout << "out fun of operator overloading is called and result is:"<< endl;
        cout << real << " +"<< " i" << img;
    }
};
class overriding{
    public:
   virtual void fun(){
        cout << "this is a base class" << endl;
    }
};
class override: public overriding{
public:
void fun(){
    cout << "this is a derived class" << endl;
}
};
int main(){
//  Complex c1(4, 3);
//  Complex c2(3,6);
//  Complex c3 = c1 + c2;
//  c3.print();
overriding *o;
override oe;
o = & oe;
o->fun();


 return 0;
 }