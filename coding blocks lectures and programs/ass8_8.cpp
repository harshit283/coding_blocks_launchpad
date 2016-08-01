#include<iostream>
using namespace std;
int fact(int n){
    if(n==0){
        return 1;
    }
        return n*fact(n-1);

}

int ncr(int n,int r){
int x;
   x=fact(n)/(fact(r)*fact(n-r));
           return  x;

}
int main ()
{
    int a[100];
    int m,n;
    cout<<"enter the number of rows"<<endl;
    cin>>m;
    cout<<"enter the number of columns"<<endl;
    cin>>n;
    cout<<"all possible paths are"<<endl;
    cout<<ncr(m+n-2,n-1);

               return  0;


}
