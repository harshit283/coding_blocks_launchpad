#include<iostream>
using namespace std;
void merges(int *a,int n)
{
    int c[100];
    int i=0,j=n/2,k=0;
    while(i<n/2 && j<=n-1)
    {
        if(a[i]<a[j]){
             c[k]=a[i];
              i++;k++;

                     }
         else{
                c[k]=a[j];
                 j++;k++;
         }
    }
    if(i==n/2){
        while(j<n)
        {
            c[k]=a[j];
            j++;k++;
        }
    }
    else if(j==n){
        while(i<n/2){
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
void mergesort(int *a,int n)
{
    if(n==1)
    {
        return ;
    }
    int *left=a;
    int *right=a+n/2;
    mergesort(left,n/2);
    mergesort(right,n-n/2);
    merges(a,n);
    return ;

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
    mergesort(a,n);
    cout<<"sorted array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
