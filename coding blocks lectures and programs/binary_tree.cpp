#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;
template<typename t>
class node
{
    t data;
    node*left;
    node*right;
    node():data(0),left(0),right(0){}
    node(const t & el):data(el),left(0),right(0){}

    template<typename u>
    friend class binary_tree;
};

template<typename t>
class binary_tree
{
    node<t>*root;

public:
    binary_tree():root(0){}

    binary_tree(const binary_tree & T):root(0)        //copy constructor
    {
        root=copy(T.root);
        return ;
    }

private:
    static node<t>*copy(const node<t>* address)
    {
        node<t>*curr;
        if(address!=NULL)
        {
            curr=new node<t>(address->data);
        }
        else{
            return NULL;
        }
        curr->left=copy(address->left);
        curr->right=copy(address->right);
        return curr;

    }
public:
    void create_binary_tree_dfs()
    {
        if(root!=0)
        {
            throw "tree already exists";
        }
        root=create_binary_tree_dfs_helper();
        return ;
    }

private:
     static node<t>* create_binary_tree_dfs_helper()
     {
         t el;
         cout<<"enter the data for the node:";
         cin>>el;
         node<t>*curr=new node<t>(el);
         char ch;
         cout<<"does "<<el<<" has a left child (y/n):";
         cin>>ch;
         if(ch=='y' || ch=='Y')
         {
             curr->left=create_binary_tree_dfs_helper();
         }
         char ph;
         cout<<"does "<<el<<" has a right child (y/n):";
         cin>>ph;
         if(ph=='y' || ph=='y')
         {
             curr->right=create_binary_tree_dfs_helper();
         }

         return curr;
     }

public:
    void print_preorder() const
    {
        if(root==0)
        {
            return ;
        }
        print_preorder_helper(root);
        cout<<endl;
        return ;
    }

private:
    static void print_preorder_helper(const node<t>*address)
    {
        if(address!=NULL)
        {
            cout<<address->data<<" " ;
        }
        else{
            return;
        }

        print_preorder_helper(address->left);
        print_preorder_helper(address->right);
        return ;
    }

public:
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

    ~binary_tree()
    {
        clear();
    }
private:
    static void clear_helper(const node<t>*address)
    {
        if(address==NULL)
        {
            return ;
        }
        clear_helper(address->left);
        clear_helper(address->right);
        delete address;
        return ;
    }

public:
    binary_tree & operator = (const binary_tree & T)
    {
        clear();
        root=copy(T.root);
        return *this;
    }

    void  operator == (const binary_tree & T) const
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
        if(my==NULL && other==NULL)
        {
            return true;
        }
        else if(my==NULL && other!=NULL || my!=NULL && other==NULL)
        {
            return false;
        }

        if( helper(my->left,other->left))
        {
            if(my->data==other->data)
            {
                 if(helper(my->right,other->right))
                 {
                       if(my->data==other->data)
                             {
                                   return true;
                             }
                       else
                             {
                                   return false;
                             }
                }
                else
                      {
                           return false;
                      }

            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

public:
    void mirror()
    {
        if(root==0)
        {
            return ;
        }
        node<t>*temp=mirror_copy(root);
        clear();
        binary_tree TREE;
        TREE.root=temp;
        *this=TREE;
        TREE.clear();
        return ;
    }
private:
    static node<t>*mirror_copy(const node<t>*address)
    {
        node<t>*curr;
        if(address!=NULL)
        {
            curr=new node<t>(address->data);
        }
        else{
            return NULL;
        }

        curr->left=mirror_copy(address->right);
        curr->right=mirror_copy(address->left);
        return curr;
    }

public:
    void delete_half_nodes()
    {
        if(root==0)
        {
            return ;
        }
        vector< node<t>*>v;
        root=delete_half_nodes_helper(root,v);
        return ;
    }

    private:
    static node<t>* delete_half_nodes_helper( node<t>*address,vector<node<t>*> & v)
    {
        if(address==NULL)
        {
            return NULL;
        }
        else if(address->left == NULL && address->right!=NULL  || address->left!=NULL && address->right==NULL)
        {
            v.push_back(address);
        }
        else if(address->left == NULL &&  address->right==NULL)
        {
            return address;
        }
        address->left=delete_half_nodes_helper(address->left,v);
        address->right=delete_half_nodes_helper(address->right,v);

        if(v[v.size()-1]==address)
        {
            if(address->left!=NULL)
            {
                v.pop_back();
                return address->left;
            }
            v.pop_back();
            return address->right;
        }
        else{
            return address;
        }
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
            if(address==NULL)
            {
                return ;
            }
            print_post_order_helper(address->left);
            print_post_order_helper(address->right);
            cout<<address->data<<" ";
            return ;
        }

    public:
        void print_in_order() const
        {
            if(root==0)
            {
                return ;
            }
            print_in_order_helper(root);
            cout<<endl;
            return ;
        }

    private:
        static void print_in_order_helper(const node<t>*address)
        {
            if(address==NULL)
            {
                return ;
            }

            print_in_order_helper(address->left);
            cout<<address->data<<" ";
            print_in_order_helper(address->right);
            return ;
        }

    public:
        void print_leaf_nodes() const
        {
            if(root==0)
            {
                return ;
            }
            print_leaf_nodes_helper(root);
            cout<<endl;
            return ;

        }

    private:
        static void print_leaf_nodes_helper(const node<t>* address)
        {
            if(address==NULL)
            {
                return ;
            }
            else if(address->left==NULL && address->right==NULL)
            {
                cout<<address->data<<" ";
                return ;
            }

            print_leaf_nodes_helper(address->left);
            print_leaf_nodes_helper(address->right);
            return ;
        }

    public:
        void delete_leaf_nodes()
        {
            if(root==0)
            {
                return ;
            }
            root=delete_leaf_nodes_helper(root);
            return ;
        }
    private:
        static node<t>* delete_leaf_nodes_helper( node<t>*address)
        {
            if(address==NULL)
            {
                return NULL;
            }
            else if(address->left==NULL && address->right==NULL)
            {

                delete address;
                return NULL;
            }
            address->left=delete_leaf_nodes_helper(address->left);
            address->right=delete_leaf_nodes_helper(address->right);
            return address;
        }

    public:
        void maximum_sum() const
        {
            if(root==0)
            {
                return ;
            }
            vector<const node<t>*> v;
            vector<const node<t>*> m;
            t sum=-1000000;
            maximum_sum_helper(root,v,m,sum);

            cout<<"desired path is:";
            for(int i=0;i<m.size();i++)
            {
                cout<<m[i]->data<<" ";
            }
            m.clear();
            v.clear();

            cout<<endl;
            return;
        }

    private:
        static void maximum_sum_helper(const node<t>*address,vector<const node<t>*> & v ,vector<const node<t>*> & m ,  t & sum)
        {
            if(address==NULL)                         //there is no need to return the vector since we are receivimg it by const reference
                                                      //changes will be observed
            {
                return ;
            }
            else if(address->left==NULL && address->right==NULL)
            {
                v.push_back(address);
                 t temp_sum=0;
                for(int i=0;i<v.size();i++)
                {
                    temp_sum+=v[i]->data;
                }
                if(temp_sum>sum)
                {
                    m.clear();
                    for(int i=0;i<v.size();i++)
                    {
                          m.push_back(v[i]);
                    }
                    sum=temp_sum;
                }
                v.pop_back();
                return ;
            }
            v.push_back(address);
            maximum_sum_helper(address->left,v,m,sum);
            maximum_sum_helper(address->right,v,m,sum);
            v.pop_back();
            return ;
        }

    public:
        void print_just_largest_than_k(t k)const
        {
            if(root==0)
            {
                return ;
            }
            vector<const node<t>*> v;
            print_just_largest_than_k_helper(root,v,k);
            if(v.size()==0)
            {
                cout<<"not possible";
                return ;
            }
            t smallest;
            smallest=v[0]->data;
            for(int i=1;i<v.size();i++)
            {
                if(v[i]->data < smallest)
                {
                    smallest=v[i]->data;
                }
            }
            cout<<"element just largest than k is:"<<smallest;
            return;
        }

    private:
        static void print_just_largest_than_k_helper(const node<t>*address,vector<const node<t>*> & v,const t & el)
        {
            if(address==NULL)
            {
                return ;
            }
            else if(address->data > el)
            {
                v.push_back(address);
                return ;
            }
            print_just_largest_than_k_helper(address->left,v,el);
            print_just_largest_than_k_helper(address->right,v,el);
            return ;
        }

    public:
        void print_root_to_leaf() const
        {
            if(root==0)
            {
                return ;
            }
            vector<const node<t>*> v ;
            print_root_to_leaf_helper(root,v);
            cout<<endl;
            return ;
        }

    private:
        static void print_root_to_leaf_helper(const node<t>*address , vector<const node<t>*> & v)
        {
            if(address==NULL)
            {
                return ;
            }
            else if(address->left==NULL  && address->right == NULL)
            {
                v.push_back(address);
                for(int i=0;i<v.size();i++)
                {
                    cout<<v[i]->data<<" ";
                }
                cout<<endl;
                v.pop_back();
                return ;
            }
            v.push_back(address);
            print_root_to_leaf_helper(address->left,v);
            print_root_to_leaf_helper(address->right,v);
            v.pop_back();
            return ;
        }

    public:
        void print_root_to_el(t el)const
        {
            if(root==0)
            {
                return ;
            }

            vector<const node<t>*> v;
            if(print_root_to_el_helper(root,v,el))
            {
                cout<<"desired path is:"<<endl;
                for(int i=v.size()-1;i>=0;i--)
                {
                    cout<<v[i]->data<<" ";
                }
            }
            else{
                cout<<"not possible";
            }
            return ;
        }

    private:
        static bool print_root_to_el_helper(const node<t>*address , vector<const node<t>*> & v , const t & el)
        {
            if(address==NULL)
            {
                return false;
            }
            else if(address->data==el)
            {
                v.push_back(address);
                return true;
            }

            if(print_root_to_el_helper(address->left,v,el))
            {
                v.push_back(address);
                return true;
            }
            if(print_root_to_el_helper(address->right,v,el))
            {
                v.push_back(address);
                return true;
            }
            return false;

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

        void print_at_depth_k(int k) const
        {
            if(root==0)
            {
                return ;
            }
            int flag=0;
            pair< node<t>*,int>P;
            queue< pair< node<t>*,int > > Q;
            P.first=root;
            P.second=0;
            Q.push(P);
            while(!Q.empty())
            {
                pair< node<t>*,int> temp = Q.front();

                if(temp.second==k)
                {
                    flag++;
                    cout<<temp.first->data<<" ";
                    Q.pop();
                    continue;
                }
                   pair< node<t>*,int> child1,child2;
                   if(temp.first->left!=NULL)
                   {
                      child1.first=temp.first->left;
                      child1.second=temp.second+1;
                      Q.push(child1);
                   }
                   if(temp.first->right!=NULL)
                   {
                        child2.first=temp.first->right;
                        child2.second=temp.second+1;
                        Q.push(child2);
                   }

                   Q.pop();
            }
            if(flag==0)
            {
                cout<<"k is not valid depth";
            }
            return ;
        }

        void print_level_order()
        {
             if(root==0)
            {
                return ;
            }
            vector < pair< node<t>*,int> >V;
            pair< node<t>* ,int > P;
            P.first=root;
            P.second=1;
            V.push_back(P);
            int index=0;
            int i=1;
            int count = node_count_helper(root);
            while(i<count)
            {
                  pair< node<t> * ,int > temp =V[index];
                  pair< node<t>*,int> child1,child2;
                   if(temp.first->left!=NULL)
                   {
                      child1.first=temp.first->left;
                      child1.second=temp.second+1;
                      V.push_back(child1);
                      i++;
                   }
                   if(temp.first->right!=NULL)
                   {
                        child2.first=temp.first->right;
                        child2.second=temp.second+1;
                        V.push_back(child2);
                        i++;
                   }
                   index++;
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


        void print_zig_zag_level_order()
        {
            if(root==0)
            {
                return ;
            }
            vector < pair< node<t>*,int> >V;
            pair< node<t>* ,int > P;
            P.first=root;
            P.second=1;
            V.push_back(P);
            int index=0;
            int i=1;
            int count = node_count_helper(root);
            while(i<count)
            {
                  pair< node<t> * ,int > temp =V[index];
                  pair< node<t>*,int> child1,child2;
                   if(temp.first->left!=NULL)
                   {
                      child1.first=temp.first->left;
                      child1.second=temp.second+1;
                      V.push_back(child1);
                      i++;
                   }
                   if(temp.first->right!=NULL)
                   {
                        child2.first=temp.first->right;
                        child2.second=temp.second+1;
                        V.push_back(child2);
                        i++;
                   }
                   index++;
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

      int  node_count()
    {
            return node_count_helper(root);
    }
    private:
        static int node_count_helper(const node<t>*address)
        {
            if(address==NULL)
            {
                return 0;
            }
            return 1+node_count_helper(address->left)+node_count_helper(address->right);
        }




    public:
        void possible_path(t k)
        {
            if(root==0)
            {
                return ;
            }
            vector<const node<t>*> v;
            if(possible_path_helper(root,v,k))
            {
                cout<<"yes possible";
            }
            else{
                cout<<"not possible";
            }
            v.clear();
            return ;
        }
    private:
        static bool possible_path_helper(const node<t>*address , vector< const node<t>*> &v ,const t & el)
        {
            if(address==NULL)
            {
                return false;
            }
            else if(address->left==NULL && address->right==NULL)
            {
                v.push_back(address);
                t temp=0;
                for(int i=0;i<v.size();i++)
                {
                    temp+=v[i]->data;
                }

                if(temp==el)
                {
                    return true;
                }
                else{
                    v.pop_back();
                    return false;
                }
            }

            v.push_back(address);
            if(possible_path_helper(address->left,v,el))
            {
                return true;
            }
            else{
                if(possible_path_helper(address->right,v,el))
                {
                    return true;
                }
            }
            v.pop_back();
            return false;
        }

    public:
        void are_leaf_nodes_at_same_level()
        {
            if(root==0)
            {
                return ;
            }
            int size;
            int flag=0;
            vector<const node<t>*> v;
            if(are_leaf_nodes_at_same_level_helper(root,v,size,flag))
            {
                cout<<"no";
            }
            else{
                cout<<"yes";
            }
            v.clear();
            return ;
        }
        private:
        static bool are_leaf_nodes_at_same_level_helper(const node<t>*address , vector< const node<t>* > & v ,int & size,int &flag)
        {
            if(address==NULL)
            {
                return false;
            }
            else if(address->left==NULL && address->right == NULL)
            {
                 v.push_back(address);
                if(flag==0)
                {
                    size=v.size();
                    flag++;
                    v.pop_back();
                    return false;
                }
                else{
                    if(size!=v.size())
                    {
                         v.pop_back();
                        return true;
                    }
                    else{
                         v.pop_back();
                        return false;
                    }
                }
            }
                v.push_back(address);
                if(are_leaf_nodes_at_same_level_helper(address->left,v,size,flag))
                {
                    return true;
                }
                if(are_leaf_nodes_at_same_level_helper(address->right,v,size,flag))
                {
                    return true;
                }
                v.pop_back();
                return false;

            }

        public:
            void mirror_method_2()
            {
                if(root==0)
                {
                    return ;
                }
                root=mirror_method_2_helper(root);
                return ;
            }
        private:
            static node<t>*mirror_method_2_helper( node<t>* address)
            {
                if(address==NULL)
                {
                    return NULL;
                }
                else if(address->left==NULL && address->right==NULL)
                {
                    return address;
                }
                node<t>*temp1 = mirror_method_2_helper(address->left);
                node<t>*temp2 = mirror_method_2_helper(address->right);
                address->left=temp2;
                address->right=temp1;
                return address;
            }

            public:
           void is_element_present( t el)
           {
               if(root==0)
               {
                   return ;
               }
               if(is_element_present_helper(root,el))
               {
                   cout<<"present";
               }
               else{
                cout<<"not present";
               }
               return ;
           }
        private:
           static bool is_element_present_helper( const node<t>*address, const t & el)
           {
               if(address==NULL)
               {
                   return false;
               }
               else if(address->data==el)
               {
                   return true;
               }
               if(is_element_present_helper(address->left,el))
               {
                   return true;
               }
               if(is_element_present_helper(address->right,el))
               {
                   return true;
               }
               return false;

           }
        public:
            void check_if_two_nodes_with_sum(t sum)
            {
                if(root==0)
                {
                    return ;
                }
                vector< const node<t>*> v;
                check_if_two_nodes_with_sum_helper(root,v);
                for(int i=0;i<v.size();i++)
                {
                    for(int j=i+1;j<v.size();j++)
                    {
                        if(v[i]->data+v[j]->data==sum)
                        {
                            cout<<" pair of nodes with given sum are found";
                            v.clear();
                            return ;
                        }
                    }
                }
                cout<<"no possible pair";
                v.clear();
                return ;

            }
        private:
           static void check_if_two_nodes_with_sum_helper( const node<t>*address,vector< const node<t>*> & v)
           {
               v.push_back(address);
               int i=1;
               int index=0;
               int count=node_count_helper(address);
               while(i<count)
               {
                  const  node<t>*temp=v[index];
                   index++;

                   if(temp->left!=NULL)
                   {
                       v.push_back(temp->left);
                       i++;
                   }
                   if(temp->right!=NULL)
                   {
                       v.push_back(temp->right);
                       i++;
                   }
               }
               return ;
           }

        public:
            void post_order_iterative()
            {
                if(root==0)
                {
                    return ;
                }
                stack<const node<t>*>s,r;

                s.push(root);
                while(!s.empty())
                {
                    r.push(s.top());
                    s.pop();
                    if(r.top()->left!=NULL)
                    {
                        s.push(r.top()->left);
                    }
                    if(r.top()->right!=NULL)
                    {
                        s.push(r.top()->right);
                    }
                }
                while(!r.empty())
                {
                    cout<<r.top()->data<<" ";
                    r.pop();
                }
                return ;
            }

            void lowest_common_ancestor(const t & el1,const t & el2){
                if(root==0)
                {
                    return ;
                }
                vector<const node<t>*> v1,v2;


                if(print_root_to_el_helper(root,v1,el1))
                {
                    if(print_root_to_el_helper(root,v2,el2))
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
        public:

            void print_height()
            {
                int height=print_height_helper(root);
                cout<<"height of tree is:"<<height;
                return ;
            }
        private:
            static int print_height_helper(const node<t>*address)
            {
                if(address==NULL)
                {
                    return 0;
                }
                int lh=print_height_helper(address->left);
                int rh=print_height_helper(address->right);
                if(lh>rh)
                {
                    return 1+lh;
                }
                else{
                    return 1+rh;
                }
            }

        public:
            void print_diameter()
            {
               if(root==0)
               {
                   throw" TREE IS EMPTY";
               }
               pair<int,int>my_pair=print_diameter_helper(root);
               cout<<"diameter is:"<<endl;
               cout<<my_pair.first<<endl;
               return ;
            }
        private:
            static pair<int,int> print_diameter_helper(const node<t>*address)
            {
                if(address==NULL)
                {
                    pair<int,int>my_pair(0,0);
                    return my_pair;
                }
                pair<int,int> temp_left,temp_right,temp;
                temp_left=print_diameter_helper(address->left);
                temp_right=print_diameter_helper(address->right);
                int height=max(temp_left.second,temp_right.second)+1;
                int dummy=max(temp_left.first,temp_right.first);
                int diameter=max(dummy,temp_left.second+temp_right.second+1);
                temp.first=diameter;
                temp.second=height;
                return temp;
            }
        public:
            void nodes_with_sum_method1(const t & sum)
            {
                if(root==0)
                {
                    return ;
                }
                int index=0;
                vector<node<t>*>v;
                v.push_back(root);
                int i=1;
                int count=node_count_helper(root);
                while(i<count)
                {
                    node<t>*temp=v[index];
                    index++;
                    if(temp->left!=NULL)
                    {
                        v.push_back(temp->left);
                        i++;
                    }
                    if(temp->right!=NULL)
                    {
                        v.push_back(temp->right);
                        i++;
                    }
                }
                for( i=0;i<v.size();i++)
                {
                    for(int j=i+1;j<v.size();j++)
                    {
                        if(v[i]->data+v[j]->data==sum)
                        {
                            cout<<"yes";
                            v.clear();
                            return ;
                        }
                    }
                }
                cout<<"no";
                return ;
            }
//////////////////////////////////////////////////////////////
            ///CHECK
            public:
           void function(t*post,t*in,int m)
           {
               int poststart=0;
               int postend=m-1;
               int instart=0;
               int inend=m-1;
               root=function_helper(post,poststart,postend,in,instart,inend);
               return ;
           }
        private:
           static node<t>*function_helper(t*post,int poststart,int postend,t*in,int instart,int inend)
           {
               if(poststart > postend || instart > inend)
               {
                   return NULL;
               }
               node<t>*temp=new node<t>(post[postend]);
               int i=instart;
               for(;i<=inend;i++)
               {
                   if(post[postend]==in[i])
                   {
                       break;
                   }
               }
               temp->left=function_helper(post,poststart,poststart+i-1,in,instart,i-1);
               temp->right=function_helper(post,poststart+i+1,postend-1,in,i+1,inend);
               return temp;
           }

           public:
           void min_insertions_required( binary_tree & T)
           {
               int count=0;
               min_insertions_required_helper(root,T.root,count);
               if(count==-1)
               {
                   cout<<"not possible";
               }
               else{
                cout<<"min nodes are"<<count;
               }
               return ;
           }
           private:
           static void min_insertions_required_helper( node<t>*my, node<t>*other,int & count)
           {
               if(other!=NULL && my==NULL)
               {

                   count+=node_count_helper(other);
                   return ;
               }
               else if(other==NULL && my==NULL)
               {
                   return ;
               }
               else if(other==NULL && my!=NULL)
               {
                   count=-1;
                   return ;
               }
               min_insertions_required_helper(my->left,other->left,count);
                if(count==-1)
               {
                   return ;

               }
               min_insertions_required_helper(my->right,other->right,count);
                if(count==-1)
               {
                   return ;

               }
               return;
           }

           public:
            void lowest_common_ancestor_method2(const t & el1,const t & el2)
            {
                if(root==0)
                {
                    throw"tree is empty";
                }
                if(is_element_present_helper(root,el1)&&is_element_present_helper(root,el2))
                {
                    node<t>*ptr=lowest_common_ancestor_method2_helper(root,el1,el2);
                    cout<<"lowest common ancestor is:"<<ptr->data<<endl;;
                    return ;
                }
                else{
                    cout<<"lca not possible";
                    return ;
                }
            }

           private:
            static node<t>*lowest_common_ancestor_method2_helper(node<t>*curr,const t & el1,const t & el2)
            {
                if(curr==NULL)
                {
                    return NULL;
                }
                if(curr->data==el1 || curr->data == el2)
                {
                    return curr;
                }
                node<t>*l=lowest_common_ancestor_method2_helper(curr->left,el1,el2);
                node<t>*r=lowest_common_ancestor_method2_helper(curr->right,el1,el2);
                if(r&&l)
                {
                    return curr;
                }
                if(l==NULL)
                {
                    return r;

                }
                else{
                    return l;
                }
            }
                 public:
                void min_depth()
                {
                    if(root==0)
                    {
                        return ;
                    }
                    int count=0;
                    int size=1000000;
                    min_depth_helper(root,count,size);
                    cout<<"min depth is"<<size;
                    return ;
                }
                private:
                static void min_depth_helper(const node<t>*curr,int & count,int & size)
                {
                   if(curr->left==0 && curr->right==0)
                   {
                       count++;
                       if(count<size)
                       {
                           size=count;
                       }
                       count--;
                       return ;
                   }
                   if(curr->left==0 && curr->right!=0)
                   {
                       count++;
                       min_depth_helper(curr->right,count,size);
                       count--;
                       return;
                   }
                   else if(curr->left!=0 && curr->right==0)
                   {
                       count++;
                       min_depth_helper(curr->left,count,size);
                       count--;
                       return;
                   }
                   count++;
                   min_depth_helper(curr->left,count,size);
                   min_depth_helper(curr->right,count,size);
                   count--;
                   return;
                }

                public:
                    node<t>*get_element(const t & el)
                    {
                        if(root==NULL)
                        {
                            throw"tree is empty";
                        }
                        node<t>*ptr=get_element_helper(root,el);
                        if(ptr==NULL)
                        {
                            cout<<"element not found";
                        }
                        else{
                            cout<<"found";
                        }
                        return ;

                    }
                private:
                    const node<t>*get_element_helper(const node<t>*curr,const t & el)
                    {
                        if(curr==NULL)
                        {
                            return NULL;
                        }
                        if(curr->data==el)
                        {
                            return curr;
                        }
                        const node<t>*temp;
                        temp=get_element_helper(curr->left,el);
                        if(temp!=NULL)
                        {
                            return temp;
                        }
                        else{
                            temp=get_element_helper(curr->right,el);
                            if(temp!=NULL)
                            {
                                return temp;
                            }
                            else{
                                return NULL;
                            }
                        }
                    }
            public:
                void func(const t & el,int k)
                {
                    if(root==NULL)
                    {
                        throw"tree is empty";
                    }
                    const node<t>*ptr=get_element_helper(root,el);

                    if(ptr==NULL)
                    {
                        cout<<"invalid element";
                        return;
                    }
                    func_helper(ptr,k);
                    return ;
                }
            private:
                static void func_helper(const node<t>*curr,int k)
                {
                    if(curr==NULL)
                    {
                        return;
                    }
                    if(k==0)
                    {
                        cout<<curr->data<<" ";
                        return ;
                    }
                    func_helper(curr->left,k-1);
                    func_helper(curr->right,k-1);
                    return;
                }

              public:
                void print_at_distance_k(const t & el,int k)
                {
                    if(root==0)
                    {
                        throw"tree is empty";
                    }
                    if(root->data==el)
                    {
                         func(el,k);
                         return ;
                    }
                    func(el,k);
                    print_at_distance_k_helper(root,el,k);
                }

              private:
                static void print_at_distance_k_helper(const node<t>*curr,const t & el,int k)
                {
                    if(curr==NULL || curr->data==el)
                    {
                        return ;
                    }
                    if(is_element_present_helper(curr->left,el))
                    {
                        int ld=check_distance(curr,el);
                        if(k==ld)
                        {
                            cout<<curr->data<<" ";
                            print_at_distance_k_helper(curr->left,el,k);
                        }
                        else if(k>ld)
                        {
                            func_helper(curr->right,k-ld-1);
                            print_at_distance_k_helper(curr->left,el,k);
                        }
                        else{
                            print_at_distance_k_helper(curr->left,el,k);
                        }
                        return ;
                    }
                    else{
                        int rd=check_distance(curr,el);
                        if(k==rd)
                        {
                            cout<<curr->data<<" ";
                            print_at_distance_k_helper(curr->right,el,k);
                        }
                        else if(k>rd)
                        {
                            func_helper(curr->left,k-rd-1);
                            print_at_distance_k_helper(curr->right,el,k);
                        }
                        else{
                            print_at_distance_k_helper(curr->right,el,k);
                        }
                        return ;
                     }
                     return;
                }

              private:
                static int check_distance(const node<t>*curr,const t & el)
                {
                    if(curr==NULL)
                    {
                        return 0;
                    }
                   int size=0;
                check_distance_helper(curr,el,size);
                return size-1;
                }
              private:
                static bool check_distance_helper(const node<t>*curr,const t & el,int &size)
                {
                      if(curr==NULL)
                      {
                          return false;
                      }
                      if(curr->data==el)
                      {
                          size++;
                          return true;
                      }
                      if(check_distance_helper(curr->left,el,size))
                      {
                          size++;
                          return true;
                      }
                      else{
                        if(check_distance_helper(curr->right,el,size))
                        {
                            size++;
                            return true;
                        }
                        else{
                            return false;
                        }
                      }
                }



        public:
            void check_bst()
            {
                int count=0;
                t small=-100000;
                check_bst_helper(root,small,count);
                if(count==5)
                {
                    cout<<"yes";
                }
                else{
                    cout<<"no";
                }
                return ;
            }
        private:
            static void check_bst_helper(const node<t>*curr,t & small,int &count)
            {
                if(curr==NULL)
                {
                    return ;
                }
               check_bst_helper(curr->left,small,count);
               if(curr->data > small)
               {
                   small=curr->data;
                   count++;
               }
               check_bst_helper(curr->right,small,count);
               return ;
            }
};
int main ()
{

//alter the code min_depth like func_helper
    binary_tree<int>T;
    T.create_binary_tree_bfs();
    T.check_bst();
   // T.print_diameter();
    //T.print_height();

    //T.func(1,1);
    //T.min_depth();
    //T.print_at_distance_k(4,4);
   // T.lowest_common_ancestor_method2(4,14);
    //T.print_in_order();
    /*binary_tree<int>Q;
    cout<<endl;

    Q.create_binary_tree_bfs();
    T.min_insertions_required(Q);


   /* int post[]={8,6,3,11,12,9,19,5,4,2};
    int in[]={6,8,3,2,11,9,12,4,19,5};
    T.function(post,in,11);
    T.print_preorder();
    //T.create_binary_tree_bfs();
    //T.print_in_order();
    //T.print_post_order();
    //T.print_diameter();
    //T.print_height();
    //T.post_order_iterative();
    //T.print_level_order();
    //T.lowest_common_ancestor(4,8);
    //T.print_zig_zag_level_order();

    //T.check_if_two_nodes_with_sum(23);
    //T.is_element_present(19);
    /*T.print_preorder();
    T.mirror_method_2();
    T.print_preorder();
    //T.are_leaf_nodes_at_same_level();
    //T.possible_path(30);
    //T.diameter();
    /*T.print_preorder();
    T.print_level_order();
    */
    //T.print_at_depth_k(2);
    //T.print_root_to_el(12);
    //T.print_just_largest_than_k(5);
    //T.maximum_sum();
    /*T.print_leaf_nodes();
    T.delete_leaf_nodes();
    T.print_preorder();
    /*
    T.delete_half_nodes();
    T.print_preorder();
    */
    /*T.mirror();
    T.print_preorder();*/
    /*T.create_binary_tree_dfs();
    T.print_preorder();
   /* binary_tree<int>Q=T;
    Q.print_preorder();
    Q.clear();
    Q=T;
    Q.print_preorder();
    Q==T;
    */
   /* binary_tree<int>Q;
    Q.create_binary_tree_dfs();
    Q==T;
    */
    return 0;
}
/*
 public:
            void check_bst()
            {
                if(root==0)
                {
                    throw"TREE IS EMPTY";
                }
                check_bst_helper(root,100000,-10000000)?cout<<"yes":cout<<"no";
                return;
            }
        private:
            static bool check_bst_helper(const node<t>*curr,t max,t min)
            {
                if(curr==NULL)
                {
                    return true;
                }
                if(curr->data > max || curr->data<min)
                {
                    return false;
                }
                return check_bst_helper(curr->left,curr->data,min)&&check_bst_helper(curr->right,max,curr->data);
            }
            */
