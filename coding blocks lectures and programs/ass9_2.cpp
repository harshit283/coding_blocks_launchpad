#include<iostream>
using namespace std;
void printallsubsets(int *a,int n,int *sol,int siz,int k)
{
    if(n==0)
    {
         int sum=0;
        for(int i=0;i<siz;i++)
        {
            sum+=sol[i];
        }
        if(sum==k){
            for(int  i=0;i<siz;i++){
                cout<<sol[i];
            }
            cout<<endl;
        }
        return ;
    }

    printallsubsets(a+1,n-1,sol,siz,k);
    sol[siz]=*a;
    printallsubsets(a+1,n-1,sol,siz+1,k);
      return ;
}

int main ()
{
    int a[100],n,sol[100],i,k;
    cout<<"enter the size"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the number"<<endl;
    cin>>k;
    cout<<"required subsets are"<<endl;
    printallsubsets(a,n,sol,0,k);
    return 0;
}
