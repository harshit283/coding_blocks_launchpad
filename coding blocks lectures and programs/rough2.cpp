/*#include<iostream>
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

}

return 0;

}
*/
/*
#include<iostream>
using namespace std;
void func(char*a,char*sol,int size)
{
    if(*a=='\0')
    {
        for(int i=0;i<size;i++)
        {
            cout<<sol[i];
        }
        cout<<endl;
        return ;
    }

    func(a+1,sol,size);
    sol[size]=*a;
    func(a+1,sol,size+1);
    return ;
}
int main ()
{
    char a[100],sol[100];
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    cout<<"all possible subsets are:"<<endl;
    func(a,sol,0);
    return 0;

}
*/
#include<iostream>
using namespace std;

/*
int minCoins(int S, int *denom, int denomsize) {
    if (S <= 0) {
        return -1;
    }
    for (int i = 0; i < denomsize; i++) {
        if (denom[i] == S){
            return 1;
        }
    }
    int ans = -1;
    for (int i = 0; i < denomsize; i++) {
        int subans = minCoins(S-denom[i], denom, denomsize);
        if (subans!= -1) {
            if (ans == -1 || ans > subans) {
                ans = subans;
            }
        }
    }
    if ( ans == -1) {
        return ans;
    } else {
        return ans+1;
    }
}
int main() {
    int a[100],k,n;
    cout<<"enter the size of the array:"<<endl;
    cin>>n;
    cout<<"enter the array containing the denominations:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the sum:"<<endl;
    cin>>k;
   cout<<minCoins(k,a,n);
   */
   int main()
   {

   int a=5;
   int b=10;
     cout<<(a==b)<<endl;
   cout<<a<<endl<<b;
    return 0;
}
