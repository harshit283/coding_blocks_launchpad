#include<iostream>
using namespace std;
int fact(int n)
{
    int i;
    for(i=n-1;i>=1;i--){
        n=n*i;
    }
    return n;
}
int NCR(int n,int r){
int ans;
ans=fact(n)/(fact(n-r)*fact(r));
return ans;

}
int main()
{
    int i,n,r;
    cout<<"enter the number";
    cin>>i;
    cout<<"factorial of the number is:"<<fact(i)<<endl;
    cout<<"enter values of n and r for calculating ncr"<<endl;
    cout<<"n=";cin>>n;cout<<"r=";cin>>r;
    cout<<"ans is"<<NCR(n,r);

return 0;
}
