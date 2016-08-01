#include<iostream>
using namespace std;

struct node
{
    node*next;
    int data;
};
void begin(node*&head,int el)
{
    node*temp=new node;
    temp->data=el;
    temp->next=head;
    head=temp;
}

void smallest(node*head)
{
    int min=100000;
    node*it=head;
    node*temp;
    while(it!=NULL)
    {
        if(it->data<min)
        {
            min=it->data;



        }
        it=it->next;

    }
    cout<<min;
    return ;


}
/*
void print(node*head)
{
    while(head!)
}
*/
int main ()
{
    int n,i;
    node*head=0;
    cout<<"number of elements"<<endl;
    cin>>n;
    for(i=1;i<n;i++)
    {
        begin(head,i);
    }
    //print(head);
    smallest(head);
}
