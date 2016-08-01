#include<iostream>
using namespace std;
long long int fibo(int n,long long int *a)
{
    if(a[n]!=0)
    {
        return a[n];
    }
    if(n<=2)
    {
        a[n]=1;
        return 1;
    }
    a[n]= fibo(n-1,a)+fibo(n-2,a);
    return a[n];
}
int main ()
{
   /*cout<<"enter the n value for nth fibonacci number:"<<endl;e
   int n;
   cin>>n;
   int k;
   int i=1;
   int j=1;
   if(n==1 || n==2)
   {
       cout<<1;
       return 0;
   }
   int  count=2;
   while(count!=n)
   {
       k=i+j;
       i=j;
       j=k;
       count++;
   }
   cout<<k<<endl;
   */

   int n;
   cin>>n;
   long long int a[n+1];
   for(int i=0;i<=n;i++)
   {
       a[i]=0;
   }
   cout<<fibo(n,a);

   return 0;
}
