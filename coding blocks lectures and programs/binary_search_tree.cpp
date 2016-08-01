#include<iostream>
#include<vector>
using namespace std;

template<typename t>
class node
{
    t data;
    node*left;
    node*right;

    public:
    node():left(0),right(0),data(0){}
    node(const t & el):data(el),right(0),left(0){}

    template<typename u>
    friend class binary_search_tree;

};
template<typename t>
class deque_node
{
    t data;
    deque_node*prev,*next;

public:
    deque_node(const t & el):data(el),prev(0),next(0){}

    template<typename u>
    friend class binary_search_tree;
};
template<typename t>
class binary_search_tree
{
    node<t>*root;
    node<t>*max;
    node<t>*min;
    deque_node<t>*head,*tail;


public:
    binary_search_tree():root(0),min(NULL),max(NULL),head(0),tail(0){}
    binary_search_tree(const binary_search_tree & T):root(0),max(NULL),min(NULL)
    {
        root=copy(T.root);
        max=print_maximum_helper(root);
        min=print_minimum_helper(root);
        return ;
    }
private:
    static node<t>* copy(const node<t>*other)
    {
        if(other==NULL)
        {
            return NULL;
        }
        node<t>*temp=new node<t>(other->data);
        temp->left=copy(other->left);
        temp->right=copy(other->right);
        return temp;
    }

    public:
    ~binary_search_tree()
    {
        clear();

    }

    void clear()
    {

        clear_helper(root);
        root=0;
        min=0;
        max=0;
        return ;
    }
    private:
        static void clear_helper(node<t>*address)
        {
            if(address==NULL)
            {
                return ;
            }
            if(address->left==NULL && address->right==NULL)
            {
                delete address;
                return ;
            }
            clear_helper(address->left);
            clear_helper(address->right);
            return ;
        }
    public:
        void create_binary_search_tree(const t & el)
        {
           root=insert_nodes_helper(root,el,min,max);
           return ;
        }

        void insert_nodes(const t & el)
        {
            root=insert_nodes_helper(root,el,min,max);
            return ;
        }
        private:

        static node<t>*insert_nodes_helper( node<t>*curr,const t & el,node<t>* & t_min,node<t>*& t_max)
        {
            if(curr==NULL)
            {
                node<t>*temp=new node<t>(el);
                if(t_min==NULL && t_max==NULL)
                {
                    t_min=t_max=temp;
                }
                else{
                    if(el > t_max->data)
                    {
                        t_max=temp;
                    }
                    else if(el < t_min->data)
                    {
                        t_min=temp;
                    }
                }
                return temp;
            }
            else if(curr->data >= el)
            {
                curr->left=insert_nodes_helper(curr->left,el,t_min,t_max);
            }
            else if(curr->data < el)
            {
                curr->right=insert_nodes_helper(curr->right,el,t_min,t_max);
            }
            return curr;
        }

        public:
            binary_search_tree & operator =(const binary_search_tree & T)
            {
                clear();
                root=(T.root);
                return ;
            }

public:
        void print_preorder()
        {
            print_preorder_helper(root);
            cout<<endl;
            return ;
        }
    private:
        static void print_preorder_helper(const node<t>*address)
        {
            if(address==NULL)
            {
                return ;
            }
            cout<<address->data<<" ";
            print_preorder_helper(address->left);
            print_preorder_helper(address->right);
            return ;
        }

        public:
        void print_minimum() const
        {
            if(root==0)
            {
                throw"tree is empty";
            }
             const node<t>*min=print_minimum_helper(root);
            cout<<min->data;
            cout<<endl;
            return ;
        }
    private:
        static const node<t>*print_minimum_helper(const node<t>*curr)
        {
            if(curr->left==NULL)
            {
                return curr;
            }
            print_minimum_helper(curr->left);
        }
           private:
        static  node<t>*print_minimum_helper( node<t>*curr)
        {
            if(curr->left==NULL)
            {
                return curr;
            }
            print_minimum_helper(curr->left);
        }

    public:
        void print_maximum() const
        {
            if(root==NULL)
            {
                throw" tree is empty";
            }
             const node<t>*max=print_maximum_helper(root);
            cout<<max->data<<endl;
            return ;
        }
    private:
        static  const node<t>*print_maximum_helper( const node<t>*curr)
        {
            if(curr->right==NULL)
            {
                return curr;
            }
            print_maximum_helper(curr->right);
        }

        static  node<t>*print_maximum_helper(  node<t>*curr)
        {
            if(curr->right==NULL)
            {
                return curr;
            }
            print_maximum_helper(curr->right);
        }

    public:
        void find_element(const t & el)
        {
            if(root==NULL)
            {
                throw" tree is empty";
            }
            if(find_element_helper(root,el))
            {
                cout<<"yes found";
            }
            else{
                cout<<"no";
            }
            return ;
        }

     private:
        static bool find_element_helper(const node<t>*curr,const t & el)
        {
            if(curr==NULL)
            {
                return false;
            }
            else if(curr->data==el)
            {
                return true;
            }
            else if(curr->data > el)
            {
                if(find_element_helper(curr->left,el))
                {
                    return true;
                }
            }
            else{
                if(find_element_helper(curr->right,el))
                {
                    return true;
                }
            }
            return false;
        }

        public:
    void create_tree_using_pre(t*arr,int n)
    {
         int start=0;
         int end=n-1;
         root=create_tree_using_pre_helper(arr,start,end,max,min);
         return ;

    }
     private:
    static node<t>*create_tree_using_pre_helper(t*arr,int start,int end,node<t>*&t_max,node<t>*&t_min)
    {
        if(start > end)
        {
            return NULL;
        }
        node<t>*curr=new node<t>(arr[start]);
        if(t_min==NULL && t_max==NULL)
                {
                    t_min=t_max=curr;
                }
                else{
                    if(arr[start] > t_max->data)
                    {
                        t_max=curr;
                    }
                    else if(arr[start] < t_min->data)
                    {
                        t_min=curr;
                    }
                }
        int i;
        for(i=start+1;i<end;i++)
        {
            if(arr[i] > arr[start])
            {
                break;
            }
        }
        int k=i-1;
        curr->left=create_tree_using_pre_helper(arr,start+1,k,t_max,t_min);
        curr->right=create_tree_using_pre_helper(arr,k+1,end,t_max,t_min);
        return curr;

    }

     public:
        void delete_nodes(const t & el)
        {
            if(root==NULL)
            {
                throw "tree is empty";
            }
           /* cout<<"hello";
            cout<<min->data;
            cout<<"hello";
            */
            root=delete_nodes_helper(root,el);
            max=print_maximum_helper(root);
            min=print_minimum_helper(root);
            return;
        }


     private:
        static node<t>*delete_nodes_helper(node<t>*curr,const t & el)
        {
            if(curr==NULL)
            {
                return NULL;
            }
            else if(curr->data < el)
            {
                curr->right=delete_nodes_helper(curr->right,el);
                return curr;
            }
            else if(curr->data > el)
            {
                curr->left=delete_nodes_helper(curr->left,el);
                return curr;
            }
            else{
                if(curr->left==NULL&&curr->right==NULL)
                {
                    delete curr;
                    return NULL;
                }
                else if(curr->left==NULL && curr->right!=NULL)
                {
                    node<t>*temp=curr->right;
                    delete curr;
                    return temp;
                }
                else if(curr->left!=NULL && curr->right==NULL)
                {
                    node<t>*temp=curr->left;
                    delete curr;
                    return temp;
                }
                else{
                    node<t>*temp=print_maximum_helper(curr->left);
                    t val=temp->data;
                    curr->left=delete_nodes_helper(curr->left,val);
                    curr->data=val;
                    return curr;
                }
            }
        }
        public:
        void insert_iterative(const t & el)
        {
            node<t>*temp=new node<t>(el);
            if(root==NULL)
            {
                root=temp;
                return ;
            }
            node<t>*it=root;
            node<t>*prev=NULL;
            while(it!=NULL)
            {
                if(it->data < el)
                {
                    prev=it;
                    it=it->right;
                }
                else{
                    prev=it;
                    it=it->left;
                }
            }

            if(prev->data < el)
            {
                prev->right=temp;
                return ;
            }
            else{
                prev->left=temp;
                return ;
            }
        }
        public:
            void create_binary_search_tree_inorder(vector<t> & v)
            {
                if(root!=NULL)
                {
                    throw"tree is already created";
                }

                int start=0;
                int end=v.size()-1;
                root=create_binary_search_tree_inorder_helper(v,start,end);
            }
        private:
            static node<t>*create_binary_search_tree_inorder_helper(vector<t>&v,int start,int end)
            {
                if(start > end)
                {
                    return NULL;
                }
                int mid=(start+end)/2;
                node<t>*curr=new node<t>(v[mid]);
                curr->left=create_binary_search_tree_inorder_helper(v,start,mid-1);
                curr->right=create_binary_search_tree_inorder_helper(v,mid+1,end);
                return curr;

            }


        public:
            node<t>* get_maximum()
            {
                if(root==0)
                {
                    throw"tree is empty";
                }
                return max;
            }
            node<t>* get_minimum()
            {
                if(root==0)
                {
                    throw " tree is empty";
                }

                return min ;
            }

            void size() const
            {
                cout<<"size is:"<<size_helper(root);
                cout<<endl;
                return ;
            }
        private:
            static int size_helper(const node<t>*address)
            {
                if(address==NULL)
                {
                    return 0;
                }
                return 1+size_helper(address->left)+size_helper(address->right);
            }

        public:
            void is_empty()
            {
                if(size_helper(root)==0)
                {
                    cout<<"empty";
                }
                else{
                    cout<<"not empty";
                }
                return ;
            }
            void successor(const t& el)
            {
                if(root==0)
                {
                    throw"tree is empty";
                }
                const node<t>*temp=get_node(root,el);
                if(temp==NULL)
                {
                    cout<<"element not present";
                    return ;
                }
                if(temp->right!=NULL)
                {
                    node<t>*ptr=print_minimum_helper(temp->right);
                    cout<<"succesor is:"<<ptr->data;
                    return ;
                }
                node<t>*parent=NULL;
                node<t>*curr=root;
                while(curr!=temp)
                {
                    if(curr->data > temp->data)
                    {
                        parent=curr;
                        curr=curr->left;
                    }
                    else{
                        curr=curr->right;
                    }
                }
                if(parent==NULL)
                {
                    cout<<"succesor not possible";
                }
                else{
                    cout<<"successor is:"<<parent->data;
                }
                return ;
            }
            private:
           const node<t>*get_node( const node<t>*address,const t & el) const
            {
                if(address==NULL)
                {
                    return NULL;
                }
                if(address->data > el)
                {
                     return get_node(address->left,el);
                }
                else if(address->data < el)
                {
                     return get_node(address->right,el);
                }
                else{
                    return address;
                }
            }


               node<t>*get_node(  node<t>*address,const t & el)
            {
                if(address==NULL)
                {
                    return NULL;
                }
                if(address->data > el)
                {
                     return get_node(address->left,el);
                }
                else if(address->data < el)
                {
                     return get_node(address->right,el);
                }
                else{
                    return address;
                }
            }

public:
            void predecessor(const t & el)
            {
                if(root==0)
                {
                    throw"tree is empty";
                }
                const node<t>*temp=get_node(root,el);
                if(temp==0)
                {
                    cout<<"element not found";
                    return ;
                }
                if(temp->left!=NULL)
                {
                    node<t>*ptr=print_maximum_helper(temp->left);
                    cout<<"predecessor is:"<<ptr->data;
                    return ;
                }
                node<t>*parent=NULL;
                node<t>*curr=root;
                while(curr!=temp)
                {
                    if(curr->data < temp->data)
                    {
                        parent=curr;
                        curr=curr->right;
                    }
                    else{
                        curr=curr->left;
                    }
                }
                if(parent==NULL)
                {
                    cout<<"predecessor not possible";
                }
                else{
                    cout<<"predecessor:"<<parent->data;
                }
                return ;

            }


        public:
            void check_bst()
            {
                int count=0;
                t small=-100000;
                check_bst_helper(root,small,count);
                if(count==size_helper(root))
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

        public:
            void create_binary_search_tree_post(const vector<t>& v)
            {
                if(v.size()==0)
                {
                    cout<<"vector is empty";
                    return ;
                }
                int start=0;
                int end=v.size()-1;
                root=create_binary_search_tree_post_helper(v,start,end);
                return ;
            }
        private:
            static node<t>*create_binary_search_tree_post_helper(const vector<t> & v,int start,int end)
            {
                if(start > end)
                {
                    return NULL;
                }
                node<t>*curr=new node<t>(v[end]);
                int i;
                for( i=start;i<end;i++)
                {
                    if(v[i]>v[end])
                    {
                        break;
                    }
                }
                int k=i-1;
                curr->left=create_binary_search_tree_post_helper(v,start,k);
                curr->right=create_binary_search_tree_post_helper(v,k+1,end-1);
                return curr;
            }

        public:
            void print_in_range(const t &el1,const t & el2)
            {

                if(el1>el2)
                {
                    print_in_range_helper(root,el1,el2);
                }
                else{
                    print_in_range_helper(root,el2,el1);
                }
                return ;
            }

        private:
            static void print_in_range_helper(const node<t>*curr,const t &k1,const t & k2)
            {
                if(curr==NULL)
                {
                    return ;
                }
                if(curr->data < k1 && curr->data > k2)
                {
                    cout<<curr->data<<" ";
                    print_in_range_helper(curr->left,k1,k2);
                    print_in_range_helper(curr->right,k1,k2);
                }
                 else if(curr->data < k2)
                {
                    print_in_range_helper(curr->right,k1,k2);
                }
                else if(curr->data > k1)
                {
                    print_in_range_helper(curr->left,k1,k2);
                }
                else if(curr->data == k1 || curr->data==k2)
                {
                    return ;
                }
                return ;
            }
            public:
            void create_double_linked_list()
            {
                if(root==0)
                {
                    throw"tree is empty";
                }
                deque_node<t>*it;
                create_double_linked_list_helper(root,head,it);
            }
            void create_double_linked_list_helper(const node<t>*curr, deque_node<t> * & head ,deque_node<t>*&it)
            {
                if(curr==NULL)
                {
                    return ;
                }
                create_double_linked_list_helper(curr->left,head,it);
                deque_node<t>*temp=new deque_node<t>(curr->data);
                if(head==NULL)
                {
                    head=tail=temp;
                    temp->prev=NULL;
                    it=head;
                }
                else{
                    it->next=temp;
                    tail=temp;
                    temp->prev=it;
                    it=temp;
                }
                create_double_linked_list_helper(curr->right,head,it);
                return ;
            }

            void print_deque()
            {
                if(head==0)
                {
                    return ;
                }
                deque_node<t>*it=head;
                while(it)
                {
                    cout<<it->data<<" ";
                    it=it->next;
                }
                cout<<endl;
                return ;
            }

            void print_deque_reverse()
            {
                if(head==0)
                {
                    return ;
                }
                deque_node<t>*it=tail;
                while(it)
                {
                    cout<<it->data<<" ";
                    it=it->prev;
                }
                cout<<endl;
                return;
            }

            void insert_duplicates()
            {
                insert_duplicates_helper(root);
                return;
            }
            void insert_duplicates_helper(node<t>*curr)
            {
               if(curr==NULL)
               {
                   return ;
               }
               node<t>*ptr=curr->left;
               node<t>*temp=new node<t>(curr->data);
               curr->left=temp;
               temp->left=ptr;
               insert_duplicates_helper(temp->left);
               insert_duplicates_helper(curr->right);
               return ;
            }
/*
            void find_pair_with_sum(const t & sum)
            {
                if(root==0)
                {
                    throw"tree is empty";
                }
                pair<node<t>*,node<t>*>mypair(NULL,NULL);
                find_pair_with_sum_helper(root,mypair,sum);

                    if(mypair.first&&mypair.second)
                    {
                        cout<<mypair.first->data<<" "<<mypair.second->data<<endl;
                        return ;
                    }
                    cout<<"not possible";
                    return;
            }
            private:
            static void find_pair_with_sum_helper( node<t>*curr,pair<node<t>*,node<t>*>&mypair,const t & sum)
            {
                if(curr==NULL)
                {
                    return ;
                }
                if(curr->data >=sum)
                {
                    find_pair_with_sum_helper(curr->left,mypair,sum);
                }
                else{
                    mypair.first=curr;
                    node<t>*temp=get_node(curr,sum-curr->data);
                    if(temp==curr || temp==NULL)
                    {
                        mypair.first=NULL;
                        find_pair_with_sum_helper(curr->left,mypair,sum);
                        find_pair_with_sum_helper(curr->right,mypair,sum);
                        return ;
                    }
                    mypair.second=temp;
                    return ;
                }
                return;
            }
            */

            void find_pair_with_sum(const t & sum)
            {
                if(root==0)
                {
                    throw "TREE IS EMPTY";
                }
                vector<t>v;
                find_pair_with_sum_helper(root,v,sum);
                int i=0;
                int j=v.size()-1;
                while(j>i)
                {
                    if(v[i]+v[j]==sum)
                    {
                        cout<<v[i]<<" "<<v[j]<<endl;
                        return ;
                    }
                    else if(v[i]+v[j]>sum)
                    {
                        j--;
                    }
                    else{
                        i++;
                    }
                }
                cout<<"not possible";
                return ;
            }

            private:
                static void find_pair_with_sum_helper(const node<t>*curr,vector<t>&v,const t &sum)
                {
                    if(curr==NULL)
                    {
                        return;
                    }
                    find_pair_with_sum_helper(curr->left,v,sum);
                    v.push_back(curr->data);
                    find_pair_with_sum_helper(curr->right,v,sum);
                    return ;
                }


            public:
                void update_with_sum()
                {
                    if(root==0)
                    {
                        throw"tree is empty";
                    }
                    vector<pair<node<t>*,t> >v;
                    int flag=0;
                    int it=0;
                    update_with_sum_helper(root,v,flag);
                    update_with_sum_util(v,root,it);
                    v.clear();
                    return ;
                }
            private:
                static void update_with_sum_util(vector<pair<node<t>*,t> > & v  , node<t>*curr,int & it)
                {
                    if(curr==NULL)
                    {
                        return ;
                    }
                    update_with_sum_util(v,curr->right,it);
                    pair<node<t>*,t>temp;
                    temp=v[it];
                    it++;
                    if(temp.second!=0)
                    {
                        curr->data=temp.second;
                    }
                    update_with_sum_util(v,curr->left,it);
                    return ;
                }
            private:
                static void update_with_sum_helper(node<t>*curr,vector<pair<node<t>*,t> >& v,int & flag)
                {
                    if(curr==NULL)
                    {
                        return ;
                    }
                    update_with_sum_helper(curr->right,v,flag);
                    if(flag==0)
                    {
                        pair<node<t>*,t> temp;
                        temp.first=curr;
                        temp.second=0;
                        v.push_back(temp);
                        flag++;
                    }
                    else{
                        pair<node<t>*,t> temp=v[v.size()-1];
                        pair<node<t>*,t> my_pair;
                        my_pair.first=curr;
                        my_pair.second=temp.second+temp.first->data;
                        v.push_back(my_pair);
                    }
                    update_with_sum_helper(curr->left,v,flag);
                    return ;
                }

public:
               static int find_possible_bst(int start,int end)
                {
                    if(start>end)  //|| start==end)
                    {
                        return 1;
                    }
                    int count=0;
                    for(int i=start;i<=end;i++)
                    {
                        count+=find_possible_bst(start,i-1)*find_possible_bst(i+1,end);
                    }
                    return count;
                }
};

int main()
{
    /*
    max and min are updated in functions create tree,insert nodes,delete nodes
    */

    binary_search_tree<int>T;
    //cout<<T.find_possible_bst(1,4);

   /* int n;
cout<<"enter the number of nodes";
cin>>n;
    vector<int>V;
    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;
        V.push_back(val);
    }
    T.create_binary_search_tree_inorder(V);
    /*T.insert_duplicates();
    T.print_preorder();
    /*T.create_double_linked_list();
    T.print_deque();
    T.print_deque_reverse();

   // T.print_in_range(1,3);
   //T.print_preorder();
    /*
    T.get_maximum();

    T.delete_nodes(10);
    T.delete_nodes(1);
    T.get_maximum();
    T.get_minimum();
    T.size();
    T.is_empty();
    */

    /*int n;
    cout<<"enter the number of nodes";
    cin>>n;
    cout<<"enter the data for the nodes";
    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;
        T.create_binary_search_tree(val);
    }
*/
/*
    T.print_preorder();
    T.update_with_sum();
    T.print_preorder();

    //T.check_bst();
    //T.find_pair_with_sum(5);
     /*T.print_preorder();
     T.print_in_range(1,3);

    /*T.create_binary_tree_dfs();
     T.print_preorder();
     cout<<endl;
     T.check_bst();
    //T.predecessor(5);
    cout<<endl;
    //T.successor(6);
    //T.insert_nodes(-1);
    /*T.print_preorder();
    T.get_maximum();
    /*T.print_minimum();
    T.find_element(10);
    */
   // T.insert_iterative(100);
   // T.delete_nodes(2);
   // T.print_preorder();





    return 0;
}
