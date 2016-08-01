#include<bits/stdc++.h>
using namespace std;
template<typename t>
int main ()
{
    vector<pair<int,int> > v;
    for(int i=1;i<=5;i++)
    {
        int val1;
        cin>>val1;
        int val2;
        cin>>val2;
        pair<int,int>temp(val1,val2);
        v.push_back(temp);
    }
    heap<int>h;
    h.create_heap(v,100);
    pair<int,int> my_pair=h.extract_min();
    h.decrease_key(4,100);
    my_pair=h.extract_min();
    cout<<endl;
    cout<<my_pair.first<<" "<<my_pair.second;
    return 0;
}
