#include<iostream>
using namespace std;
int main ()
{
    int n,i,j,k,l;
    cout<<"enter the number of lines";
    cin>>n;
     i=1;
     while(i<=n){
        j=1;
        while(j<=i){
            cout<<"*";
            j++;
        }
        cout<<" ";
        k=1;
        while(k<=n-i+1){
            cout<<"*";
            k++;
        }
        cout<<" ";
        k=1;
        while(k<=n+1-i){
            cout<<"*";
            k++;
        }
        cout<<" ";
        l=j-1;
        while(l>=1){
            cout<<"*";
            l--;
        }
        cout<<endl;
        i++;
     }
     return 0;
}
