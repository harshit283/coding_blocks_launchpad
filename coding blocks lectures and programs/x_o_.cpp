#include<iostream>
using namespace std;
int main()
{
    char a[100][100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            a[i][j]='O';
    }
    int i,j, start=1, end=n-2;
    while(start <= end)
    {
        for(i=start;i<=end;i++)
            a[start][i]='X';
        for(i=start+1;i<=end;i++)
            a[i][end]='X';
        for(i=end-1;i>=start;i--)
            a[end][i]='X';
        for(i=end-1;i>=start+1;i--)
            a[i][start]='X';
        start+=2;end-=2;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
