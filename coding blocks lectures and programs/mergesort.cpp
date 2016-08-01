#include<iostream>
using namespace std;
void mergesort(int a[],int b[],int m,int n){
    int i=m-1,j=n-1,k=m+n-1,l;
    while(i>=0 && j>=0){
        if(a[i]<b[j]){
            a[k]=b[j];
            k--;j--;
        }
        else{
            a[k]=a[i];
            k--;i--;
        }

    }
    if(i<0){
        for(l=0;l<=j;l++){
            a[l]=b[l];
        }
    }
     return;
}
int main ()
{
    int a[100],b[50],m,n,i;
    cout<<"enter the total elements for the first array(<50)";
    cin>>m;
    cout<<"enter the total elements for second array(<50)";
    cin>>n;
    cout<<"enter first sorted array";
    for(i=0;i<m;i++){
        cin>>a[i];
    }
    cout<<"enter second sorted array";
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    mergesort(a,b,m,n);
    cout<<"sorted array is";
    for(i=0;i<m+n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
