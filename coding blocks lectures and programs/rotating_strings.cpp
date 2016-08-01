#include<iostream>
using namespace std;
int len(char*a){
int i=0;
while(a[i]!='\0'){
    i++;
}
    return i;
}

void rev(char *a,int n,int k)
{
    int i=0,j=n-1;
    char temp;
    while(j>=i){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;j--;
    }

    i=n,j=k-1;
    while(j>=i){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;j--;
    }


    i=0,j=k-1;
    while(j>=i){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;j--;
    }
    cout<<"rotated string is:-";
    cout<<a;
}
int main ()
{
    char a[100];
    int i,k,n;
    cout<<"enter the array:-";
    cin.getline(a,100);
    cout<<"enter the number";
    cin>>k;
    n=len(a);
    rev(a,n-k,n);
}

///METHOD 2
///SHIFTING
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100];
    cin.getline(a,100);
    int k;
    cin>>k;
    int n=strlen(a);
    int i=n-k;
    int j=1;
    int l;
    while(i<=n-1)
    {
       l=i;
       char ch=a[i];
       while(l>=j)
       {
           a[l]=a[l-1];
           l--;
       }
       a[l]=ch;
       i++;j++;
    }
    cout<<a;

    return 0;
}
*/
