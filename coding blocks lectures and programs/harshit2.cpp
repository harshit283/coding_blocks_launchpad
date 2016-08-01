#include<bits/stdc++.h>
using namespace std;
int x=1;
void my_function(int n,char src,char helper,char dest)
{
    if(n==0)
    {
        return ;
    }
    my_function(n-1,src,dest,helper);
    cout<<x<<":-move "<<"disc "<<n<<" from "<<src<<" to "<<dest<<endl;
    x++;
    my_function(n-1,helper,src,dest);
    return ;
}
int main()
{
    int n;
    cin>>n;
    my_function(n,'A','B','C');
    return 0;
}
