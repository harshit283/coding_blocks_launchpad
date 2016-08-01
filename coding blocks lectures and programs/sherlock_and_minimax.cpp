
///QUESTION STATEMENT
/*
Watson gives Sherlock an array A1,A2...AN.
He asks him to find an integer M between P and Q(both inclusive), such that, min {|Ai-M|, 1 ≤ i ≤ N} is maximised. If there are multiple solutions, print the smallest one.*/
///O(NLOGN) SOLUTION
#include<bits/stdc++.h>
using namespace std;
int ans;
int a[200];
int p,q,n,max_val;
void my_function(int k)
{
    int temp_val=INT_MAX;
    for(int i=0;i<n;i++)
    {
        temp_val=min(temp_val,abs(k-a[i]));
    }
    if(temp_val >= max_val)
    {
         if(temp_val > max_val)
        {
            ans=k;
            max_val=temp_val;
        }

       else  if(temp_val==max_val && k < ans)
                ans=k;

    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>p>>q;
    max_val=INT_MIN;
    my_function(p);
    my_function(q);
    sort(a,a+n);
    for(int i=1;i<n;i++)
    {
        int val=(a[i]+a[i-1])/2;
        if(val > p && val < q)
            my_function(val);
        else{

            int upper=max(a[i-1],p);
            int lower=min(a[i],q);
            int x;
            int c=INT_MAX;
            for(int k=upper;k<=lower;k++)
            {
                if(abs(k-val) < c)
                {
                    c=abs(k-val);
                    x=k;
                }
            }
            my_function(x);
        }
    }

    cout<<ans;
    return 0;
}

///O(N^2) SOLUTION

/*
#include<bits/stdc++.h>
using namespace std;
int ans;
int a[200];
int p,q,n,max_val;
void my_function(int k)
{
    int temp_val=INT_MAX;
    for(int i=0;i<n;i++)
    {
        temp_val=min(temp_val,abs(k-a[i]));
    }
    if(temp_val >= max_val)
    {
         if(temp_val > max_val)
        {
            ans=k;
            max_val=temp_val;
        }

       else  if(temp_val==max_val && k < ans)
                ans=k;

    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>p>>q;
    max_val=INT_MIN;
    my_function(p);
    my_function(q);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int val=(a[i]+a[j])/2;
            if(val >p && val <q)
            my_function((a[i]+a[j])/2);
        }
    }

    cout<<ans;
    return 0;
}

*/
