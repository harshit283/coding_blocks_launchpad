#include<iostream>
using namespace std;
void sort1(int *a,int i,int n)
{
    if(i==n-1){
        return ;
    }
    if(a[i]>a[i+1]){
        int temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
    }
    sort1(a,i+1,n);
}
void sort(int *a,int n)
{
    if(n==1){
        return ;
    }
    sort1(a,0,n);

    sort(a,n-1);
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
    sort(a,n);
    cout<<"sorted array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
