#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter the total number of elements :";
    int n;
    cin>>n;
    cout<<"enter the numbers"<<endl;
    array<int,100>a;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        a[i]=val;
    }
    array<int,100>dp;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i] >= a[j])
            {
                if(dp[i] < dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
    }
    /*
int ans=-1;
    for(int i=0;i<n;i++)
    {
        if(ans < dp[i])
        {
            ans=dp[i];
        }
    }
    cout<<ans;
    */
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }
    return 0;
}
