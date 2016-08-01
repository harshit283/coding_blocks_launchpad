#include<bits/stdc++.h>
using namespace std;
int max_cash(int *a,int start,int end,int n,int mat[][100])
{
    if(mat[start][end]!=-1)
    {
        return mat[start][end];
    }
    if(start==end)
    {
        mat[start][end]=a[start]*n;
        return a[start]*n;
    }
    int val1=a[start]*(n-end+start)+max_cash(a,start+1,end,n,mat);
    int val2=a[end]*(n-end+start)+max_cash(a,start,end-1,n,mat);
    mat[start][end]=max(val1,val2);
    return max(val1,val2);

}

int main()
{
    int a[100];
    int mat[100][100];
    cout<<"enter the total number of prices";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j]=-1;
        }
    }

     for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            if(i==j)
            {
                mat[i][j]=a[i]*n;
            }
        }
    }

    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int max_price(const array<int,100> &a,int start,int end,int n,array<array<int,100>,100> & mat)
{
    if(mat[start][end])
    {
        return mat[start][end];
    }
    if(start==end)
    {
        mat[start][end]=a[start]*n;
        return a[start]*n;
    }
    mat[start][end]=max(a[start]*(n-end+start)+ max_price(a,start+1,end,n,mat),a[end]*(n-end+start)+max_price(a,start,end-1,n,mat));
    return mat[start][end];
}
int main ()
{
    cout<<"enter the total number of prices:";
    int n;
    cin>>n;
    cout<<"enter the prices:"<<endl;
    array<int,100>a;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        a.at(i)=val;
    }
    array<array<int,100>,100> mat={0};
    cout<<max_price(a,0,n-1,n,mat);
    return 0;
}
*/
