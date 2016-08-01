#include<iostream>
using namespace std;
int main ()
{
    int a,b,i,j;
    cout<<"enter two numbers";
    cin>>a>>b;
    i=a;j=b;
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    cout<<"lcm is"<<(i*j)/a;
    return 0;
}
