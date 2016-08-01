#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter the side";
    int n;
    cin>>n;
    cout<<"enter the number of jumps"<<endl;
    array<int,100> mat;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        mat[i]=val;
    }
    array<int,100>dp;
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        dp[i]=INT_MAX;
    }
    for(int i=0;i<n;i++)
    {
              int j,k;
              k=i+1;
            for( j=1;j<=mat[i];j++)
            {
                if(k==n)
                {
                    break;
                }
                if(dp[k] > dp[i]+1)
                {
                      dp[k]=dp[i]+1;
                }
                k++;
            }
            if(k==n)
            {
                break;
            }

    }
 cout<<endl;
 for(int i=0;i<n;i++)
 {
     cout<<dp[i]<<" ";
 }
    return 0;
}
