#include<iostream>
using namespace std;
int main ()
{
    int a[100][100],b[100][2];
    int i,j,k,pos,x=0,y=0,m,n;

    cout<<"enter the number of rows"<<endl;
    cin>>m;
    cout<<"enter the number of columns"<<endl;
    cin>>n;
    cout<<"enter the elements"<<endl;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    for(i=0;i<m;i++){
            pos=i;
        for(j=0;j<n;j++){
                if(a[i][j]>a[i][pos])
            {
                pos=j;
            }
        }
        for(k=0;k<m;k++){
            if(a[k][pos]<a[i][pos]){
                break;
            }
        }
        if(k==m){
           y++;
        b[x][0]=i;
        b[x][1]=pos;
        x++;
        }
    }

    if(y==0){
        cout<<endl<<"no saddle points present";
    }
    else{
        cout<<endl<<"coordinates of saddle point(in terms of index) are"<<endl;
        for(i=0;i<=x-1;i++){
            cout<<"("<<b[i][0]<<","<<b[i][1]<<")"<<endl;
        }
    }

 return 0;
}
