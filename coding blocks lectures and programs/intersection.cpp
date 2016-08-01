#include<iostream>
using namespace std;
int main()
{
    int a[100],b[100],n,m,i,j;
    cout<<"enter the total elements for first array";
    cin>>n;
    cout<<"enter total elements for second array";
    cin>>m;
    cout<<"enter elements for first array";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter elements for second array";
    for(i=0;i<m;i++){
        cin>>b[i];
    }
   cout<<" intersection of the arrays are as follows:";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i]==b[j]){
                cout<<b[j]<<" ";
                break;
            }
        }
    }

}
