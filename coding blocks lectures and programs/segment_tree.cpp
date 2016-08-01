#include<bits/stdc++.h>
using namespace std;
int a[100];
int segment_tree[100000];
 void my_func(int curr,int start,int end)
 {
     if(start==end)
     {
         segment_tree[curr]=a[start];
         return ;
     }
     int mid=(start+end)/2;
     my_func(curr*2+1,start,mid);
     my_func(curr*2+2,mid+1,end);
     segment_tree[curr]=min(segment_tree[2*curr+1],segment_tree[2*curr+2]);
     return ;
 }

 int min_range_query(int curr,int a,int b,int start,int end)
 {
     if(a <= start && b>=end)
        return segment_tree[curr];
     if( a > end || b < start)
        return INT_MAX;
     int mid=(start+end)/2;
     return min(min_range_query(curr*2+1,a,b,start,mid),min_range_query(curr*2+2,a,b,mid+1,end));
 }
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];
    int k=1;
    int len;
    while(k<n)
    k=k*2;
    len=k*2-1;
    for(int i=0;i<len;i++)
        segment_tree[i]=INT_MAX;
     my_func(0,0,n-1);
    for(int i=0;i<len;i++)
        cout<<segment_tree[i]<<" ";

    int a,b;
    cin>>a>>b;
    cout<<min_range_query(0,a,b,0,len-1);
    return 0;

}
