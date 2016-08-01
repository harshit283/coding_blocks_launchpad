#include<iostream>
using namespace std;
int main()
{
    int N;
    cout<<"Enter the number "<<endl;
    cin>>N;
    int r,sum=0;
    while(N>0)
    {
        r=N%2;
        N=N/2;
        if(r==1)
            sum=sum+r;


    }
    cout<<"\nAns is "<<sum;
    return 0;
}
