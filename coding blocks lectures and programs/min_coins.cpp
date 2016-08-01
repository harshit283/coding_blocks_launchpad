#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int x=0;
int denom( vector<int>&v,int sum,int *a)
{
    x++;
    if(a[sum]!=-1)
    {
        return a[sum];
    }
    if(sum==0)
    {
        a[sum]=0;
        return 0;
    }
for(int i=0;i<v.size();i++)
{
    if(sum==v[i])
    {
        a[sum]=1;
        return 1;
    }
}

  int count=0;
   for(int i=0;i<v.size();i++)
   {
  if(sum-v[i]>0)
 {
    int ans=denom(v,sum-v[i],a)+1;
    if(ans > 0)
    {
        count++;
    }
 }

}
a[sum]=min;
return min;
}
int main ()
{
   vector<int>v;
   int n,sum;
   cout<<"enter total denominations";
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       v.push_back(i);
   }
   cout<<"enter the sum";
   cin>>sum;
   int a[sum+1];
   for(int i=0;i<sum+1;i++)
   {
       a[i]=-1;
   }

   cout<<"minimun coins are:"<<endl<<denom(v,sum,a);
   return 0;
}

/////////////////////////////////////////////////////////////////////////////////
/// BY USING BOTTOM TO TOP I.E DP
/*
int main ()
{

   vector<int>denom;
   cout<<"enter the number of denominations:"<<endl;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       int val;
       cin>>val;
       denom.push_back(val);
   }
   cout<<"enter the sum";
   int sum;
   cin>>sum;
   int dp[sum+1];
   int parent[sum+1];
   dp[0]=0;
   for(int i=1;i<=sum;i++)
   {
       dp[i]=INT_MAX;
       parent[i]=-1;
   }
///APPROACH 1

   for(int i=1;i<=sum;i++)
   {
       for(int j=0;j<denom.size();j++)
       {
           if(i-denom[j]>=0 && dp[i]>dp[i-denom[j]]+1)
           {
               dp[i]=dp[i-denom[j]]+1;
               parent[i]=j;
           }
       }
   }
cout<<dp[sum];
cout<<endl;
int temp_sum=sum;
while(temp_sum)
{
    cout<<denom[parent[temp_sum]]<<" ";
    temp_sum=temp_sum-denom[parent[temp_sum]];
}
}
/*
///APPROACH 2

    for(int i=0;i<denom.size();i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j-denom[i]>=0)
            {
                if(dp[j] > dp[j-denom[i]]+1)
                {
                    dp[j]=dp[j-denom[i]]+1;
                    parent[j]=i;
                }
            }
        }
    }
    cout<<dp[sum];
    cout<<endl;
int temp_sum=sum;
while(temp_sum)
{
    cout<<denom[parent[temp_sum]]<<" ";
    temp_sum=temp_sum-denom[parent[temp_sum]];
}

   return 0;
}
/*
#include<iostream>
using namespace std;
int minCoins(int S, int *denom, int denomsize) {
    if (S <= 0) {
        return -1;
    }
    for (int i = 0; i < denomsize; i++) {
        if (denom[i] == S) {
            return 1;
        }
    }
    int ans = -1;
    for (int i = 0; i < denomsize; i++) {
        int subans = minCoins(S-denom[i], denom, denomsize);
        if (subans!= -1) {
            if (ans == -1 || ans > subans) {
                ans = subans;
            }
        }
    }
    if ( ans == -1) {
        return ans;
    } else {
        return ans+1;
    }
}
int main() {
     int denom[100];
   int n,sum;
   cout<<"enter total denominations";
   cin>>n;
    for(int i=0;i<n;i++)
     {
         cin>>denom[i];
     }
   /*for(int i=1;i<=n;i++)
   {
       int val;
       cin>>val;
       v.push_back(val);
   }*/
   /*
   cout<<"enter the sum";
   cin>>sum;
   /*int a[100];
   for(int i=0;i<100;i++)
   {
       a[i]=-1;
   }
   */
   /*
   cout<<"minimun coins are:"<<endl<<minCoins(sum,denom,n);
   return 0;
    return 0;
}
*/
