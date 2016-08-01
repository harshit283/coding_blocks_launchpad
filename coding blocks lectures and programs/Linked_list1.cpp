#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
};

void merging(Node *&head1, Node *&head2)
{
    Node *sorthead=NULL, *sorttail=NULL;
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            if(sorthead==NULL)
            {
                sorthead=head1;
                head1=head1->next;
                sorthead->next=NULL;
                sorttail=sorthead;
            }
            else
            {
                sorttail->next=head1;
                sorttail=head1;
                head1=head1->next;
                sorttail->next=0;
            }

        }
        else
        {
            if(sorthead==NULL)
            {
                sorthead=head2;
                head2=head2->next;
                sorthead->next=NULL;
                sorttail=sorthead;
            }
    else
            {
                sorttail->next=head2;
                sorttail=head2;
                head2=head2->next;
                sorttail->next=0;
            }
        }
    }
    if(head1==NULL)
    {
        sorttail->next=head2;
    }
    else
    {
        sorttail->next=head1;
    }
    head1=sorthead;
    head2=sorttail;

}

void print_linked_list(Node *head)
{
    if(head==NULL)
    {
        cout<<"\nNo element exist ";
        return;
    }
    cout<<"\n";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;

    }
    return;

}

void insert_at_beginning(Node *&head, int ele)
{
    if(head==NULL)
    {
        Node *ptr=new Node;
        ptr->data=ele;
        ptr->next=0;
        head=ptr;
        return;
    }
    Node *it=head;
    Node *ptr=new Node;
    ptr->data=ele;
    ptr->next=head;
    head=ptr;
    return;

}

void insert_at_end(Node *&head, int ele)
{
    if(head==NULL)
    {
        Node *ptr=new Node;
        ptr->data=ele;
        ptr->next=0;
        head=ptr;
        return;
    }
    Node *it=head;
    while(it->next!=NULL)
    {
        it=it->next;
    }
    Node *ptr=new Node;
    ptr->data=ele;
    ptr->next=0;
    it->next=ptr;
    return;
}

void delete_at_beginning(Node *&head)
{
    if(head==NULL)
    {
        cout<<"\nNot Possible     No element exists ";
        return;
    }
    Node *ptr=head;
    head=head->next;
    delete  ptr;
    return;
}

void delete_at_end(Node *&head)
{
    if(head==NULL)
    {
        cout<<"\nNot Possible ";
        return;
    }
    if(head->next==NULL)
    {
        delete head;
        head=0;
        return;
    }
    Node *it=head;
    while(it->next->next!=NULL)
    {
        it=it->next;
    }

    delete it->next;
    it->next=NULL;
    return;


}

Node * find_element_at_k(Node *head, int k)
{
    if(k<0)
    {
        return NULL;
    }


    if(k==1)
    {
        return head;
    }
    int i=1;
    while(i<k)
    {
        if(head->next==NULL)
        {
            cout<<"\nNot possible ";
            return NULL;
        }
        head=head->next;
        i++;
    }

    return head;

}

void delete_element_at_k(Node *&head, int k)
{
    if(k<0)
    {
        cout<<"\nNot Possible ";
        return;
    }


    if(k==1)
    {
        delete_at_beginning(head);
        return;
    }
    int i=1;
    Node *it=head;
    while(i<k-1)
    {
        if(it->next==NULL)
        {
            cout<<"\nNot possible ";
            return;
        }
        it=it->next;
        i++;
    }
    Node *ptr=it->next;
    it->next=it->next->next;
    delete ptr;
    return;

}


void insert_element_at_k(Node *&head, int k, int ele)
{
    if(k<0)
    {
        cout<<"\nNot Possible ";
        return;
    }


    if(k==1)
    {
        insert_at_beginning(head, ele);
        return;
    }
    int i=1;
    Node *it=head;
    while(i<k-1)
    {
        if(it->next==NULL)
        {
            cout<<"\nNot possible ";
            return;
        }
        it=it->next;
        i++;
    }
    if(it->next==NULL)
    {
        insert_at_end(head,ele);
        return;
    }
    Node *ptr=new Node;
    ptr->data=ele;
    ptr->next=it->next;
    it->next=ptr;
    return;

}




int main()
{
    Node *head1=0;
    insert_at_beginning(head1,5);

    print_linked_list(head1);
    insert_at_beginning(head1,4);
    insert_at_beginning(head1,3);
    insert_at_beginning(head1,2);
    insert_at_end(head1,10);
    insert_at_end(head1,100);
    print_linked_list(head1);
    /*delete_at_beginning(head);
    print_linked_list(head);
    delete_at_beginning(head);
    print_linked_list(head);
    delete_at_beginning(head);
    print_linked_list(head);
    delete_at_end(head);
    print_linked_list(head);
    delete_at_end(head);
    print_linked_list(head);
    delete_at_end(head);
    print_linked_list(head);
    delete_at_end(head);
    delete_at_end(head);
    print_linked_list(head);
    print_linked_list(head);*/
    /*Node *ptr1=find_element_at_k(head,1);
    if(ptr1!=NULL)
        cout<<"\n"<<ptr1->data;
    delete_at_end(head);
    delete_at_end(head);
    delete_at_end(head);
    delete_at_end(head);
    delete_at_end(head);
    delete_at_end(head);
    delete_at_end(head);
    delete_at_end(head);
    ptr1=find_element_at_k(head,1);
    if(ptr1!=NULL)
        cout<<"\n"<<ptr1->data;*/
    /*print_linked_list(head);
    delete_element_at_k(head,2);
    print_linked_list(head);
    delete_element_at_k(head,1);
    print_linked_list(head);
    insert_element_at_k(head,2,5);
    print_linked_list(head);
    insert_element_at_k(head,1,1000);
    print_linked_list(head);*/
     Node *head2=0;
    insert_at_beginning(head2,5);

    //print_linked_list(head2);
    insert_at_beginning(head2,4);
    insert_at_beginning(head2,3);
    insert_at_beginning(head2,2);
    insert_at_end(head2,100);
    insert_at_end(head2,100);
    print_linked_list(head2);
    merging(head1,head2);
    print_linked_list(head1);

    return 0;
}
