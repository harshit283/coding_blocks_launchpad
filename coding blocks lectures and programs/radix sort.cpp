#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int i,j,k,val;
    for( i=1;i<=n-1;i++)
    {
        k=i;
        val=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j] > val)
            {
                a[k]=a[k-1];
                k--;
            }
            else break;
        }
        a[k]=val;
    }


    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
