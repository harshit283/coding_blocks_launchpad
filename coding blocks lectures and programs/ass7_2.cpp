/*#include<iostream>
using namespace std;
int main ()
{
    int a[100][100],b[100];
    int i,j,n,l,k=0;
    cout<<"enter the dimension of the square matrix"<<endl;
    cin>>n;
    cout<<"enter only ones and zeros"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0){
                b[k]=i;
                k++;
                break;
            }
        }
    }

    k++;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
            if(a[j][i]==0)
            {
                b[k]=i;
                k++;
                break;
            }
        }
    }
    k=0;
    for(i=0;i<n;i++){
            if(i==b[k]){
         for(j=0;j<n;j++){
             a[i][j]=0;
              }
            k++;
            }
        }
        k++;

     for(i=0;i<n;i++)
     {
             if(i==b[k]){
             for(j=0;j<n;j++){
                a[j][i]=0;
             }
                k++;
             }
         }

     cout<<"required array is:"<<endl;
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             cout<<a[i][j]<<" ";
         }
         cout<<endl;
     }

    return 0;

}
*/

///METHOD*2
/// O(N^2)  WITH CONSTANT SPACE COMPLEXITY

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100][100];
    cout<<"enter zeros and ones"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }

    for(int i=0;i<n;i++)
    {
        int j;
        for( j=0;j<n;j++)
        {
            if(a[i][j]==0)
                break;
        }
        if(j==n)
        {
            for(int k=0;k<n;k++)
                a[i][k]=2;
        }
    }

    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            if(a[j][i]==0)
            {
                break;
            }
        }
        if(j==n)
        {
            int k;
            for(k=0;k<n;k++)
            {
                if(a[k][i]==2)
                    a[k][i]=3;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==3)
                a[i][j]=1;
            else a[i][j]=0;
        }
    }

    cout<<"ANSWER IS:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
