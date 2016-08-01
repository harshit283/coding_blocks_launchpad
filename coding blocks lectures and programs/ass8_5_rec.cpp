#include<iostream>
using namespace std;

double gs(int i)
{
    if(i==0)
    {
        return 1;
    }

    return 0.5*gs(i-1);
}
 double call(int i,int k,double sum)
    {
        if(i==k+1)
        {
            return sum;
        }

        sum=sum+gs(i);
        return call(i+1,k,sum);

    }

int main ()
{
   int i,k;
    cout<<"enter the number of terms"<<endl;
    cin>>k;
    cout<<endl<<"sum"<<endl<<call(0,k,0);
    return 0;
}
