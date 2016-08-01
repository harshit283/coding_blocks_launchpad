#include<iostream>
#include<stack>
using namespace std;
template<typename t>
class queue
{
    stack<t>s1;
    stack<t>s2;
    public:
    queue(){}

    queue(const queue & q)
    {
        s1=q.s1;
        s2=q.s2;
        return ;
    }
    ~queue(){}

    bool is_empty()
    {
        return s1.empty() && s2.empty();
    }

    void push_back(const t & el)
    {
        s1.push(el);
        return ;
    }
    void pop_front()
    {
        if(is_empty())
        {
            throw "queue is empty";
        }
        if(!s2.empty())
        {
            s2.pop();
           return ;
        }
        else{
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
            return ;
        }
    }

    t & get_top()
    {
        if(is_empty())
        {
            throw"queue is empty";
        }
        if(!s2.empty())
        {
            return s2.top();
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
};

int main()
{
    queue<int>Q;
    for(int i=1;i<=10;i++)
    {
        Q.push_back(i);
    }
    /*Q.pop_front();
    Q.pop_front();
    Q.push_back(100);
    while(!Q.is_empty())
    {
        cout<<Q.get_top()<<" ";
        Q.pop_front();
    }
    cout<<endl;
    cout<<Q.is_empty();
    cout<<endl;
    */
    queue<int>P=Q;
    Q.pop_front();
     while(!Q.is_empty())
    {
        cout<<Q.get_top()<<" ";
        Q.pop_front();
    }
    cout<<endl;
    while(!P.is_empty())
    {
        cout<<P.get_top()<<" ";
        P.pop_front();
    }
    return 0;
}
