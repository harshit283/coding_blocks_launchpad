#include<iostream>
using namespace std;
int main ()
{
    int a[100][100],i,j,k,l,n,num;
    cout<<"enter the dimension for the square matrix";
    cin>>n;
    cout<<"enter the elements such that every row and column is sorted"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<endl<<"enter the number you want to find";
    cin>>num;
    for(i=0;i<n;i++)
    {
        if(num<=a[i][n-1] )
        {
            for(l=0;l<n;l++)
            {
                if(num==a[i][l])
                {
                    cout<<"number found";
                    return 0;
                }
            }
        }
    }
}
