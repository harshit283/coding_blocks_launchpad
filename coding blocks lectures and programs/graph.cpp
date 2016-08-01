#include<bits/stdc++.h>
using namespace std;
class Graph
{
    vector<list<int> >adjlist;
public:
    Graph(){}
    int vertices_count()
    {
        return adjlist.size();
    }
    void add_edges(int src,int dest)
    {
        int max=src>dest?src:dest;
        if(max +1 > vertices_count())
        {
            adjlist.resize(max+1);
        }
        list<int>::iterator it=find(adjlist[src].begin(), adjlist[src].end(),dest);
            if(it!=adjlist[src].end())
            {
                throw"you are inserting again";
            }
            adjlist[src].push_back(dest);
            //adjlist[dest].push_back(src);

    }
    void add_edges_directed(int src,int dest)
    {
        int max=src>dest?src:dest;
        if(max +1 > vertices_count())
        {
            adjlist.resize(max+1);
        }
        list<int>::iterator it=find(adjlist[src].begin(),adjlist[src].end(),dest);
            if(it!=adjlist[src].end())
            {
                return;
            }
            adjlist[src].push_back(dest);
            return ;
    }

    void print_bfs()
    {
        vector<bool>  visited (vertices_count(),false);//parametrised constructor
        for(int i=1;i<visited.size();i++)
        {
            if(visited[i]==true)
            {
                continue;
            }
            queue<int>Q;
            Q.push(i);
            visited[i]=true;
            while(!Q.empty())
            {
                int curr=Q.front();
                Q.pop();
                cout<<curr<<" ";
                list <int> ::iterator it=adjlist[curr].begin();
                while(it!=adjlist[curr].end())
                {
                    if(visited[*it]==false)
                    {
                        Q.push(*it);
                        visited[*it]=true;
                    }
                    it++;
                }
            }
        }
        cout<<endl;
        return ;
    }

    void print_dfs()
    {
        vector<bool>visited(vertices_count(),false);
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==false)
            {
                print_dfs_helper(visited,i);
            }
        }
        cout<<endl;
        return ;
    }
    void print_dfs_helper(vector<bool> & visited,int src)
    {
        visited[src]=true;
        cout<<src<<" ";
        list<int>::iterator it=adjlist[src].begin();
        while(it!=adjlist[src].end())
        {
            if(visited[*it]==false)
            {
                print_dfs_helper(visited,*it);
            }
            it++;
        }
        return ;
    }

    void connected_components()
    {
        if(adjlist.size()==0)
        {
            throw"graph is empty";
        }
        vector<int>v;
        vector<bool>visited(vertices_count(),false);
        for(int i=0;i<visited.size();i++)
        {

            if(visited[i]==true)
            {
                continue;
            }
             v.push_back(100000);
            queue<int> Q;
            Q.push(i);
            visited[i]=true;
            while(!Q.empty())
            {
                int curr=Q.front();
                v.push_back(curr);
                Q.pop();
                list<int>::iterator it=adjlist[curr].begin();
                while(it!=adjlist[curr].end())
                {
                    if(visited[*it]==false)
                    {
                        Q.push(*it);
                        visited[*it]=true;
                    }
                    it++;
                }
            }
        }
        cout<<"connected components are:"<<endl;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==100000)
            {
                cout<<endl;
                continue;
            }
            cout<<v[i]<<" ";
        }
        return ;

    }

    void detect_cyclic()
    {
        if(adjlist.size()==0)
        {
            throw"graph is empty";
        }
        vector<bool>visited(vertices_count(),false);
        for(int i=0;i<adjlist.size();i++)
        {
            if(visited[i]==false)
            {
                if(detect_cyclic_helper(visited,i,-1))
                {
                    cout<<"cyclic";
                    return ;
                }
            }
        }
        cout<<"not cyclic";
        return ;
    }

private:
     bool detect_cyclic_helper(vector<bool>&visited,int src,int parent)
    {
        visited[src]=true;
         list<int>::iterator it=adjlist[src].begin();
         while(it!=adjlist[src].end())
         {
             if(visited[*it]==false)
             {
                 if(detect_cyclic_helper(visited,*it,src))
                 {
                     return true;
                 }
             }
             else if(*it!=parent)
             {
                 return true;
             }
             it++;
         }
         return false;
    }
public:
    void find_shortest_path_bfs(int src,int dest)
    {
        if(adjlist.size()==0)
        {
             throw"GRAPH IS EMPTY";
        }
        vector<int>visited(vertices_count(),-1);
        queue<int> Q;
        Q.push(src);
        visited[src]=-100;
        while(!Q.empty())
        {
            int curr=Q.front();
            Q.pop();
            list<int>::iterator it=adjlist[curr].begin();
            while(it!=adjlist[curr].end())
            {
                if(visited[*it]!=-1)
                {
                    it++;
                    continue;
                }
                Q.push(*it);
                visited[*it]=curr;
                if(*it==dest)
                {
                    break;
                }
                it++;
            }
            if(*it==dest)
            {
                break;
            }
        }
        if(Q.empty())
        {
            cout<<"no possible path";
            return ;
        }
        stack<int>path;
        path.push(dest);
        int ptr=dest;
        while(ptr!=src)
        {
            path.push(visited[ptr]);
            ptr=visited[ptr];
        }
        cout<<"shortest path is:"<<endl;
        while(!path.empty())
        {
            cout<<path.top()<<" ";
            path.pop();
        }
        return ;
    }

    public:
    int return_shortest_path_bfs(int src,int dest)
    {
        if(adjlist.size()==0)
        {
             throw"GRAPH IS EMPTY";
        }
        vector<int>visited(vertices_count(),-1);
        queue<int> Q;
        Q.push(src);
        visited[src]=-100;
        while(!Q.empty())
        {
            int curr=Q.front();
            Q.pop();
            list<int>::iterator it=adjlist[curr].begin();
            while(it!=adjlist[curr].end())
            {
                if(visited[*it]!=-1)
                {
                    it++;
                    continue;
                }
                Q.push(*it);
                visited[*it]=curr;
                if(*it==dest)
                {
                    break;
                }
                it++;
            }
            if(*it==dest)
            {
                break;
            }
        }
        if(Q.empty())
        {
            return -1;
        }
        stack<int>path;
        path.push(dest);
        int ptr=dest;
        while(ptr!=src)
        {
            path.push(visited[ptr]);
            ptr=visited[ptr];
        }
        return path.size();
    }

    void is_connected()
    {
        if(adjlist.size()==0)
        {
            throw "GRAPH IS EMPTY";
        }
        vector<bool>visited(vertices_count(),false);
        int flag=0;
        for(int i=0;i<adjlist.size();i++)
        {
            if(visited[i]==true)
            {
                continue;
            }
            flag++;
            if(flag>1)
            {
                visited.clear();
                cout<<"not connected"<<endl;;
                return ;
            }
            queue<int>Q;
            Q.push(i);
            visited[i]=true;

            while(!Q.empty())
            {
                int curr=Q.front();
                Q.pop();
                list<int>::iterator it=adjlist[curr].begin();
                while(it!=adjlist[curr].end())
                {
                    if(visited[*it]==false)
                    {
                        Q.push(*it);
                        visited[*it]=true;
                    }
                    it++;
                }
            }
        }
        visited.clear();
        cout<<"connected"<<endl;;
        return ;
    }

    void delete_edge(int v1,int v2)
    {
        if(!adjlist.size())
        {
            throw"GRAPH IS EMPTY";
        }
         list<int>::iterator it=find(adjlist[v1].begin(),adjlist[v1].end(),v2);
         if(it!=adjlist[v1].end())
         {
             adjlist[v1].erase(it);
         }else{
            throw"invalid demand";
         }
           list<int>::iterator ptr=find(adjlist[v2].begin(),adjlist[v2].end(),v1);
           if(ptr!=adjlist[v2].end())
           {
               adjlist[v2].erase(ptr);
           }else{
            throw"invalid demand";
           }
           return ;
    }

    void is_bipartite()
    {
        int k;
        if(adjlist.size()==0)
        {
            throw"GRAPH IS EMPTY";
        }
        vector<int>visited(vertices_count(),-1);
        for(int i=0;i<adjlist.size();i++)
        {
            if(visited[i]!=-1)
            {
                continue;
            }
            k=0;
            queue<int>Q;
            Q.push(i);
            visited[i]=k;
            while(!Q.empty())
            {
                int curr=Q.front();
                Q.pop();
                list<int>::iterator it=adjlist[curr].begin();
                while(it!=adjlist[curr].end())
                {
                    if(visited[*it]==-1)
                    {
                        k=visited[curr];
                        k=1-k;
                        Q.push(*it);
                        visited[*it]=k;
                    }else{
                        k=visited[curr];
                        if(visited[*it]==k)
                        {
                            cout<<"not bipartite"<<endl;;
                            return ;
                        }
                    }
                    it++;
                }
            }
        }
        cout<<"bipartite"<<endl;
        return ;
    }
    void find_minimum_dice_throws( int k,vector<pair<int,int> > & snakes_and_ladders)
    {
          pair<int,int>temp1,temp2;
          for(int i=1;i<=k;i++)
          {
                  temp1=snakes_and_ladders[i];
                  if(temp1.first==i)
                  {
                      continue;
                  }
                  for(int j=i+1;j<=i+6;j++)
                  {
                      if(j>k)
                      {
                          break;
                      }
                      temp2=snakes_and_ladders[j];
                      if(temp2.first==j)
                      {
                          this->add_edges_directed(i,temp2.second);
                          continue;
                      }
                      this->add_edges_directed(i,j);
                  }
          }
           find_shortest_path_bfs(1,k);
           //count==-1?cout<<"not possible":cout<<"min dice throws required are:"<<count-1<<endl;
          return ;
    }


    stack<int> topological_sort()
    {
        vector<bool>visited(vertices_count(),false);
        stack<int>sorted;
        for(int i=0;i<adjlist.size();i++)
        {
            if(visited[i]==false)
            {
                  topological_sort_util(i,visited,sorted);
            }
        }
        return sorted;
    }


    private:
        void topological_sort_util(int src,vector<bool>& visited,stack<int> & sorted)
        {
            visited[src]=true;
            list<int>::iterator it=adjlist[src].begin();
            while(it!=adjlist[src].end())
            {
                if(visited[*it]==false)
                {
                    topological_sort_util(*it,visited,sorted);
                }
                it++;
            }
            sorted.push(src);
            return ;
        }

    public:
        int longest_path()
        {
            int value=0;
            stack<int>sorted=this->topological_sort();
            if(sorted.empty())
            {
                return 0;
            }
            queue<int>Q;
            Q.push(sorted.top());
            vector<int>visited(vertices_count(),0);
            visited[sorted.top()];
            while(!Q.empty())
            {
                int curr=Q.front();
                Q.pop();
                list<int>::iterator it=adjlist[curr].begin();
                while(it!=adjlist[curr].end())
                {
                    if(visited[*it]==0)
                    {
                        int temp=visited[curr];
                        Q.push(*it);
                        visited[*it]=temp+1;
                    }
                    else{
                        int temp=visited[curr];
                        if(visited[*it]<temp+1)
                        {
                            visited[*it]=temp+1;
                        }
                    }
                    it++;
                }
            }
            int max=-1;
            for(int i=0;i<visited.size();i++)
            {
                if(visited[i]>max)
                {
                    max=visited[i];
                }
            }
           return max;
        }



        void number_of_islands(const vector<vector<int> > &v)
        {
            vector<vector<bool> > visited;
            visited.resize(v.size());
            for(int i=0;i<v.size();i++)
            {
                visited[i].resize(v[i].size());
            }
            for(int i=0;i<visited.size();i++)
            {
                for(int j=0;j<visited[i].size();j++)
                {
                    visited[i][j]=false;
                }
            }
            int count=0;
            for(int i=0;i<v.size();i++)
            {
                for(int j=0;j< v[0].size();j++)
                {
                    if(visited[i][j]==false && v[i][j]==1)
                    {
                        dfs_util(i,j,visited,v);
                        count++;
                    }
                }
            }
            cout<<"number of island are:"<<endl;
            cout<<count;
            return;
        }

        void dfs_util(int x,int y,vector<vector<bool> >&visited,const vector<vector<int> >& v)
        {
            visited[x][y]=true;
            int R=visited.size();
            int C=visited[0].size();
            int delta[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
            for(int i=0;i<8;i++)
            {
                int newx=x+delta[i][0];
                int newy=y+delta[i][1];
                if(newx<R &&newx>=0 && newy<C && newy>=0 && visited[newx][newy]==false && v[newx][newy]==1)
                {
                    dfs_util(newx,newy,visited,v);
                }
            }
            return ;
        }


        void maximum_teams(vector<vector<int> >&v)
        {
            for(int i=0;i<v.size();i++)
            {
                sort(v[i].begin(),v[i].end());
            }
            for(int i=0;i<v.size();i++)
            {
                for(int j=0;j<v.size();j++)
                {
                    if(i!=j && can_be_placed(v[i],v[j]))
                    {
                        add_edges_directed(i,j);
                    }
                }
            }
           cout<< this->longest_path()+1;
           return ;
        }

        bool can_be_placed(const vector<int>&v1,const vector<int>&v2)
        {
            for(int i=0;i<v1.size();i++)
            {
                if(v2[i]<=v1[i])
                {
                    return false;
                }
            }
            return true;
        }

        void lexographic_order(const vector<vector<int> >&v)
        {
            for(int i=0;i<v.size();i++)
            {
                for(int j=i+1;j<v.size();j++)
                {
                    for(int k=0;k< min(v[i].size(),v[j].size());k++)
                    {
                        if(v[i][k]!=v[j][k])
                        {
                            add_edges_directed(v[i][k],v[j][k]);
                            break;
                        }
                    }
                }
            }

            cout<<"lexographic order is:"<<endl;
            stack<int>s=this->topological_sort();
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
            return ;
        }





        //shortest path between source and destination by this approach
        //source=0 and other infinity
};
int main ()
{

    Graph G;
    G.add_edges(1,2);
   // G.add_edges(1,3);
    G.add_edges(2,4);
    G.add_edges(2,5);
    G.add_edges(3,6);
    G.add_edges(3,7);
    G.print_bfs();
   /* vector<vector<int> >v;
    v.resize(3);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            int val;
            cin>>val;
            v[i].push_back(val);
        }
    }
       G.lexographic_order(v);
       */
    //G.maximum_teams(v);

    /*int k;
    cout<<"enter total numbers on the board";
    cin>>k;
    int n;
    int val,o_val;
    cout<<"enter total count snakes and ladders";
    cin>>n;
    pair<int,int>my_pair(-1,-1);
    vector<pair<int,int> >snakes_and_ladders(k+1,my_pair);
    int count=0;
    pair<int,int>temp;
    while(count!=n)
    {
        cout<<"enter the value:-";
        cin>>val;
        temp.first=val;
        cout<<"enter the actual value:-";
        cin>>o_val;
        temp.second=o_val;
        snakes_and_ladders[temp.first]=temp;
        count++;
    }
    G.find_minimum_dice_throws(k,snakes_and_ladders);
    */
     //G.add_edges(1,0);
     /*G.add_edges_directed(6,5);
     //G.add_edges(1,2);
     G.add_edges_directed(4,5);
     //G.add_edges(2,3);
     G.add_edges_directed(6,4);
    // G.add_edges(2,0);
      G.add_edges_directed(5,1);
      //G.add_edges(0,3);
     G.add_edges_directed(1,0);
     //G.add_edges(5,4);
     //G.add_edges(0,4);
     //G.add_edges(4,0);
     G.add_edges_directed(4,0);
     //G.add_edges(4,6);
     G.add_edges_directed(4,3);
     //G.add_edges(5,6);
     G.add_edges_directed(3,2);
     G.add_edges_directed(2,0);
     G.print_bfs();*/
     //G.longest_path();

     //G.find_shortest_path_bfs(0,6);
     /*G.is_connected();
     G.print_bfs();
     G.delete_edge(1,6);
     */
     //G.is_connected();
      //G.is_bipartite();

     //G.connected_components();

     //G.detect_cyclic();


    //G.print_bfs();
   // G.print_dfs();

    return 0;
}
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{
    vector<int>v;
    sort(v.begin(),v.end());
    sort(arr,arr+6);//end+1;
    ifwe want to sort in different manner
    sort(v.begin(),v.end(),compare); //greater<int>();
    bool compare(int a,int b) check for what type of data you wnat to sort
    {
        if(b>a)
        return false;
        else
            return true;
    }

    bool compare(pair<int,int>,pair<int,int>b)
    {
        if(a.first<b.first)
        {
             return true;
        }
        if(a.first==b.first)
        {
              return a.second<b.second;
        }
    return false;
    }
*/
