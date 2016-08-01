#include<bits/stdc++.h>
using namespace std;
int  mat[10000000];
int min_coins(int *a,int n,int sum)
{
    if(mat[sum]!=-1)
        return mat[sum];
    if(sum==0)
    {
        mat[sum]=0;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==sum)
        {
            mat[sum]=1;
            return 1;
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i] > sum)
           continue;
        int val=1+min_coins(a,n,sum-a[i]);
        if(val < ans)
            ans=val;
    }
    mat[sum]=ans;
    return ans;
}

  int knapsack(vector<pair<int,int> >& v , int index ,int max_wt)
  {
      if(max_wt==0 || index==v.size())
            return 0;
      if(v[index].second > max_wt)
          return knapsack(v,index+1,max_wt);
      return max(v[index].first+knapsack(v,index+1,max_wt-v[index].second) , knapsack(v,index+1,max_wt));
  }


  int max_price(int *a,int n,int start,int end)
  {
      if(start==end)
        return a[start]*n;
      return max(a[start]*(n-end+start)+max_price(a,n,start+1,end)  ,   a[end]*(n-end+start)+max_price(a,n,start,end-1));
  }

   int eggs(int n,int k)
   {
       if(k==0)
        return 0;
       if(n==1 || k==1)
        return k;
       int ans=INT_MAX;
       for(int i=1;i<=k;i++)
       {
           int val=1+max(eggs(n-1,i),eggs(n,k-i));
           if(val < ans)
            ans=val;
       }
       return ans;
   }
/*
int  mat[100][100]={0};
bool subsets_sum(int *a,int n,int sum)
{
    if(mat[n][sum]!=-1)
       return mat[n][sum];
    if(sum==0)
    {
        cout<<"hello";
        mat[n][sum]=1;
        return true;
    }
    if(n==0)
    {
        cout<<"hello";
        mat[n][sum]=0;
        return false;
    }
    if(subsets_sum(a+1,n-1,sum))
    {
        mat[n][sum]=1;
        return true;
    }
    if(subsets_sum(a+1,n-1,sum-*a))
    {
        mat[n][sum]=1;
        return true;
    }
      mat[n][sum]=0;
      return false;
}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"enter the sum";
    int sum;
    cin>>sum;
    mat[0][a[0]]=1;
    /*cout<<subsets_sum(a,n,sum)<<endl;
     for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
            cout<<mat[i][j]<<" ";;
            cout<<endl;
    }
    */

   /* for(int i=1;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(a[i]==j)
                mat[i][j]=1;
            else if(a[i] > j)
                mat[i][j]=mat[i-1][j];
            else{
                mat[i][j]=mat[i-1][j-a[i]];
            }
        }
    }

    cout<<mat[n-1][sum]<<endl;
     for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
            cout<<mat[i][j]<<" ";;
            cout<<endl;
    }

    */
int main()
{
    /*int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"enter the sum"<<endl;
    int sum;
    cin>>sum;
    for(int i=0;i<=sum;i++)
        mat[i]=INT_MAX;

    mat[0]=0;

    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]==i)
                mat[i]=1;
            else if(a[j] < i)
            {
                if(mat[i] > 1+mat[i-a[j]])
                    mat[i]=1+mat[i-a[j]];
            }
        }
    }
    for(int i=0;i<=sum;i++)
        cout<<mat[i]<<" ";
        */

  /* int n;
    cin>>n;
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the value :";
        int val;
        cin>>val;
        cout<<"enter its weight :";
        int wt;
        cin>>wt;
        pair<int,int>my_pair(val,wt);
        v.push_back(my_pair);
    }

    cout<<"enter max weight :";
    int max_wt;
    cin>>max_wt;
    int dp[100][100];
    for(int i=0;i<=max_wt;i++)
    {
        if(i>=v[0].second)
            dp[0][i]=v[0].first;
        else dp[0][i]=0;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=max_wt;j++)
        {
            if(v[i].second==j)
                dp[i][j]=max(dp[i-1][j],v[i].first);
            else if(v[i].second > j)
                dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=max(dp[i-1][j],v[i].first+dp[i-1][j-v[i].second]);
            }
        }
    }
    cout<<dp[n-1][max_wt];
    */
    /*
    int n;
    cin>>n;
    int a[100];
    cout<<"enter the prices"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<max_price(a,n,0,n-1);
    */


   /* int n;
    cin>>n;
    cout<<"enter the prices";
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"enter the length";
    cin>>l;
    cout<<rod(a,n);
    */mvcmn

    int n,k;
    cout<<"enter the number of floors :"<<endl;
    cin>>k;
    cout<<"enter the number of eggs"<<endl;
    cin>>n;
///    dp[n+1][k+1];
   // cout<<eggs(n,k);+

    return 0;
}
