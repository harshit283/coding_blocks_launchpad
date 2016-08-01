#include<iostream>
using namespace std;
void merge(int*a,int n)
{
    int i=0;
    int j=n/2;
    int k=0;
    int c[100];
    while(i<n/2 && j<n)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
           k++;i++;
        }

        else{
            c[k]=a[j];
            j++;k++;
        }
    }

    if(i==n/2)
    {
        while(j<n)
        {
            c[k]=a[j];
            k++;j++;
        }
    }
    else{
        while(i<n/2)
        {
            c[k]=a[i];
            i++;k++;
        }
    }

    for(i=0;i<n;i++)
    {
        a[i]=c[i];
    }
    return ;
}
void mergesort(int*a,int n)
{
    if(n==1)
    {
        return ;
    }

    mergesort(a,n/2);
    mergesort(a+n/2,n-n/2);
    merge(a,n);
    return ;
}
int main ()
{
    int a[100],i,n;
    cout<<"enter the size"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"sorted array is"<<endl;
    mergesort(a,n);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
