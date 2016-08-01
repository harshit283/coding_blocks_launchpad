#include<iostream>
using namespace std;
int prime(int n){
    int i;
    i=2;
    while(i<n){
        if(n%i==0){
          return -1;
        }
        else{
        i++;
        }
    }
        return n;

}
void prime2toN(int n){

int i=2;int ans;
while(i<=n){
    ans=prime(i);
    if(ans!=-1){
    cout<<ans<<" ";
    }
    i++;
}
}


int main(){
  int n;

cout<<"enter the number upto which you primes";
cin>>n;
prime2toN(n);

}
