/*
T[i][j]=max{ t[i][j-1],
price[j]-price[m] for m=0,1,2 .... j-1 + t[i-1][m]; ///this solution is in 0(day*day*k);
 see pic from phone
  for the further optimized solution i.e. in 0(day*k);
*/
///HACKER RANK STOCK MAXIMISE

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long int arr[10];
    for(int c=0;c<t;c++)
    {
        long long int n;
        cin>>n;
        long long int a[50000];
        for(int i=0;i<n;i++)
            cin>>a[i];

        long long int curr_max=-1;
        long long int profit=0;
        for(int i=n-1;i>=0;i--)
        {
            if(curr_max < a[i])
                curr_max=a[i];
            else profit+=curr_max-a[i];
        }
        arr[c]=profit;
    }

    return 0;
}
