#include<iostream>
using namespace std;
bool func(char*a,char*b,char*c)
{
    if(*c=='\0' && *b=='\0' && *a=='\0')
         return true;
    else if(*c=='\0')
        return false;
    else if(*c==*a && *c==*b)
        return (func(a+1,b,c+1) ||  func(a,b+1,c+1));
    else if(*c==*a)
        return func(a+1,b,c+1);
    else if(*c==*b)
        return func(a,b+1,c+1);
    return false;
}
int main ()
{
    char a[100],b[100],c[100];
    cout<<"enter the first string"<<endl;
    cin.getline(a,100);
    cout<<"enter the second string"<<endl;
    cin.getline(b,100);
    cout<<"enter the third string"<<endl;
    cin.getline(c,100);
    if(func(a,b,c))
          cout<<"yes";
    else
        cout<<"no";

    return 0 ;
}
