#include<bits/stdc++.h>
using namespace std;
///MEMORISATION
int mat[1000];
int min_steps(int n)
{
    if(mat[n]!=-1)
    {
        return mat[n];
    }
    if(n==1)
    {
        mat[n]=0;
        return 0;
    }
    if(n%2==0 && n%3==0)
    {
        int temp=min(min_steps(n-1),min_steps(n/2));
        mat[n]=1+min(temp,min_steps(n/3));
        return mat[n];
    }
    if(n%2==0 && n%3!=0)
    {
        mat[n]= 1+min(min_steps(n-1),min_steps(n/2));
        return mat[n];
    }
    if(n%2!=0 && n%3==0 )
    {
        mat[n]= 1+min(min_steps(n-1),min_steps(n/3));
        return mat[n];
    }
    mat[n]=1+min_steps(n-1);
    return mat[n];

}
int main ()
{
    /*cout<<"enter the number:"<<endl;
    int n;
    cin>>n;
    cout<<"minimum steps required are:";
    for(int i=0;i<=n;i++)
    {
        mat[i]=-1;
    }
    cout<<endl<< min_steps(n);
    */

    ///TOP BOTTOM  APPROACH
     cout<<"enter the number:"<<endl;
    int n;
    cin>>n;
    cout<<"minimum steps required are:";
    int a[n+1];
    a[0]=-1;
    a[1]=0;
    for(int i=2;i<=n;i++)
    {
        int val=i;
        if(val%2==0 && val%3==0)
        {
            int temp=min(a[val/2],a[val/3]);
            a[i]=1+min(a[val-1],temp);
            continue;
        }
        if(val%2==0 && val%3!=0)
        {
            a[i]=1+min(a[val/2],a[val-1]);
            continue;
        }
        if(val%2!=0&&val%3==0)
        {
            a[i]=1+min(a[val/3],a[val-1]);
            continue;
        }
        a[i]=a[val-1]+1;
    }
    cout<<a[n];
    return 0;
}
