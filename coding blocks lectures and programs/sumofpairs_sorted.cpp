#include<iostream>
using namespace std;
void sum(int a[],int n,int k){
int i=0,j=n-1,l=0;
while(j>i){
    if((a[i]+a[j])==k){
        cout<<"("<<a[i]<<","<<a[j]<<")"<<endl;
        i++;j--;l++;
    }
    else if((a[i]+a[i])>k){
        j--;
    }
    else if((a[i]+a[i])<k){
        i++;
    }
}
if(l==0){
    cout<<"no such pairs";
}

}
int main ()
{
    int a[100],i,n,k;
    cout<<"enter total elements of the array";
    cin>>n;
    cout<<"enter sorted array";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter the number";
    cin>>k;
    sum(a,n,k);
}
