#include<bits/stdc++.h>
using namespace std;
   string s1,s2;
int main ()
{
    cout<<"enter the first string:"<<endl;
    cin>>s1;
    cout<<"enter the second string:"<<endl;
    cin>>s2;
    int mat[100][100];
    for(int i=0;i<=s1.size();i++)
    {
        mat[i][0]=0;
    }
    for(int i=0;i<=s2.size();i++)
    {
        mat[0][i]=0;
    }
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                mat[i][j]=mat[i-1][j-1]+1;
                continue;
            }
            mat[i][j]=0;
        }
    }
    cout<<"longest common substring is:"<<endl;
    int ans=-1;
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            if(mat[i][j] > ans)
            {
                ans=mat[i][j];
            }
        }
    }
    cout<<ans;
    return 0;
}
