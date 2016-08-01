#include<iostream>
using namespace std;
int main()
{
    long long int a[100000000],n,i,j,temp ;
    cout<<"enter total number of elements";
    cin>>n;
    for(i=0;i<n;i++){
        a[i]=i;
    }
    for(i=0;i<n-1;i++){
            for(j=i+1;j>=1;j--){
                if(a[j]<a[j-1]){
                    temp=a[j-1];
                    a[j-1]=a[j];
                    a[j]=temp;
                }
                else{
                    break;
                }

            }
    }
    return 0;
}
