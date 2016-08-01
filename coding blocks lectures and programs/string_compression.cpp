#include<bits/stdc++.h>
using namespace std;
void compress(char *a)
{
    int i=1;
    int count=1;
    while(a[i]!='\0')
    {
        if(a[i]==a[i-1])
        {
            count++;
            i++;
            continue;
        }
        cout<<a[i-1]<<count;
        count=1;
        i++;
    }
    cout<<a[i-1]<<count;
    return ;
}

int main()
{
    char a[100];
    cin.getline(a,100);
    compress(a);
    return 0;
}
