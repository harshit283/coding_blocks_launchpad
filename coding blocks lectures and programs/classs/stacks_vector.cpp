#include<iostream>
using namespace std;
template<typename t>
class node
{
    node*next;
    t data;
public:
     node():next(0),data(0){}
     node(const t&el):data(el),next(0){}

     template<typename u>
     friend class stack;

};
template<typename u>
class stack
{

    node<t>* head;
    node<t>*tail;

public:
    stack():head(0),tail(0){} //default constructor

    stack(const stack& s):head(s.head),tail(s.tail)
    {
        if(s.head==0)
        {
            return ;
        }
        node<t>*it=s.head;
        copy(it);

    }



    void copy( node<t>*it)
    {
         while(it)
        {
            if(head==0)
            {
                head=tail=it;
            }
            else
            {
                tail->next=it;
                tail=it;
            }
            it=it->next;
        }
    }



    ~stack()
    {
         clear();
    }



    void clear()
    {
           if(head==0)
        {
            return ;
        }

        while(head)
        {
            node<t>*temp=head->next;
            delete head;
            head=temp;
        }

        head=0;
        tail=0;
    }



    stack&operator =(const stack& s)
    {
        clear();
        node<t>*it=s.head;
        copy(it);
        return *this;

    }

    void pop_back()
    {
        node<t>*it=head;
        while(it->next!=0)
        {
            it=it->next;
        }

    }

};

int main ()
{
    return 0;
}
