#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<n;i++)
    {
       int val=a[i];
       int j ;
       j=i-1;
       while(j>=0 && a[j] > val)
       {
           a[j+1]=a[j];
           j--;
       }
       a[j+1]=val;
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<< "   ";
    }
    return 0;
}
