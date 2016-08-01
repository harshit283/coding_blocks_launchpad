#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a[100][100];
   cout<<"enter the dimensions of the matrix:"<<endl;
   int m,n;
   cin>>m>>n;
   cout<<"input the binary matrix"<<endl;
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           cin>>a[i][j];
       }
   }

   int dp[m+1][n+1];

   for(int i=0;i<n;i++)
   {
       dp[0][i]=a[0][i];
   }
   for(int i=0;i<m;i++)
   {
       dp[i][0]=a[i][0];
   }

   for(int i=1;i<m;i++)
   {
       for(int j=1;j<n;j++)
       {
           if(a[i][j]==0)
           {
               dp[i][j]=0;
               continue;
           }
           int temp=min(dp[i-1][j],dp[i][j-1]);
           dp[i][j]=min(temp,dp[i-1][j-1])+1;
       }
   }
   int max=-1;
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(dp[i][j]>max)
           {
               max=dp[i][j];
           }
       }
   }

cout<<endl;
   for(int i=0;i<m;i++)
   {
       for(int j=0;j<n;j++)
       {
           cout<<dp[i][j]<<" ";
       }
       cout<<endl;
   }

   cout<<max;
   return 0;
}
