#include<iostream>
#include<queue>
using namespace std;
template<typename t>
class stack
{
    queue<t>q1;
    queue<t>q2;

    public:
    stack(){}

    stack(const stack & s)
    {
        q1=s.q1;
        q2=s.q2;
        return ;
    }
    ~stack(){}

    bool is_empty()
    {
        return q1.empty() && q2.empty();
    }

    void pop()
    {
        if(is_empty())
        {
            throw"stack is empty";
        }
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ;
    }
    void push(const t & el)
    {
        q1.push(el);
        return ;
    }
    t & get_top()
    {
        if(is_empty())
        {
            throw"stack is empty";
        }
        return q1.back();
    }


};
int main ()
{
    stack<int>s;
    for(int i=1;i<=10;i++)
    {
        s.push(i);
    }
    while(!s.is_empty())
    {
        cout<<s.get_top()<<" ";
        s.pop();
    }
    return 0;
}
