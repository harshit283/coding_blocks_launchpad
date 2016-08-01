#include<bits/stdc++.h>
using namespace std;
template<typename t>
class generic_tree;
template<typename type>
class gt_node
{
    type data;
    vector<gt_node*> children;
public:

    gt_node(const type & el):data(el){}

    template<typename t>
    friend class generic_tree;
};
template<typename t>
class generic_tree
{
    gt_node<t>*root;
public:
    generic_tree():root(NULL){}

    generic_tree(const generic_tree & T):root(NULL)
    {
        if(T.root==NULL)
            return;
        root=helper(T.root);
        return ;
    }

    static gt_node<t>*helper(const gt_node<t>*curr)
    {
        gt_node<t>*temp=new gt_node<t>(curr->data);
        for(int i=0;i<curr->children.size();i++)
            helper(curr->children[i]);
        return temp;
    }

    generic_tree & operator = (const generic_tree & T)
    {
        clear();
        if(T.root==NULL)
            return *this;
        root=helper(T.root);
        return *this;
    }

    ~ generic_tree()
    {
         clear();
    }

    void clear()
    {
        if(root==NULL)
            return ;
        clear_helper(root);
        root=NULL;
        return ;
    }
    void clear_helper(gt_node<t>*curr)
    {
        for(int i=0;i<curr->children.size();i++)
            clear_helper(curr->children[i]);
        delete curr;
        return ;
    }

    void create_tree_dfs()
    {
        if(root!=NULL)
            throw" TREE ALREADY EXISTS";
       root=create_tree_dfs_helper();
       return ;
    }

   static gt_node<t>*create_tree_dfs_helper()
    {
        cout<<"enter the data for the node:-";
        int el;
        cin>>el;
        gt_node<t>*temp=new gt_node<t>(el);
        cout<<"enter the number of children:-";
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            temp->children.push_back(create_tree_dfs_helper());
        return temp;
    }



    void create_tree_bfs()
    {
        if(root!=NULL)
            throw"TREE ALREADY EXISTS";
        cout<<"enter the data for the root node:-";
        int el;
        cin>>el;
        gt_node<t>*temp=new gt_node<t>(el);
        queue<gt_node<t>*> Q;
        Q.push(temp);
        while(!Q.empty())
        {
            gt_node<t>*curr=Q.front();
            Q.pop();
            cout<<"enter the number of children for node with data "<<curr->data<<":-";
            int n;
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cout<<"enter data for child number "<<i+1<<":-";
                int val;
                cin>>val;
                gt_node<t>* node= new gt_node<t>(val);
                curr->children.push_back(node);
                Q.push(node);
            }
        }
        root=temp;
        return;
    }
    void print_preorder() const
    {
        if(root==NULL)
            return ;
        print_preorder_helper(root);
        cout<<endl;
        return ;
    }
    static void print_preorder_helper(const gt_node<t>*curr)
    {
        cout<<curr->data<<" ";
        for(int i=0;i<curr->children.size();i++)
            print_preorder_helper(curr->children[i]);
        return ;
    }

    void print_postorder()const
    {
        if(root==NULL)
            return ;
        print_postorder_helper(root);
        cout<<endl;
        return ;
    }
    static void print_postorder_helper(const gt_node<t>*curr)
    {
        for(int i=0;i<curr->children.size();i++)
            print_postorder_helper(curr->children[i]);
        cout<<curr->data<<" ";
        return ;
    }

    void print_largest() const
    {
        if(root==NULL)
            throw" TREE IS EMPTY";
        const gt_node<t>*temp=print_largest_helper(root);
        cout<<temp->data<<endl;
    }

    static const gt_node<t>*print_largest_helper(const gt_node<t>*curr)
    {
        const gt_node<t>*node=curr;
        for(int i=0;i<curr->children.size();i++)
        {
            const gt_node<t>*temp=print_largest_helper(curr->children[i]);
            if(node->data < temp->data)
                node=temp;
        }
        return node;
    }

    void print_el_depth_k(int k) const
    {
        if(root==NULL)
            return ;
        if(k<0)
            return ;
        print_el_depth_k_helper(root,k);
    }

    static void print_el_depth_k_helper(const gt_node<t>*curr,int k)
    {
        if(k==0)
        {
             cout<<curr->data<<" ";
             return ;
        }
        for(int i=0;i<curr->children.size();i++)
             print_el_depth_k_helper(curr->children[i],k-1);
        return ;
    }

    void print_root_to_el( t  el) const
    {
        if(root==NULL)
            return ;
        if(!print_root_to_el_helper(root,el))
            cout<<" element not present";
            else cout<<root->data<<" ";
        return ;
    }

    static bool print_root_to_el_helper(const gt_node<t>*curr,t el)
    {
        if(curr->data==el)
             return true;
        for(int i=0;i<curr->children.size();i++)
        {
            if(print_root_to_el_helper(curr->children[i],el))
            {
                cout<<curr->children[i]->data<<" ";
                return true;
            }
        }
        return false;
    }

    void print_root_to_leaf()
    {
        if(root==NULL)
            return ;
            vector<gt_node<t>*> v;
            v.push_back(root);
        print_root_to_leaf_helper(root,v);
    }

    /*static void print_root_to_leaf_helper(const gt_node<t>*curr,vector<gt_node<t>*> & v)
    {
        int i;
        for( i=0;i<curr->children.size();i++)
        {
            v.push_back(curr->children[i]);
            print_root_to_leaf_helper(curr->children[i],v);
        }
        if(i==curr->children.size() && i!=0)
        {
            v.pop_back();
            return ;
        }
        for(int i=0;i<v.size();i++)
            cout<<v[i]->data<<" ";
            cout<<endl;
        v.pop_back();
        return ;
    }
    */
    static void print_root_to_leaf_helper(const gt_node<t>*curr,vector<gt_node<t>*> & v)
    {
        if(curr->children.size()==0)
        {
            for(int i=0;i<v.size();i++)
                cout<<v[i]->data<<" ";
                cout<<endl;
                v.pop_back();
                return ;
        }
        for(int i=0;i<curr->children.size();i++)
        {
            v.push_back(curr->children[i]);
            print_root_to_leaf_helper(curr->children[i],v);
        }
        v.pop_back();
        return ;
    }

    void print_height() const
    {
        if(root==NULL)
             return ;
        cout<<"HEIGHT IS:"<<print_height_helper(root);
    }
    static int print_height_helper(const gt_node<t>*curr)
    {
           if(curr->children.size()==0)
               return 0;
           int max_height=INT_MIN;
           for(int i=0;i<curr->children.size();i++)
           {
               int val=1+print_height_helper(curr->children[i]);
               if(val > max_height)
                max_height=val;
           }
           return max_height;
    }

    void print_leaf_count()
    {
        if(root==NULL)
            return ;
        cout<<"COUNT OF LEAVES IS"<<print_leaf_count_helper(root)<<endl;
    }
    static int print_leaf_count_helper(const gt_node<t>*curr)
    {
        if(curr->children.size()==0)
            return 1;
            int count=0;
        for(int i=0;i<curr->children.size();i++)
            count=count+print_leaf_count_helper(curr->children[i]);
        return count;
    }

    void print_count_greater() const
    {
        if(root==NULL)
            return ;
        cout<<"COUNT IS "<<print_count_greater_helper(root,root->data)<<endl;
    }

    static int print_count_greater_helper(const gt_node<t>*curr,t value)
    {
        if(curr->children.size()==0)
        {
            if(curr->data > value)
                return 1;
            else return 0;
        }

        int count=0;
        if(curr->data > value)
            count++;
        for(int i=0;i<curr->children.size();i++)
            count=count+print_count_greater_helper(curr->children[i],value);
        return count;
    }

    bool operator == (const generic_tree & T) const
    {
        if(check(root,T.root))
            return true;
        else return false;
    }

    static bool check(const gt_node<t>*curr,const gt_node<t>*add)
    {
        if(curr->data !=add->data)
            return false;
        if(curr->children.size()!=add->children.size())
            return false;
        for(int i=0;i<curr->children.size();i++)
        {
            if(!check(curr->children[i],add->children[i]))
                    return false;
        }
        return true;
    }

   void special_node() const
   {
       if(root==NULL)
           return ;
     const gt_node<t>*temp;
     int  sum = INT_MIN;
     special_node_helper(root,temp,sum);
       cout<<"NODE IS "<< temp->data<<endl;
   }
   static  void special_node_helper(const gt_node<t>*curr,const gt_node<t> * & temp ,int sum)
   {
       int temp_sum=curr->data;
       for(int i=0;i<curr->children.size();i++)
        temp_sum+=curr->children[i]->data;
       if(temp_sum > sum)
       {
           sum=temp_sum;
           temp=curr;
       }
          for(int i=0;i<curr->children.size();i++)
            special_node_helper(curr->children[i],temp,sum);
          return ;
   }

   void just_greater_than_k(int k) const
   {
       if(root==NULL)
        return ;
       const gt_node<t>*node=just_greater_than_k_helper(root,k);
       if(node==NULL)
        return ;
       else cout<<node->data<<endl;
       return ;
   }
   static const gt_node<t>*just_greater_than_k_helper(const gt_node<t>*curr,int k)
   {
       if(curr->children.size()==0)
       {
           if(curr->data > k)
            return curr;
            else return NULL;
       }
       const gt_node<t>*temp=NULL;
       for(int i=0;i<curr->children.size();i++)
       {
           const gt_node<t>*node=just_greater_than_k_helper(curr->children[i],k);
           if(node!=NULL)
           {
               if(temp==NULL)
                temp=node;
               else if(temp->data > node->data)
                temp=node;
           }
       }
        if(curr->data <= k)
            return temp;
        if(temp==NULL)
            return curr;
        else if(temp->data < curr->data)
            return temp;
        else if(temp->data > curr->data)
            return curr;
       return temp;
   }

   void path_with_sum(int sum) const
   {
       if(root==NULL)
        return ;
     if(path_with_sum_helper(root,sum))
            cout<<"yes";
        else cout<<"no";
   }

   static bool path_with_sum_helper(const gt_node<t>*curr,int sum)
   {
       if(curr->children.size()==0)
       {
           if(sum-curr->data==0)
                return true;
            else return false;
       }
       for(int i=0;i<curr->children.size();i++)
       {
           if(path_with_sum_helper(curr->children[i],sum-curr->children[i]->data))
            return true;
       }
       return false;
   }
   void post_order_iterative() const
   {
       if(root==NULL)
        return ;
       stack<gt_node<t>*> s1,s2;
       s1.push(root);
       for(int i=0;i<root->children.size();i++)
           s2.push(root->children[i]);
       while(!s2.empty())
       {
           gt_node<t>*node=s2.top();
           s2.pop();
           s1.push(node);
           for(int i=0;i<node->children.size();i++)
               s2.push(node->children[i]);
           node=s2.top();
           s2.pop();
           s1.push(node);
           for(int i=0;i<node->children.size();i++)
            s2.push(node->children[i]);
       }

       while(!s1.empty())
       {
           cout<<s1.top()->data<<" ";
           s1.pop();
       }
       cout<<endl;
       return ;
   }

   void get_second_largest()const
   {
       if(root==NULL)
        return ;
       pair<gt_node<t>*,gt_node<t>*> temp=get_second_largest_helper(root);
       if(temp.second==NULL)
        cout<<"only one element present"<<endl;
       else cout<<temp.second->data<<endl;
       return ;

   }

   static pair<gt_node<t>*,gt_node<t>*> get_second_largest_helper( gt_node<t>* curr)
   {
       pair<gt_node<t>*,gt_node<t>*> temp(curr,NULL);
       for(int i=0;i<curr->children.size();i++)
       {
           pair<gt_node<t>*,gt_node<t>*> my_pair=get_second_largest_helper(curr->children[i]);
           if(my_pair.first->data > temp.first->data)
           {
               if(my_pair.second!=NULL && temp.second !=NULL)
               {
                   if(my_pair.second->data > temp.first->data)
                       temp.second=my_pair.second;
                   else temp.second=temp.first;
               }
                else temp.second=temp.first;
               temp.first=my_pair.first;
           }
           else
           {
                 if(my_pair.second==NULL && temp.second==NULL || my_pair.second !=NULL && temp.second==NULL)
                        temp.second=my_pair.first;
                 else{
                        if(temp.second->data < my_pair.first->data)
                        temp.second=my_pair.first;
                     }
           }
       }
       return temp;
   }
};
int main()
{
     class generic_tree<int> T;
     //T.create_tree_dfs();
     T.create_tree_bfs();
     T.print_postorder();
     T.get_second_largest();
    // T.post_order_iterative();
     //T.print_largest();
    // T.print_preorder();
     //T.path_with_sum(11);
     //T.just_greater_than_k(51);
     //T.special_node();
    // T.print_count_greater();
     //T.print_leaf_count();
     //T.print_height();
    // T.print_root_to_leaf();
     //T.print_root_to_el(14);
    // T.print_el_depth_k(2);
    return 0;
}
