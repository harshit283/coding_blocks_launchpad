#include<bits/stdc++.h>
using namespace std;
template<typename t>
class graph
{
    unordered_map<t,vector<pair<t,int> > >my_map;
public:
    graph(){}

    int get_vertices_count()
    {
        return my_map.size();
    }

    void add_egde_or_update(t src,t dest,int weight)
    {
        typename vector<pair<t,int> > ::iterator it=my_map[src].begin();
        while(it!=my_map[src].end())
        {
            if(it->first==dest)
                it->second=weight;
            it++;
        }
        pair<t,int>temp(dest,weight);
        my_map[src].push_back(temp);
        return;
    }

    void delete_edge(t src,t dest)
    {
        if(my_map.count(src))
        {
             typename vector<pair<t,int> > ::iterator it=my_map[src].begin();
             while(it!=my_map[src].end())
             {
                 if(it->first==dest)
                 {
                     my_map[src].erase(it);
                     if(my_map[src].empty())
                        my_map.erase(src);
                        return ;
                 }
                 it++;
             }
        }
        return ;
    }

    int get_weight(t src,t dest)
    {
         if(my_map.count(src))
        {
             typename vector<pair<t,int> > ::iterator it=my_map[src].begin();
             while(it!=my_map[src].end())
             {
                 if(it->first==dest)
                    return it->second;
                 it++;
             }
        }
        return -1;
    }

    void print_bfs()
    {
        unordered_set<t>visited;
        queue<t> Q;
        typename  unordered_map<t,vector<pair<t,int> > > ::iterator it=my_map.begin();
        while(it!=my_map.end())
        {
            if(visited.count(it->first))
            {
                it++;
                continue;
            }
            Q.push(it->first);
            visited.insert(it->first);
            while(!Q.empty())
            {
                t curr=Q.front();
                cout<<curr<<" ";
                Q.pop();
                if(my_map.count(curr)!=1)
                    continue;
                typename vector<pair<t,int> > ::iterator vit=my_map[curr].begin();
                while(vit!=my_map[curr].end())
                {
                    if(visited.count(vit->first)!=1)
                    {
                        visited.insert(vit->first);
                        Q.push(vit->first);
                    }
                    vit++;
                }
            }
            it++;
        }
        cout<<endl;
        return ;
    }

    void print_dfs()
    {
        unordered_set<t> visited;
        typename  unordered_map<t,vector<pair<t,int> > > ::iterator it=my_map.begin();
        while(it!=my_map.end())
        {
            if(!visited.count(it->first))
                print_dfs_util(visited,it->first);
            it++;
        }
        cout<<endl;
        return ;
    }

    void print_dfs_util(unordered_set<t> & visited , t curr)
    {
        visited.insert(curr);
        cout<<curr<<" ";
        if(my_map.count(curr)!=1)
               return ;
        typename vector<pair<t,int> > ::iterator it=my_map[curr].begin();
        while(it!=my_map[curr].end())
        {
            if(!visited.count(it->first))
                print_dfs_util(visited,it->first);
            it++;
        }
        return ;
    }

    void detect_cycle()
    {
        unordered_set<t> visited;
        typename  unordered_map<t,vector<pair<t,int> > > ::iterator it=my_map.begin();
        while(it!=my_map.end())
        {
            if(!visited.count(it->first))
            {
                if(detect_cycle_util(visited,it->first,-1))
                {
                    cout<<"yes";
                    return ;
                }
            }
            it++;
        }
        cout<<"no"<<endl;
        return ;
    }

    bool detect_cycle_util(unordered_set<t> & visited , t curr , t parent)
    {
        visited.insert(curr);
        if(my_map.count(curr)!=1)
               return false;
        typename vector<pair<t,int> > ::iterator it=my_map[curr].begin();
        while(it!=my_map[curr].end())
        {
            if(it->first!=parent && visited.count(it->first))
                  return true;
            if(visited.count(it->first)!=1)
            {
                if(detect_cycle_util(visited,it->first,curr))
                    return true;
            }
            it++;
        }
        return false;
    }

     void shortest_path(t src,t dest)
    {
        vector<t>path;
        path.push_back(dest);
        unordered_map<t,t>visited;
        queue<t> Q;
        visited[src]=-1;
        Q.push(src);

            while(!Q.empty())
            {
                t curr=Q.front();
                Q.pop();
                if(my_map.count(curr)!=1)
                    continue;
                typename vector<pair<t,int> > ::iterator vit=my_map[curr].begin();
                while(vit!=my_map[curr].end())
                {
                    if(visited.count(vit->first)!=1)
                    {
                        visited[vit->first]=curr;
                        Q.push(vit->first);
                        if(vit->first==dest)
                        {
                            t key=dest;
                            while(visited[key]!=-1)
                            {
                                path.push_back(visited[key]);
                                key=visited[key];
                            }
                            cout<<"shortest path is : "<<endl;
                            for(int i=path.size()-1;i>=0;i--)
                                cout<<path[i]<<" ";
                                return ;
                        }
                    }
                    vit++;
                }
            }
        cout<<"INVALID DESTINATION";
        return ;
    }

     void topological_sort()
    {
        unordered_set<t> visited;
        stack<t>S;
        typename  unordered_map<t,vector<pair<t,int> > > ::iterator it=my_map.begin();
         it=my_map.begin();
          if(my_map.count(it->first))
                cout<<it->first<<" ";
                cout<<endl<<endl;
        while(it!=my_map.end())
        {
            if(!visited.count(it->first))
                topological_sort_util(visited,it->first,S);

            it++;
        }
      /*  while(!S.empty())
        {
            cout<<S.top()<<" ";
            S.pop();
        }*/
        it=my_map.begin();
          if(my_map.count(it->first))
                cout<<it->first<<" ";
        cout<<endl;
        return ;
    }

    void topological_sort_util(unordered_set<t> & visited , t curr, stack<t> & s)
    {
        //cout<<curr<<" ";
        visited.insert(curr);
        if(my_map.count(curr)!=1)
        {
            //cout<<curr<<" ";
            s.push(curr);
            return ;
        }
        typename vector<pair<t,int> > ::iterator it=my_map[curr].begin();
        while(it!=my_map[curr].end())
        {
            if(!visited.count(it->first))
                print_dfs_util(visited,it->first);
            it++;
        }
        s.push(curr);
        return ;
    }
};
int main()
{
    graph<int> G;
    G.add_egde_or_update(1,2,10);
    G.add_egde_or_update(1,3,10);
    G.add_egde_or_update(2,4,10);
    //G.add_egde_or_update(4,3,10);
    G.add_egde_or_update(4,5,10);
   // G.add_egde_or_update(5,3,10);
    //G.add_egde_or_update(2,1,10);
    //G.add_egde_or_update(3,1,10);
    //G.add_egde_or_update(4,2,10);
    G.add_egde_or_update(3,4,10);
    G.add_egde_or_update(3,5,10);
   // G.add_egde_or_update(5,4,10);
    /*G.delete_edge(1,3);
    G.delete_edge(3,1);*/
    G.add_egde_or_update(5,6,10);
   // G.add_egde_or_update(6,5,10);
    G.add_egde_or_update(1,6,10);
   // G.add_egde_or_update(6,1,10);
   // G.add_egde_or_update(7,6,10);
    G.add_egde_or_update(6,7,10);
   // G.add_egde_or_update(7,4,10);
    G.add_egde_or_update(4,7,10);
   /* G.print_bfs();
    G.print_dfs();*/
    //G.detect_cycle();
   // G.shortest_path(3,7);
    cout<<endl;
    G.topological_sort();

    return 0;
}
