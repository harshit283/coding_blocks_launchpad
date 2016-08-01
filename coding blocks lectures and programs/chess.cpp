#include<iostream>
using namespace std;
int main ()
{
    int a[10][10],b[2][2];
    int i,j,k=0,l,n,c;
    cout<<"enter the dimension of the square array";
    cin>>n;
    cout<<"enter only two ones and all other zeros";
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
            if(a[i][j]==1){
                b[0][k]=i;
                b[1][k]=j;
                k++;
            }
        }
    }
    i=b[0][0];j=b[1][0];k=b[0][1];l=b[1][1];
    if(k==i || l==j){
        cout<<"not safe";
    }
    else if((i-k)==(j-l)||(i-k)==(l-j)){
        cout<<"unsafe";
    }

    else {
        cout<<"safe";
    }

return 0;



}
