#include<iostream>
#include<cstring>
using namespace std;
class student{
    int marks;
    int age;
    char *name;
    const int member;

public:

    student():marks(0),age(0),member(0),name("xyz")
    {


    }
    student(const char*ptr) :marks(0),age(0),member(10)
    {
        int len=strlen(ptr);
        name=new char[len+1];
        strcpy(name,ptr);

    }
    student(const char*ptr,int data) :marks(0),age(data),member(20)
    {
        int len=strlen(ptr);
        name=new char[len+1];
        strcpy(name,ptr);

    }
    student (const student&s):age(s.age),marks(s.marks),member(s.member)
    {
        if(s.name==0)
        {
            return ;
        }
        delete name;
        int len=strlen(s.name);
        name=new char[len+1];
        strcpy(name,s.name);
        return ;

    }
    void readinfo()
    {
        char temp[100];
        cout<<"enter the name:"<<endl;
        cin.getline(temp,100);
        if(name!=0)
        {
           delete name;

        }
        int len=strlen(temp);
           name=new char[len+1];
        strcpy(name,temp);
        cout<<"enter the age:"<<endl;
        cin>>age;
        cout<<"enter the marks:"<<endl;
        cin>>marks;

    }
    void printdata()const
    {
        cout<<"name of the student is:"<<endl;
        cout<<name;
        cout<<endl;
        cout<<"age of student is:"<<endl;
        cout<<age;
        cout<<endl;
        cout<<"marks of student is"<<endl;
        cout<<marks;
    }

    bool setname(const char*newname)
    {
        if(strlen(newname)<3)
        {
            return false;
        }

        delete name;
        int len=strlen(newname);
        name=new char [len+1];
        strcpy(name,newname);
        return true;
    }

    const char *getname()
    {
        return name;
    }


    ~student()
    {
        if(name!=0)
        {
            delete name;
        }
    }


};
int main()
{ /*
    student s;
    s.readinfo();
    s.printdata();
    student s2("harshit");
    cout<<endl<<s2.getname()<<endl;

    student s3("harshit",18);
    s3.setname("ab");
    cout<<s3.getname()<<endl;
    s3.setname("aggarwal");
    cout<<s3.getname();
    cout<<endl;
   student s4(s2);
    s4.printdata();
    */
    student s;
    s.readinfo();
    s.printdata();

    return 0;
}
