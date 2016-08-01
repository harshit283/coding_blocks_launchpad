#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<limits.h>
#include<iterator>
#include<algorithm>
using namespace std;
int main()
{
   /* int a[100],b[100];
    int m,n;
    cin>>m>>n;
    cout<<"enter first array"<<endl;
    for(int i=0;i<m;i++)
        cin>>a[i];
    cout<<"enter the second array"<<endl;
    for(int i=0;i<n;i++)
        cin>>b[i];

    unordered_map<int,vector<int> > my_map;
    for(int i=0;i<m;i++)
        my_map[a[i]].push_back(a[i]);

    for(int i=0;i<n;i++)
    {
        if(my_map.count(b[i]))
        {
            my_map[b[i]].pop_back();
            if(my_map[b[i]].empty())
            my_map.erase(b[i]);
        }
        else{
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    */

  /* unordered_map<int,vector<int>> my_map;
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        my_map[a[i]].push_back(a[i]);
    }
    int sum;
    cout<<"enter the sum"<<endl;
    cin>>sum;
    for(int i=0;i<n;i++)
    {
        if(my_map.count(sum-a[i]))
        {
            cout<<a[i]<<" "<<sum-a[i]<<endl;
            my_map[a[i]].pop_back();
            my_map[sum-a[i]].pop_back();
            if(my_map[a[i]].empty())
                my_map.erase(a[i]);
            if(my_map[sum-a[i]].empty())
                my_map.erase(sum-a[i]);
        }
        else{
            my_map[a[i]].pop_back();
            if(my_map[a[i]].empty())
                my_map.erase(a[i]);
        }
    }
    */
/*
    unordered_set<int> my_set;
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        my_set.insert(a[i]);
    }

    int r_val,l_val,fr_val,fl_val;
    int max_len=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int val=a[i];
        l_val=val;
        while(1)
        {
            val--;
            if(my_set.count(val))
                l_val=val;
            else break;
        }
        val=a[i];
        r_val=val;
        while(1)
        {
            val++;
            if(my_set.count(val))
                r_val=val;
            else break;
        }
        if(r_val - l_val +1 > max_len)
        {
            max_len=r_val-l_val+1;
            fr_val=r_val;
            fl_val=l_val;
        }
    }

    for(int i=fl_val;i<=fr_val;i++)
        cout<<i<<" ";
        */

/*
    unordered_map<int,vector<int> > my_map;
    int a[100];
    int n;
    cout<<"enter the number of elements"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        my_map[a[i]].push_back(a[i]);
    }
    int Q;
    cout<<"enter the number of queries"<<endl;
    cin>>Q;
    vector<pair<int,int> > v;
    cout<<"enter the queries"<<endl;
    for(int i=0;i<Q;i++)
    {
        int val1;
        int val2;
        cin>>val1>>val2;
        pair<int,int> my_pair(val1,val2);
        v.push_back(my_pair);
    }

    int i;
    for( i=0;i<Q;i++)
    {
        cout<<"mode after query number "<<i+1<<" : ";
        pair<int,int> temp=v[i];
        my_map[a[temp.first]].pop_back();
        if(my_map[a[temp.first]].empty())
            my_map.erase(a[temp.first]);
        my_map[temp.second].push_back(temp.second);
        a[temp.first]=temp.second;
        int val,size=0;
        for(int j=1;j<=n;j++)
        {
            if(my_map[a[j]].size() > size)
            {
                size=my_map[a[j]].size();
                 val=a[j];
            }
            else if(my_map[a[j]].size()==size)
            {
                if(val > a[j])
                    val=a[j];
            }
        }
        cout<<val<<endl;;
    }

    */
    unordered_set<int> my_set;
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dis;
    cout<<"enter distance ( < n )"<<endl;
    cin>>dis;
    int pos_r=0,pos_f=0,k;
    my_set.insert(a[0]);
    for(int i=0;i<n;i++)
    {
        k=i;
        while( k<=n-1  && (pos_f - pos_r <=dis))
        {
            pos_f++;
            if(pos_f - pos_r > dis)
            {
                my_set.erase(a[i]);
                pos_r=i+1;
                pos_f--;
                break;
            }
            k++;
            if(my_set.count(a[pos_f]))
               {
                   cout<<"yes";
                   return 0;
               }
            else my_set.insert(a[pos_f]);
        }
    }

    cout<<"no";
    return 0;
}
