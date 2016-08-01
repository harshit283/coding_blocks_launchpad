/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int sol[100000];
    sol[0]=1;
    for(int i=1;i<n;i++)
    {
        if(a[i] > a[i-1])
            sol[i]=sol[i-1]+1;
        else sol[i]=1;
    }

    int sum=sol[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(a[i] > a[i+1])
        {
            if(sol[i] <= sol[i+1])
                sol[i]=sol[i+1]+1;
        }
        sum+=sol[i];
    }


    cout<<sum;
    return 0;
}
*/


