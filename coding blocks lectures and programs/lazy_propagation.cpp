#include<bits/stdc++.h>
using namespace std;
vector<int> segment_tree;
    vector<int > v;
        vector<int > lazy;
int n;


void create_tree(int curr,int start,int end)
{
    if(start==end)
    {
        segment_tree[curr]=v[start];
        return ;
    }
    int mid=(start+end)/2;
    create_tree(curr*2+1,start,mid);
    create_tree(curr*2+2,mid+1,end);
    segment_tree[curr]=max(segment_tree[2*curr+1],segment_tree[2*curr+2]);
    return ;
}


void update_range_query(int delta,int a,int b,int curr,int start,int end)
{
    if(start > end)
        return ;
    if(lazy[curr]!=0)
    {
        segment_tree[curr]+=lazy[curr];
        if(end!=start)
        {
            lazy[curr*2+1]+=lazy[curr];
            lazy[curr*2+2]+=lazy[curr];
        }
        lazy[curr]=0;
    }

    if(end < a || start > b)  ///NO OVERLAP;
        return ;

    if(start >=a && end<=b)
    {
        cout<"dhjf";               ///TOTAL OVERLAP;
        segment_tree[curr]+=delta;
        if(start!=end)
        {
            lazy[2*curr+1]+=delta;
            lazy[2*curr+2]+=delta;
        }
        return ;
    }

    int mid=(start+end)/2;  ///PARTIAL OVERLAP;
    update_range_query(delta,a,b,curr*2+1,start,mid);
    update_range_query(delta,a,b,curr*2+2,mid+1,end);
    segment_tree[curr]=max(segment_tree[2*curr+1],segment_tree[2*curr+2]);
    return ;
}


int  get_query(int a,int b,int curr,int start,int end)
{
    if(start > end)
        return INT_MIN;

    if(lazy[curr]!=0)
    {
        segment_tree[curr]+=lazy[curr];
        if(end!=start)
        {
            lazy[curr*2+1]+=lazy[curr];
            lazy[curr*2+2]+=lazy[curr];
        }
        lazy[curr]=0;
    }

       if(end < a || start > b)  ///NO OVERLAP;
          return INT_MIN;

    if(start >=a && end<=b)
    {                                  ///TOTAL OVERLAP;
        return segment_tree[curr];
    }

    int mid=(start+end)/2;  ///PARTIAL OVERLAP;
    return max(get_query(a,b,curr*2+1,start,mid),get_query(a,b,curr*2+2,mid+1,end));
}


int main()
{
    cin>>n;
    v.resize(n+1);
    int m;
    cin>>m;
    int cnt=1;
        while(cnt < n)
        {
               cnt=cnt*2;
        }
       int len=2*cnt;
        lazy.resize(len);
        segment_tree.resize(len,INT_MIN);
        create_tree(1,1,n);

    for(int i=0;i<m;i++)
    {
        int a,b;
        int k;
        cin>>a>>b>>k;
        update_range_query(k,a,b,1,1,n);
        cout<<endl;
        cout<<"hj";
                 for(int i=1;i<=len-1;i++)
            cout<<segment_tree[i]<<" ";

    }
    cout<<get_query(1,n,1,1,n);

    return 0;
}
