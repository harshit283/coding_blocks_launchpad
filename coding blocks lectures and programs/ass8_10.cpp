#include<iostream>
using namespace std;
int steps(int n)
{
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    else if(n==3){
        return 4;
    }
    return steps(n-1)+steps(n-2)+steps(n-3);
}
int main()
{
    int n;
    cout<<"enter the number of steps"<<endl;
    cin>>n;
    cout<<"total ways to reach top is:"<<endl<<steps(n);
    return 0;
}
