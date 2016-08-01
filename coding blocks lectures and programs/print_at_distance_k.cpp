#include<bits/stdc++.h>
using namespace std;
template<typename t>
class node
{
    node*left;
    node*right;
    t data;
public:
    node():data(0),left(NULL),right(NULL){}
    node(const t & el):data(el),left(NULL),right(NULL){}
    template<typename u>
    friend class binary_tree;
};
template<typename t>
class binary_tree
{
    node<t>*root;
public:
    binary_tree():root(NULL){}
    const node<t>*get_address(const t & el)
    {
        if(root==NULL)
        {
            cout<<"TREE IS EMPTY";
            return nullptr;
        }
        return get_address_helper(root,el);
    }
private:
     const  node<t>*get_address_helper(const node<t>*curr,const t & el)
    {
        if(curr==NULL)
        {
            return NULL;
        }
        if(curr->data ==el)
        {
            return curr;
        }
       const node<t>*temp= get_address_helper(curr->left,el);
        if(temp!=NULL)
        {
            return temp;
        }
        return get_address_helper(curr->right,el);
    }
public:
    void print_bottom(const node<t>*curr,int k) const
    {
        if(curr==NULL)
        {
            return ;
        }
        if(k==0)
        {
            cout<<curr->data<<" ";;
            return ;
        }
        print_bottom(curr->left,k-1);
        print_bottom(curr->right,k-1);
        return ;
    }

public:
    int print_at_k(const t & el,int k)
    {
            const node<t>*address=get_address(el);
            if(address==NULL)
            {
                return 0;
            }
        print_at_k_helper(root,address,k);
        return 0;
    }
private:
     int print_at_k_helper(const node<t>*curr,const node<t>*target,int k)
    {
        if(curr==target)
        {
            print_bottom(curr,4);
            return 1;
        }
        if(curr==NULL)
        {
            return -1;
        }

        int ld=print_at_k_helper(curr->left,target,k);
        if(ld!=-1)
        {
            if(ld==k)
            {
                cout<<curr->data<<" ";
            }else{
                  print_bottom(curr->right,k-ld-1);
            }
            return ld;
        }
        int rd=print_at_k_helper(curr->right,target,k);
        if(rd!=-1)
        {
            if(rd==k)
            {
                cout<<curr->data<<" ";
            }
            else{
                print_bottom(curr->left,k-rd-1);
            }
            return rd;
        }
        return -1;
    }

     public:
        void create_binary_tree_bfs()
        {
            if(root!=0)
            {
                throw "tree already already exists";
            }
            queue< node<t>*> Q;
            t el;
            cout<<"enter the data for the node";
            cin>>el;
            node<t>*curr=new node<t>(el);
            Q.push(curr);
            while(!Q.empty())
            {
                char ch;
                 node<t>*temp=Q.front();
                cout<<"does " <<temp->data<<" has left child(y/n)";
                cin>>ch;
                if(ch=='y' || ch=='Y')
                {
                    t el2;
                    cout<<"enter the data for the node:";
                    cin>>el2;
                    temp->left=new node<t>(el2);
                    Q.push(temp->left);
                }

                char ph;
                cout<<"does " <<temp->data<<" has right child(y/n)";
                cin>>ph;
                if(ph=='y' || ph=='Y')
                {
                    t el2;
                    cout<<"enter the data for the node:";
                    cin>>el2;
                    temp->right=new node<t>(el2);
                    Q.push(temp->right);
                }
                Q.pop();
            }
            root=curr;
            return ;
        }


};
int main ()
{
    binary_tree<int>T;
    T.create_binary_tree_bfs();
    T.print_at_k(6,3);
    return 0;
}
