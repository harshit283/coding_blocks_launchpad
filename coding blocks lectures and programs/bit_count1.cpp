#include<iostream>
using namespace std;
int main()
{
    int N;
    cout<<"Enter the number "<<endl;
    cin>>N;
    int sum=0;
    int i=0;
    while(i<32)
    {

       if((N&1)==1)
          sum++;

        N=N>>1;
        i++;
    }
    cout<<"\nAns is "<<sum;
    return 0;
}
