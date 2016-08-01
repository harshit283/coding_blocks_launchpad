#include<iostream>
using namespace std;
int main ()
{
    int a[100][100];
    int n,m,p=0,q=0,r=0,s=0;
    int i=0,j=0;
    int l;

    cout<<"enter rows"<<endl;
    cin>>m;
    cout<<"enter columns"<<endl;
    cin>>n;
     int k=m*n;
     cout<<"enter the elements"<<endl;
     for(i=0;i<m;i++)
     {
         for(j=0;j<n;j++){
            cin>>a[i][j];
         }
     }
    cout<<"elements in spiral order are:"<<endl;
    i=0,j=0;
    for(l=0;l<100;l++)
    {
        while(j<=n-l-1){
            cout<<a[i][j]<<" ";
            j++;p++;
        }
        if(p+q+r+s==k){
            return 0 ;
        }
        j--;i++;
        while(i<=m-1-l){
            cout<<a[i][j]<<" ";
            i++;q++;
        }
         if(p+q+r+s==k){
            return 0;
        }
        i--;j--;
        while(j>=l){
            cout<<a[i][j]<<" ";
            j--;r++;
        }
         if(p+q+r+s==k){
            return 0 ;
        }
        j++;i--;
        while(i>=l+1){
            cout<<a[i][j]<<" ";
            i--;s++;
        }
         if(p+q+r+s==k){
            return 0 ;
        }
        j++;i++;
    }

}
