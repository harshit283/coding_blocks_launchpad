#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sol[100];
    stack<pair<int,int> >s;
    pair<int,int>my_pair(a[0],1);
    s.push(my_pair);
    sol[0]=1;
    for(int i=1;i<n;i++)
    {
        if(s.top().first > a[i])
        {
            pair<int,int> temp(a[i],1);
            s.push(temp);
            sol[i]=1;
            continue;
        }
        if(s.top().first==a[i])
        {
            pair<int,int>temp(a[i],s.top().second+1);
            s.top()=temp;
            sol[i]=s.top().second;
            continue;
        }
        int sum=1;
        int flag=0;
        while( !s.empty() && s.top().first <=a[i] )
        {
            if(s.top().first==a[i])
            {
                pair<int,int>temp(a[i],s.top().second+1);
                s.top()=temp;
                sol[i]=s.top().second;
                flag++;
                break;
            }
            sum=sum+s.top().second;
            s.pop();
        }

        if(flag==1)
        {
            continue;
        }
            pair<int,int>temp(a[i],sum);
            s.push(temp);
            sol[i]=sum;
    }

    cout<<"STOCK SPANS ARE:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<sol[i]<<" ";
    }

    return 0;
}
