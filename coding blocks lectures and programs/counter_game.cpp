#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int arr[100];
    int p=0;
    for(int c=0;c<t;c++)
    {
        unsigned long long int n;
        int l=1;
        cin>>n;
        if(n==1)
        {
            cout<<"Richard";
            continue;
        }
    while(1)
    {
        int count=0;
        int k=0;
        while(k<64)
        {
            if(n&(1ll<<k))
                count++;
            k++;
        }
        if(count==1)
            n=n/2;
        else {
            k=63;
            count=0;
            unsigned long long int temp=n;
            while(k>=0)
            {
                if((temp&(1ll<<k))==0)
                      count++;
                else {
                    temp=1ll<<k;
                    temp=~temp;
                    n=n&temp;
                    break;
                }
                k--;
            }
        }
        l=1-l;
        if(n==1)
        {
            if(l==0)
            arr[p]=false;
            else arr[p]=true;
            p++;
            break;
        }

    }
    }

    for(int i=0;i<p;i++)
        if(arr[i])
        cout<<"Richard"<<endl;
    else cout<<"Louise"<<endl;
    return 0;
}
/*
#include<stdio.h>
int setBits(unsigned long long int n) {
    int count = 0 ;
    while(n) {
        n &= (n-1) ;
        count ++ ;
    }
    return count ;
}

int main() {
    int t ;
    scanf("%d\n",&t) ;
    while(t--) {
        unsigned long long int n ;
        scanf("%llu\n",&n) ;
        if (setBits(n-1) & 1) printf("Louise\n") ;
        else printf("Richard\n") ;
    }
    return 0;
}
*/
