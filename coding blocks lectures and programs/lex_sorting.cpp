#include<iostream>
using namespace std;
void swap(char *a,char*b)
{
    char c[100];
    int i=0;
    while(a[i]!='\0')
    {
        c[i]=a[i];
        i++;
    }
    c[i]='\0';
    i=0;
    while(b[i]!='\0')
    {
        a[i]=b[i];
        i++;
    }
    a[i]='\0';
    i=0;
    while(c[i]!='\0')
    {
        b[i]=c[i];
        i++;
    }
    b[i]='\0';
    return ;
}

bool is_greater(char*a,char*b)
{
    int i=0;
    while(a[i]!='\0' && b[i]!='\0')
    {
        if(b[i] > a[i])
         return false;
         else if(a[i] > b[i])
            return true;
         i++;
    }
    if(a[i]=='\0' && b[i]=='\0')
        return false;
    else if(a[i]!='\0')
        return true;
    else return false;

}
int main()
{
    char str[100][100];
    int n;
    cin>>n;
    cin.get();
    cout<<"enter the strings"<<endl;
    for(int i=0;i<n;i++)
    {
        cin.getline(str[i],100);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n-2-i;j++)
        {
            if(is_greater(str[j],str[j+1]))
                swap(str[j],str[j+1]);
        }
    }

    cout<<"STRINGS IN LEXOGRAPHICAL ORDER ARE:"<<endl;
    for(int i=0;i<n;i++)
        cout<<str[i]<<endl;
    return 0;
}
