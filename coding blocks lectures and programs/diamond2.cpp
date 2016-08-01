#include<iostream>
using namespace std;
int main ()
{
    int n,i,j,k,l,m,a;
    cout<<"enter the number of lines(odd)";
    cin>>n;
    i=1;
    while(i<=(n+1)/2){
            j=1;
    while(j<=(n+1)/2-i){
        cout<<" ";
        j++;
    }
    k=1;
    while(k<=2*i-1){
        cout<<"*";
        k++;
    }
    cout<<endl;
    i++;
    }

    l=1;
    while(l<=n/2){
        m=1;
        while(m<=l){
            cout<<" ";
            m++;
        }
        a=1;
        while(a<=2*(n/2-l)+1){                             //try forming factor of (n-i)*p +c,p can be any number and c is the constant which ca be found by putting n=i
            cout<<"*";
            a++;
        }
        cout<<endl;
        l++;
    }

    return 0;
}











