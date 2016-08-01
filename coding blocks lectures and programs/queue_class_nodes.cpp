#include<iostream>
using namespace std;
template<typename t>
class node
{
    node*next;
    t data;
    node():next(0),data(0){}
    node(const t &el):next(0),data(el){}

    template<typename type>
    friend class queue;

};

template <typename t>
class queue
{
    node<t>*head;
    node<t>*tail;
    public:

    queue(): head(0),tail(0){}

    queue(const queue & q):head(0),tail(0)     //copy constructor
    {
        if(q.head==0)
        {
            return ;
        }
         const node<t>*it=q.head;
        copy(it);
        return ;

    }
     void copy( const node<t>*it)
     {
        while(it)
        {
            node<t>*temp=new node<t>(it->data);
            if(head==0)
            {
                head=tail=temp;
            }
            else
            {
                tail->next=temp;
                tail=temp;
            }
            it=it->next;
        }
        return ;

     }
    void clear()
    {

        if(head==0)
        {
            return ;
        }
        node<t>*it=head;
        while(it)
        {
              it=head->next;
            delete head;
            head=it;
        }

        head=tail=0;

        return ;
    }

    bool empty()
    {
        return head==0;
    }

    void pop_back()
    {
        if(head==0)
        {
            throw" queue is empty";
        }
        node<t>*it=head->next;
        delete head;
        head=it;
        if(head==0)
        {
            head=tail=0;
        }
        return ;
    }

    void push_back(const t & el)
    {
        if(head==0)
        {
            node<t>*temp=new node<t>(el);
            head=tail=temp;
            return ;
        }
        node<t>*temp=new node<t>(el);
        tail->next=temp;
        tail=temp;
        return ;

    }

    t & front()                   //  returning only data part of the nide
    {
        if(head==0)
        {
            throw" queue is empty";
        }
        return head->data;
    }

    const t & front()  const               //  returning only data part of the nide
    {
        if(head==0)
        {
            throw" queue is empty";
        }
        return head->data;
    }

       t& back()
       {
           if(head==0)
           {
               throw" queue is empty";
           }
           return tail->data;
       }

       const t& back()  const
        {
           if(head==0)
           {
               throw" queue is empty";
           }
           return tail->data;
        }

        queue & operator = (const queue & q)
        {
            node<t>*it=q.head;
            copy(it);
            return *this;
        }

        void reverse()
        {
            if(head==0 || head->next==0)
            {
                return ;
            }
            node<t>*it=head;
            node<t>*head1=0;
            node<t>*tail1=0;
            while(it)
            {
                node<t>*temp=new node<t>(it->data);
                if(head1==0)
                {
                    head1=tail1=temp;
                }
                else
                {
                    temp->next=head1;
                    head1=temp;
                }
                it=it->next;

            }
            clear();

            head=head1;
            tail=tail1;
            return ;
        }

        ~queue()
        {
            clear();
        }

};
int main ()
{

    queue<int> q;
    for(int i=1;i<=10;i++)
    {
        q.push_back(i);

    }

   /*  queue<int> r;
      r=q;
     r.front()=100;
     r.back()=100;
    while(!r.empty())
    {
        cout<<r.front()<<" ";
        r.pop_back();
    }
    */
    q.reverse();

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop_back();
    }


    return 0;
}
