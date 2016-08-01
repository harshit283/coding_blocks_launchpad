#include<iostream>
using namespace std;
void rdup(int *a,int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<=n-1;j++){
            if(a[i]==a[j]){
                for(k=j;k<=n-2;k++){
                    a[k]=a[k+1];
                }
                n--;j--;
            }
        }
    }

cout<<"aray after removal of duplicate elements is";
for(i=0;i<n;i++){
    cout<<a[i]<<" ";
}
return ;
}
int main ()
{
    int a[100],n,i;
    cout<<"enter total elements of the array";
    cin>>n;
    cout<<"enter the array";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    rdup(a,n);
    return 0;
}
