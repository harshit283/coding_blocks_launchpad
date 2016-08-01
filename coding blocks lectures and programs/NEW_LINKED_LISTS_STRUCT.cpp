#include<iostream>
using namespace std;
struct node
{
    int data;
    node * next;
};

void insert_at_begin(node*&head,int el)
{
    node*temp=new node;
    temp->data=el;
    temp->next=head;
    head=temp;
    return ;
}
/*
void insert_at_begin(node**head,int el)
{
    node*temp=new node;
    temp->data=el;
    temp->next=*head;
    *head=temp;
}
*/
void print_list(node * head)
{
    while(head)
    {
        cout<<head->data<<" " ;
        head=head->next;
    }
    cout<<endl;
    return ;
}

void reverse_print(node*head)
{
    if(head==NULL)
        return ;
    reverse_print(head->next);
    cout<<head->data<<" " ;
    return ;
}

void delete_from_end(node*&head)
{
    if(head==NULL)
        return ;
    node*it=head;
    if(it->next==NULL)
    {
        delete head;
        head=NULL;
        return ;
    }
    while(it->next->next!=NULL)
        it=it->next;
        delete it->next;
        it->next=NULL;
        return ;
}

void delete_from_begin(node*&head)
{
    if(head==NULL)
        return ;
    node*it=head->next;
    delete head;
    head=it;
    return ;

}
void insert_at_end(node*&head,int el)
{
    node*it=head;
    if(it==NULL)
    {
        head=new node;
        head->data=el;
        head->next=NULL;
        return ;
    }
    while(it->next)
        it=it->next;
    it->next=new node;
    it->next->data=el;
    it->next->next=NULL;
    return ;
}

int find_kth(node*head,int index)
{
    if(index < 0)
        return -1;
    if(head==NULL)
        return -1;
    int i=0;
    while(i<index && head!=NULL)
    {
        head=head->next;
        i++;
    }
    if(head==NULL)
        return -1;
    return head->data;

}

void delete_kth(node*&head,int index)
{
    if(index < 0)
        return ;
    if(head==NULL)
        return ;
    if(index==0)
    {
        node*temp=head->next;
        delete head;
        head=temp;
        return ;
    }

     int i=1;
     node*it=head;
    while(i<index && it)
    {
        it=it->next;
        i++;
    }
    if(it==NULL)
        return ;
    if(it->next==NULL)
            return ;
    node*temp=it->next->next;
    delete it->next;
    it->next=temp;
    return ;

}

void insert_at_kth(node * & head,int index,int el)
{
    if(index < 0)
        return ;
    if(head==NULL && index==0)
    {
        head=new node;
        head->data=el;
        head->next=NULL;
        return ;
    }
    int i=1;
    node*it=head;
    while(i<index  && it)
    {
        it=it->next;
        i++;
    }
    if(it==NULL)
        return ;
    node*temp=new node;
    temp->data=el;
    temp->next=it->next;
    it->next=temp;
    return ;

}

void find_mid_point(node*head)
{
    int i=0;
    node*it=head;
    while(head)
    {
        head=head->next;
        i++;
    }
    if(i==0)
    {
        cout<<" LIST IS EMPTY"<<endl; return ;
    }
    if(i==1)
    {
        cout<<"ONLY ONE ELEMENT IS PRESENT";return ;
    }

    if(i%2)
    {
        cout<<"MID ELEMENT IS :- "<<endl;
        cout<<find_kth(it,i/2);
    }
    else{
        cout<<"TWO MIDS POSSIBLE"<<endl;
        cout<<find_kth(it,i/2-1);
        cout<<endl<<find_kth(it,i/2);
    }
       return ;
}


void merge_ll(node*&head1,node*&head2)
{
    if(head1==NULL && head2==NULL)
        return ;
    node*it1=head1;
    node*it2=head2;
    node*ptr;
    if(it1->data <=it2->data)
    {
        ptr=it1;
        it1=it1->next;
    }
    else{
        ptr=it2;
        it2=it2->next;
    }

    while(it1 && it2)
    {
        if(it1->data <=it2->data)
        {
            ptr->next=it1;
            ptr=it1;
            it1=it1->next;
            continue;
        }
        ptr->next=it2;
        ptr=it2;
        it2=it2->next;
    }
    if(it1==NULL)
        ptr->next=it2;
    else if(it2==NULL)
        ptr->next=it1;
    if(head1->data > head2->data)
        head1=head2;
    return ;
}

void removing_dup(node* & head)
{
    if(head==NULL || head->next==NULL)
           return ;
    node*it=head->next;
    node*prev_of_it=head;
    while(it)
    {
        if(prev_of_it->data==it->data)
        {
            prev_of_it->next=it->next;
            delete it;
            it=prev_of_it->next;
            continue;
        }
        prev_of_it=it;
        it=it->next;
    }
    return ;
}

void reverse_ll(node*&head)
{
    if(head==NULL || head->next==NULL)
               return ;
    node*ahead=head->next;
    node*prev=NULL;
    node*curr=head;
    while(curr)
    {
        ahead=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ahead;
    }
    head=prev;
    return ;
}

void odd_even(node*&head)
{
    if(head==NULL || head->next==NULL)
        return ;
    node*e_head=NULL;
    node*e_tail=NULL;;
    node*o_head=NULL;
    node*o_tail=NULL;
    node*it=head;
    while(it)
    {
        if(it->data%2!=0)
        {
            if(o_head==NULL)
                o_head=o_tail=it;
            else{
                o_tail->next=it;
                o_tail=it;
            }
        }
        else{
            if(e_head==NULL)
                e_head=e_tail=it;
            else{
                e_tail->next=it;
                e_tail=it;
            }
        }
      it=it->next;
    }
    if(o_tail==NULL || e_tail==NULL)
        return ;
    o_tail->next=e_head;
    e_tail->next=NULL;
    head=o_head;
    return ;
}
void special_reverse(node*& head,int k)
{
    if(k<=0)
        return ;
    int i=1;
    node*it=head;
    while(i < k && it)
    {
        it=it->next;
        i++;
    }
    if(it==NULL)
      return ;
    node*add=it->next;
    it->next=NULL;
    node*my_head=head;
      reverse_ll(my_head);
      reverse_ll(add);
      head->next=add;
      head=my_head;
      return ;
}
int flag=0;
node*helper(node*,node*);
void check_if_pal(node*head)
{
    node*add=helper(head,head);
    if(flag==0)
        cout<<"no";
    else if (flag)
        cout<<"yes";
    return ;
}
node*helper(node*head,node*it)
{
    if(it==NULL)
        return head;
    node*add=helper(head,it->next);
    if(add==NULL)
        return NULL;
    if(add->data==it->data)
    {
        if(add->next==NULL)
        {
            flag++;
            return NULL;
        }else return add->next;
    }
    else return NULL;
}


int rev_helper(node*&head,node*it,node*prev)
{
    if(it==NULL)
         return -1;
    int add= rev_helper(head,it->next,it);
    if(add==-1)
    {
        head=it;
        it->next=prev;
    }
    else{
        it->next=prev;
    }
    return 0;
}

void reverse_ll_rec(node*&head)
{
    if(head==NULL || head->next==NULL)
        return ;
        node*it=head;
        node*prev=NULL;
    rev_helper(head,it,prev);
    return ;
}

node*get_and_remove_min(node*&head)
{
   node * smallest=head;
   node*prev_of_smallest=NULL;
   node*it=head->next;
   node*prev=head;
   while(it)
   {
       if(it->data < smallest->data)
       {
           prev_of_smallest=prev;
           smallest=it;
       }
       prev=it;
       it=it->next;
   }
   if(smallest==head)
        head=head->next;
      else{
        prev_of_smallest->next=smallest->next;
      }
   return smallest;

}

void selectionSort(node* & head)
{
    if(head==NULL || head->next==NULL)
        return ;
    node*sorthead=NULL;
    node*sorttail=NULL;
    while(head)
    {
        node*add=get_and_remove_min(head);
        if(sorthead==NULL)
            sorthead=sorttail=add;
        else{
            sorttail->next=add;
            sorttail=add;
        }
    }
    head=sorthead;
    //sorttail->next=NULL;
    return;
}


node*get_and_remove_max(node*&head)
{
    node*largest=head;
    node*prev_of_largest=NULL;
    node*it=head->next;
    node*prev_of_it=head;
    while(it)
    {
        if(it->data > largest->data)
        {
            largest=it;
            prev_of_largest=prev_of_it;
        }
        prev_of_it=it;
        it=it->next;
    }
    if(largest==head)
        head=head->next;
    else prev_of_largest->next=largest->next;
    return largest;
}
void bubblesort(node*&head)
{
    if(head==NULL || head->next==NULL)
        return ;
    node*sorthead=NULL;
    node*sorttail=NULL;
    while(head)
    {
        node*add=get_and_remove_max(head);
        if(sorthead==NULL)
            sorthead=sorttail=add;
            else{
                add->next=sorthead;
                sorthead=add;
            }
    }
    head=sorthead;
    sorttail->next=NULL;
    return ;
}


void bubblesort_rec(node*&head,node*sorthead,node*sorttail)
{
    if(head==NULL)
    {
        head=sorthead;
        return ;
    }

    node*add=get_and_remove_max(head);
    if(sorthead==NULL)
    {
           sorthead=sorttail=add;
           sorttail->next=NULL;
    }

    else{
        add->next=sorthead;
        sorthead=add;
    }
    bubblesort_rec(head,sorthead,sorttail);
    return ;
}
node*previousOfMid(node*head)
{
    node*it=head;
    node*prev=head;
    node*ptr=NULL;
    while(it->next)
    {
        ptr=prev;
        prev=prev->next;
        it=it->next->next;
        if(it==NULL)
            break;
    }
    return ptr;
}

void merge_sort(node*&head)
{
    if(head==NULL || head->next==NULL)
        return ;
    node*add=previousOfMid(head);
    node*temp=add->next;
    add->next=NULL;
    merge_sort(head);
    merge_sort(temp);
    merge_ll(head,temp);
    return ;
}

void an_bn(node*&head)
{
    if(head==NULL)
        return ;
    node*it1=head;
    node*it2=previousOfMid(head)->next;
    node*sorttail=NULL;
    node*temp=NULL;
    while( it2)
    {
        if(sorttail==NULL)
           sorttail=it1;
        else
           sorttail->next=it1;
           sorttail=it1;
           temp=it1->next;
           sorttail->next=it2;
           sorttail=it2;
           it1=temp;
           it2=it2->next;
    }
    sorttail->next=NULL;
    return ;

}
int main()
{
    node*head=NULL;
    int n;
    cin>>n;
     for(int i=1;i<=n;i++)
     {
         int val;
         cin>>val;
         insert_at_end(head,val);
     }
        print_list(head);
        an_bn(head);
        //selectionSort(head);
        //bubblesort_rec(head,NULL,NULL);
        //odd_even(head);
        //special_reverse(head,3);
       // bubblesort(head);
        print_list(head);
        //check_if_pal(head);
        //reverse_ll_rec(head);
        //print_list(head);
     /*node*head2=NULL;
     for(int i=3;i<=11;i++)
        insert_at_end(head2,2*i);
        print_list(head2);
        merge_ll(head1,head2);
        print_list(head1);
        cout<<"2nd list is:";
        print_list(head2);
        */



        //find_mid_point(head);
        /*delete_kth(head,5);
        print_list(head);
        delete_kth(head,8);
        print_list(head);
        delete_kth(head,6);
        print_list(head);
        delete_kth(head,0);
        print_list(head);
        delete_kth(head,0);
        */
        //delete_from_end(head);
   // print_list(head);
    /*reverse_print(head);
    cout<<endl;*/
    //delete_from_begin(head);
    //insert_at_end(head,10);
   /* int el=find_kth(head,9);
    if(el==-1)
        cout<<"element not present";
        else cout<<"yes found   "<<el;*/
    //print_list(head);

    return 0;
}
