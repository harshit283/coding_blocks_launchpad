#include<bits/stdc++.h>
using namespace std;
int mat[8][8][100]={0};
double knight_on_a_chessboard(int currx,int curry,int k)
{
    if(mat[currx][curry][k]!=0)
    {
        return mat[currx][curry][k];
    }
    if(k==0)
    {
        mat[currx][curry][k]=1;
        return 1;
    }
    int delta[8][2]={{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    double prob=0;
    for(int i=0;i<8;i++)
    {
        int newx=currx+delta[i][0];
        int newy=curry+delta[i][1];
        if(newx>=0 && newx<8 && newy>=0 && newy<8)
        {
            prob+=knight_on_a_chessboard(newx,newy,k-1);
        }
    }
    mat[currx][curry][k]=prob/8;
    return prob/8;
}

int main()
{
    cout<<"enter the initial coord of knight:"<<endl;
    int x,y;
    cin>>x>>y;
    cout<<"enter the total moves";
    int k;
    cin>>k;
    cout<<"prob is"<<knight_on_a_chessboard(x,y,k);
    cout<<endl;
/*
    ///DP BOTTOM UP SOLUTION

   cout<<"enter the initial coord of knight:"<<endl;
    int x,y;
    cin>>x>>y;
    cout<<"enter the total moves";
    int k;
    cin>>k;
    long double mat1[8][8],mat2[8][8];
    for(int l=0;l<=k;l++)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(l==0)
                {
                    mat1[i][j]=1;
                }
                else{
                     int delta[8][2]={{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};

    long  double prob=0;
    for(int c=0;c<8;c++)
    {
        int newx=i+delta[c][0];
        int newy=j+delta[c][1];
        if(newx>=0 && newx<8 && newy>=0 && newy<8)
        {
            prob=prob+mat1[newx][newy];
        }
    }
    mat2[i][j]=prob/8;
                }
            }
        }
        if(l)
        {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                mat1[i][j]=mat2[i][j];
            }
        }
        }
    }
    cout<<"required prob is:"<<endl;
    cout<<mat1[x][y];
    */

    return 0;
}
