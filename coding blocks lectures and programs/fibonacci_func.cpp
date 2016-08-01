#include<iostream>
using namespace std;
int fibonacci(int n){
    int i=1,j=1,k;
    if(n==0){
        return 1;
    }
    while(n>=j){
        if(n==j){
            return 1;
        }
        else{
            k=i+j;
            i=j;
            j=k;
        }
    }
    if(j>n){
        return 0;
    }
}
int main ()
{
    int n,ans;
    cout<<"enter a number";
    cin>>n;
    ans=fibonacci(n);
    if(ans==1){
        cout<<"member of fibonacci";
    }
    else if(ans==0){
        cout<<"not a member of fibonacci";
    }
    return 0;
}
