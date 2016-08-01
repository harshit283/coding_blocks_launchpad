#include<iostream>
using namespace std;
int len(char *a)
{
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    return i;
}

void rev(char*a,int j,int i){
     char temp;
     if(j<=i){
        return ;
     }
     else {
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
        rev(a,j-1,i+1);
     }
}

int main()
{
    char a[100];
    int i;
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    rev(a,len(a)-1,0);
    cout<<endl<<"reversed string is:"<<a;
}
