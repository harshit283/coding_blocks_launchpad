#include<iostream>
using namespace std;
int x=0;
void printallsubsets(char *a,int  n,char *sol,int siz)
{
    x++;
    if(n==0)
    {
            for(int  i=0;i<siz;i++){
                cout<<sol[i];
            }
            cout<<endl;
        return ;
    }


    printallsubsets(a+1,n-1,sol,siz);
    sol[siz]=*a;
    printallsubsets(a+1,n-1,sol,siz+1);
      return ;
}

int main ()
{
    char a[100],sol[100];
    int n,i;
    cout<<"enter the size"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"required subsets are"<<endl;
    printallsubsets(a,n,sol,0);
    cout<<"x is:"<<x;
    return 0;
}
