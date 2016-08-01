#include<bits/stdc++.h>
using namespace std;
void convert_to_binary(unsigned long long int n)
{
    int i,j,k;
    for(i=63;i>=0;i--)
    {
        k=1ll<<i;
        j=n&k;
        j==0?cout<<0:cout<<1;
    }
    return ;
}
int main()
{
    unsigned long long int n;
    /*n=4;
    n&=(n-1);
    cout<<n;*/
    cin>>n;
    convert_to_binary(n);
    //cout<<pow(2,30);
    return 0;
}
