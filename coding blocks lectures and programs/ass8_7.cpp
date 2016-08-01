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

bool checkrev(char*a,char*b,int j,int i)
{
    if(j<=i)
    {
        return true;
    }

    else{
        if(a[i]==b[j])
        {
            return checkrev(a,b,j-1,i+1);
        }
        else{
            return false;
        }
    }
}

int main()
{
    char a[100],b[100];
    int i;
    cout<<"enter the first string"<<endl;
    cin.getline(a,100);
    cout<<"enter the second string"<<endl;
    cin.getline(b,100);
    if(len(a)!=len(b)){
        cout<<"no";
    }
    else{
   i= checkrev(a,b,len(a)-1,0);
   if(i==1){
    cout<<"yes";
   }
    else{
        cout<<"no";
    }
    }
    return 0;
}
