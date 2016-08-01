#include<bits/stdc++.h>
using namespace std;
int main ()
{
    cout<<"enter the total numbers";
    int n;
    cin>>n;
    cout<<"enter the numbers:"<<endl;
    array<int ,100>arr;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        arr.at(i)=val;
    }
    cout<<"enter the sum"<<endl;
    int sum;
    cin>>sum;
    array<bool,100>a,b;
    a[0]=true;
    b[0]=true;
    for(int i=1;i<=sum;i++)
    {
        if(arr[0]==i)
        {
            a[i]=true;
            continue;
        }
        a[i]=false;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j-arr[i] >=0)
            {
                b[j]=a[j-arr[i]];
                continue;
            }
            b[j]=a[j];
        }

        for(int k=0;k<=sum;k++)
        {
           a[k]=b[k];
        }
    }

    for(int i=0;i<=sum;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
