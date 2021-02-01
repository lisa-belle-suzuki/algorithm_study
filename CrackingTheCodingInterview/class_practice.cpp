#include <bits/stdc++.h>

using namespace std;

class Student{
public:
    string name;
    int age;
    float height;

    void setData(string name, int age, float height);
};

void Student::setData(string name, int age, float height){
    this->name = name;
    this->age = age;
    this->height = height;
}

int main(){
    Student student;
    student.setData("太郎", 24, 170.2);
    cout << student.age << endl;
    return 0;
}