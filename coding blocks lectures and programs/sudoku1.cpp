#include<iostream>
using namespace std;

void check_box(int A[9][9], int B[9], int x, int y)
{
    int x_box=x/3, y_box=y/3;
    x_box*=3;
    y_box*=3;
    int i,j;
    for(i=x_box;i<x_box+3;i++)
    {
        for(j=y_box;j<y_box+3;j++)
        {
            if(A[i][j]!=0)
            {
                B[A[i][j]-1]++;
            }
        }
    }

}


void check_row_column(int A[9][9], int B[9], int x, int y)
{
    int i,j;
    for(i=0;i<9;i++)
    {
        B[i]=0;
    }
    for(i=0;i<9;i++)
    {
        if(A[x][i]!=0)
        {
            B[A[x][i]-1]++;
        }
        if(A[i][y]!=0)
        {
            B[A[i][y]-1]++;
        }
    }

}

bool solve_sudoku(int A[9][9], int B[9],int x, int y)
{
    bool ans;
    if(x==9)
    {
        return true;
    }
    if(y==9)
    {
        return solve_sudoku(A,B,x+1,0);


    }
    if(A[x][y]!=0)
    {
        return solve_sudoku(A,B,x,y+1);

    }
    check_row_column(A,B,x,y);
    check_box(A,B,x,y);
    int i,j,k;
    for(i=0;i<9;i++)
    {

        if(B[i]==0)
        {
            A[x][y]=i+1;
            ans=solve_sudoku(A,B,x,y+1);
            if(ans)
            {
                return true;
            }
            else
            {
                check_row_column(A,B,x,y);
                check_box(A,B,x,y);

            }
        }
    }

 A[x][y]=0;

    return false;

}

int main()
{
    int A[9][9],B[9],i,j,k;
    cout<<"Enter the sudoku puzzle elements "<<endl;
    cout<<"Enter 0 at the blank boxes and elements between 1 to 9 at other places "<<endl;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cin>>A[i][j];
        }
    }
    for(i=0;i<9;i++)
    {
        B[i]=0;
    }
    bool ans=solve_sudoku(A,B,0,0);
    if(ans)
    {
        cout<<"\n\t\tSolved Sudoku "<<endl;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                cout<<A[i][j]<<"  ";
            }
            cout<<"\n";
        }
    }
    else
    {
        cout<<"\nNot Possible to fill this Sudoku ";
        cout<<"\n\t\tSolved Sudoku "<<endl;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                cout<<A[i][j]<<"  ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
