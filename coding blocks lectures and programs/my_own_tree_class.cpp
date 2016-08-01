#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
template<typename t>
class node
{
    t data;
    vector<node*>children;
public:
    node():data(0){}
    node(const t & el): data(el){}

    template<typename u>
    friend class tree;

};

template<typename t>
class tree
{
    node<t>*root;
public:
    tree():root(0){}

     tree(const tree & T):root(0)           //copy constructor
     {
         if(T.root==0)
         {
             return ;
         }
         root=copy(T.root);
         return  ;
     }

private:
    static node<t>* copy(const node<t>*address)
    {
        node<t>*curr=new node<t>(address->data);
        for(int i=0;i<address->children.size();i++)
        {
            node<t>*child=copy(address->children[i]);
            curr->children.push_back(child);
        }
        return curr;
    }

    public:

        ~tree()
        {
            clear();
        }

    void clear()
    {
        if(root==0)
        {
            return ;
        }
        clear_helper(root);
        root=0;
        return ;
    }

    private:
        static void clear_helper(const node<t>*address)
        {
            for(int i=0;i<address->children.size();i++)
            {
                clear_helper(address->children[i]);
            }
            delete address;
            return ;
        }

   public:
    void create_tree()
    {
        if(root!=0)
        {
            throw "tree is already created";
        }
        root=create_tree_helper();
        return ;
    }
private:
   static node<t>*create_tree_helper()
    {
        t el;
        cout<<"enter the data for the node";
        cin>>el;
        node<t>*curr=new node<t>(el);
        int count;
        cout<<"enter the number of child:";
        cin>>count;

        for (int i=0;i<count;i++)
        {
            node<t>*temp=create_tree_helper();
            curr->children.push_back(temp);
        }
        return curr;
    }

    public:
    void print_preorder() const
    {
        if(root==0)
        {
            return;
        }
        print_preorder_helper(root);
        cout<<endl;
        return ;
    }
    private:

        static void print_preorder_helper(const node<t>*address)
        {
            cout<<address->data<<" ";
            for(int i=0;i<address->children.size();i++)
            {
                print_preorder_helper(address->children[i]);
            }

            return ;
        }

    public:
        tree & operator = (const tree & T)
        {
            clear();
            root=copy(T.root);
            return*this;
        }

        void  get_largest()  const
        {
            if(root==0 || root->children.size()==0)
            {
                cout<<"largest node is"<<root->data;
                return ;
            }
             cout<<"largest node is:"<<get_largest_helper(root);
             return ;
        }

    private:
       static  t  get_largest_helper(const node<t>*address)
        {
            t largest=address->data;
            for(int i=0;i<address->children.size();i++)
            {
                t temp=get_largest_helper(address->children[i]);
                if(temp>largest)
                {
                    largest=temp;
                }
            }
            return largest;
        }

    public:
     void create_tree_bfs()
     {
         if(root!=0)
         {
             throw "tree alredy exists";
         }
         cout<<"enter the data for the node:";
         t el;
         cin>>el;
         node<t>*curr=new node<t>(el);
         queue<node<t>*>Q;
         Q.push(curr);
         while(!Q.empty())
         {
             node<t>*temp=Q.front();
             int count;
             cout<<"enter the number of child:";
             cin>>count;
             for(int i=0;i<count;i++)
             {
                 cout<<"enter the data for the node";
                 t element;
                 cin>>element;
                 node<t>*child=new node<t>(element);
                 temp->children.push_back(child);
                 Q.push(child);
             }
             Q.pop();
         }
         root=curr;
         return;
     }

     void print_root_to_el(const t & el) const
     {
         if(root==0)
         {
             return ;
         }
         vector< const node<t>*> v;
         if(print_root_to_el_helper(root,el,v))
         {
             cout<<"path is:"<<endl;
             for(int i=v.size()-1;i>=0;i--)
             {
                 cout<<v[i]->data<<" ";
             }
         }
         else
         {
             cout<<"not possible";
         }
         return ;
     }

    private:

       static  bool print_root_to_el_helper(const node<t>*address,const t & el,vector<const node<t>*> & v)
        {
            if(address->data==el)
            {
                v.push_back(address);
                return true;
            }

            for(int i=0;i<address->children.size();i++)
            {
                if(print_root_to_el_helper(address->children[i],el,v))
                {
                    v.push_back(address);
                    return true;
                }
            }
            return false;
        }

    public:
        void print_root_to_leaf() const
        {
            if(root==0)
            {
                return ;
            }
            vector<const node<t>*> V;
            print_root_to_leaf_helper(root,V);
            return ;
        }

    private:
        static void print_root_to_leaf_helper(const node<t>*address,vector<const node<t>*> & V)
        {
            V.push_back(address);

            for(int i=0;i<address->children.size();i++)
            {
                print_root_to_leaf_helper(address->children[i],V);
            }
            if(address->children.size()==0)
            {
                    for(int i=0;i<V.size();i++)
                    {
                         cout<<V[i]->data<<" ";
                    }
                    cout<<endl;
            }
           V.pop_back();
           return ;
        }

    public:
        void print_till_k(int k) const
   {
       if(root==0)
       {
           throw"empty";
       }
       int flag=0;
       pair<node<t>*,int>p(root,0);
       queue<pair<const node<t>*,int> >Q;
       Q.push(p);
       while(!Q.empty())
       {
           pair<const node<t>*,int> temp=Q.front();
           if(temp.second==k)
           {
               flag++;
               cout<<temp.first->data<<" ";
               Q.pop();
               continue;
           }
           for(int i=0;i<temp.first->children.size();i++)
           {
               pair<const node<t>*,int>child;
               child.first=temp.first->children[i];
               child.second=temp.second+1;
               Q.push(child);
           }
           Q.pop();
       }
       if(flag==0)
       {
           cout<<"no element present at depth k";
           return ;
       }
   }


     void print_second_largest()
     {
         if(root==0 || root->children.size()==0)
         {
             cout<<"second largest not possible";
             return ;
         }
         node<t>*largest=print_second_largest_helper(root);
         t ptr=largest->data;
         largest->data=-1000000;
         node<t>*temp=print_second_largest_helper(root);;
         largest->data=ptr;
         cout<<"largest element is:"<<largest->data<<endl;
         cout<<"second largest element is:"<<temp->data;
         return;

     }

    private:
       static node<t>* print_second_largest_helper( node<t>*address)
        {
            node<t>*largest=address;
            for(int i=0;i<address->children.size();i++)
            {
                node<t>*temp=print_second_largest_helper(address->children[i]);
                if(temp->data>largest->data)
                {
                    largest=temp;
                }
            }
            return largest;
        }

    public:
        void get_second_largest() const
        {
            if(root==0 || root->children.size()==0)
            {
                cout<<"second largest not possible:";
            }
            pair<const node<t>*,const node<t>*>P = get_second_largest_helper(root);
            cout<<"second largest element is:"<<P.second->data;
            return ;

        }

    private:
        static pair<const node<t>*,const node<t>*> get_second_largest_helper(const node<t>*address)
        {
            pair<const node<t>*,const node<t>*>p;
            p.first=address;
            p.second=NULL;

            for(int i=0;i<address->children.size();i++)
            {
                 pair<const node<t>*,const node<t>*>child=get_second_largest_helper(address->children[i]);
                 if(child.first->data > p.first->data)
                 {
                     if(child.second==NULL)
                     {
                         p.second=p.first;
                     }
                     else
                     {
                        if(p.first->data > child.second->data)
                        {
                            p.second=p.first;
                        }
                        else
                        {
                            p.second=child.second;
                        }
                     }
                     p.first=child.first;
                 }
                 else
                 {
                     if(p.second!=NULL && p.second->data > child.first->data){}
                     else{
                        p.second=child.first;
                     }
                 }
            }
            return p;
        }

    public:
        void print_post_order() const
        {
            if(root==0)
            {
                return ;
            }
            print_post_order_helper(root);
            cout<<endl;
            return ;
        }
    private:
        static void print_post_order_helper(const node<t>*address)
        {
            for(int i=0;i<address->children.size();i++)
            {
                print_post_order_helper(address->children[i]);
            }
            cout<<address->data<<" " ;
            return ;
        }
    public:
        void print_height() const
        {
            if(root==0)
            {
                cout<<" height=0";
                return ;
            }
            int size=0;
            int temp=0;
            print_height_helper(root,temp,size);
            cout<<"height of the tree is:"<<size;
            return ;
        }
    private:
        static void print_height_helper(const node<t>*address, int & temp ,int & size)
        {
            if(address->children.size()==0)
            {
                temp++;
              if(temp > size)
              {
                  size=temp;
              }
               temp--;
                return ;
            }
            temp++;
            for(int i=0;i<address->children.size();i++)
            {
                print_height_helper(address->children[i],temp,size);
            }
            temp--;
            return ;
        }

    public:
        void count_nodes_with_data_greater_than_root() const
        {
            if(root==0)
            {
                return ;
            }
            int size=0;
            count_nodes_with_data_greater_than_root_helper(root,size,root->data);
            cout<<"number of nodes with data greater than root are:"<<size;
            return ;
        }
    private:
        static void count_nodes_with_data_greater_than_root_helper(const node<t>*address,int & size,const t & el)
        {
            if(address->data > el)
            {
                 size++;
                if(address->children.size()==0)
                {
                    return ;
                }
                else{
                    for(int i=0;i<address->children.size();i++)
                    {
                        count_nodes_with_data_greater_than_root_helper(address->children[i],size,el);
                    }
                    return ;
                }
            }
            for(int i=0;i<address->children.size();i++)
            {
                count_nodes_with_data_greater_than_root_helper(address->children[i],size,el);
            }
            return ;
        }

    public:
        void count_leaf_nodes()const
        {
            if(root==0)
            {
                return ;
            }
            int count=0;
            count_leaf_nodes_helper(root,count);
            cout<<"number of leaf nodes are:"<<count;
            return ;
        }
    private:
        static void count_leaf_nodes_helper(const node<t>*address,int & count)
        {
            if(address->children.size()==0)
            {
                count++;
                return ;
            }
            for(int i=0;i<address->children.size();i++)
            {
                count_leaf_nodes_helper(address->children[i],count);
            }
            return ;
        }
    public:
        int  node_count() const
        {
            if(root==0)
            {
                return 0;
            }
            int count=0;
            node_count_helper(root,count);
            return 1+count ;
        }
    private:
        static int node_count_helper(const node<t>*address,int & count )
        {
            if(address->children.size()==0)
            {
                return 1;
            }
            for(int i=0;i<address->children.size();i++)
            {
                count+=node_count_helper(address->children[i],count);
            }
            return 1;


        }
    public:
        void print_level_order() const
        {
            if(root==0)
            {
                return ;
            }
            int index=0;
            pair< const node<t>* , int >P;
            vector< pair< const node<t>*, int> >V;
            P.first=root;
            P.second=0;
            V.push_back(P);
            int i=1;
            int count=(*this).node_count();
            while(i<count)
            {
                pair< const node<t>*,int> temp=V[index];
                index++;
              for(int j=0;j<temp.first->children.size();j++)
              {
                  pair<const node<t>*,int> child;
                  child.first=temp.first->children[j];
                  child.second=temp.second+1;
                  V.push_back(child);
                  i++;

              }
            }
            int k=0;
            for( i=0;i<V.size();i++)
            {
                pair<const node<t>*,int> temp=V[i];
                if(temp.second==k)
                {
                    cout<<temp.first->data<<" ";
                }
                else{
                    cout<<endl;
                    k=temp.second;
                    cout<<temp.first->data<<" ";
                }
            }
            V.clear();
            return ;
        }
    public:
        void check_path_sum(const t & sum)
        {
            if(root==0)
            {
                cout<<"not possible";
                return ;
            }
            vector<const node<t>*>v;
            if(check_path_sum_helper(root,v,sum))
            {
                cout<<"yes";
            }
            else{
                cout<<"no";
            }
            v.clear();
            return;

        }
    private:
        static bool check_path_sum_helper(const node<t>*address, vector<const node<t>*> & v,const t & sum)
        {
            if(address->children.size()==0)
            {
                v.push_back(address);
                t temp_sum=0;
                for(int i=0;i<v.size();i++)
                {
                    temp_sum+=v[i]->data;
                }
                if(temp_sum==sum)
                {
                    return true;
                }
                else{
                    v.pop_back();
                    return false;
                }
            }
                  v.push_back(address);
                for(int i=0;i<address->children.size();i++)
                {
                    if(check_path_sum_helper(address->children[i],v,sum))
                    {
                        return true;
                    }
                }
                v.pop_back();
                return false;
            }
    public:
        void node_just_greater_than_k(const t & k)
        {
            if(root==0)
            {
                cout<<"not possible";
                return ;
            }
            vector<const node<t>*> v;
            node_just_greater_than_k_helper(root,v,k);

            if(v.size()==0)
            {
                cout<<"no element found";
                return;
            }

            t smallest=v[0]->data;
            for(int i=1;i<v.size();i++)
            {
               if(v[i]->data < smallest)
               {
                   smallest=v[i]->data;
               }
            }
            cout<<"element just greater than k is:"<<smallest;
            return ;

        }
    private:
        static void node_just_greater_than_k_helper(const node<t>*address,vector<const node<t>*> & v,const t & k)
        {
            if(address->data > k)
            {
                v.push_back(address);
            }
            if(address->children.size()==0)
            {
                return ;
            }
            else{
                    for(int i=0;i<address->children.size();i++)
                    {
                         node_just_greater_than_k_helper(address->children[i],v,k);
                    }
                    return ;
            }

            for(int i=0;i<address->children.size();i++)
            {
                node_just_greater_than_k_helper(address->children[i],v,k);
            }
            return ;
        }

    public:
        void operator == (const tree & T) const      //const function cannot call non const
        {
            if(helper(root,T.root))
            {
                cout<<"yes";
            }
            else{
                cout<<"no";
            }
            return ;
        }
    private:
        static bool helper(const node<t>*my,const node<t>*other)
        {
            if(my->data!=other->data)
            {
                return false;
            }
            for(int i=0;i<other->children.size();i++)
            {
                if(helper(my->children[i],other->children[i])==false)
                {
                    return false;
                }
            }
            return true;
        }
    public:
        void print_iteratively() const
        {
            if(root==0)
            {
                cout<<endl;
                return ;
            }
            queue< node<t>*>Q;
            Q.push(root);
            while(!Q.empty())
            {
               node<t>*temp=Q.front();
               cout<<temp->data<<" ";
               Q.pop();
               for(int i=0;i<temp->children.size();i++)
               {
                   Q.push(temp->children[i]);
               }
            }
            return ;
        }

        void post_order_iterative()
        {
            if(root==0)
            {
                return ;
            }
            stack< const node<t>*> s,r;
            s.push(root);
            while(!s.empty())
            {
                r.push(s.top());
                s.pop();

                for(int i=0;i<r.top()->children.size();i++)
                {
                    s.push(r.top()->children[i]);
                }
            }
            while(!r.empty())
            {
                cout<<r.top()->data<<" ";
                r.pop();
            }
            cout<<endl;
            return ;
        }

         public:
        void print_zig_zag_level_order() const
        {
            if(root==0)
            {
                return ;
            }
            int index=0;
            pair< const node<t>* , int >P;
            vector< pair< const node<t>*, int> >V;
            P.first=root;
            P.second=1;
            V.push_back(P);
            int i=1;
            int count=(*this).node_count();
            while(i<count)
            {
                pair< const node<t>*,int> temp=V[index];
                index++;
              for(int j=0;j<temp.first->children.size();j++)
              {
                  pair<const node<t>*,int> child;
                  child.first=temp.first->children[j];
                  child.second=temp.second+1;
                  V.push_back(child);
                  i++;

              }
            }
            int k=1;int j;int l;
            for(i=0;i<V.size();i++)
            {
                pair< const node<t>* ,int >temp = V[i];
                if(temp.second%2!=0)
                {
                    k=temp.second;
                    for( j=i;j<V.size();j++)
                    {
                        pair< const node<t>* ,int >temp1=V[j];
                        if(temp1.second==k){}
                        else{
                            break;
                        }
                    }
                    cout<<endl;
                    for( l=i;l<j;l++)
                    {
                        pair< const node<t>* ,int >temp1=V[l];
                        cout<<temp1.first->data<<" ";
                    }
                    i=l-1;
                }
                else{
                    k=temp.second;
                      for( j=i;j<V.size();j++)
                    {
                        pair< const node<t>* ,int >temp1=V[j];
                        if(temp1.second==k){}
                        else{
                            break;
                        }
                    }
                    cout<<endl;
                    for( l=j-1;l>=i;l--)
                    {
                        pair< const node<t>* ,int >temp1=V[l];
                        cout<<temp1.first->data<<" ";
                    }
                      i=j-1;
                }

            }

            V.clear();
            return ;
        }

            void lowest_common_ancestor(const t & el1,const t & el2){
                if(root==0)
                {
                    return ;
                }
                vector<const node<t>*> v1,v2;
                if(print_root_to_el_helper(root,el1,v1))
                {
                    if(print_root_to_el_helper(root,el2,v2))
                    {
                        const node<t>* ancestor=NULL;

                        int i,j;
                        for( i=v1.size()-1,j=v2.size()-1;i>=0,j>=0;j--,i--)
                        {
                            if(v1[i]==v2[j])
                            {
                                ancestor=v1[i];
                            }
                        }
                        if(ancestor==NULL)
                        {
                            cout<<"no common ancestor";
                            return ;
                        }

                        cout<<"lowest common ancestor is:"<<ancestor->data;
                        return ;
                    }
                    cout<<"element not found";
                    return ;
                }
                cout<<"element not found";
                return ;
            }

            void find_some_special_node()
            {
                if(root==0)
                {
                    cout<<"not possible";
                    return ;
                }
                t sum=-1000000;
                pair<node<t>*,t >p;
                p.first=NULL;
                p.second=sum;
                find_some_special_node_helper(root,p);
                cout<<"required node is:"<<p.first->data;
                return ;

            }

         private:
            static void find_some_special_node_helper( node<t>*address, pair<node<t>*,t> & p)
            {
                if(address->children.size()==0)
                {
                    if(address->data > p.second)
                    {
                        p.second=address->data;
                        p.first=address;
                    }
                    return ;
                }
                    t temp=0;
                    for(int i=0;i<address->children.size();i++)
                    {
                        temp+=address->children[i]->data;
                    }
                    temp+=address->data;
                    if(temp > p.second)
                    {
                        p.second=temp;
                        p.first=address;
                    }
                    for(int i=0;i<address->children.size();i++)
                    {
                        find_some_special_node_helper(address->children[i],p);
                    }
                    return;

            }
};
int main ()
{
    tree<int>T;
    //T.create_tree();
    T.create_tree_bfs();
    T.get_second_largest();
    //T.print_height();
    //T.post_order_iterative();
    //T.find_some_special_node();
    //T.lowest_common_ancestor(5,9);
    //T.print_post_order();
    //T.print_zig_zag_level_order();
    //T.post_order_iterative();
    //T.print_level_order();
    //T.print_iteratively();
    /*cout<<endl;
    tree<int>Q;
    Q.create_tree_bfs();
    Q==T;
   // T.node_just_greater_than_k(10);
    //T.check_path_sum(28);
    //T.print_preorder();
    //T.print_level_order();
    //cout<<T.node_count();

    //T.count_leaf_nodes();
    //T.count_nodes_with_data_greater_than_root();
    //T.print_height();
    //T.print_post_order();
   // T.get_second_largest();

   // T.print_root_to_leaf();
    //T.print_root_to_el(11);
    //T.print_preorder();
    /*
    T.create_tree();
    T.print_preorder();
    tree<int>Q;
    Q.print_preorder();
    Q.clear();
    Q.print_preorder();
    T.print_preorder();

    Q=T;
    Q.print_preorder();
    Q.get_largest();
    */
    return 0;
}
