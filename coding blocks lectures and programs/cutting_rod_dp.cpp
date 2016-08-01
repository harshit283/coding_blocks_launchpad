#include<bits/stdc++.h>
using namespace std;
 int x=0;
///MEMORISATION
int max_price(const vector<pair<int,int> > & v ,int len,int *mat)
{
    x++;
    if(mat[len]!=0)
    {
        return mat[len];
    }
    if(len==0)
    {
        mat[len]=0;
        return 0;
    }
    int ans=INT_MIN;
    int val=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        pair<int,int>temp=v[i];
        if(len-temp.first >= 0)
        {
            val=temp.second + max_price(v,len-temp.first,mat);
        }
        if(val > ans)
        {
            ans=val;
        }
    }
    mat[len]=ans;
    return ans;
}
int main ()
{
    cout<<"enter the total number of prices:";
    int n;
    cin>>n;
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the length:";
        int len;
        cin>>len;
        cout<<"enter its price:";
        int val;
        cin>>val;
        pair<int,int>temp(len,val);
        v.push_back(temp);
    }
    cout<<"enter the length of the rod:";
    int len;
    cin>>len;
    int mat[100]={0};
    cout<<max_price(v,len,mat);
    cout<<"x is:"<<x;
}

    /*cout<<"enter the total number of prices:";
    int n;
    cin>>n;
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++)
    {
        cout<<"enter the length:";
        int len;
        cin>>len;
        cout<<"enter its price:";
        int val;
        cin>>val;
        pair<int,int>temp(len,val);
        v.push_back(temp);
    }
    cout<<"enter the length of the rod:";
    int len;
    cin>>len;
    int mat[100];
    mat[0]=0;
    for(int i=1;i<=len;i++)
    {
        mat[i]=INT_MIN;
    }

    for(int i=1;i<=len;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            pair<int,int>temp=v[j];
            if(i-temp.first>=0)
            {
                if(mat[i] < temp.second+mat[i-temp.first])
                {
                    mat[i]=temp.second+mat[i-temp.first];
                }
            }
        }
    }
cout<<endl;
    for(int i=0;i<=len;i++)
    {
        cout<<mat[i]<<" ";
    }
    //cout<<"maximum price is"<<endl<<mat[len];
    return 0;
}
*/
