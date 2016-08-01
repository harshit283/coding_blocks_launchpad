#include<iostream>
#include<cstring>
using namespace std;
void rev(char*a,int i,int j)
{
    while(j>i)
    {
        char temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;j--;
    }
    return;
}

int main ()
{
    char a[100];
    int i=0;
    int j=0,k,n;
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    n=strlen(a);
    k=n;
    while(n+1)
    {
        if(a[i]==' ' || a[i]=='\t'|| a[i]=='\0')
        {
            rev(a,j,i-1);
            j=i+1;
        }
        i++;n--;
    }
    rev(a,0,k-1);
    cout<<"required string is:"<<endl;
    cout<<a;
    return 0;


}

