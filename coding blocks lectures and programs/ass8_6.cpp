#include<iostream>
using namespace std;
 double sum(int i,double a,int k){

        if(k==i){
            return 1;
        }
        else{
            double ans=0.5*sum(i,a/2,k+1);
                 return ans;

        }

    }

int main ()
{
    int n,i;
    double a,s=0;
    cout<<"enter the number";
    cin>>n;
    for(i=1;i<=n;i++){
        a=1;
    s+=sum(i,a,0);
    }
    cout<<"sum is"<<1+s;
    return 0;
}
