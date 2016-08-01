#include<iostream>
using namespace std;
class node
{
    int data;
    node * next;
    public:
    node():next(0),data(0){}
    node(int el):next(0),data(el){}

    const int &getdata() const
    {
        return data;
    }

    void setdata(int el)
    {
        data=el;
        return ;
    }
    friend class linkedlist;


};

class linkedlist{

    node*head;
    node*tail;
    public:
     linkedlist():head(0),tail(0){}    //constructor
     linkedlist (const linkedlist & l) :head(0),tail(0)  //  initialise the data members at copy constructor
     {
         cout<<"hello";
         if(l.head==0)
         {
            return ;
         }
        const node*it=l.head;
         while(it)
         {
             node*temp=new node(it->data);
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

     ~linkedlist()      //destructor
     {
         clear();
     }

     void clear()
     {
         while(head)
             {
                 node*temp=head->next;
                 delete head;
                 head=temp;

             }
         head=0;tail=0;
     }

     void printlist()const{
         node*it=head;
         while(it)
         {
             cout<<it->data<<" ";
             it=it->next;
         }
         cout<<endl;
         return ;
     }

     void createlist(int el)
     {
         insertatend(el);
         return ;
     }
     void insertatend(int el)
     {
             node*temp=new node(el);
         if(head==0)
         {
             head=tail=temp;
         }
         else{
            tail->next=temp;
            tail=temp;
         }
         return;
     }

     void insertathead(int el)
     {
         node*temp=new node(el);
         if(head==0)
         {
             head=temp;
             head->next=0;
         }
         else
         {
             temp->next=head;
             head=temp;

         }
         return ;
     }


     void printrev()const
     {
         revhelper(head);
         cout<<endl;
         return ;
     }
     void revhelper(node*head)const
     {
         node*it=head;
         if(it==0)
         {
             return ;
         }
         revhelper(it->next);
         cout<<it->data<<" ";
         return ;
     }


     void reverselinkedlist()
     {
         node*temp;
         node*cur=head;
         node*prev=0;
         while(cur)
         {
             temp=cur->next;
             cur->next=prev;
             prev=cur;
             cur=temp;
         }
        head=prev;
        return ;
     }

     void deletefromk(int k)
     {
         if(k<0 || k==0 ||k>length(head))
         {
             return ;
         }
         else if(k==1)

         {
             node*temp=head->next;
             delete head;
             head=temp;
             return ;
         }
         int i=1;
         node*it=head;
         while(i<k-1)
         {
             it=it->next;
             i++;
         }
          node*temp=it->next->next;
          delete it->next;
          it->next=temp;
          return ;

     }


     int length(node*head)const
     {
         node*it=head;
         int i=0;
         while(it)
         {
             i++;
             it=it->next;
         }
         return i;
     }


     bool operator ==(const linkedlist &l) const
     {
         const node*it1=head;
         const node*it2=l.head;
         while(it1!=0 && it2!=0)
         {
             if(it1->data!=it2->data)
             {
                 return false;
             }
             it1=it1->next;
             it2=it2->next;
         }
         if(it1==0 && it2==0)
         {
             return true;
         }
         else{
            return false;
         }
     }
/*
     linkedlist  & operator +(const linkedlist &l)
     {
         const node*it=l.head;              NOTE THAT IF WE CREATE A SEPERATE LIST and returning it by reference doesn't make any sense
                                             because it will be a local object(linkedkist ans is a local object which is statically allocated)
                                             hence we cannot return it by reference
         while(it)
         {
             (*this).insertatend(it->data);
             it=it->next;
         }
       return *this;

    }
    */
    linkedlist operator + (const linkedlist &l) const
    {
        linkedlist ans=*this;

        ans+=l;
        return ans;
    }

    linkedlist operator~() const
    {
        linkedlist ans=*this;
         node*it=ans.head;
        while(it)
        {
            it->data=~(it->data);
            it=it->next;
        }
        return ans;
    }


    linkedlist & operator =(const linkedlist &l)
    {
        clear();
        node*it=l.head;
        while(it)
        {
            insertatend(it->data);
            it=it->next;
        }

        return *this;
    }

    linkedlist & operator +=(const linkedlist & l)
    {
        node*it=l.head;
        while(it)
        {
            (*this).insertatend(it->data);
            it=it->next;
        }
        return *this;
    }

    linkedlist & operator +=(int val)
    {
        insertatend(val);
        return *this;
    }

    linkedlist operator ++(int val)
    {
           linkedlist ans=*this;
           ++(*this);
           return ans;
    }

    linkedlist & operator++()
    {
        node*it=head;
        while(it)
        {
            it->data=it->data+1;
            it=it->next;
        }
        return *this;
    }

    /*int operator [](int index) const
    {
       const node*it=head;
        int i=1;
        while(i<index+1)
        {
            i++;
            it=it->next;
        }
        return it->data;
    }
*/
    const int & operator [](int index) const
    {
       const node*it=head;
        int i=1;
        while(i<index+1)
        {
            i++;
            it=it->next;
        }
        return it->data;
    }
};
int main ()
{
    linkedlist l1;
    int n;
    cout<<"enter the number of elements:"<<endl;
    cin>>n;
    cout<<"enter the elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        l1.createlist(val);
    }
    l1.printlist();
    linkedlist l2;
    l2=l1;
    l2.printlist();
    linkedlist l3=l1+l2;
    l3.printlist();

    /*
    cout<<"second list is:"<<endl;
    linkedlist l2=l1;
    l2.printlist();
    cout<<endl;

   cout<<"reversed linked list is:"<<endl;

    l1.reverselinkedlist();
    l1.printlist();

    cout<<endl;
    l2.printlist();
    cout<<endl;
    l2.printrev();
    cout<<endl;
    l2.printlist();
    */
/*
    l1.insertathead(100);
    l1.printlist();
    cout<<endl;
    l1.reverselinkedlist();
    l1.printlist();
    cout<<endl;

    l1.deletefromk(6);
    l1.printlist();
*/
/*
   linkedlist l2=l1;
    l2.reverselinkedlist();
    l2.printlist();

    /*if(l1==l2)
    {
        cout<<endl<<"given lists are equal";
    }
    else
    {
        cout<<endl<<"given lists are not equal";
    }
    cout<<endl<<"combined linkedlist are:"<<endl;
    /*

    l1+l2;
    l1.printlist();
    */
   // linkedlist &temp = l1;
    linkedlist l5 = temp;//+l2;
   // l3.printlist();
    /*
    cout<<endl;
    l3=l1+l1;
    l3.printlist();
    */

/*
    linkedlist l4=~l2;
    l4.printlist();
    cout<<endl;
    l2.printlist();
    */
    /*
    l1=l2;
    l1.printlist();
    l2.printlist();
    */

/*
    l1+=l2;
    l1.printlist();
    l2.printlist();
    l1+=100;
    l1.printlist();
    */
/*
     (l1++).printlist();
     (++l1).printlist();
     */





    return 0;
}
