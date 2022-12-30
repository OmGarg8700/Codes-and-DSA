#include<iostream>
#include<string>
using namespace std;

class new_student{
    public:
    int a = 5; 
};

class derived_student{
    public:
    string a;

    void newfun(){
        cout<<"Calling the function from derived class!!"<<endl;
    }
    void myfun(){
        cout<<"This is from derived class"<<endl;
    }
};

class Student : public derived_student, public new_student{             // including two or more classes
    public:
    string name;   
    string gender;
    int age;

    Student(string a, string b, int c){
        name = a, gender = b, age = c;
    }

    Student(){
        // cout<<"Default Constructor";
    };

    Student(Student &a){
        name = a.name;
        gender = a.gender;
        age = a.age;
    }

    ~Student(){
        cout<<"Destructor called"<<endl;
    }

    void ObjectInfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;
    }

    bool operator == (Student &a){
        if(name == a.name && age == a.age && gender == a.gender){
            return true;
        }
        return false;
    }
};

int main(){
    // Student a("Om", "male", 12);
    // Student b;
    // b.name = "Shivam";
    // b.age = 5;
    // b.gender = "male";
    // a.ObjectInfo();
    // b.ObjectInfo();
    // Student c(a);
    // c.ObjectInfo();
    // bool d = (c==a);
    // cout<<d;

    Student a("Harry", "male", 15);
    a.myfun();
    
    // this is multiple inheritence and polymorphism
    

    return 0;
}