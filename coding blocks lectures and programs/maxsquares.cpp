#include<iostream>
using namespace std;
int main()
{
    int N;
    cout<<"Enter the length of base"<<endl;
    cin>>N;
    int i;
    if(N%2==1)
        N--;

    i=((N*N)/2-N)/4;

    if(i<0)
        i=0;
    cout<<"\n"<<i;
    return 0;


}
