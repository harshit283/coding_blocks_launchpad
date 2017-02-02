







#include<bits/stdc++.h>
using namespace std;
template<typename type>
 class binary_tree;
template<typename t>
class bt_node
{
    t data;
    bt_node*left;
    bt_node*right;
public:
    bt_node(const t & el):data(el),left(NULL),right(NULL){}
    template<typename type>
    friend class binary_tree;
};

template<typename t>
class binary_tree
{
    bt_node<t>*root;
public:
    binary_tree():root(NULL){}

    void create_tree()
    {
        if(root!=NULL)
           throw"TREE ALREADY EXISTS";
           root=create_tree_helper();
    }

    static bt_node<t>*create_tree_helper()
    {
        cout<<"enter the data for the node ";
        int el;
        cin>>el;
        bt_node<t>*node=new bt_node<t>(el);

        cout<<"does " <<el<<" has a left child (y/n) ";
        char ch;
        cin>>ch;
        if(ch=='y' || ch=='Y')
            node->left=create_tree_helper();
        cout<<"does " <<el<<" has a right child (y/n) ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
            node->right=create_tree_helper();
        return node;
    }

    void print_preorder() const
    {
        print_preorder_helper(root);
        cout<<endl;
    }

    static void print_preorder_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
            return ;
        cout<<curr->data<<" ";
        print_preorder_helper(curr->left);
        print_preorder_helper(curr->right);
        return ;
    }

    void print_postorder() const
    {
        print_postorder_helper(root);
        cout<<endl;
    }

    static void print_postorder_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
            return ;
        print_postorder_helper(curr->left);
        print_postorder_helper(curr->right);
        cout<<curr->data<<" ";
        return ;
    }

    void print_inorder() const
    {
        print_inorder_helper(root);
        cout<<endl;
    }

    static void print_inorder_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
            return ;
        print_inorder_helper(curr->left);
         cout<<curr->data<<" ";
        print_inorder_helper(curr->right);
        return ;
    }

    void print_height() const
    {
        if(root==NULL)
            return;
        cout<<"HEIGHT IS:"<<print_height_helper(root);
    }
    static int print_height_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
            return -1;
        return 1+max(print_height_helper(curr->left),print_height_helper(curr->right));
    }

    void delete_half_nodes()
    {

        root=delete_half_nodes_helper(root);
    }

    static bt_node<t>*delete_half_nodes_helper( bt_node<t>*curr)
    {
        if(curr==NULL)
            return NULL;
        curr->left=delete_half_nodes_helper(curr->left);
        curr->right=delete_half_nodes_helper(curr->right);
        if(curr->left==NULL && curr->right!=NULL)
        {
            bt_node<t>*ptr=curr->right;
            delete curr;
            return ptr;
        }
        else if(curr->left!=NULL && curr->right==NULL)
        {
            bt_node<t>*ptr=curr->left;
            delete curr;
            return ptr;
        }
        return curr;
    }

    void delete_leaf()
    {
        root=delete_leaf_helper(root);
    }
    static bt_node<t>*delete_leaf_helper(bt_node<t>*curr)
    {
        if(curr==NULL)
            return NULL;
        if( !curr->left && ! curr->right)
        {
            delete curr;
            return NULL;
        }
        curr->left=delete_leaf_helper(curr->left);
        curr->right=delete_leaf_helper(curr->right);
        return curr;
    }

    bool operator == (const binary_tree & T) const
    {
        return helper(root,T.root);
    }

   static bool helper(const bt_node<t>*curr,const bt_node<t>*add)
    {
        if(!curr && ! add)
        return true;
        if(!curr && add || curr &&  !add)
            return false;
        if(curr->data != add->data)
            return false;
        if(helper(curr->left,add->left))
        {
            if(helper(curr->right,add->right))
               return true;
            else return false;
        }
        return false;
    }


    void create_from_post_in(int *post,int*in,int n)
    {
        root=create_from_post_in_helper(post,in,n);
    }

    static bt_node<t>*create_from_post_in_helper(int *post,int *in ,int n)
    {
        ///BASE CASE
        if(n<=0)
            return NULL;
        bt_node<t>*node=new bt_node<t>(post[n-1]);
        int i;
        for( i=0;i<n;i++)
        {
            if(post[n-1]==in[i])
                break;
        }
        node->left=create_from_post_in_helper(post,in,i);
        node->right=create_from_post_in_helper(post+i,in+i+1,n-i-1);
        return node;
    }

    void print_diameter() const
    {
        if(root==NULL)
            return ;
        pair<int,int> my_pair=print_diameter_helper(root);
        cout<<my_pair.first<<" "<<my_pair.second;
    }
    static pair<int,int> print_diameter_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
        {
               pair<int,int>temp(0,0);
               return temp;
        }
          pair<int,int> left,right;
          left=print_diameter_helper(curr->left);
          right=print_diameter_helper(curr->right);
          left.first= max(max(left.first,right.first),1+left.second+right.second);
          left.second=1+max(left.second,right.second);
          return left;
    }

    void is_balanced() const
    {
        if(root==NULL)
            return false;
        pair<int,bool>temp=is_balanced_helper();
        if(temp.second==false)
            cout<<"no";
        else cout<<"yes";
        return ;
    }
    static pair<int ,bool>  is_balanced_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
            {
                 pair<int,bool> temp(0,true);
            }
        pair<int,bool> l=is_balanced_helper(curr->left);
        pair<int,bool> r=is_balanced_helper(curr->right);
        if(l.second == false || r.second==false)
        {
            l.second=false;
            return l;
        }
        l.first=1+max(l.first,r.first);
        l.second=true;
        return l;
    }

    void print_nodes_with_no_sibling() const
    {
        if(root==NULL)
            return ;
        print_nodes_with_no_sibling_helper(root);
    }

    static void print_nodes_with_no_sibling_helper(const bt_node<t>*curr)
    {
        if(curr==NULL || curr->left==NULL && curr->right==NULL)
            return ;
        if(!curr->left && curr->right)
        {
            cout<<curr->right->data<<" ";
            print_nodes_with_no_sibling_helper(curr->right);
            return ;
        }
        if(curr->left && !curr->right)
        {
            cout<<curr->left->data<<" ";
            print_nodes_with_no_sibling_helper(curr->left);
            return ;
        }

        print_nodes_with_no_sibling_helper(curr->left);
        print_nodes_with_no_sibling_helper(curr->right);
        return ;
    }

   void max_sum_path() const
   {
      ///REFER BINARY TREE CLASS(binary_tree.cpp)
   }

   void leaf_at_same_level() const
   {
       if(root==NULL)
        return ;
        int height=-1;
       leaf_at_same_level_helper(root,0,height)==true ? cout<<"yes" : cout<<"no";
       return ;
   }


   static bool leaf_at_same_level_helper(const bt_node<t>* curr, int temp ,int &height)  ///NEW VARIABLE HEIGHT WILL BE FORMED EVERY TIME ( ON THAT PARTICULAR STACK)
                                                                                        /// HENCE WHEN WE RETURN height will be same as original so here temp and height are
                                                                                         ///  modified in same way

   {
       if(curr==NULL)
        return true;
       if( ! curr->left  &&  ! curr->right)
       {
           if(height==-1)
            {
                height=temp;
                cout<<height<<endl;
                return true;
            }
           else
           {    if(temp!=height)
                return false;
                else return true;
           }
       }
       if(leaf_at_same_level_helper(curr->left,temp+1,height))
       {
        if(leaf_at_same_level_helper(curr->right,temp+1,height))
             return true;
       else return false;
       }
       return false;
   }

     const bt_node<t>*is_present( t  el) const
     {
         return is_present_helper(el,root);
     }

    static const bt_node<t>* is_present_helper( t & el,const  bt_node<t>*curr)
     {
         if(curr==NULL)
            return NULL;
         if(curr->data==el)
            return curr;
        const bt_node<t>*l=is_present_helper(el,curr->left);
         if(l==NULL)
            return is_present_helper(el,curr->right);
         else return l;
     }

     void node_with_sum(  t sum) const
     {
         if(root==NULL)
            return ;
         if(nodes_with_sum_helper(sum,root))
            cout<<"yes";
         else cout<<"no";
         return ;
     }

    bool nodes_with_sum_helper( t sum, const bt_node<t>*curr) const
     {
         if(curr==NULL)
            return false;
        const bt_node<t>*ptr=is_present(sum-curr->data);
         if(ptr)
            return true;
         if(nodes_with_sum_helper(sum,curr->left))
            return true;
         if(nodes_with_sum_helper(sum,curr->right))
            return true;
         return false;
     }

     ///LOWEST COMMON ANCESTOR
     /// MAKE SURE THAT BOTH ROOTS ARE PRESENT
     /*
     struct Node *findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL) return NULL;

    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1 || root->key == n2)
        return root;

    // Look for keys in left and right subtrees
    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);

    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}
*/

///MIRROR THE TREE


/// JUST LARGER THAN K SAME AS WE DID IN GENERIC TREE

   void min_depth()
   {
       cout<<min_depth_helper(root);
   }
   static int min_depth_helper(const bt_node<t>*curr)
   {
       if(curr==NULL)
        return -1;
       return 1+min(min_depth_helper(curr->left),min_depth_helper(curr->right));
   }

   void check_bst()
   {
      cout<< check_bst_helper(root);
   }

   ///ALTHOUGH THIS SOLUTION IS INCORRECT
   ///BUT STILL WE COUNLD HAVE WRITTEN IN MORE PRESENTABLE MANNER
    /*
int isBST(struct node* node)
{
  if (node == NULL)
    return(true);

  if (node->left!=NULL && maxValue(node->left) > node->data)
    return(false);

  if (node->right!=NULL && minValue(node->right) < node->data)
    return(false);

  if (!isBST(node->left) || !isBST(node->right))
    return(false);

  return(true);
} */
   ///CORRECT AND BETTER SOLUTION WILL BE TO TRAVERSE INORDER
   /// AND MAINTAINING A PREVIOuS POINTER
   static bool check_bst_helper(const bt_node<t>*curr)
   {
       if(curr==NULL)
        return true;
       if(check_bst_helper(curr->left))
       {
           if(check_bst_helper(curr->right))
           {
               if(curr->left && curr->right)
               {
                   if(curr->data >= curr->left->data  && curr->data < curr->right->data)
                    return true;
               }
               else if(curr->left && ! curr->right)
               {
                   if(curr->data >=curr->left->data)
                    return true;
               }
               else if(!curr->left  &&  curr->right)
               {
                   if(curr->data < curr->right->data)
                    return true;
               }
               else if(! curr->left  &&  ! curr->right)
                      return true;
           }

       }
       return false;
   }


   void pre_order_it()
   {
       stack<bt_node<t>*> s;
       s.push(root);
       while(!s.empty())
       {
           bt_node<t>*temp=s.top();
           s.pop();
           cout<<temp->data<<" ";
           if(temp->right)
            s.push(temp->right);
           if(temp->left)
            s.push(temp->left);
       }
   }

   void inorder_it()
   {
       if(root==NULL)
        return;
       stack<bt_node<t>*> s;
       s.push(root);
       bt_node<t>*temp=s.top();
       left_push(s,root);
       while(!s.empty())
       {
           temp=s.top();
           cout<<temp->data<<" ";
           s.pop();
           if(temp->right)
            {
                s.push(temp->right);
                left_push(s,temp->right);
            }
       } return ;
   }

   void left_push(stack<bt_node<t>*> & s ,bt_node<t>*node)
   {
        while(node)
        {
            if(node->left)
                s.push(node->left);
            else break;
            node=node->left;
        }
        return ;
   }

   void inorder_iterative_method2()
   {
       stack<bt_node<t>*> s;
       bool bool_value=false;
       bt_node<t>*it=root;
       while(bool_value==false)
       {
           if(it)
           {
               s.push(it);
               it=it->left;
           }
           else{
              if(!s.empty())
              {
                  cout<<s.top()->data<<" ";
                  it=s.top()->right;
                  s.pop();
              }
              else bool_value=true;
           }
       }

   }

     /* void post_order_iterative()
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
            }*/
///SEE ONE STACK SOLUTION FROM GEEKS



 void print_at_distance_k(t  el,int k)
    {
        if(root==NULL)
            return ;
        bt_node<t>*node=address_of_node_helper(root,el);
        print_at_distance_k_helper(root,node,k);
        return ;
    }
    static int  print_at_distance_k_helper( bt_node<t>*curr,bt_node<t>*target,int k)
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
           else print_at_depth_k_helper(curr->left,k-rd-1);
           return rd;
       }
       return -1;
    }

    void print_at_depth_k(bt_node<t>*target,int k)
    {
        print_at_depth_k_helper(target,k);
    }
    static void print_at_depth_k_helper( bt_node<t>*curr,int k)
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

    void address_of_node(const t & el) const
   {
          address_of_node_helper(root,el);
   }
   static bt_node<t>*address_of_node_helper( bt_node<t>*curr,const t &el)
   {
       if(curr==NULL)
        return NULL;
       if(curr->data==el)
        return curr;
       if(curr->data < el)
        return address_of_node_helper(curr->right,el);
       else return address_of_node_helper(curr->left,el);
   }
};
int main()
{
    binary_tree<int> T;
    /*int a[]={4,5,2,6,7,3,1};
    int b[]={4,2,5,1,6,3,7};
     T.create_from_post_in(a,b,7);
     */
     T.create_tree();
     T.print_preorder();
     T.print_at_distance_k(10,4);
    /* T.pre_order_it();
     cout<<endl;
     T.inorder_iterative_method2();*/


     //T.check_bst();
   //  T.print_preorder();
     //T.node_with_sum(18);
     //T.print_nodes_with_no_sibling();
     //T.is_balanced();
     //T.print_diameter();
    /*T.create_tree();
    T.print_preorder();
    T.delete_half_nodes();
    T.print_preorder();*/
    return 0;
}
