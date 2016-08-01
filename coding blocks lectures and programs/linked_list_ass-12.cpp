#include<iostream>
using namespace std;

struct node{

    int data;
    node*next;

};

void begin(node*&head,int el)
{

     node*temp=new node;
     temp->data=el;
     temp->next=head;
     head=temp;

}

void print(node*head)
{
    while(head!=0)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return ;
}

int len(node*head)
{
    int i=0;
    while(head!=0)
    {
        i++;
        head=head->next;
    }
    return i;
}


node *rev(node*head)
{
    node*curr=head;
    node*prev=0;
    node*next;
    while(curr!=0)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void  func(node*&head,int k)
{
    if(k==0)
    {
        return ;
    }

     int i=1;
    node*temp1=head;
    node*ptr=head;
    while(i<k)
    {
       i++;
       temp1=temp1->next;
    }

    node*temp2=temp1->next;
    node*ptr2=temp2;
    temp1->next=0;
    node*temp3=rev(head);

     i=1;
    while(i<k)
    {
        i++;
        ptr2=ptr2->next;

    }
    node*ptr3=ptr2->next;
    ptr2->next=0;
    node*temp4=rev(temp2);

     node*ptr4=head;
     ptr4->next=temp4;

    head=temp3;
    temp2->next=ptr3;

    return ;

}

void shift(node*&head)
{                                  //try this by using the concept of merging

    int  n=len(head);
    int k=0;

    if(head->data%2==0)
    {
        node*a=head->next;
        node*prevofa=head;
        while(a!=0)
        {
           k++;
            if(a->data%2!=0)
            {
                break;
            }
            a=a->next;
            prevofa=prevofa->next;
        }
        if(a==0)
        {
            return ;
        }
        else{
                node*temp=head;
                head=a;
           node*ptr=temp;
           while(ptr->next!=0)
           {
               ptr=ptr->next;

           }
            prevofa->next=0;
           ptr->next=temp;

        }

    }

        node* temp=head->next;
         node*prevoftemp=head;
         int i=k;
        while(i<=n)
        {
            if(temp->data%2!=0)
            {
                temp=temp->next;
                prevoftemp=prevoftemp->next;
                i++;
            }
            else{
                   node* ptr=temp;
                while(ptr->next!=0)
                {
                 ptr=ptr->next;
                }
                ptr->next=temp;
                prevoftemp->next=temp->next;
                node*ptr2=temp->next;
                ptr->next->next=0;
                 temp=ptr2;
                 i++;

            }
            if(i==n)
            {
                return ;
            }

        }


}

void function(node*head)
{
   node*ptr=head;
    node*ptr2;
    node*temp;
    node*temp2;
    node*temp3;
    int i=1;
    int k;
    int n=len(head);
    int j=n/2;
    while(i<=n/2)
    {
        k=1;
        if(k>=j)
        {
            break;
        }
        temp2=ptr;
        temp3=ptr;
        ptr2=ptr;
        while(k<j)
        {
            k++;                                         //first keep the address safe and the n make change in the very next step
            ptr2=ptr2->next;

        }
      ptr=ptr->next;
      temp2=ptr2->next;
      ptr2->next=ptr2->next->next;
      temp3->next=temp2;
      temp2->next=ptr;

        i++;j--;
    }
    //ptr->next=0;
}
node*small(node*&head)
{
    node*it=head->next;
    node*prevofit=head;
    node*smallest=head;
    node*prevofsmallest=0;

    while(it!=0)
    {
        if(it->data<smallest->data)
        {
            smallest=it;
            prevofsmallest=prevofit;
        }
        prevofit=it;
        it=it->next;
    }

    if(smallest==head)
    {
        head=head->next;
    }
    else{
        prevofsmallest->next=smallest->next;
    }
    return smallest;

}

node* selectionsort(node*head)
{
    node*sorthead=0;
    node*sorttail=0;
    while(head!=0)
    {
       node*smallest=small(head);
       if(sorthead==0)
       {
           sorthead=sorttail=smallest;
       }
       else{
        sorttail->next=smallest;
        sorttail=smallest;
       }

    }

    return sorthead;

}
node*lar(node*&head)
{
    node*it=head->next;
    node*prev=head;
    node*largest=head;
    node*prevoflar=0;
    while(it!=0)
    {
        if(it->data>largest->data)
        {
           prevoflar=prev;
           largest=it;
        }
        prev=it;
        it=it->next;
    }
    if(largest==head)
    {
        head=head->next;
    }

    else{
        prevoflar->next=largest->next;
    }

    return largest;

}
node*bubblesort(node*head,node*sorthead,node*sorttail)
{
    if(head==0)
    {
        return sorthead;
    }

        node*largest=lar(head);
        if(sorthead==0)
        {
            sorthead=sorttail=largest;
            sorttail->next=0;
        }
        else{
            largest->next=sorthead;
            sorthead=largest;
        }
    bubblesort(head,sorthead,sorttail);
}
int main ()
{
    node*head=0;
    int i=1,n;
    cout<<"enter the number of elements"<<endl;
    cin>>n;
    cout<<"enter the elements"<<endl;
    for(i=1;i<=n;i++)
    {
        int value;
        cin>>value;
        begin(head,value);
    }
    cout<<"original list:"<<endl;
    print(head);
    cout<<endl;
    /*

    int k;
    cout<<"enter the number"<<endl;
    cin>>k;
    if(len(head)<2*k)
    {
        cout<<"enter correct value"<<endl;
    }
    else{
    cout<<"required list is:"<<endl;
    func(head,k);
    print(head);
    }*/
    /*
    cout<<"required list is:"<<endl;
    int k=len(head);
    if(k==1 || k==0)
    {
        print(head);
    }
    else{
    shift(head);
    print(head);
    }
*/

/*
    cout<<"required list is:"<<endl;
    function(head);
    print(head);

    */
   // node*temp=selectionsort(head);
   node*temp=bubblesort(head,0,0);
    cout<<"list after sorting:"<<endl;
    print(temp);

    return 0;



}
