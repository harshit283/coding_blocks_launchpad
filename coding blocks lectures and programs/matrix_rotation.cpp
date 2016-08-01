#include<bits/stdc++.h>
using namespace std;
int main()
{
     int m,n,r;
    cin>>m>>n>>r;
    int mat[302][302];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>mat[i][j];
    }


    int ver_upper=1;
    int ver_lower=m;
    int hor_upper=1;
    int hor_lower=n;
    while(ver_upper < ver_lower && hor_upper < hor_lower)
    {
        int x=ver_upper;
        int y=hor_upper;
        int k=2*(ver_upper-ver_lower + hor_upper - hor_lower);
        int temp=r%k;
        if(temp)
        {
            int count=0;
            while(count < temp)
            {
                 int c=ver_lower;
                 int val=mat[c][hor_upper];
                 while(c >= ver_upper+1)
                 {
                     mat[c][hor_upper]=mat[c-1][hor_upper];
                     c--;
                 }
                 c=hor_lower;
                 int val2=mat[ver_lower][c];
                 while(c>=hor_upper+2)
                 {
                     mat[ver_lower][c]=mat[ver_lower][c-1];
                     c--;
                 }
                 mat[ver_lower][c]=val;
                 c=ver_upper;
                 val=mat[c][hor_lower];
                 while(c <= ver_lower-2)
                 {
                     mat[c][hor_lower]=mat[c+1][hor_lower];
                     c++;
                 }
                 mat[c][hor_lower]=val2;
                 c=hor_upper;
                 while(c <= hor_lower-2)
                 {
                     mat[ver_upper][c]=mat[ver_upper][c+1];
                     c++;
                 }
                 mat[ver_upper][c]=val;
                 count++;
            }
        }
        ver_upper++;
        ver_lower--;
        hor_upper++;
        hor_lower--;

    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
