#include<bits/stdc++.h>
using namespace std;
template<typename type>
 class binary_search_tree;
template<typename t>
class bst_node
{
    t data;
    bst_node*left;
    bst_node*right;
public:
    bst_node():left(NULL),right(NULL){}
    bst_node(const t & el):data(el),left(NULL),right(NULL){}
    template<typename type>
    friend class binary_search_tree;
};

template<typename t>
class binary_search_tree
{
    bst_node<t>*root;
public:
    binary_search_tree():root(NULL){}

    binary_search_tree(const binary_search_tree & T)
    {
        root=copy_helper(T.root);
    }

    static bst_node<t>*copy_helper(const bst_node<t>*add)
    {
        if(add==NULL)
        return NULL;

        bst_node<t>*node=new bst_node<t>(add->data);
        node->left=copy_helper(add->left);
        node->right=copy_helper(add->right);
        return node;
    }

    void create_bst(const t & el)
    {
        root=insert_node_helper(root,el);
    }

    ~binary_search_tree()
    {
        //clear();
    }
    void clear()
    {
        clear_helper(root);
        root=NULL;
    }

    void delete_leaf()
    {
        if(root==NULL)
            return ;
        root=delete_leaf_helper(root);
    }

     static bst_node<t>*delete_leaf_helper(bst_node<t>*curr)
     {
         if(curr==NULL)
            return NULL;
         if(!curr->left  &&  ! curr->right)
         {
             delete curr;
             return NULL;
         }
         curr->left=delete_leaf_helper(curr->left);
         curr->right=delete_leaf_helper(curr->right);
         return curr;
     }

    static  void clear_helper(bst_node<t>*curr)
    {
        if(curr==NULL)
            return ;
        clear_helper(curr->left);
        clear_helper(curr->right);
        delete curr;
        return ;
    }

    void insert_node(const t & el)
    {
        root=insert_node_helper(root,el);
    }

    static bst_node<t>*insert_node_helper( bst_node<t>*curr,const t & el)
    {
        if(curr==NULL)
        {
            bst_node<t>*node=new bst_node<t>(el);
            return node;
        }

        if(curr->data < el)
            curr->right=insert_node_helper(curr->right,el);
        else curr->left=insert_node_helper(curr->left,el);
        return curr;
    }

    void create_bbst(const vector<t> & v)
    {
        int start=0;
        int end=v.size()-1;
        root=create_bbst_helper(v,start,end);
    }

    static bst_node<t>*create_bbst_helper(const vector<t> & v,int start,int end)
    {
        if(start >end)
            return NULL;
        int mid=(start+end)/2;
        bst_node<t>*node=new bst_node<t>(v[mid]);
        node->left=create_bbst_helper(v,start,mid-1);
        node->right=create_bbst_helper(v,mid+1,end);
        return node;
    }

    void print_preorder()const
    {
        print_preorder_helper(root);
        cout<<endl;
        return ;
    }
    static void print_preorder_helper(const bst_node<t>*curr)
    {
        if(curr==NULL)
            return ;
        cout<<curr->data<<" ";
        print_preorder_helper(curr->left);
        print_preorder_helper(curr->right);
        return ;
    }

     void print_postorder()const
    {
        print_postorder_helper(root);
        cout<<endl;
        return ;
    }
    static void print_postorder_helper(const bst_node<t>*curr)
    {
        if(curr==NULL)
            return ;
        print_postorder_helper(curr->left);
        print_postorder_helper(curr->right);
          cout<<curr->data<<" ";
        return ;
    }
    void insert_iterative(const t & el)
    {
        bst_node<t>*node=new bst_node<t>(el);
        if(root==NULL)
        {
            root=node;
            return ;
        }
        bst_node<t>*it=root;
        bst_node<t>*prev=NULL;
        while(it)
        {
            prev=it;
            if(it->data < el)
                it=it->right;
            else it=it->left;
        }
        if(prev->data < el)
            prev->right=node;
        else prev->left=node;
        return ;
    }

    void create_bbst_pre(const vector<t> & v)
    {
         root=create_bbst_pre_helper(v,0,v.size()-1);
    }

    static bst_node<t>*create_bbst_pre_helper(const vector<t>  &  v  ,int start,int end)
    {
        if(start > end)
            return NULL;
        bst_node<t>*ptr=new bst_node<t>(v[start]);
        int i;
        for(i=start;i<=end;i++)
        {
            if(v[i] > v[start])
                break;
        }
        i--;
        ptr->left=create_bbst_pre_helper(v,start+1,i);
        ptr->right=create_bbst_pre_helper(v,i+1,end);
        return ptr;
    }

    void print_maximum()
    {
        if(root==NULL)
            return ;
        cout<<print_maximum_helper(root)->data;
    }
    static  bst_node<t>*print_maximum_helper(bst_node<t>*curr)
    {
        if(!curr->left  &&  !curr->right)
        {
            return curr;
        }
        return print_maximum_helper(curr->right);
    }

   void print_minimum()
    {
        if(root==NULL)
            return ;
        cout<<print_minimum_helper(root)->data;
    }
    static  const bst_node<t>*print_minimum_helper(const bst_node<t>*curr)
    {
        if(curr==NULL)
            return NULL;
        if(!curr->left)
        {
            return curr;
        }
        return print_maximum_helper(curr->left);
    }

    void is_present(const t & el) const
    {
        if(root==NULL)
            throw" tree is empty";
        is_present_helper==true ? cout<<"yes"  :   cout<<"no";
    }
    static bool is_present_helper(const bst_node<t>*curr,const t & el)
    {
         if(curr==NULL)
            return false;
        if(curr->data==el)
            return true;
        if(curr->data < el)
        {
            if(is_present_helper(curr->right,el))
                  return true;
            return false;
        }

        if(is_present_helper(curr->left,el))
            return true;
        return false;
    }

    void delete_node(const t & el)
    {
        if(root==NULL)
            return ;
        root=delete_node_helper(root,el);
    }

    static bst_node<t>*delete_node_helper(bst_node<t>*curr,const t & el)
    {
     if(curr==NULL)
            return NULL;
        if(curr->data==el)
        {
           if(!curr->left  &&  !curr->right)
           {
               delete curr;
               return NULL;
           }

         else if(curr->left  && ! curr->right)
          {
              bst_node<t>*ptr=curr->left;
              delete curr;
              return ptr;
          }
         else  if(!curr->left && curr->right)
          {
              bst_node<t>*ptr=curr->right;
              delete curr;
              return ptr;
          }
          else {
          bst_node<t>*ptr=print_maximum_helper(curr->left);
          curr->data=ptr->data;
          curr->left=delete_node_helper(curr->left,ptr->data);
          return curr;
          }
    }
    if(curr->data < el)
        curr->right=delete_node_helper(curr->right,el);
    else  curr->left=delete_node_helper(curr->left,el);
    return curr;
    }
///o(n) approach for successor and predecessor
    void successor(const t & el)
    {
        bst_node<t>*ptr=NULL;
       if(successor_helper(root,el,ptr))
           cout<<ptr->data;
         else  cout<<"no";
           cout<<endl;
    }

    static bool successor_helper( bst_node<t>*curr,const t & el,bst_node<t>*&ptr)
    {
        if(curr==NULL)
            return false;
        if(successor_helper(curr->left,el,ptr))
            return true;
        if(curr->data > el)
        {
            ptr=curr;
            return true;
        }
        if(successor_helper(curr->right,el,ptr))
            return true;
        return false;
    }

    void puccessor(const t & el)
    {
        bst_node<t>*ptr=NULL;
       if(puccessor_helper(root,el,ptr))
           cout<<ptr->data;
         else  cout<<"no";
           cout<<endl;
    }

    static bool puccessor_helper( bst_node<t>*curr,const t & el,bst_node<t>*&ptr)
    {
        if(curr==NULL)
            return false;
        if(puccessor_helper(curr->right,el,ptr))
            return true;
        if(curr->data < el)
        {
            ptr=curr;
            return true;
        }
        if(puccessor_helper(curr->left,el,ptr))
            return true;
        return false;
    }
    /// ALSO YOU HAVE TO CREATE A FUNCTION TO RETURN ADDRESS OF THE DESIRED NODE
    ///0(LOGN) SOLUTION
    /*
    struct node * inOrderSuccessor(struct node *root, struct node *n)
{
    // step 1 of the above algorithm
    if( n->right != NULL )
        return minValue(n->right);

    struct node *succ = NULL;

    // Start from root and search for successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }

    return succ;
}
*/

   void address_of_node(const t & el) const
   {
          address_of_node_helper(root,el);
   }
   static bst_node<t>*address_of_node_helper( bst_node<t>*curr,const t &el)
   {
       if(curr==NULL)
        return NULL;
       if(curr->data==el)
        return curr;
       if(curr->data < el)
        return address_of_node_helper(curr->right,el);
       else return address_of_node_helper(curr->left,el);
   }

   void successor_in_logn(const t & el)
   {
       bst_node<t>*node=address_of_node_helper(root,el);
       if(!node)
        return ;
       if(node->right)
        {
            cout<<print_minimum_helper(node->right)->data<<endl;
            return ;
        }
        bst_node<t>*succ=NULL;
        node=root;
        while(node)
        {
            if(node->data > el)
            {
                succ=node;
                node=node->left;
            }
            else node=node->right;
        }
        if(!succ)
            return;
        cout<<succ->data<<endl;
        return ;

   }

   void predecessor_in_logn(const t & el)
   {
       bst_node<t>*node=address_of_node_helper(root,el);
       if(!node)
        return ;
       if(node->left)
        {
            cout<<print_maximum_helper(node->left)->data<<endl;
            return ;
        }
        bst_node<t>*succ=NULL;
        node=root;
        while(node)
        {
            if(node->data < el)
            {
                succ=node;
                node=node->right;
            }
            else node=node->left;
        }
        if(!succ)
            return;
        cout<<succ->data<<endl;
        return ;

   }
   void count_trees(int n)
   {
       cout<<count_trees_helper(1,n);
   }
   static int count_trees_helper(int start,int end)
   {
       if(start > end)
        return 1;
        int sum=0;
       for(int i=start;i<=end;i++)
       {
           sum=sum+count_trees_helper(start,i-1)*count_trees_helper(i+1,end);
       }
       return sum;
   }


    void insert_duplicates()
    {
        if(root==NULL)
            return ;
        insert_duplicates_helper(root);
    }
    static void insert_duplicates_helper(bst_node<t>*curr)
    {
        if(curr==NULL)
            return;
        bst_node<t>*node=new bst_node<t>(curr->data);
        bst_node<t>*ptr=curr->left;
        curr->left=node;
        node->left=ptr;
        insert_duplicates_helper(node->left);
        insert_duplicates_helper(curr->right);
        return ;
    }

    void print_in_range(const t & k1,const t & k2)
    {
        print_in_range_helper(root,k1,k2);
    }

    static void print_in_range_helper(const bst_node<t>*curr,const t & k1,const t & k2)
    {
        if(curr==NULL)
            return ;
        if(curr->data < k2  && curr->data > k1)
        {
            cout<<curr->data<<" ";
            print_in_range_helper(curr->left,k1,k2);
            print_in_range_helper(curr->right,k1,k2);
        }
        else if(curr->data >= k2)
            print_in_range_helper(curr->left,k1,k2);
        else if(curr->data <=k1)
            print_in_range_helper(curr->right,k1,k2);

        return ;
    }

    void update_nodes_with_sum()
    {
        int sum=0;
        update_nodes_with_sum_helper(root,sum);
    }
    static void update_nodes_with_sum_helper(bst_node<t>*curr,int & sum)
    {
        if(curr==NULL)
            return ;
        update_nodes_with_sum_helper(curr->right,sum);
        sum+=curr->data;
        curr->data=sum;
        update_nodes_with_sum_helper(curr->left,sum);
        return ;
    }

    void create_tree_post(const vector<t> & v)
    {
        if(root)
            throw" TREE ALFREADY EXISTS";
        root=create_tree_post_helper(v,0,v.size()-1);
    }
    static bst_node<t>*create_tree_post_helper(const vector<t> & v  ,int start,int end)
    {
        bst_node<t>*node=new bst_node<t>(v[end]);
        if(start == end)
             return node;
        int i;
        for(i=start ; i<=end ;i++)
        {
            if(v[i] > v[end])
                break;
        }
        i--;
        node->left=create_tree_post_helper(v,start,i);
        node->right=create_tree_post_helper(v,i+1,end-1);
        return node;
    }


    void convert_bst_to_dll()
    {
        bst_node<t>*head=NULL;
        bst_node<t>*tail=NULL;
        convert_bst_to_dll_helper(root,head,tail);
        cout<<"sorted order is\n";
        tail->right=NULL;
        bst_node<t>*it=head;
        while(it)
        {
            cout<<it->data<<" ";
             it=it->right;
        }
        cout<<endl<<"reverse order is \n";
        it=tail;
        while(it)
        {
            cout<<it->data<<" ";
            it=it->left;
        }
        return ;

    }

    /// TIME COMPLEXITY O(N) AND SPACE COMPLEXITY O(1) + O(LOGN) OF FUNCTION CALL STACK
    static  void convert_bst_to_dll_helper(bst_node<t> * curr,bst_node<t>*&head,bst_node<t> * & tail)
    {
        if(curr==NULL)
            return;
        convert_bst_to_dll_helper(curr->left,head,tail);
        curr->left=tail;
        if(head==NULL)
            head=curr;
        if(tail!=NULL)
        tail->right=curr;
        tail=curr;
        convert_bst_to_dll_helper(curr->right,head,tail);
        return ;
    }

    void nodes_with_sum(t sum)
    {
        pair<bst_node<t>*,bst_node<t>*> my_pair(NULL,NULL);
        stack<bst_node<t>*> s,r;
       bool bool_value1=false;
       bool bool_value2=false;
       bst_node<t>*it1=root;
       bst_node<t>*it2=root;
       bst_node<t>*val1;
       bst_node<t>*val2;

       while(1)
       {

       while(bool_value1==false)
       {
           if(it1)
           {
               s.push(it1);
               it1=it1->left;
           }
           else{
              if(!s.empty())
              {
                  val1=s.top();
                  bool_value1=1;
                  it1=s.top()->right;
                  s.pop();
              }
              else bool_value1=true;
           }
       }
       while(bool_value2==false)
       {
           if(it2)
           {
               r.push(it2);
               it2=it2->right;
           }
           else{
            if(!r.empty())
            {
                val2=r.top();
                it2=r.top()->left;
                r.pop();
                bool_value2=1;
            }
            else bool_value2=1;
           }
       }

       if(val1->data+val2->data==sum)
       {
           my_pair.first=val1;
           my_pair.second=val2;
           break;
       }
       else if(val1->data + val2->data > sum)
            bool_value2=false;
       else bool_value1=false;
    }


    if(my_pair.first)
    {
        cout<<my_pair.first->data<<" "<<my_pair.second->data;
    }
    else cout<<"not possible";

    }


    void print_at_distance_k(t  el,int k)
    {
        if(root==NULL)
            return ;
        bst_node<t>*node=address_of_node_helper(root,el);
        print_at_distance_k_helper(root,node,k);
        return ;
    }
    static int  print_at_distance_k_helper( bst_node<t>*curr,bst_node<t>*target,int k)
    {
       if(curr==NULL)
          return -1;
       if(curr==target)
       {
           print_at_depth_k_helper(target,k);
           return 0;
       }

       int ld=print_at_distance_k_helper(curr->left,target,k);
       if(ld!=-1)
       {
           ld++;
           if(ld==k)
            cout<<curr->data<<" ";
           else print_at_depth_k_helper(curr->right,k-ld-1);
           return ld;
       }
       int rd=print_at_distance_k_helper(curr->right,target,k);
       if(rd!=-1)
       {
           rd++;
           if(rd==k)
            cout<<curr->data<<" ";
           else print_at_depth_k_helper(curr->left,k-ld-1);
           return rd;
       }
       return -1;
    }

    void print_at_depth_k(bst_node<t>*target,int k)
    {
        print_at_depth_k_helper(target,k);
    }
    static void print_at_depth_k_helper( bst_node<t>*curr,int k)
    {
        if(curr==NULL)
            return ;
        if(k==0)
        {
            cout<<curr->data<<" ";
            return ;
        }
        print_at_depth_k_helper(curr->left,k-1);
        print_at_depth_k_helper(curr->right,k-1);
        return ;
    }


   void lca(const t  k1,const t  k2)
   {
       bool v1=false;
       bool v2=false;
       bst_node<t>*node=lca_helper(root,k1,k2,v1,v2);
        /// CALL FOR IS PRESENT FUNCTION TO CONFIRM WHETHER FALSE ONE IS PRESENT OR NOT
        return ;
   }
   static bst_node<t>*lca_helper( bst_node<t>*curr,const t & k1,const t & k2,bool & v1,bool & v2)
   {
       if(curr==NULL)
        return NULL;
       if(curr->data==k1)
       {
         v1=true;
         return curr;
       }
       if(curr->data==k2)
       {
           v2=true;
           return curr;
       }
      if(k2 < curr->data)
          return lca_helper(curr->left,k1,k2,v1,v2);
      else if(k1 > curr->data)
            return lca_helper(curr->right,k1,k2,v1,v2);
      else if(k1 < curr->data && k2 > curr->data)
            return curr;
   }

};
int main()
{
    binary_search_tree<int> T;
    int n;
    cout<<"enter n";
    cin>>n;
    vector<int> v;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        v[i]=val;
       // T.insert_iterative(val);
    }

    T.create_bbst(v);
    T.print_preorder();
    T.lca(7,11);
    //T.print_at_distance_k(10,4);
    //T.nodes_with_sum(46);
    //T.print_preorder();
    //T.create_bbst_pre(v);
    //T.print_in_range(1,25);
   // T.update_nodes_with_sum();
    //T.convert_bst_to_dll();

    /*T.print_preorder();
    T.insert_duplicates();
    T.print_preorder();
    */
    //T.predecessor_in_logn(10);
    //T.print_preorder();
   // T.successor_in_logn(8);
    //cout<<endl;
    /*T.successor_in_logn(4);
    T.successor_in_logn(10);
    T.successor_in_logn(20);
    T.successor_in_logn(22);
   // T.count_trees(13);
*/
   // T.create_bbst_pre(v);

    //T.print_maximum();
    //T.delete_node(7);
    //T.print_preorder();


    return 0;
}
