#include<iostream>
using namespace std;
int bsearch(int*a,int start,int ed,int k){

  if(start>ed)
  {
      return -1;
  }
 int mid=(start+ed)/2;
if(k==a[mid]){
    return mid;
}
else if(k>a[mid]){
    return bsearch(a,mid+1,ed,k);
}
else{
    return bsearch(a,start,mid-1,k);
}


}
int main()
{
    int a[100],k,n,j,i;
    cout<<"enter total elements of the array";
    cin>>n;
    cout<<"entered array in sorted order"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the value you want to search";
    cin>>k;
    j=bsearch(a,0,n-1,k);
    if(j==-1)
    {
        cout<<"number not found";
    }
    else
    cout<<"its index is"<<j;
}
