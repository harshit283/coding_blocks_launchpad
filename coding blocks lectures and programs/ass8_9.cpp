   /*#include<iostream>
using namespace std;
int len(char*a)
{
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    return i;
}

int main ()
{
    char a[100];
    int i,n,k;
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    n=len(a);
    for(i=0;i<=n-2;i++){
      if(a[i]==a[i+1]) {
        for(k=i+1;k<=n-2;k++){
            a[k]=a[k+1];
        }
        n--;i--;
      }
    }
     cout<<"required string is:"<<endl;
    for(i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
    }
*/

#include<iostream>
using namespace std;
int dup(char*a,int n,int i)
{
    int k;
    if(i==n-1){
        return n;
    }

    if(a[i]==a[i+1]){
        for(k=i+1;k<=n-2;k++){
            a[k]=a[k+1];
        }
        n--;i--;
    }
    dup(a,n,i+1);

}
int len(char*a){
    int i=0;
    while(a[i]!='\0'){
        i++;
    }

return i;

}
int main ()
{
    char a[100];
    int i,n,k;
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    n=len(a);
    k=dup(a,n,0);
    cout<<"required string is:"<<endl;
    for(i=0;i<k;i++){
        cout<<a[i];
    }
    return 0;
}
