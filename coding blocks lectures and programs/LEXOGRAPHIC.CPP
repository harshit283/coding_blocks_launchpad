#include<iostream>
using namespace std;
int main ()
{
    char ch;
    int i=0,j=0,k=0,l=0,x,y,a,b;
    ch=cin.get();
    while(ch!='$'){
        if(ch=='N'){
            i++;
        }
        else if(ch=='S'){
        j++;
        }
        else if(ch=='W'){
            k++;
        }
        else if(ch=='E'){
            l++;
        }
        ch=cin.get();
    }

    x=i-j;y=l-k;
    if(x==0 && y==0)
    {
        cout<<"initial position";
    }
    else {
    if(y>0){
        for(a=y;y>0;y--){
            cout<<'E';
        }
    }
    if(x>0){
        for(b=x;b>0;b--){
            cout<<'N';
        }
    }
    if (x<0){
        for(a=-x;a>0;a--){
            cout<<'S';
        }
    }
           if(y<0){
          for(b=-y;b>0;b--){
            cout<<'W';
          }
           }
    }
    return 0;
    }




