#include<iostream>
using namespace std;
int main()
{
    int i,j,k=1,l=0,num;
    cout<<"enter the number";
    cin>>num;
    i=1;
    while(i<=num){
        j=1;
    while(j<=i){
        if(i%2!=0){
            cout<<k;
        k=1-k;
        if(i==j){
            k=1;
        }
        }
        else{
            cout<<l;
        l=1-l;
        }
        j++;
    }
    cout<<endl;
    i++;
}
  return 0;
}
