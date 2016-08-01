#include<iostream>
using namespace std;
int  search7(int *a,int n,int index)
{
    if(index==n){
        return -1;
    }
    else{
            if(a[index]==7)
            {
                return index;
            }
            else
       search7(a,n,index+1);
    }
}
int main ()
{
    int a[100],n,i,k;
    cout<<"enter the size";
    cin>>n;
    cout<<"enter the array"<<endl;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    k=search7(a,n,0);
    if(k==-1)
    {
        cout<<"not found";
    }
    else{
        cout<<"index is"<<k;
    }

    return 0;
}
