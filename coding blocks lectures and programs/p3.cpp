#include<iostream>
using namespace std;
int main()
{
    int N;
    cout<<"\nEnter the number of rows "<<endl;
    cin>>N;
    int i,j,k;
    char ch;
    for(i=0;i<N;i++)
    {
        ch='A';
        for(j=N-i;j>0;j--)
        {
            cout<<ch;
            ch=ch+1;
        }
        ch--;
        for(j=N-i;j>0;j--)
        {
            cout<<ch;
            ch=ch-1;
        }
        cout<<"\n";

    }
    return 0;
}
