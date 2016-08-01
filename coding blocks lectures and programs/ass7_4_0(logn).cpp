#include<iostream>
using namespace std;
int binary_2d(int a[][100],int n,int k)
{
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    while(end - start > 1)
    {
        if(k==a[mid][n-1])
            return -1;
        if(k > a[mid][n-1])
        {
            start=mid+1;
            mid=(start+end)/2;
        }else
        {
            end=mid-1;
            mid=(start+end)/2;
        }
    }
    if(k==a[start][n-1] || k==a[end][n-1])
        return -1;
    if(k<a[start][n-1])
        return start;
        else if(k>a[start][n-1] && k<a[end][n-1])
            return end;
            else return end==n-1?end:end+1;

}
int binary_search(int *a,int n,int k)
{
      int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    while(start<=end)
    {
        if(k==a[mid])
            return 1;
        else if(k > a[mid])
        {
            start=mid+1;
            mid=(start+end)/2;
        }
        else{
            end=mid-1;
            mid=(start+end)/2;
        }
    }

    return 0;
}
int main()
{
    int n;
    cin>>n;
    int a[100][100];
    int i;
    int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
    int k;
    cin>>k;
    int temp=binary_2d(a,n,k);
    cout<<temp<<endl;
    if(temp==-1)
    {
        cout<<"yes";
        return 0;
    }
        temp=binary_search(a[temp],n,k);
        if(temp==0)
            cout<<"no";
        else cout<<"yes";
    return 0;
}
