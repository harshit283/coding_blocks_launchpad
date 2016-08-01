#include<iostream>
using namespace std;
int main ()
{
   int i,j,k,l,n;
   cin>>n;
   cout<<endl;
   i=1;
   while(i<=n)
   {
       j=1;k=1;l=0;
       while(j<=i)
       {

           if(i%2!=0)
           {
               cout<<k<<" ";
               k=1-k;
           }
           else
           {
               cout<<l<<" ";
               l=1-l;
           }
           j++;
       }
       cout<<endl<<endl;
       i++;
   }
    return 0;
}
