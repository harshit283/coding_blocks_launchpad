#include<iostream>
using namespace std;
bool search7(int *a,int n)
{
    if(n==0){
        return false;
    }
    else{
            if(*a==7)
            {
                return true;
            }
            else
       search7(a+1,n-1);
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

    k=search7(a,n);
    if(k==1){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    return 0;
}
