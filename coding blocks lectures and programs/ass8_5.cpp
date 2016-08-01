#include<iostream>
#include<cstring>
using namespace std;
int  convert(char*a,int n,int sum)
{
    int j;
   if(*a=='\0'){
    return sum;
   }
   else{
    if(*a=='1'){
        j=1;
    }
    else if(*a=='2'){
        j=2;
    }
    else if(*a=='3'){
        j=3;
    }
    else if(*a=='4'){
       j=4;
    }
    else if(*a=='5'){
        j=5;
    }
    else if(*a=='6'){
        j=6;
    }
    else if(*a=='7'){
        j=7;
    }
    else if(*a=='8'){
        j=8;
    }
    else if(*a=='9'){
        j=9;
    }
    else if(*a=='0'){
        j=0;
    }
    int c=1;
     for(int i=1;i<n;i++){
        c=c*10;
     }

     sum=sum+j*c;
    convert(a+1,n-1,sum);
   }
}
int main()
{
    char a[100];

    int i;
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    cout<<endl<<convert(a,strlen(a),0);
    return 0;
}
