#include<iostream>
#include<vector>
using namespace std;
int knapsack (const vector<pair<int,int> >& v,int max_wt,int index,int mat[][100])
{

    if(mat[index][max_wt]!=-1)
    {
        return mat[index][max_wt];
    }
    if(index==v.size() || max_wt==0)
    {
        mat[index][max_wt]=0;
        return 0;
    }

     pair<int,int>temp=v[index];
     if(temp.second > max_wt)
     {
        mat[index][max_wt]= knapsack(v,max_wt,index+1,mat);
        return mat[index][max_wt];
     }
     int val1=temp.first+knapsack(v,max_wt-temp.second,index+1,mat);
     int val2=knapsack(v,max_wt,index+1,mat);
     int ans=max(val1,val2);
     mat[index][max_wt]=ans;
     return ans;

}

int main()
{

    vector<pair<int,int> > v;
    cout<<"enter the number of values";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int val,wt;
        cout<<"enter the value:";
        cin>>val;
        cout<<"enter the weight";
        cin>>wt;
        pair<int,int>temp;
        temp.first=val;
        temp.second=wt;
        v.push_back(temp);
    }
    cout<<"enter the max weight";
    int max_wt;
    cin>>max_wt;
    int mat[100][100];
    for(int i=0;i<max_wt+1;i++)
    {
        for(int j=0;j<max_wt+1;j++)
        {
            mat[i][j]=-1;
        }
    }
    int sum=-1;
    cout<<knapsack(v,max_wt,0,mat);
    cout<<endl;





    /// SOLVE KNAP SACK VIA BOTTOM UP APPROACH




    return 0;
}

