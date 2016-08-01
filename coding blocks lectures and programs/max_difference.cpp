#include<iostream>
using namespace std;
int max_dif(int *a,int n){
  int i,k,x,y,j;
  int dif=-100000;
  for(i=0;i<n;i++){
        x=0;y=0;
    for(j=0;j<=i;j++){
        x=x+a[j];
    }
  for(j=i+1;j<n;j++){
    y=y+a[j];
  }
  if((y-x)>dif){
    dif=y-x;
    k=i;
  }
  }
  return k;

}
int main (){
int a[100],n,i,k;
cout<<"enter the size of array";
cin>>n;
cout<<"enter the array";
for(i=0;i<n;i++){
    cin>>a[i];
}
cout<<"index where the difference is maximum is:"<<max_dif(a,n);
return 0;

}
