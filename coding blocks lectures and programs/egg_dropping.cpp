#include<iostream>
#include<limits.h>
using namespace std;
int min_floors(int f,int n)
{
    if(f==0 || f==1)
    {
        return f;
    }
    if(n==1)
    {
        return f;
    }
    int ans=INT_MAX;
    int val;
    for(int i=1;i<=f;i++)
    {
        val=1+max(min_floors(i-1,n-1),min_floors(f-i,n));
        if(val < ans)
        {
            ans=val;
        }
    }
    return ans;

}
int main ()
{
    cout<<"enter the number of floors:"<<endl;
    int f;
    cin>>f;
    cout<<"enter the number  of eggs:"<<endl;
    int e;
    cin>>e;
    //cout<<min_floors(f,e);
    int mat[100][100]={0};
    for(int i=1;i<=f;i++)
    {
        mat[1][i]=i;
    }
    for(int i=2;i<=e;i++)
    {
        for(int j=1;j<=f;j++)
        {
            if(i>j)
            {
                mat[i][j]=mat[i-1][j];
                continue;
            }
            int ans=INT_MAX;
            for(int k=1;k<=j;k++)
            {
                int val=1+max(mat[i-1][k-1],mat[i][j-k]);
                if(ans > val)
                {
                    ans=val;
                }
            }
            mat[i][j]=ans;
        }
    }
    cout<<"answer is:"<<mat[e][f];

    return 0;
}
