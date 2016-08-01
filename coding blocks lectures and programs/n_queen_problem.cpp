#include<bits/stdc++.h>
using namespace std;
int mat[100][100]={0};
int n;
bool is_safe(int row,int col)
{
    if(row==0)
        return true;
    for(int i=0;i<row;i++)
    {
        if(mat[i][col]==1)
            return false;
    }

    for(int i=row,j=col;i>=0 && j>=0 ;i--,j--)
    {
        if(mat[i][j])
        return false;
    }

   for(int i=row,j=col;i>=0 && j<n ; i--,j++)
   {
        if(mat[i][j])
        return false;
   }


   return true;
}
bool n_queens(int n,int index)
{
    ///BASE CASE
    if(index==n)
        return true;
    for(int i=0;i<n;i++)
    {
        if(is_safe(index,i))
        {
            mat[index][i]=1;
            if(n_queens(n,index+1))
                return true;
            else mat[index][i]=0;
        }
    }
    return false;
}
int main()
{
    cin>>n;
    n_queens(n,0);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
