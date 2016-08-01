#include<iostream>
using namespace std;
int sum(int a[],int n){
  int i,sum=0;
  for(i=0;i<n;i++){
    sum=sum+a[i];
  }
  return sum;
}
void sort(int a[],int n){
    int i,j,temp,pos;
    for(i=0;i<n-1;i++){
    pos=i;
    for(j=i+1;j<=n-1;j++){
        if(a[j]<a[pos]){
            pos=j;
        }
    }
    temp=a[pos];
    a[pos]=a[i];
    a[i]=temp;
    }

}
int main ()
{
    int a[100],n,i;
    cout<<"enter the number of elements in the array(<100)";
    cin>>n;
    cout<<"enter the elements of the array";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"sum of the elements of the array is"<<sum(a,n)<<endl;
    sort(a,n);
    cout<<"sorted array is"<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
