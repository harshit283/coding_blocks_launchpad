#include<iostream>
using namespace std;
void func(int i,int k)
{
    if(i>k){
        return ;
    }
    cout<<i<<endl;
    func(10*i,k);
    for(int j=1;j<=9;j++){
        func(10*i+j,k);
    }

}
int main ()
{
    int n,i;
    cout<<"enter the number"<<endl;
    cin>>n;
    cout<<"lexographical order is:"<<endl;
    for(i=1;i<=9;i++)
        func(i,n);
    return 0;

}
