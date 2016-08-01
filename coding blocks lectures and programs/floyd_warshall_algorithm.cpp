#include<bits/stdc++.h>
using namespace std;
long long int mat[401][401];
int main()
{
    long long int n,m;
    cin>>n>>m;
    for( int i=1;i<=n;i++)
    {
        for( int j=1;j<=n;j++)
        {
            if(i==j)
              mat[i][j]=0;
            else mat[i][j]=INT_MAX;
        }
    }

    for( int i=0;i<m;i++)
    {
        int x,y,r;
        cin>>x>>y>>r;
        mat[x][y]=r;
    }

    for( int k=1;k<=n;k++)
    {
        for( int i=1;i<=n;i++)
        {
            for( int j=1;j<=n;j++)
            {
                if(mat[i][j] > mat[i][k] + mat[k][j])
                    mat[i][j]=mat[i][k]+mat[k][j];
            }
        }
    }

     int q;
    cin>>q;
    vector<int> sol;
    for( int i=0;i<q;i++)
    {
         int a,b;
        cin>>a>>b;
        sol.push_back(mat[a][b]);
    }

    for( int i=0;i<sol.size();i++)
    {
        if(sol[i]==INT_MAX)
            cout<<-1<<endl;
        else cout<<sol[i]<<endl;
    }

    return 0;
}

