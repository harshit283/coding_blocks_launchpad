#include<bits/stdc++.h>
using namespace std;
int mat[10][10];
int max_len;
int m,n;
int main()
{

    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
  int count;
  max_len=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            count=0;
            if(mat[i][j]==1)
            {
                mat[i][j]=2;
                queue<pair<int,int> >Q;
                pair<int,int>my_pair(i,j);
                Q.push(my_pair);
                count++;
                while(!Q.empty())
                {
                    pair<int,int>temp=Q.front();
                    Q.pop();
                    int delta[8][2]={{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0}};
                    for(int k=0;k<8;k++)
                    {
                        int newx=temp.first+delta[k][0];
                        int newy=temp.second+delta[k][1];
                        if(newx >=0 && newx <m && newy >=0 && newy <n && mat[newx][newy]==1)
                        {
                            mat[newx][newy]=2;
                            pair<int,int> p;
                            p.first=newx;
                            p.second=newy;
                            Q.push(p);
                            count++;
                        }
                    }
                }
                if(max_len < count)
                    max_len=count;
            }
        }
    }
    cout<<max_len;
    return 0;
}
