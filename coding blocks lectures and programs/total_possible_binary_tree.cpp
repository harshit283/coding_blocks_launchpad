#include<iostream>
using namespace std;
long long int function(int start,int end,long long int  mat[][100])
{
    if(mat[start][end]!=-1)
    {
        return mat[start][end];
    }

    if(start>=end)
    {
        mat[start][end]=1;
        return 1;
    }
    long long int count =0;
    for(int i=start;i<=end;i++)
    {
        count+=function(start,i-1,mat)*function(i+1,end,mat);
    }
    mat[start][end]=count;
    return count;
}

int main ()
{
    long long int mat[100][100];
    cout<<"enter the number:"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            mat[i][j]=-1;
        }
    }
    cout<<function(1,n,mat);
    return 0;
}
