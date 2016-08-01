#include<bits/stdc++.h>
using namespace std;
template<typename t>
class min_stack
{
    stack<t> s1;
    stack<t> s2;
public:
    min_stack(){}

    void push(t el)
    {
        if(s1.empty())
        {
            s1.push(el);
            s2.push(el);
        }
        else{
            s1.push(el);
            if(el <= s2.top())
                s2.push(el);
        }
    }




    void pop()
    {
        if(s1.empty())
            return ;
        if(s1.top()==s2.top())
            s2.pop();
        s1.pop();
        return ;
    }

    t & get_top()
    {
        if(s1.empty())
            return ;
        else return s1.top();
    }

    const t & get_min()
    {
        if(s2.empty())
            throw"empty";
        return s2.top();
    }
};
int main()
{
    min_stack<int> S;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        S.push(val);
    }

    for(int i=0;i<n;i++)
    {
        cout<<S.get_min()<<" ";
        S.pop();
    }
    return 0;
}
