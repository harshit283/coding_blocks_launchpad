#include<iostream>
#include<cstring>
using namespace std;
void comb(char *a,char*sol,int n,int i,int k)
{
    if(i==n)
    {
        cout<<sol;
        cout<<endl;
        return ;
    }
    sol[k]=a[i] -'0'+'A';
    sol[k+1]='\0';
    comb(a,sol,n,i+1,k+1);
    if(a[i+1]!='\0')
    {
        int x;
        x=(a[i]-'0')*10+a[i+1]-'0';
        if(x<=25)
        {
            sol[k]=x+'A';
            sol[k+1]='\0';
            comb(a,sol,n,i+2,k+1);

        }
    }
    return ;

}
int main ()
{
    char sol[100];
    char a[100];
    int n,i;
    sol[0]='\0';
    cout<<"enter the string:"<<endl;
    cin.getline(a,100);
    cout<<"all combinations are:"<<endl;
    comb(a,sol,strlen(a),0,0);
    return 0;

}
/*
#include<bits/stdc++.h>
using namespace std;
void comb(char*a,char*sol,int size)
{
    if(*a=='\0')
    {
        for(int i=0;i<size;i++)
            cout<<sol[i]<<" ";
        cout<<endl;
        return ;
    }
    sol[size]=*a-'0'+65; /// one at a time
    comb(a+1,sol,size+1);
    if(*(a+1)=='\0')                /// two at a time
        return ;
    int value=*a-'0';
    value=value*10+*(a+1)-'0';
    if(value >=0 && value <=25)
    {
        sol[size]=value+65;
        comb(a+2,sol,size+1);
    }
    return ;
}
int main()
{
    char a[100];
    cin.getline(a,100);
    char sol[100];
    cout<<"ALL POSSIBLE COMBINATIONS ARE:"<<endl;
    comb(a,sol,0);
    return 0;
}

*/
