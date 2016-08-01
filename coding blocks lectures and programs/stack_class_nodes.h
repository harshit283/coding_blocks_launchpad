#ifndef stack_H
#define stack_H
#include<iostream>
using namespace std;

template<typename type>
class node
{
    node*next;
    type data;
    node():next(0),data(0){}
    node(const type & el):next(0),data(el){}

    template <typename t>
    friend class stack;

};
template<typename t>
class stack
{

     node<t>*head;
     public:

     stack():head(0){}       //default constructor

     stack(const stack & s) :head(0)    //copy constructor
     {
         if(s.head==0)
         {
             return ;
         }
         const node<t>*it=s.head;
         node<t>*ptr;
         while(it)
         {
             node <t> * temp = new node<t>(it->data);

             if(head==0)
             {
                 head=temp;
              ptr=temp;

             }
             else
             {
                 head->next=temp;
                 head=temp;
             }
             it=it->next;
         }
         head=ptr;
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
         head=0;
         return ;
     }
   ~stack()
   {
       clear();

   }
     bool empty()
     {
         return head==0;
     }


     void pop_back()
     {
         if(head==0)
         {

             throw "stack is empty";
         }

         if(head->next==0)
         {
             delete head;
             head=0;
             return ;
         }

         node<t>*temp=head->next;
         delete head;
         head=temp;
         return ;
     }

     void push_back(const t&el)
     {
         if(head==0)
         {
             head=new node<t>(el);
             return ;
         }
         node<t>*temp=new node<t>(el);
         temp->next=head;
         head=temp;
         return ;
     }

     const t &  top()  const        //to return only the data of top node of the stack
     {
         if(head==0)
         {
             throw "stack is empty";
         }
         return head->data;
     }

       t &  top()
     {
         if(head==0)
         {
             cout<<"hello confirmed";
             throw "stack is empty";
         }
         return head->data;

     }

     stack & operator=(const stack & s)
     {
         clear();
       const node<t>*it=s.head;
         node<t>*ptr;
         while(it)
         {
             node <t> * temp = new node<t>(it->data);

             if(head==0)
             {
                 head=temp;
              ptr=temp;

             }
             else
             {
                 head->next=temp;
                 head=temp;
             }
             it=it->next;
         }
         head=ptr;
         return *this;

     }

};
#endif // stack_H
/*
int main()
{
     stack<int>s;
    for(int i=1;i<=10;i++)
    {
        s.push_back(i);
    }
    //stack<int>r=s;
     //s.clear();
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop_back();
    }
    return 0;
}
*/
