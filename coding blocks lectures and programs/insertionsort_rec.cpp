#include<iostream>
using namespace std;
void s(int *a,int n,int i)
{
    if(i==n-1)
    {
        return ;
    }
    for(int j=0;j<n-1-i;j++)
    {
        if(a[j]>a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
    s(a,n,i+1);
}
int main ()
{
    int a[100];
    int i,n;
    cout<<"enter the size"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
             s(a,n,0);
    cout<<"sorted array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
