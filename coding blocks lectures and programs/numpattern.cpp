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
            cout<<j;
            j++;
        }
        k=1;
        while(k<=2*n-2*i){
            cout<<" ";
            k++;
        }
        l=j-1;
        while(l>=1){
            cout<<l;
            l--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}
