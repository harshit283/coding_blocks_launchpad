#include<iostream>
using namespace std;
int sum(int *a,int n)
{
    if(n==1)
    {
        return *a;
    }
    return  *a+sum(a+1,n-1);

}
int main()
{
    int a[100],i,n,j;
    cout<<"enter the size";
    cin>>n;
    cout<<"enter the array";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"sum is:"<<sum(a,n);

    return 0;

}
