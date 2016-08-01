#include<iostream>
using namespace std;
int main ()
{
    int a[100],b[100];
    int m,n;
    cin>>m>>n;
    cout<<"enter first array"<<endl;
    for(int i=0;i<m;i++)
        cin>>a[i];
    cout<<"enter second array"<<endl;
    for(int i=0;i<n;i++)
    cin>>b[i];

    int i=0,j=0;
    int sum1=0,sum2=0;
    int f_sum=0;
    while(i<m && j<n)
    {
       if(a[i]==b[j])
       {
           sum1+=a[i];
           sum2+=a[i];
           f_sum+=max(sum1,sum2);
           sum1=0;
           sum2=0;
       }
       else{
             sum1+=a[i];
             sum2+=b[j];
       }

       i++;j++;
    }
    f_sum+=max(sum1,sum2);
    if(i==m)
    {
        while(j<n)
        {
            f_sum+=b[j];
            j++;
        }
    }
    else if(j==n)
    {
        while(i<m)
        {
            f_sum+=a[i];
            i++;
        }
    }
    cout<<f_sum;
    return 0;
}
