#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
    char a[100],b[100];
    int sol1[256]={0};
    int sol2[256]={0};
    int i,j;
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    cout<<"enter the string"<<endl;
    cin.getline(b,100);
    for(i=0;a[i]!='\0';i++)
    {
        j=a[i];
        sol1[j]++;
    }
    for(i=0;a[i]!='\0';i++)
    {
        j=b[i];
        sol2[j]++;
    }
    for(i=0;i<256;i++)
    {
        if(sol1[i]!=sol2[i])
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}
