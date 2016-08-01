#include<iostream>
using namespace std;
int len(char *a){
int i=0;
while(a[i]!=0){
    i++;
}

   return i;

}


int htoi(char*A){
    int sum=0,l=1,i,n=len(A),j;

for(i=n-1;i>=0;i--){

    if(A[i]=='a')
        {
            j=10;
        }
        else if(A[i]=='b')
        {
            j=11;
        }
        else if(A[i]=='c')
        {
            j=12;
        }
        else if(A[i]=='d')
        {
            j=13;
        }
        else if(A[i]=='e')
        {
            j=14;
        }
        else if(A[i]=='f')
        {
            j=15;
        }
        else if(A[i]=='1')
        {
            j=1;
        }
        else if(A[i]=='2')
        {
            j=2;
        }
        else if(A[i]=='3')
        {
            j=3;
        }
        else if(A[i]=='4')
        {
            j=4;
        }
        else if(A[i]=='5')
        {
            j=5;
        }
        else if(A[i]=='6')
        {
            j=6;
        }
        else if(A[i]=='7')
        {
            j=7;
        }
        else if(A[i]=='8')
        {
            j=8;
        }
        else if(A[i]=='9')
        {
            j=9;
        }
        else if(A[i]=='0')
        {
            j=0;
        }

     sum=sum+j*l;
     l=l*16;

}

return sum;


}
int main ()
{
    char a[100];

    cout<<"enter the string";
    cin.getline(a,100);
    cout<<"corresponding decimal number will be"<<htoi(a);
    return 0;
}

