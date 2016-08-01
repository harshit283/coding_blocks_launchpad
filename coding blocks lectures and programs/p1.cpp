#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"\nEnter the number of rows (odd) "<<endl;
    cin>>n;
    int i=0;
    int j,k;
    while(i<n)
    {
        j=0;

        while(j<i)
        {
            cout<<" ";
            j++;
        }

        j=0;
        k=2*n-2*i-1;

        while(j<k)
        {
            cout<<"*";
            j=j+1;
        }
        i=i+1;
        cout<<"\n";


    }
    return 0;
}
