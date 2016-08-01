#include<iostream>
using namespace std;
int main ()
{
   int a[100],b[100],c[100],n,i,j,temp,k;
   cout<<"enter the total number of elements";
   cin>>n;
   cout<<"enter the elements of first array";
   for(i=0;i<n;i++){
    cin>>a[i];
   }

   cout<<"enter the elements of second array";
   for(i=0;i<n;i++){
    cin>>b[i];
   }
    for(i=0,k=0;i<n,k<n;i++,k++){
        c[k]=a[i];
    }
    for(i=0,k=n;i<n,k<2*n;i++,k++){
        c[k]=b[i];
    }

    for(i=0;i<2*n-1;i++){
        for(j=0;j<=2*n-2-i;j++){
            if(c[j]>c[j+1]){
                temp=c[j+1];
                c[j+1]=c[j];
                c[j]=temp;
            }
        }
    }

    cout<<"median is"<<((c[n-1]+c[n])/2.0);
    return 0;

}
