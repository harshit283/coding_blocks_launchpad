#include<iostream>
using namespace std;
int count0(int n,int i)
{
    if(n==0 && i==0)
    {
        return -1;
    }
    else if(n==0)
    {
        return i;
    }
    else{
        if(n%10==0){
            i++;
            return count0(n/10,i);
        }
        else{
            return count0(n/10,i);
        }
    }

}
int main()
{
    int num,i;
    cout<<"enter the number";
    cin>>num;
    if(num==0){
        cout<<"number of zeros:"<<1;
    }
    else{
    i=count0(num,0);

   if(i==-1)
   {
       cout<<"no zeros in the number";
   }
   else{
    cout<<"number of zeros are:"<<i;
   }
    }
    return 0;

}
