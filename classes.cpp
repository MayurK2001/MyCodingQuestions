#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    int age;
    string name;
    bool gender;
    Student(int age, string name, bool gender){
          this->age = age;
          this->name = name;
          this->gender = gender;
    }
    void setName(string name){
        this->name = name;
    }
    void getName(){
        cout << "name is : " << name << endl;
    }
    Student(Student &x){
           cout << "copy constructor" << endl;
           age = x.age;
           name = x.name;
           gender = x.gender;
    }
    void print(){
        cout << "age = " << age << "," << "name = " << name << "," << "gender = " << gender << endl;
    }
};

int main(){
  Student s(15, "pr", 1);
  s.print();
 Student b(s);
 b.print();
 b.setName("aayush");
 cout << "after setting the name" << endl;
 cout << "The name is: "  << endl;
  b.getName();
 b.print();

    return 0;
}