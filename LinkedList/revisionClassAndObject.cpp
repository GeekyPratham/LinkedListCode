// #include <iostream>
// using namespace std;
// class Student{
// public:
//     string name;
//     int rno;
//     float marks;
    
//     Student(string name,int rno,float marks){
//         this->name=name;
//         this->rno = rno;
//         this-> marks = marks;

//     }
// };
// void change(Student* ptr){
//     ptr->name="Shivam";

// }
// int main(){
//     Student s("Pratham",26,93.4);
//     Student* ptr = &s;
//     cout<<s.name<<endl;
//     // (*ptr).name="Shivam";
//     // ptr->name = "Shivam";
//     // cout<<s.name<<endl;
//     change(&s);
//     cout<<s.name<<endl;



// }

#include <iostream>
using namespace std;
class Student{
public:
    string name;
    int rno;
    float marks;
    
    Student(string name,int rno,float marks){
        this->name=name;
        this->rno = rno;
        this-> marks = marks;

    }
};
void change(Student* s){
    s->name = "Shivam";
}

int main(){
    Student*s = new Student("Pratham",26,93.4);
  
    cout<<s->name<<endl;
    cout<<s->rno<<endl;
    cout<<s->marks<<endl;
    change(s);
    cout<<s->name<<endl;
  



}