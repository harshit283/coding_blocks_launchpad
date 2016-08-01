#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    int i=0;
    int j;
    int max=-1000;
    int sum=0;
    int min=1000;
    while(i<n)
    {   cout<<"\n A"<<i+1<<"=";
        cin>>j;
        sum=sum+j;
        if(max<j)
            max=j;
        if(min>j)
            min=j;
            i++;

    }
    cout<<"\nMin "<<min;
    cout<<"\nMax "<<max;
    cout<<"\nMean "<<sum/n;
    return 0;



}

