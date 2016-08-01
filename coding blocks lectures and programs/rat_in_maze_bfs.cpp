#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mat[100][100];
    int m,n,i,j,ratx ,raty,cheezx,cheezy;
    cout<<"enter the number of rows:"<<endl;
    cin>>m;
    cout<<"enter the number of columns"<<endl;
    cin>>n;
    cout<<"enter the array(only -1 and 0):"<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<"enter the x coordinate of rat"<<endl;
    cin>>ratx;
    cout<<"enter the y coordinate of rat"<<endl;
    cin>>raty;
    cout<<"enter the x coordinate of cheese"<<endl;
    cin>>cheezx;
    cout<<"enter the y coordinate of cheese"<<endl;
    cin>>cheezy;

    queue<pair<int,int> > Q;
    pair<int,int> temp(ratx,raty);
    mat[ratx][raty]=1;
    Q.push(temp);
    int newx,newy;
    int path[100][2];
    int k=0;
    path[k][0]=ratx;
    path[k][1]=raty;
    k++;
    int val=1;
    int delta[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    while(!Q.empty())
    {
        pair<int,int>p=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
             newx=p.first+delta[i][0];
             newy=p.second+delta[i][1];
            if(newx>=0 && newx<m && newy>=0 && newy<n && mat[newx][newy]==0)
            {
                mat[newx][newy]=mat[p.first][p.second]+1;
                if(val < mat[newx][newy])
                {
                    val=mat[newx][newy];
                    path[k][0]=newx;
                    path[k][1]=newy;
                    k++;
                }
                pair<int,int>p(newx,newy);
                Q.push(p);
                if(newx==cheezx && newy==cheezy)
                    break;
            }
        }
        if(newx==cheezx && newy==cheezy)
            break;
    }

    if(Q.empty())
        cout<<"no";
    else{
        cout<<"yes";
        cout<<endl<<mat[newx][newy]-1;
        cout<<endl<<"PATH IS:"<<endl;
       for(int i=0;i<k;i++)
        cout<<path[i][0]<<","<<path[i][1]<<" ";
    }

    return 0;
}
