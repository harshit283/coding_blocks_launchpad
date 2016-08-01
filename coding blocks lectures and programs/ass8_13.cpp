#include<iostream>
using namespace std;
void removex(char*a,char*b)
{
    if(*a=='\0'){
            *b='\0';
        return ;
    }
    else if(*a!='x'){
            *b=*a;
            removex(a+1,b+1);
        }
    else if(*a!='\0'){
        removex(a+1,b);
    }

    }
int main()
{
    char a[100],b[100];
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    removex(a,b);
    cout<<"answer is:"<<endl<<b;
    return 0;

}
