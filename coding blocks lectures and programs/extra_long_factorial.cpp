#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
int func(int n,int size)
{
    int carry=0;
    for(int i=0;i<size;i++)
    {
        int prod=arr[i]*n+carry;
        arr[i]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        arr[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
}
int main()
{
    int n;
    cin>>n;
    arr[0]=1;
    int size=1;
    for(int i=2;i<=n;i++)
        size=func(i,size);
   for(int i=size-1;i>=0;i--)
        cout<<arr[i];


    return 0;

}



