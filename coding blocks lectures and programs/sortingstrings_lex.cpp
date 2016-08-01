///METHOD -1
/// BY LEXOGRAPHIC SORTING OF STRINGS
#include<iostream>
#include<cstring>
using namespace std;
void rev(char*a,int n)
{
    int i=0,j=n-1;
    while(j>i){
        char temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;j--;
    }
    return ;
}
void swaps(char*a,char*b){
   char temp[100];
   int i;
   for(i=0;a[i]!='\0';i++){
    temp[i]=a[i];
   }
   temp[i]='\0';
   for(i=0;b[i]!='\0';i++){
    a[i]=b[i];
   }
   a[i]='\0';
   for(i=0;temp[i]!='\0';i++){
    b[i]=temp[i];
   }
   b[i]='\0';

    return ;

}
int strcmp(char*a,char*b)
{
    int i=0;
    while(a[i]!='\0' || b[i]!='\0'){
            if(b[i]>a[i]){
                break;
            }
            else if(a[i]>b[i]){
                return 1;
            }
            i++;
    }
    if(b[i]=='\0'){
        return 1;
    }
    return 0;

}
int main ()
{

    char a[10000][100];
    int i,n,j,k,s,l;
    cout<<"enter the number of strings"<<endl;
    cin>>n;

    for(i=1;i<n;i++){
    k=i;
    s=0;
      while(k>0){
         l=k%10;
       k=k/10;

       if(l==1)
        {
            a[i][s]='1';
        }
        else if(l==2)
        {
            a[i][s]='2';
        }
        else if(l==3)
        {
            a[i][s]='3';
        }
        else if(l==4)
        {
            a[i][s]='4';
        }
        else if(l==5)
        {
            a[i][s]='5';
        }
        else if(l==6)
        {
            a[i][s]='6';
        }
        else if(l==7)
        {
            a[i][s]='7';
        }
        else if(l==8)
        {
            a[i][s]='8';
        }
        else if(l==9)
        {
            a[i][s]='9';
        }
        else if(l==0)
        {
            a[i][s]='0';
        }
        s++;
    }
    a[i][s]='\0';
    rev(a[i],strlen(a[i]));
    }

    for(i=0;i<n-1;i++){                            //bubble sort
        for(j=0;j<=n-2-i;j++){
            if(strcmp(a[j],a[j+1])==1){
                swaps(a[j],a[j+1]);
            }
        }
    }
    cout<<"strings after sorting in lexographic manner are:"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<endl;


    return 0;

}

///METHOD -2
/*
#include<iostream>
using namespace std;
void my_function(int n,int temp_num)
{
    for(int i=0;i<=9;i++)
    {
        if(temp_num==0 && i==0)
            continue;
        int temp=10*temp_num+i;
        if(temp <= n)
        {
            cout<<temp<<endl;
            my_function(n,temp);
        }
        else return ;
    }
    return ;
}
int main()
{
    int n;
    cin>>n;
    cout<<"REQUIRED COMBINATIONS ARE:"<<endl;
    my_function(n,0);
    return 0;
}
*/
