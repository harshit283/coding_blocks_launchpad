#include<bits/stdc++.h>
using namespace std;
int x=0;
int knapsack(const vector<pair<int,int> >& v,int max_wt,int index,int a[][100])
{
    x++;
    if(a[index][max_wt]!=0)
    {
        return a[index][max_wt];
    }

    if(index==v.size() || max_wt==0)
    {
        a[index][max_wt]=0;
        return 0;
    }
    pair<int,int>temp=v[index];
    if(temp.second > max_wt)
    {
        a[index][max_wt]= knapsack(v,max_wt,index+1,a);
        return a[index][max_wt];
    }
    a[index][max_wt]= max(temp.first+knapsack(v,max_wt-temp.second,index+1,a),knapsack(v,max_wt,index+1,a));
    return a[index][max_wt];
}
int main()
{
    cout<<"enter the total number of values:"<<endl;
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the value:"<<endl;
        int val;
        cin>>val;
        cout<<"enter its weight:"<<endl;
        int wt;
        cin>>wt;
        pair<int,int> temp(val,wt);
        v.push_back(temp);
    }
    cout<<"enter the max weight:"<<endl;;
    int max_wt;
    cin>>max_wt;
    int a[100][100]={0};
    cout<<"maximum possible value is:"<<endl;
    cout<<knapsack(v,max_wt,0,a);
    cout<<"x is:"<<x;

 ///BOTTOM TOP APPROACH
 /*
    cout<<"enter the total number of values:"<<endl;
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the value:";
        int val;
        cin>>val;
        cout<<"enter its weight:";
        int wt;
        cin>>wt;
        pair<int,int> temp(val,wt);
        v.push_back(temp);
    }
    cout<<"enter the max weight:";;
    int max_wt;
    cin>>max_wt;
    int a[n+1][max_wt+1];
    pair<int,int >temp;
     temp=v[0];
     int val;
     int flag=0;
     for(int i=1;i<=max_wt;i++)
     {
         if(i-temp.second >=0 && flag==0)
         {
             a[0][i]=temp.first;
             val=temp.first;
             flag++;
             continue;
         }
        else if(i-temp.second >=0 && flag==1)
         {
             a[0][i]=val;
             continue;
         }
       a[0][i]=0;
     }

     for(int i=1;i<n;i++)
     {
         for(int j=1;j<=max_wt;j++)
         {
             pair<int,int>temp=v[i];
             if(temp.second > j)
             {
                 a[i][j]=a[i-1][j];
                 continue;
             }
             int dif=j-temp.second;
             a[i][j]=max(a[i-1][j],temp.first+a[i-1][dif]);
         }
     }
     cout<<"maximum possible value is:"<<endl<<a[n-1][max_wt];
     */
return 0;
}
