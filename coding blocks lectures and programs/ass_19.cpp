/*#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
int main ()
{
   /// QUESTION-2 CHECK WHETHER GIVEN ARRAY IS THE SUBSET OF OTHER ARRAY
    cout<<"enter the size of the arrays"<<endl;
    int m,n;
    cin>>m>>n;
    cout<<"enter the first array"<<endl;
    int a[m+1];
    int b[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }

    cout<<endl;
    cout<<"enter the second array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }

    unordered_set<int> set;
    for(int i=0;i<m;i++)
    {
       set.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        int temp=set.count(b[i]);
        if(temp==0)
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
*/

    ///QUESTION -4
    /*
     cout<<"enter the total numbers"<<endl;
    int n;
    cin>>n;
    int a[n+1];
    cout<<"enter the numbers"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the sum";
    int sum;
    cin>>sum;
    unordered_map< int,vector<int> > map;
    for(int i=0;i<n;i++)
    {
        int temp=map.count(sum-a[i]);
        if(temp==0)
        {
            map[a[i]].push_back(a[i]);
            continue;
        }
        cout<<a[i]<<" "<<sum-a[i]<<endl;
        if(map[sum-a[i]].empty())
        {
            map.erase(sum-a[i]);
            continue;
        }
        map[sum-a[i]].pop_back();
        if(map[sum-a[i]].empty())
        {
            map.erase(sum-a[i]);
        }
    }
*/

    ///QUESTION-8
/*
    int a[100];
    int k,n;
    unordered_set<int>set;
    cout<<"enter the number of elements:"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the range";
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        int ptr=set.count(a[i]);
        if(ptr==1)
        {
            cout<<"yes";
            return 0;
        }
        set.insert(a[i]);
    }
    int temp=set.count(a[0]);
    if(temp==1){
        cout<<"yes";
        return 0;
    }

    int i=0;
    while(i<=n-2)
    {
        if(i+k+1>=n)
        {
            set.erase(a[i+1]);
            int val1=set.count(a[i+1]);
            if(val1==1)
            {
                cout<<"yes";
                return 0;
            }
            else
            {
                i++;
                continue;
            }
        }
        set.erase(a[i+1]);
        int ptr=set.count(a[k+i+1]);
        if(ptr==1)
        {
            cout<<"yes";
            return 0 ;
        }
        set.insert(a[i+k+1]);
        int val=set.count(a[i+1]);
        if(val==1)
        {
            cout<<"yes";
            return 0;
        }
        else{
            i++;
        }
    }
    cout<<"no";
    */


   ///QUESTION 5
   /* cout<<"enter the total numbers";
    int n;
    cin>>n;
    int a[n+1];
    cout<<"enter the numbers"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    unordered_set<int> set;
    for(int i=0;i<n;i++)
    {
        set.insert(a[i]);
    }
    int count1=0;
    int count2=0;
    int temp1=1,temp2=1;
    int j=1;
    int k=1;
    int val1=0,val2=0,f_val1,f_val2,size=-1;
    for(int i=0;i<n;i++)
    {
        int temp=set.count(a[i]);
        if(temp==1)
        {
            while(temp1)
            {
                temp1=set.count(a[i]-j);
                if(temp1==1)
                {
                    count1++;
                    val1=a[i]-j;
                    set.erase(a[i]-j);
                    j++;
                }
                else{
                    j=1;
                    val1=a[i]-count1;
                    count1=0;temp1=1;
                    break;
                }
            }
            while(temp2)
            {
                temp2=set.count(a[i]+k);
                if(temp2==1)
                {
                    count2++;
                    val2=a[i]+k;
                    set.erase(a[i]+k);
                    k++;
                }
                else{
                    k=1;
                    val2=a[i]+count2;
                    count2=0;temp2=1;
                    break;
                }
            }

        if(val2-val1+1 > size)
        {
            size=val2-val1+1;
            f_val1=val1;
            f_val2=val2;
        }
        }
    }

    cout<<"required output is:"<<endl;
    int i=f_val1;
    while(i<=f_val2)
    {
        cout<<i<<" ";
        i++;
    }
    */


    ///QUESTION-7 PRINT VERTICAL ORDER
    /*
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
template<typename t>
class node
{
    t data;
    int hd;
    node*left;
    node*right;
public:
    node(const t & el,const int & dis):data(el),hd(dis)
    {
        left=NULL;
        right=NULL;
    }

    template<typename u>
    friend class BTREE;
};
template<typename t>
class BTREE
{
    node<t>*root;
    node<t>*min;
    node<t>*max;
public:
    BTREE():root(NULL),min(NULL){}
    void create_btree_bfs()
    {
        cout<<"enter the data for the node";
        t val;
        cin>>val;
        root=new node<t>(val,0);
        queue<node<t>*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            node<t>*temp=Q.front();
            Q.pop();
            cout<<"does "<<temp->data<<" has a left child(y/n):";
            char ch;
            cin>>ch;
            if(ch=='y' || ch=='Y')
            {
                cout<<"enter the data for the node:";
                t dt;
                cin>>dt;
                temp->left=new node<t>(dt,temp->hd-1);
                if(min==NULL)
                {
                    min=temp->left;
                }
                else if(min->hd > temp->hd-1)
                {
                    min=temp->left;
                }

                Q.push(temp->left);
            }
            cout<<"does "<<temp->data<<" has a right child(y/n):";
            char ph;
            cin>>ph;
            if(ph=='Y' || ph=='y')
            {
                cout<<"enter the data for the node:";
                t dt;
                cin>>dt;
                temp->right=new node<t>(dt,temp->hd+1);
                if(max==NULL)
                {
                    max=temp->right;
                }
                else if(max->hd < temp->hd+1)
                {
                    max=temp->right;
                }
                Q.push(temp->right);
            }
        }
    }

public:
    void print_vertical_order()
    {
        if(root==NULL)
        {
            throw"TREE IS EMPTY";
        }
        unordered_map<int,vector<t> > map;
        level_order_traversal(root,map);
        int val=min->hd;
        cout<<"vertical order is:"<<endl;
        while(val<=max->hd)
        {
            for(int i=0;i<map[val].size();i++)
            {
                cout<<map[val][i]<<" ";
            }
            cout<<endl;
            val++;
        }
        return ;
    }

private:
    void level_order_traversal( node<t>*curr,unordered_map<int,vector<t> >&map)
    {
        if(curr==NULL)
        {
            return ;
        }
        map[curr->hd].push_back(curr->data);
        queue<node<t>*> Q;
        Q.push(curr);
        while(!Q.empty())
        {
            node<t>*temp=Q.front();
            Q.pop();
            if(temp->left!=NULL)
            {
                map[temp->left->hd].push_back(temp->left->data);
                Q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                map[temp->right->hd].push_back(temp->right->data);
                Q.push(temp->right);
            }
        }
        return ;
    }

};
int main ()
{
    BTREE<int> T;
    T.create_btree_bfs();
    T.print_vertical_order();
    return 0;
}
*/

///QUESTION 6

/*
#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<algorithm>
using namespace std;
int get_mode(unordered_map<int,vector<int> >& map)
{
   pair<int,int>my_pair;
   my_pair.first=0;my_pair.second=0;
   auto it=map.begin();
   while(it!=map.end())
   {
       if( it->second.size() > my_pair.second)   ///take care about comparison of signed and unsigned variables
       {
           my_pair.second=it->second.size();
           my_pair.first=it->first;
       }
       else if(it->second.size()==my_pair.second)
       {
           if(it->first <my_pair.first)
           {
               my_pair.first=it->first;
           }
       }
       it++;
   }
   return my_pair.first;
}

int main ()
{
    int n;
    cout<<"enter the number of element:"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    int a[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the number of queries"<<endl;
    int q;
    cin>>q;
    vector<pair<int,int> > v;
    for(int k=0;k<q;k++)
    {
        cout<<"enter the i and j for the query Aij"<<endl;
        int i,j;
        cin>>i>>j;
        pair<int,int>temp(i,j);
        v.push_back(temp);
    }
    unordered_map<int,vector<int> > map;
    for(int i=1;i<=n;i++)
    {
        map[a[i]].push_back(a[i]);
    }
    cout<<"modes after each query are:"<<endl;
    int count=0;
    while(count<q)
    {
        pair<int,int>temp=v[count];
        map[a[temp.first]].pop_back();
        if(map[a[temp.first]].empty())
        {
            map.erase(a[temp.first]);
        }
        map[temp.second].push_back(temp.second);
        cout<<get_mode(map)<<endl;
        count++;
    }
    return 0;
}

*/
///QUESTION 3
/// CHECK THAT THE SOLUTION IS INCORRECT
///S1=XYZABBCABBCABBX
///S2=ABBCABBX
/*
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
#include<limits.h>
using namespace std;
int main ()
{
    cout<<"enter the first string:"<<endl;
    string s1,s2;
    cin>>s1;
    cout<<"enter the second string:"<<endl;
    cin>>s2;
    int a[256]={0};
    for(int i=0;i<s2.size();i++)
    {
        a[s2[i]]++;
    }
    unordered_set<char> set;
    for(int i=0;i<s2.size();i++)
    {
        set.insert(s2[i]);
    }
    int j;
    int start=0;
    int end;
    int min_len=INT_MAX;
    for(int i=0;i<s1.size();i++)
    {
        int temp=set.count(s1[i]);
        if(temp==1)
        {
            if(a[s1[i]]>0)
            {
                a[s1[i]]--;
            for( j=0;j<256;j++)
            {
                if(a[j]!=0)
                {
                      break;
                }
            }
            }
            if(j==256)
            {
                end=i;
                int k=0;
                while(k<s1.size())
                {
                     int val=set.count(s1[start]);
                     if(val==1)
                     {
                         min_len=end-start+1;
                         start=end+1;
                         for(int i=0;i<s2.size();i++)
                         {
                             a[s2[i]]++;
                         }
                         break;
                     }
                     start++;
                     k++;
                }

            }
        }

    }

    cout<<"minimum length is:"<<endl<<min_len;
    return 0;
}

   // return 0;

//}
*/
