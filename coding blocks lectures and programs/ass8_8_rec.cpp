#include<iostream>
using namespace std;
int sum(int m,int n)
{

    if(m==1 || n==1)
    {
        return 1;

    }
    return sum(m,n-1)+sum(m-1,n);
}
int main()
{
    int m,n;
    cout<<"enter the rows"<<endl;
    cin>>m;
    cout<<"enter the columns"<<endl;
    cin>>n;
    cout<<"total ways"<<endl<<sum(m,n);
    return 0;






}
