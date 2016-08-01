#include<iostream>
using namespace std;
void func(int *a,int n,int size)
{
    if(n==0 && size==1){
        return ;
    }
    if(n==0)
    {
        for(int i=0;i<size;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
        return ;
    }

    for(int i=1;i<=n;i++)
    {
        a[size]=i;
        func(a,n-i,size+1);
    }
}
int main()
{
    int a[100],n;
    cout<<"enter the number"<<endl;
    cin>>n;
    cout<<"all combinations are"<<endl;
    func(a,n,0);
}
