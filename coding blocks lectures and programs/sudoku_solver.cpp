#include<iostream>
using namespace std;
bool Is_Valid(int a[][9],int k,int i,int j)
{
    int r=0;
    bool ans1=true,ans2=true,ans3=true;
    for(;r<9;r++)
    {
        if(a[i][r]==k)
        {
            ans1=false;
        }
    }

    int c=0;
    for(;c<9;c++)
    {
        if(a[c][j]==k)
        {
            ans2=false;
        }
    }

    int x=i;
    int y=j;

    x=x-x%3;
    y=y-y%3;
    int p,q;
    for(p=x;p<=x+2;p++)
    {
        for(q=y;q<=y+2;q++)
        {
            if(a[p][q]==k)
            {
                ans3=false;
            }
        }
    }

    return ans1 && ans2 && ans3;

}
bool Sudoku_Solver(int a[][9],int i,int j)
{
    if(i==8&& j==9)
    {
        return true;
    }
    else if(j==9)
    {
        return Sudoku_Solver(a,i+1,0);
    }

    if(a[i][j]==0)
    {
    int k;
    for(k=1;k<=9;k++)
    {

        if(Is_Valid(a,k,i,j))
        {
            a[i][j]=k;
            if(Sudoku_Solver (a,i,j+1))
            {
                return true;
            }
        }
    }
  a[i][j]=0;
    return false;

}
else
{
    return Sudoku_Solver(a,i,j+1);
}
}

int main ()
{
    int a[9][9];
    int i,j;
    cout<<"enter the elements to solve the Sudoku :"<<endl;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            a[i][j]=0;
        }
    }

    if(Sudoku_Solver(a,0,0))
    {
        cout<<"                      "<<"solved Sudoku  is:"<<endl;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    else
    {
        cout<<"given Sudoku  cannot be solved";
    }

    return 0;

}
