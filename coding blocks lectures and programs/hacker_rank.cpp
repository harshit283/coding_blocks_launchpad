/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[100000];
    priority_queue< pair<int,int> >Q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pair <int,int> my_pair(a[i],i);
        Q.push(my_pair);
    }

   int count=0;
   int i=0;
    while(Q.empty()==false && count<k)
    {
        pair<int,int> my_pair=Q.top();
        Q.pop();
        if(my_pair.second!=i)
        {
             swap(a[i],a[my_pair.second]);
             count++;
        }
        i++;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;

}
*/

#include<bits/stdc++.h>

using namespace std;

long long int A[2000009];

bool compare( pair<long long int , long long int > V1 , pair<long long int , long long int > V2)
{
    if(V1.first != V2.first)
        return V1.first < V2.first;
    else
        return V1.second >V2.second;
}


int main()
{
    long long int N,M,i,k;
    cin>>N>>M;
      assert(3<=N);
    assert(N<=10000000);
   assert(1<=M);
   assert(M<=200000);
    vector < pair<long long int , long long int > > V;
    for(i=1 ; i<=M ; i++)
    {
        long long int a,b;
        cin>>a>>b>>k;
       assert(1<=a);
        assert(a<=N);
        assert(1<=b);
        assert(b<=N);
        assert(a<=b);
        assert(0 <= k);
        assert(k<= 10000000);
        V.push_back(make_pair(a,k));
        V.push_back(make_pair(b,(-1)*k));
    }
    sort(V.begin(), V.end(), compare);
    for(i=0 ; i< V.size() ; i++)
        cout<<V[i].first<<" "<<V[i].second<<endl;
        return 0;
}
