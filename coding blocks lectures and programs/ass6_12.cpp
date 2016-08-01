#include<iostream>
using namespace std;
int main ()
{
    int a[100],b[200],n,i,j;
    cout<<"enter the size"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0,j=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            b[j]=a[i];
            j++;

        }
    }
    for(i=j;i<n;i++)
    {
        b[i]=0;
    }
    cout<<"required array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;

}

/*
#include<iostream>
using namespace std;
int main()
{
    int a[100],i,k,n,l;
    cout<<"enter the size of array(<100)";
    cin>>n;
    cout<<"enter the array";
    for(i=0;i<n;i++){
        cin>>a[i];
    }

         l=n;a[n]=0;
        for(i=0;i<=n-2;i++){                           //check that changing value of i wont change anything
            if(a[i]==0){
                for(k=i;k<=n-1;k++){
                    a[k]=a[k+1];
                }
                n--;i--;
            }
        }

        cout<<"aray after pushing zeros at the end is:";
        for(i=0;i<l;i++){
            cout<<a[i]<<" ";
        }

        return 0;
        }
        */


/*
#include<bits/stdc++.h>
using namespace std;
bool palindrome(char*a)
{
    int i=0;
    int j=strlen(a)-1;
    while(j>i)
    {
        if(a[j]!=a[i])
        {
            return false;
        }
        j--;i++;
    }
    return true;
}
int main()
{
    char a[1000];
    char b[1000];
    cin.getline(a,1000);
    int k=0;
    int count=0;
    int n=strlen(a);
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j<n)
        {
            int l=i;
            k=0;
            while(l<=j)
            {
                b[k]=a[l];
                k++;l++;
            }
            b[k]='\0';
            if(palindrome(b))
               count++;
            j++;
        }
    }
    cout<<endl<<"count is:"<<endl<<count;

    return 0;
}
*/













