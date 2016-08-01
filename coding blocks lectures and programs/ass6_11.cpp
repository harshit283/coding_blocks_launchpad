#include<iostream>
#include<cstring>
using namespace std;
int func(char*a,char*b)
{
    int i,j,n=strlen(a),m=strlen(b),l,k;
    for(i=n-1,j=m-1;i>=0;i--)
    {
        if(a[i]==b[j]){
            for( l=i-1,k=j-1;k>=0;k--,l--)
            {
                if(a[l]!=b[k]){
                    break;
                }
            }
            if(k<0){
                return l+1;
            }
        }
    }
    return -1;

}
int main ()
{

    char a[100],b[100];
    int i;
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    cout<<"enter the string"<<endl;
    cin.getline(b,100);
    i=func(a,b);
     if(i==-1){
        cout<<"not found";
     }
     else{
        cout<<"index is"<<i;
     }
    return 0;
}
