#include<iostream>
using namespace std;
int len(char*a){
int i=0;
while(a[i]!='\0'){
    i++;
}
return i;
}

void rev(char*a,int n){
    int i,j;
    char temp;
    for(i=0,j=n-1;i<=(n-2)/2;i++,j--){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    a[n]='\0';
    cout<<"reverse string is:-";
    cout<<a;
    return ;

}
int main()
{
    char a[100];int i;
    cout<<"enter the string:-";
    cin.getline(a,100);
    i=len(a);
    rev(a,i);
}
