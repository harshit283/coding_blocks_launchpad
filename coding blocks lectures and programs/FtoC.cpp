#include<iostream>
using namespace std;
int main() {
    int initial, final, step;
    cout << " Enter initial, final and step ";
    cin >> initial >> final >> step;
    while (initial <= final) {
        int c = (5.0/ 9) *(initial - 32);
        cout << initial << '\t' << c << endl;

        initial = initial+ step;
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *next;
    int coeff=0;
    int power=0;
};

node* create_list(int n)
{
    node*head,*end;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            head = (node*)malloc(sizeof(node));
            (head)->next=NULL;
            end = head;
        }
        else
        {
            (end)->next = (node*)malloc(sizeof(node));
            (end)=(end)->next;
            (end)->next=NULL;
        }
    }
    return head;
}

node * add_the_lists(node*it1,node*it2)
{
    node*head,*end;
    int power,coeff;
    int flag=0;
    while(it1 && it2)
    {
        if(it1->power==it2->power)
        {
            flag++;
            power=it1->power;
            coeff = it1->coeff + it2->coeff;
            it1=it1->next;
            it2=it2->next;
        }
        else if(it1->power > it2->power)
        {
            flag++;
            power = it1->power;
            coeff=it1->coeff;
            it1=it1->next;
        }
        else
        {
            flag++;
            power = it2->power;
            coeff=it2->coeff;
            it2=it2->next;
        }

        if(flag==1)
        {
            head = (node*)malloc(sizeof(node));
            (head)->power=power;
            (head)->coeff=coeff;
            (head)->next=NULL;
            end = head;
        }
        else
        {
            (end)->next = (node*)malloc(sizeof(node));
            (end)=(end)->next;
            (end)->power=power;
            (end)->coeff=coeff;
            (end)->next=NULL;
        }
    }
    while(it1)
    {
        (end)->next = (node*)malloc(sizeof(node));
        (end)=(end)->next;
        (end)->power=it1->power;
        (end)->coeff=it1->coeff;
        (end)->next=NULL;
        it1=it1->next;
    }
    while(it2)
    {
        (end)->next = (node*)malloc(sizeof(node));
        (end)=(end)->next;
        (end)->power=it2->power;
        (end)->coeff=it2->coeff;
        (end)->next=NULL;
        it1=it1->next;
    }

    return  head;
}

void free_memory(node*it)
{
    node*temp;
    while(it)
    {
        temp=it->next;
        free(it);
        it=temp;
    }
    return;
}
node* multiply_the_lists(node*it1,node*it2,int m)
{
    node*t1_head,*t2_head,*t3_head;
    t1_head = create_list(m);
    t2_head = create_list(m);
    node*t1_it=t1_head;
    node*t2_it=t2_head;
    int flag=0;
    while(it1)
    {
       if(flag==0)
       {
           flag=1;
           if(it1->next)
           {
               while(it2)
               {
                   t1_it->coeff = it1->coeff*it2->coeff;
                   t1_it->power = it1->power+it2->power;
                   t2_it->coeff = it1->next->coeff*it2->coeff;
                   t2_it->power = it1->next->power+it2->power;
                   it2=it2->next;
                   t1_it=t1_it->next;
                   t2_it=t2_it->next;
               }
               t3_head = add_the_lists(t1_head,t2_head);
               it1=it1->next->next;
           }
           else
           {
               while(it2)
               {
                   t1_it->coeff = it1->coeff*it2->coeff;
                   t1_it->power = it1->power+it2->power;
                   t1_it=t1_it->next;
                   it2=it2->next;
               }
               t3_head = t1_head;
               it1=it1->next;
           }

       }
        else
       {
           while(it2)
           {
               t1_it->coeff = it1->coeff*it2->coeff;
               t1_it->power = it1->power+it2->power;
               t1_it=t1_it->next;
               it2=it2->next;
           }
           node*temp = t3_head;
           t3_head = add_the_lists(t1_head,t3_head);
           free_memory(temp);
           it1=it1->next;
       }

    }

    return  t3_head;
}
int main()
{
    node*head1,*head2,*head3,*head4;
    int n,m;
    printf("Enter the number of terms for first polynomial\n");
    scanf("%d",&n);
    head1 = create_list(n);
    node*it=head1;
    int coeff1,coeff2,power1,power2;
    for(int i=0;i<n;i++)
    {
        printf("Enter the coefficient:- ");
        scanf("%d",&coeff1);
        printf("Enter the power of the corresponding term:- ");
        scanf("%d",&power1);
        it->coeff = coeff1;
        it->power = power1;
        it=it->next;
    }

    printf("\nEnter the number of terms for second polynomial\n");
    scanf("%d",&m);
    head2= create_list(m);
    it=head2;
    for(int i=0;i<m;i++)
    {
        printf("Enter the coefficient:- ");
        scanf("%d",&coeff2);
        printf("Enter the power of the corresponding term:- ");
        scanf("%d",&power2);
        it->coeff = coeff2;
        it->power = power2;
        it=it->next;
    }

    head3=add_the_lists(head1,head2);
    head4 = multiply_the_lists(head1,head2,m);
    it=head3;
    while(it!=NULL)
    {
        cout<<it->power<< " "<<it->coeff<<endl;
        it=it->next;
    }
    cout<<endl;
    /*it=head4;
    while(it!=NULL)
    {
        cout<<it->power<< " "<<it->coeff<<endl;
        it=it->next;
    }

    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *next;
    int coeff=0;
    int power=0;
};
node* create_list(int n)
{
    node*head,*end;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            head = (node*)malloc(sizeof(node));
            (head)->next=NULL;
            end = head;
        }
        else
        {
            (end)->next = (node*)malloc(sizeof(node));
            (end)=(end)->next;
            (end)->next=NULL;
        }
    }
    return head;
}
node * add_the_lists(node*it1,node*it2)
{
    node*head,*end;
    int power,coeff;
    int flag=0;
    while(it1 && it2)
    {
        if(it1->power==it2->power)
        {
            flag++;
            power=it1->power;
            coeff = it1->coeff + it2->coeff;
            it1=it1->next;
            it2=it2->next;
        }
        else if(it1->power > it2->power)
        {
            flag++;
            power = it1->power;
            coeff=it1->coeff;
            it1=it1->next;
        }
        else
        {
            flag++;
            power = it2->power;
            coeff=it2->coeff;
            it2=it2->next;
        }
        if(flag==1)
        {
            head = (node*)malloc(sizeof(node));
            (head)->power=power;

            (head)->coeff=coeff;

            (head)->next=NULL;
            end = head;
        }
        else
        {
            (end)->next = (node*)malloc(sizeof(node));
            (end)=(end)->next;
            (end)->power=power;
            (end)->coeff=coeff;
            (end)->next=NULL;
        }
    }
    while(it1)
    {
        (end)->next = (node*)malloc(sizeof(node));
        (end)=(end)->next;
        (end)->power=it1->power;
        (end)->coeff=it1->coeff;
        (end)->next=NULL;
        it1=it1->next;
    }
    while(it2)
    {
        (end)->next = (node*)malloc(sizeof(node));
        (end)=(end)->next;
        (end)->power=it2->power;
        (end)->coeff=it2->coeff;
        (end)->next=NULL;
        it2=it2->next;
    }
    return  head;
}
void free_memory(node*it)
{
    node*temp;
    while(it)
    {
        temp=it->next;
        free(it);
        it=temp;
    }
    return;
}
node* multiply_the_lists(node*it1,node*it2,int m)
{
    node*t1_head,*t2_head,*t3_head;
    t1_head = create_list(m);
    t2_head = create_list(m);
    node*t1_it=t1_head;
    node*t2_it=t2_head;
    node*temp=it2;
    int flag=0;
    while(it1)
    {
        it2=temp;
        t1_it=t1_head;
       if(flag==0)
       {
           flag=1;
           if(it1->next)
           {
               while(it2)
               {
                   t1_it->coeff = it1->coeff*it2->coeff;
                   t1_it->power = it1->power+it2->power;
                   t2_it->coeff = it1->next->coeff*it2->coeff;
                   t2_it->power = it1->next->power+it2->power;

                   it2=it2->next;

                   t1_it=t1_it->next;

                   t2_it=t2_it->next;

               }

               t3_head = add_the_lists(t1_head,t2_head);

               it1=it1->next->next;

           }
           else
           {
               while(it2)
               {
                   t1_it->coeff = it1->coeff*it2->coeff;
                   t1_it->power = it1->power+it2->power;
                   t1_it=t1_it->next;
                   it2=it2->next;
               }
               t3_head = t1_head;
               it1=it1->next;
           }
       }
        else
       {
           while(it2)
           {
               t1_it->coeff = it1->coeff*it2->coeff;
               t1_it->power = it1->power+it2->power;
               t1_it=t1_it->next;
               it2=it2->next;
           }
           node*ptr= t3_head;
           t3_head = add_the_lists(t1_head,t3_head);
           free_memory(ptr);
           it1=it1->next;
       }
    }
    return  t3_head;
}
int main()
{
    node*head1,*head2,*head3,*head4;
    int n,m;
    printf("Enter the number of terms for first polynomial\n");
    scanf("%d",&n);
    head1 = create_list(n);
    node*it=head1;
    int coeff1,coeff2,power1,power2;
    for(int i=0;i<n;i++)
    {
        printf("Enter the coefficient:- ");
        scanf("%d",&coeff1);
        printf("Enter the power of the corresponding term:- ");
        scanf("%d",&power1);
        it->coeff = coeff1;
        it->power = power1;
        it=it->next;
    }
    printf("\nEnter the number of terms for second polynomial\n");
    scanf("%d",&m);
    head2= create_list(m);
    it=head2;
    for(int i=0;i<m;i++)
    {
        printf("Enter the coefficient:- ");
        scanf("%d",&coeff2);
        printf("Enter the power of the corresponding term:- ");
        scanf("%d",&power2);
        it->coeff = coeff2;
        it->power = power2;
        it=it->next;
    }
    head3=add_the_lists(head1,head2);
    head4 = multiply_the_lists(head1,head2,m);
    it=head3;
    while(it!=NULL)
    {
        cout<<it->power<< " "<<it->coeff<<endl;
        it=it->next;
    }
    cout<<endl;
    it=head4;
    while(it!=NULL)
    {
        cout<<it->power<< " "<<it->coeff<<endl;
        it=it->next;
    }
    return 0;
}
*/
