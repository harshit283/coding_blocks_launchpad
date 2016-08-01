/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int >my_queue;
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<k;i++)
        my_queue.push(a[i]);
    for(int i=k;i<n;i++)
    {
        if(my_queue.top() > a[i])
        {
            my_queue.pop();
            my_queue.push(a[i]);
        }
    }

    while(my_queue.empty()==false)
    {
        cout<<my_queue.top()<<" ";
        my_queue.pop();
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
     priority_queue<int ,vector <int> , greater<int > >Q;
    int n;
    int k;
    cin>>n>>k;
    int a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<k;i++)
        Q.push(a[i]);

    int p=0;
    for(int i=k;i<n;i++)
    {
        a[p]=Q.top();
        Q.pop();
        p++;
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
