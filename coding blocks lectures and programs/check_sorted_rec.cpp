#include<iostream>
using namespace std;
bool sorted(int *a,int n)
{
    if(n==1)
    {
        return true;
    }
    else{
        if(*(a+1)<*a){
            return false;
        }
        else{

            return sorted(a+1,n-1);
        }
    }
}
int main ()
{
    int a[100],n,i,k;
    cout<<"enter the size";
    cin>>n;
    cout<<"enter the array";

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    k=sorted(a,n);
    if(k==1){
        cout<<"sorted";
    }
    else{
        cout<<"not sorted";
    }
    return 0;
}
