#include<iostream>
using namespace std;
void sumofpairs(int a[],int n,int k){

    int i,j,l=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if((a[i]+a[j])==k){
                cout<<"("<<a[i]<<","<<a[j]<<")"<<endl;
                l++;
            }
        }
    }
    if(l==0){
        cout<<"no possible pairs";
    }

}

int main (){

    int a[100],n,k,i;
    cout<<"enter total elements of the array";
    cin>>n;
    cout<<"enter array elements";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter the sum";
    cin>>k;
    sumofpairs(a,n,k);
    return 0;

}
