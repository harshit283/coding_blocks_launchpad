#include<iostream>
using namespace std;
int len(char*a)
{
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    return i;

}
bool check(char*a,char*b)
{
    int m=len(a),n=len(b),i;
    if(m!=n)
    {
        return false;
    }

    for(i=0;i<m;i++)
    {
        if(a[i]!=b[i])
        {
            return false;
        }
    }
        return true;


}
bool searchword(char a[][100],char b[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        j=check(a[i],b);
        if(j==1){
            return true;
        }
    }
    return false;

}
int main()
{
   char a[100][100],b[100];
   int i,n;


   cout<<"enter the number of strings";
   cin>>n;
   cin.get();
   cout<<"enter the strings"<<endl;
   for(i=0;i<n;i++)
   {
       cin.getline(a[i],100);
       cout<<endl;
   }

   cout<<"enter the word you want to search"<<endl;
   cin.getline(b,100);
   i=searchword(a,b,n);
   if(i==0)
   {
       cout<<"word not found";
   }
   else{
    cout<<"word found";
   }

   return 0;
}
/*
#include<iostream>
#include<cstring>
using namespace std;
bool check(char*a,char *b)
{
    if(strlen(a)!=strlen(b)){
        return false;
    }
    else{
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
    }

}
int main ()
{
    char a[100][100],b[100];
    int i,n;
    cout<<"enter the number of strings"<<endl;
    cin>>n;
    cin.get();
    for(i=0;i<n;i++)
    {
        cin.getline(a[i],100);
    }
    cout<<"enter the word"<<endl;
    cin.getline(b,100);


    for(i=0;i<n;i++)
    {
        if(check(a[i],b)){
            cout<<"found";
            return 0;
        }
    }
    cout<<"not found";
    return 0;
}
