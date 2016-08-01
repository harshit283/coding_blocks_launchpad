#include<iostream>
using namespace std;
int main()
{
    float delta,a,b,c,i,k,p,digit,root1,root2;
    float temp,ans,frac=0.1;
    cout<<"enter the values of a,b and c for the equation ax^2+bx+c"<<endl;
    cout<<"a=";cin>>a;
    cout<<"b=";cin>>b;
    cout<<"c=";cin>>c;
    delta=b*b-4*a*c;
    if(delta<0){
        cout<<"roots are imaginary";
    }
    else if(delta==0){
        cout<<"both roots are real and equal to"<<endl;
        cout<<(-b)/2*a;
    }
    else if(delta>0){
    i=1;
    while(i*i<=delta){
        i++;
    }
    ans=i-1;
    k=1;
    while(k<=5){
        p=1;
        temp=ans+frac*p;
        while(temp*temp<=delta){
            p++;
            temp=ans+frac*p;
        }
        digit=p-1;
        ans=ans+frac*digit;ans;
        frac=frac/10;
        k++;
    }
root1=(-b+ans)/2*a;
root2 =(-b-ans)/2*a;
cout<<"both roots are real and distinct"<<endl;
cout<<"root1 is"<<root1<<endl;
cout<<"root2 is"<<root2<<endl;

}return 0;

}

