#include<iostream>
#include<cstring>
using namespace std;
void func(char*a,char*sol,int i)
{
   if(a[i]=='\0')
   {
       cout<<sol;
       cout<<endl;
       return ;
   }
   int len;
   len=strlen(sol);
   if(a[i]=='2')
   {
       for(int j=0;j<=2;j++){
        sol[len]=j+'a';
        sol[len+1]='\0';
        func(a,sol,i+1);
       }
   }
   else if(a[i]=='3'){
          for(int j=0;j<=2;j++){
        sol[len]=j+'d';
        sol[len+1]='\0';
        func(a,sol,i+1);
       }
   }
   else if(a[i]=='4'){
        for(int j=0;j<=2;j++){
        sol[len]=j+'g';
        sol[len+1]='\0';
        func(a,sol,i+1);
       }
   }
   else if(a[i]=='5'){
     for(int j=0;j<=2;j++){
        sol[len]=j+'j';
        sol[len+1]='\0';
        func(a,sol,i+1);
       }
   }
   else if(a[i]=='6'){
      for(int j=0;j<=2;j++){
        sol[len]=j+'m';
        sol[len+1]='\0';
        func(a,sol,i+1);
       }
   }
   else if(a[i]=='7'){
        for(int j=0;j<=3;j++){
        sol[len]=j+'p';
        sol[len+1]='\0';
        func(a,sol,i+1);
       }
   }
   else if(a[i]=='8'){
         for(int j=0;j<=2;j++){
        sol[len]=j+'t';
        sol[len+1]='\0';
        func(a,sol,i+1);
       }
   }
   else if(a[i]=='9'){
      for(int j=0;j<=2;j++){
        sol[len]=j+'w';
        sol[len+1]='\0';
        func(a,sol,i+1);
       }
   }
   return ;
}
int main ()
{
    char a[100],sol[100];
    sol[0]='\0';
    cout<<"enter the string:"<<endl;
    cin.getline(a,100);
    cout<<"possible combinations are:"<<endl;
    func(a,sol,0);
    return 0;
}
