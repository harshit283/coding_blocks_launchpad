#include<iostream>
#include<cstring>
using namespace std;
class Student {
    int age;
    char *name;
    int marks;
    const int constmember;
    public:
    Student():age(0), marks(0), constmember(10),name("abcd")
    {
        cout << "Constructor Called" << endl;
    }
    Student(const char * n): age(0), marks(0), constmember(5)
    {
        cout << "Other Constructor Called" << endl;
        int len = strlen(n);
        name = new char[len+1];
        strcpy(name, n);

    }
    Student(const char *n, int a):age(a),marks(0),constmember(0) {
        cout <<"Third constructor called" << endl;
        int len = strlen(n);
        name = new char[len+1];
        strcpy(name, n);
    }
    Student(const Student &B): age(B.age),marks(B.marks),constmember(B.constmember){   //if default copy constructor was used then it would have produced shallow copy not the
                                                                                      //deep copy that is it wont create new nodes like we have did
        int len = strlen(B.name);
        name = new char[len+1];
        strcpy(name, B.name);
    }
    ~Student( ) {                      //destructor
        if (name != 0) {
            delete name;
        }
    }
    void readInfo() {
        char temp[100];
        cout << "Enter Name ";
        cin.getline(temp, 100);
        int len = strlen(temp);
        if (name != 0) {
            delete name;
        }
        name = new char[len+1];
        strcpy(name, temp);
        cout << "Enter Age ";
        cin >> age;
        cout << "Enter Marks ";
        cin >> marks;
        return;
    }
    void printInfo() {
        cout << name << endl;
        cout<< "Age : " << age << endl;
        cout << "Marks : " << marks << endl;
        return;
    }
    bool setName(const char * newname) {
        if (strlen(newname) < 3) {
            return false;
        }
        if (name != 0) {
            delete name;
        }
        name = new char[strlen(newname) + 1];
        strcpy(name, newname);
        return true;
    }
    const char * getName() {
        return name;
    }
    const int & getAge() {
        return age;
    }
};
int main() {

   /* Student S("Anushray");
    cout << sizeof(Student) << endl;
    cout << sizeof(S) << endl;
    Student S2 = S;//student s2(s);
    S.setName("Ankush");
    cout << S2.getName() << endl;


  /*  cout << "------- " << endl;
    Student * ptr = new Student("Ankush", 25);
    cout << "--------" << endl;
    S2.printInfo();
    S.printInfo();
    ptr->printInfo();*/
/*
    S.printInfo();
//    S.initialize();
    S.printInfo();
/*    Student *ptr = new Student;
    S.readInfo();
    cout << S.getName() << endl;
    const char * ptr = S.getName();
    *ptr = 'a';
    *(ptr+1) = 'b';
    *(ptr+2) = 0;*/
//    cout << S.getName() << endl;
/*
    S.printInfo();
    S.setName("Ab");
    S.printInfo();
    S.setName("Ankush");
    S.printInfo();
    */

/*    (*ptr).readInfo();
    ptr->printInfo();*/

    Student s;
    cout<<s.getName();
    Student s2("harshit");
    cout<<s2.getName();

    return 0;
}
