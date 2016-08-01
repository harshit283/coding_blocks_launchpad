#include<iostream>
using namespace std;
void insertionsort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j>=1;j--){
            if(a[j]<a[j-1]){
                temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
        }
    }
}
void printarray(int a[],int n){
int i;
for(i=0;i<n;i++){
    cout<<a[i]<<" ";
}

}

int main ()
{
    int a[100],n,i;
    cout<<"enter total elements of the array";
    cin>>n;
    cout<<"enter array elements";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    insertionsort(a,n);
    printarray(a,n);
    return 0;
}
