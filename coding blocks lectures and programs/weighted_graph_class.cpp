#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<string>
using namespace std;
template<typename t>
class weighted_graph
{
    unordered_map<t,vector<pair<t,int> > > map;
    public:
    weighted_graph(){}
    int vertices_count()
    {
        return map.size();
    }

    void add_edges(t src,t dest,int wt)
    {
        typename vector<pair<t,int> >:: iterator it=map[src].begin();
        while(it!=map[src].end())
        {
            if(it->first==dest)
            {
                return ;
            }
            it++;
        }
        pair<t,int>temp(dest,wt);
        map[src].push_back(temp);
        return ;
    }

    void delete_edge(t src,t dest)
    {
        if(map.count(src)!=1)
        {
            cout<<"no such vertex exists";
            return ;
        }
        typename vector<pair<t,int> >::iterator it=map[src].begin();
        while(it!=map[src].end())
        {
            if(it->first==dest)
            {
                map[src].erase(it);
                return;
            }
            it++;
        }
        cout<<"no edge exists between given src and dest";
        return ;
    }

    void change_weight(t src,t dest,int new_wt)
    {
        if(map.count(src)!=1)
        {
            cout<<"no such vertex exists";
            return ;
        }
       typename vector<pair<t,int> >::iterator it=map[src].begin();
        while(it!=map[src].end())
        {
            if(it->first==dest)
            {
                it->second=new_wt;
                return;
            }
            it++;
        }
         cout<<"no edge exists between given src and dest";
        return ;
    }

    int get_weight(t src,t dest)
    {
        if(map.count(src)!=1)
        {
            cout<<"no such vertex exists";
            return ;
        }

        typename vector<pair<t,int> >::iterator it=map[src].begin();
        while(it!=map[src].end())
        {
            if(it->first==dest)
            {
                return it->second;
            }
            it++;
        }
        cout<<"no edge exists between given src and dest";
    }



    void print_bfs()
    {
        unordered_set<t>set;
        typename unordered_map<t,vector<pair<t,int> > > ::iterator it=map.begin();

        for(;it!=map.end();it++)
        {
            if(set.count(it->first))
            {
                continue;
            }
            set.insert(it->first);
            queue<t>Q;
            Q.push(it->first);
            while(!Q.empty())
            {
                t curr=Q.front();
                Q.pop();
                cout<<curr<<" ";
                if(map.count(curr)!=1)
                {
                    continue;
                }
              typename vector<pair<t,int> >::iterator vit=map[curr].begin();
                while(vit!=map[curr].end())
                {
                    if(set.count(vit->first)!=1)
                    {
                        Q.push(vit->first);
                        set.insert(vit->first);
                    }
                    vit++;
                }
            }
        }
        cout<<endl;
        return ;
    }

    void print_dfs()
    {
        auto it=map.begin();
        unordered_set<t>set;
        while(it!=map.end())
        {
            if(set.count(it->first)!=1)
            {
                dfs_util(set,it->first);
            }
            it++;
        }
        cout<<endl;
        return ;
    }

    void print_map()
    {
      /* Notice that an unordered_map object makes no guarantees on which specific element is considered its first element.
       But, in any case, the range that goes from its begin to its end covers all the elements in the container (or the bucket), until invalidated.*/
        auto it=map.begin();
        while(it!=map.end())
        {
            cout<<map.bucket(it->first)<<" "<<map.bucket_size(map.bucket(it->first))<<" "<<it->first<<endl;
            it++;
        }
        cout<<endl;
        cout<<"map size is:"<<map.size();
        return ;
    }

    void dfs_util(unordered_set<t>&set ,t curr)
    {
        set.insert(curr);
        cout<<curr<<" ";
        if(map.count(curr)!=1)
        {
            return ;
        }
        auto it=map[curr].begin();
        while(it!=map[curr].end())
        {
            if(set.count(it->first)!=1)
            {
                dfs_util(set,it->first);
            }
            it++;
        }
        return ;
    }
};
int main()
{
    /*weighted_graph<int>G;
    G.add_edges(51,2,10);
    G.add_edges(45,77,20);
    G.add_edges(78,4,30);
    G.add_edges(4,6,40);
    G.add_edges(3,5,50);
    G.add_edges(2,1,60);
    G.add_edges(1,8,70);
    G.add_edges(9,1,10);
    G.add_edges(9,2,100);
    G.add_edges(9,51,110);
    G.print_bfs();
    G.print_dfs();
    G.print_bfs();

   // G.print_map();
   */

    return 0;

}

