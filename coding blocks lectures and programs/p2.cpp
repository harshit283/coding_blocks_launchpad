#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of rows (odd) "<<endl;
    cin>>n;
    int i,j,l,k;
    i=n/2+1;
    j=n/2;
    l=1;

    while(i>0)
    {
        k=0;
        while(k<j)
        {
            cout<<" ";
            k=k+1;
        }
        j--;
        k=1;
        while(k<=2*l-1)
        {
            cout<<"*";
            k++;
        }
        l++;
        i--;
        cout<<"\n";

    }
    i=n/2;
    j=n-2;
    l=1;
    while(i>=0)
    {
        k=0;
        while(k<l)
        {
            cout<<" ";
            k++;
        }
        l++;
        k=0;
        while(k<j)
        {
            cout<<"*";
            k++;
        }
        j=j-2;
        i--;
        cout<<"\n";
    }

    return 0;
}
