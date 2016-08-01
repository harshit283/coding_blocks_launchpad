///METHOD 1
///O(N)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[1000];
    cin.getline(a,1000);
    int i=0;
    int pos=0;
    int count=0;
    while(a[i]!='\0')
    {
       if(a[i]!=' ' && a[i]!='\t')
       {
           count++;
           a[pos]=a[i];
           pos++;
       }
       i++;
    }
    a[count]='\0';
    cout<<a;
    return 0;
}
///METHOD2
///O(N^2)
/*
#include<iostream>
using namespace std;
int len(char *a){
 int i=0;
 while(a[i]!='\0'){
    i++;
 }
return i;

}

void squeeze(char *a){
    int i,n,k;
    n=len(a);
    for(i=0;i<n;i++){
        if(i<=n-2){
            if(a[i]=='\t' || a[i]==' '){
                for(k=i;k<=n-2;k++){
                    a[k]=a[k+1];
                }
                n--;i--;
            }

        }
        if(i==n-1){
            if(a[i]=='\t'||a[i]==' '){
                n--;
            }
        }
    }
    cout<<"squeezed string is:";
    for(i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<len(a);
return ;


}
int main ()
{
    char a[100];
    cout<<"enter a string:";
    cin.getline(a,100);

    squeeze(a);
    return 0;
}
*/
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
    char a[100];
    int i,n,j;
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    n=strlen(a);
    for(i=0;i<=n-1;i++)
    {
        if(a[i]=='\t'|| a[i]==' ')
        {
            for(j=i;j<=n-2;j++)
            {
                a[j]=a[j+1];
            }
            n--;i--;
        }
    }
    a[i]='\0';
    cout<<endl<<a;

       return 0;
}



*/
