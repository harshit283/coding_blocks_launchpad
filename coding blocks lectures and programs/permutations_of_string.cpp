/*



*/
#include<bits/stdc++.h>
using namespace std;
void permutations(char*a,int n,int index)
{
    if(index==n)
    {
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        return ;
    }
    int i=index;
    while(i<n)
    {
        char temp=a[index];
        a[index]=a[i];
        a[i]=temp;
        permutations(a,n,index+1);
        temp=a[index];
        a[index]=a[i];
        a[i]=temp;
        i++;
    }
   return ;
}
void perm(char*a,char*sol,int size)
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

    for(int i=0,j=0;a[j]!='\0';j++)
    {
        char temp;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        sol[size]=a[i];
        perm(a+1,sol,size+1);
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    return ;

}
int main ()
{
    char a[100],sol[100];
    int l=0;
    cout<<"enter the string:"<<endl;
    cin.getline(a,100);
    cout<<"all possible permutations:"<<endl;
    permutations(a,strlen(a),0);
    return 0;
}

