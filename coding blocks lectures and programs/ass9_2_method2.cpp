#include<iostream>
using namespace std;
void subsets(int *a,int *sol,int size,int k,int sum)
{
    if(*a=='\0' && sum==k)

    {
        for(int i=0;i<size;i++)
        {
            cout<<sol[i];
        }
        cout<<endl;
        return ;
    }
       if(*a=='\0')
        {
            return ;
        }
    subsets(a+1,sol,size,k,sum);
    sol[size]=*a;
    subsets(a+1,sol,size+1,k,sum+*a);
    return ;

}
int main ()
{
    int a[100];
    int sol[100];
    int n,k,i;
    cout<<"enter the size"<<endl;
    cin>>n;
    cout<<"enter the string:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the number:"<<endl;
    cin>>k;
    cout<<"subsets are:"<<endl;
    subsets(a,sol,0,k,0);
    return 0;
}
