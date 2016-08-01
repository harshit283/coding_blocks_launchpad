#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int a[100];
    int m;
    cout<<"enter the total elements";
    cin>>m;
    int j;
    int flag=0;
    cout<<"enter the elements:"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<m;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]==a[j])
            {
                flag=1;
                break;
            }

        }
        if(flag==1)
        {
            int k;
            k=i;
            while(k<=m-2)
            {
                a[k]=a[k+1];
                k++;
            }
            i--;m--;flag=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
