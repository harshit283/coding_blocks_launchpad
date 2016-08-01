#include<iostream>
using namespace std;
int main()
{
    int n,i=1,j,k,l;
    cout<<"enter the number of lines (n>=3)";
    cin>>n;
    while(i<=n){
        j=1;
        while(j<=n-i){
            cout<<" ";
            j++;
        }
        if(i==1){
            cout<<"*";
        }
        else if(i!=1 && i<=n-1){
                cout<<"*";
        k=1;
        while(k<=2*i-3){
            cout<<" ";
            k++;
        }
        cout<<"*";

        }
        else if(i==n){
            l=1;
            while(l<=2*n-1){
                cout<<"*";
                l++;
            }
        }
            cout<<endl;
            i++;
        }
            return 0;
}
