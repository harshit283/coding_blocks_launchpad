
/// A CODE TO SHOW SOME PROPERTIES OF XOR OPERATOR
/// SANSA AND XOR

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<int> sol;
    for(int c=0;c<t;c++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(n%2==0)
        {
            sol.push_back(0);
            continue;
        }
        int val = a[0];
        for(int i=2;i<n;i+=2)
        {
            val=val ^ a[i];
        }

        sol.push_back(val);
    }

    for(int i=0;i<sol.size();i++)
        cout<<sol[i]<<endl;
    return 0;
}
