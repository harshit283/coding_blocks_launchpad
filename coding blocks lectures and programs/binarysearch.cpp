#include<iostream>
using namespace std;
int bsearch(int a[],int n,int k){
int start=0,mid,ed=n-1;
mid=(start+ed)/2;
while(start<=ed){
    if(k==a[mid]){
        return mid;
    }
    else if(k>a[mid]){
        start =mid+1;
        mid=(start+ed)/2;
    }
    else if(k<a[mid]){
        ed=mid-1;
        mid=(start+ed)/2;
    }
}
if(start>ed ){
    return -1;
}

}
int main ()
{
    int a[100],n,k,i,ans;
    cout<<"enter total elements in the array";
    cin>>n;
    cout<<"enter sorted array";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter the elements you want to search";
    cin>>k;
   ans=bsearch(a,n,k);
   if(ans==-1){
    cout<<"element you entered is not in the list";
   }
   else{
    cout<<"index of the elements is"<<ans;
   }
   return 0;
}
