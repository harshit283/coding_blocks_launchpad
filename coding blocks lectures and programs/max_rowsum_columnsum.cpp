#include<iostream>
using namespace std;
int main ()
{
    int a[10][10],i,j,m,n;
    int sum=0,l=-10000,k=-10000,c,b;
    cout<<"enter rows and column";
    cin>>m>>n;
    cout<<"enter the array"<<endl;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    for(i=0;i<m;i++){
            sum=0;
        for(j=0;j<n;j++){
            sum+=a[i][j];
        }
        if(sum>l){
            l=sum;
            c=i;
        }
    }

    for(j=0;j<n;j++){
        sum=0;
        for(i=0;i<m;i++){
            sum+=a[i][j];
        }
        if(sum>k){
            k=sum;
            b=j;
        }
    }

    if(l>k){
        cout<<"sum of row "<<c+1<<"is max";
    }

    else{
        cout<<"sum of column "<<b+1<<"is max";
    }


    return 0;


}
