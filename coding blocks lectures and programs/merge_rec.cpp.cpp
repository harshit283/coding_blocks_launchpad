#include<iostream>
using namespace std;
void mergesort(int *a,int*b,int *c,int m,int n )
{
       if(m==0 && n==0){
        return;
       }
    else if( m>0 && n>0 && *a>*b ){
        *c=*b;
        mergesort(a,b+1,c+1,m,n-1);
    }
    else if(m>0 && n>0 && *b>=*a){
        *c=*a;
        mergesort(a+1,b,c+1,m-1,n);
    }
    else if(m==0 && n!=0 ){
        *c=*b;
        mergesort(a,b+1,c+1,m,n-1);
    }
    else if(m!=0 && n==0){
        *c=*a;
        mergesort(a+1,b,c+1,m-1,n);
    }

}

int main ()
{
    int a[100],b[100],c[100];
    int m,n,i;
    cout<<"enter the size of the first array"<<endl;
    cin>>m;
    cout<<"enter the size of the second array"<<endl;
    cin>>n;
    cout<<"enter the sorted array"<<endl;
    for(i=0;i<m;i++)
    {
        cin>>a[i];
    }
    cout<<"enter sorted array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    mergesort(a,b,c,m,n);
    cout<<"sorted array is:"<<endl;
    for(i=0;i<m+n;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}
