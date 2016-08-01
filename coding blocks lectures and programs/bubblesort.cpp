#include<iostream>
using namespace std;
int main ()
{
    int arr[100],i,j,n,temp;
    cout<<"enter total numbers(<100)";
    cin>>n;
    for(i=0;i<n;i++){
            cin>>arr[i];

    }
    for(i=0;i<n-1;i++){
            for(j=0;j<=n-2-i;j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }

    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }






    return 0;


}
