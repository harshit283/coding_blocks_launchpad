#include<iostream>
using namespace std;
int maxdif(int *a,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    int csum=0,rsum,l,dif=-10000;
    for(int i=0;i<n;i++){

        csum+=a[i];
        rsum=sum-csum;
        if((rsum-csum)>dif){
            dif=rsum-csum;
            l=i;
        }
    }

    return l;
}
int main ()
{
    int a[100],i,n;
    cout<<"enter the size"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
   cout<<"index is"<<endl<< maxdif(a,n);
   return 0;

}
