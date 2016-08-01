#include<iostream>
using namespace std;
int main ()
{
    int n,i,j,k,l;
    cout<<"enter odd number of lines (n>=5)";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"*";
    }
    cout<<endl;
    for(i=1;i<=(n-2)/2+1;i++){
            for(j=1;j<=(n-2)/2+2-i;j++){
                cout<<"*";
            }
            for(k=1;k<=2*i-1;k++){
                cout<<" ";
            }
            for(l=j-1;l>=1;l--){
                cout<<"*";
            }
            cout<<endl;
    }

    for(i=1;i<=(n-2)/2;i++){
        for(j=1;j<=i+1;j++){
            cout<<"*";
        }
        for(k=1;k<=2*((n-2)/2-i)+1;k++){                          //same logic of (n-i)*p+c
                                                                    //we can use the ith loop in reverse order to derive the relations in terms of i
        cout<<" ";
        }
        for(l=j-1;l>=1;l--){
            cout<<"*";
        }
        cout<<endl;
    }

    for(i=1;i<=n;i++){
        cout<<"*";
    }
    return 0;
}













