#include<iostream>
using namespace std;
void ctof(int initial,int final,int step){
    int i;
    for(i=initial;i<=final;i+=step){
        cout<<i<<" "<<5*(i-32)/9<<endl;
    }
    return ;
}

int main ()
{
  int i,j,k;
    cout<<"enter initial value";
    cin>>i;
    cout<<"enter the final value";
    cin>>j;
    cout<<"enter the final value";
    cin>>k;
    ctof(i,j,k);
    return 0;
}
