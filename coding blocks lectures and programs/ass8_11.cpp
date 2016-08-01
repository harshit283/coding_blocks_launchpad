#include<iostream>
using namespace std;

void convertpi(char*a,char*b)
{
   if(*a=='\0'){
        *b='\0';
    return ;
   }
   else{
    if(*a=='p' && *(a+1)=='i'){
        *b='3';
        *(b+1)='.';
        *(b+2)='1';
        *(b+3)='4';
         convertpi(a+2,b+4);
    }

    else{
        *b=*a;
        convertpi(a+1,b+1);
    }
   }
}
int main()
{
    char a[100],b[100];
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    convertpi(a,b);
    cout<<"required string is:"<<endl<<b;
    return 0;
}
