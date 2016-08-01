#include<iostream>
using namespace std;
int fact(int n){
    if(n==0){
        return 1;
    }
    int i;
    for(i=n-1;i>=1;i--){
    n=n*i;
}
return n;

}
int ncr(int n,int r){
   int x;

    x=fact(n)/(fact(n-r)*fact(r));
    return x;

}

int main()
{
    int n,i,j,k,l;
    cout<<"enter the number of lines"<<endl;
    cin>>n;
    cout<<endl;
       i=1;
       while(i<=n)
       {
           j=1;
           while(j<=n-i){
            cout<<"   ";
            j++;
           }
           l=1;k=1;
          while(l<=2*i-1){
            cout<<ncr(i-1,k-1)<<"  ";
            k++;l++;
            if(l>=2*i-1){
                break;
            }
            else{
                cout<<"   ";
                l++;
            }
          }
          cout<<endl<<endl<<endl;
          i++;
       }

      return 0;
}





