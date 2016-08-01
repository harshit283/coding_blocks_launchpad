#include<iostream>
using namespace std;
int revers(int n,int rev)
{   int digit;
    if(n==0)
    {
        return rev;
    }
    digit=n%10;
    rev=rev*10+digit;
    return revers(n/10,rev);

}
int main()
{
    int num,i;
    cout<<"enter the number";
    cin>>num;
    cout<<"reverse number is:"<<revers(num,0);

    return 0;

}
