#include<iostream>
using namespace std;

struct node{

   int data;
   node*next;

};
int length(node*head)
{
    int i=0;
    while(head!=0)
    {
        i++;
        head=head->next;
    }
    return i;
}
void begin(node*&head,int el)
{
    node*temp=new node;
    temp->data=el;
    temp->next=head;
    head=temp;
    return ;
}

void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return ;
}

node*func(node*&head)
{
    node*smallest=head;
    node*it=head->next;
    node*prevofit=head;
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

    if(head==smallest)
    {
        head=head->next;
    }
    else{
        prevofsmallest->next=smallest->next;

    }

    //smallest->next=0;
    return smallest;
}
void selectionsort(node*&head)
{
    print(head);
    node*sorthead=0,*sorttail=0;
    while(head!=0)
    {
        node*smallest=func(head);
        if(sorthead==0){
            sorthead=sorttail=smallest;
        }
        else{
            sorttail->next=smallest;
           // sorttail->next->next=0;
            sorttail=smallest;
        }
    }

    head=sorthead;
    return ;
}

node* merge(node*head1,node*head2)
{
    node*sorthead=0;
    node*sorttail=0;
    node*it1=head1;
    node*it2=head2;

    while(it1!=0 && it2!=0)
    {
        if(it1->data>it2->data)
        {
            if(sorthead==0)
            {
             sorthead=sorttail=it2;
            }
            else{
                sorttail->next=it2;
              //  sorttail->next->next=0;
                sorttail=it2;
            }
            it2=it2->next;
        }
        else{

            if(sorthead==0)
            {
                sorthead=sorttail=it1;
            }
            else{
                sorttail->next=it1;
              //  sorttail->next->next=0;
                sorttail=it1;
            }
            it1=it1->next;
        }
    }
    if(it1==0)
    {
        sorttail->next=it2;
    }
    else{
        sorttail->next=it1;
    }

    return sorthead;
}

node*funcb(node*&head)
{
    node*it=head->next;
    node*prevofit=head;
    node*largest=head;
    node*prevoflargest=0;
    while(it!=0)
    {
        if(it->data>largest->data)
        {
            largest=it;
            prevoflargest=prevofit;
        }
        prevofit=it;
        it=it->next;
    }

    if(head==largest)
    {
        head=head->next;
    }
    else{
        prevoflargest->next=largest->next;
    }

    return largest;
}
void bubblesort(node*&head)
{
    node*sorthead=0;
    node*sorttail=0;
    while(head!=0)
    {
        node*largest=funcb(head);
        if(sorttail==0)
        {
            sorttail=sorthead=largest;
            sorttail->next=0;
        }
        else{
            sorthead=largest;
            sorthead->next=sorttail;
            sorttail=largest;

        }
    }
        head=sorthead;
        return ;

}
void mergesort(node*&head,int n)
{
    if(n==1)
    {
        return ;
    }
    node*temp=head;
    int i=1;
    while(i<n/2+1)
    {
        temp=temp->next;
        i++;
    }
    mergesort(head,n/2);
    mergesort(temp,n-n/2);
    head=merge(head,temp);
    return ;

}

struct mypair{

 int ans;
 node* addr;

};
mypair palin(node*head,node*curr)
{
    mypair var;
    if(curr->next==0)
    {
        if(curr->data==head->data)
        {
            var.addr=head->next;
            var.ans=1;
            return var;

        }
        else{
            var.addr=0;
            var.ans=0;
            return var;

        }
    }
     mypair subvar=palin(head,curr->next);

     if(subvar.ans==0)
     {
         return subvar;
     }

    else{

        if(subvar.addr->data==curr->data)
        {
            var.addr=subvar.addr->next;
            var.ans=1;
            return var;
        }

        else{
            var.addr=0;
            var.ans=0;
            return var;
        }
    }

}
node * mergeTwoSorted(node *&head1, node * &head2) {
    node * it1 = head1, *it2 = head2;
    node * sortHead = 0, *sortTail = 0;
    while (it1!= NULL && it2!= NULL) {
        node * smallest = 0;
        if (it1->data < it2->data) {
            smallest = it1;
            it1 = it1->next;
        } else {
            smallest = it2;
            it2 = it2->next;
        }
        smallest->next = 0;
        if (sortHead == NULL) {
            sortHead = sortTail = smallest;
        } else {
            sortTail->next = smallest;
            sortTail = smallest;
        }
    }
    if (it1 != NULL) {
        sortTail->next = it1;
    } else {
        sortTail->next = it2;
    }
    head1 = 0;
    head2 = 0;
    return sortHead;
}
node* rev(node*curr,node*prev)
{
  /*  node*next;
    node*curr=head;
    node*prev=0;
    while(curr!=0)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    head=prev;
    return ;
*/  node*next;

    if(curr==0)
    {
        return prev;
    }

    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    rev(curr,prev);
}

bool check(node*head1,node*head2)
{

    while(head1!=0)
    {
        cout << head1 -> data << " " <<endl;
        if(head1->data!=head2->data)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

void rotate(node*&head,int k)
{
    if(k==0  || k==length(head))
    {
        return ;
    }                                             //before making any modification in the list make sure you dont have to traverse the list after that
                                                //otherwise errors will be generated so perform all those operations before hand and store those addresses in
                                                 // separate pointter variables

    node*temp1=head;
    node*temp2=head;
    node*ptr;
    while(temp1->next!=0)
    {
        temp1=temp1->next;
    }
    ptr=temp1;
    temp1=head;
    int i=1;
    int n=length(head);
    while(i<n-k)
    {
        i++;
        temp1=temp1->next;
    }
    temp2=temp1->next;
    temp1->next=0;
    ptr->next=head;
    head=temp2;
    return ;

}


void dup(node*head)
{
    node*temp=head;
    node*ptr=head->next;
    while( ptr!=0)
    {

        if(temp==head && (temp->data==ptr->data))
        {
            node*temp2=ptr->next;
            delete ptr;
            temp->next=temp2;
            ptr=temp2;
        }
       else if(temp==head &&(temp->data!=ptr->data))
        {
            temp=temp->next;
            ptr=ptr->next;
        }
       else if(temp!=head &&(temp->data==ptr->data))
        {
            node*temp2=ptr->next;
            delete ptr;
            temp->next=temp2;
            ptr=temp2;
        }
       else if(temp!=head && (temp->data != ptr->data))
        {
            temp=temp->next;
            ptr=ptr->next;
        }

    }
    return ;
}
int main ()
{

    node*head=0;
    int n;
    cout<<"enter the number of terms";
    cin>>n;
    cout<<"enter the elements"<<endl;
    int value;
    for(int i=1;i<=n;i++)
    {
        cin>>value;
        begin(head,value);
    }
    print(head);
    cout<<endl;
   // cout<<"elements after sorting are"<<endl;
    //selectionsort(head);
    bubblesort(head);
    print(head);
  // mergesort(head,length(head));


//*
/*
     int m,n,i,value;
    node*head1=0;
    node*head2=0;
    cout<<"enter total elements of first list"<<endl;
    cin>>n;
    cout<<"enter total elements of second list"<<endl;
    cin>>m;
    cout<<"enter elements of first list"<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>value;
        begin(head1,value);
    }

    cout<<endl<<"enter elements of second list"<<endl;
    for(i=1;i<=m;i++)
    {
        cin>>value;
        begin(head2,value);
    }
*/
  /*
    cout<<endl;
    cout<<"elements after merging are"<<endl;

    merge(head1,head2);
    */

/*
    node*temp=mergeTwoSorted(head1,head2);
    print(temp);
*/

    // print(hed1);

     // node*temp= palin(head,head);
/*
     mypair var=palin(head,head);
     if(var.ans==0)
     {
         cout<<"no";
     }
     else{
        cout<<"yes";
     }
*/
/*
     if(length(head1)!=length(head2))
     {
         cout<<"no";
     }
     else{
     node*temp=rev(head1,0);
     print(temp);
     if(check(temp,head2))
     {
         cout<<"yes";
     }
     else{
        cout<<"no";
     }
     }
*/
/*
int m;
cout<<"enter the number"<<endl;
cin>>m;
    cout<<"required linked list is"<<endl;

      rotate(head,m);
      print(head);
      */
/*
      cout<<"list after removing duplicates is:"<<endl;
      dup(head);
      print(head);
*/

    return 0;

}
