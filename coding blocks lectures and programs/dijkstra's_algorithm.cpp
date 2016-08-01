#include<bits/stdc++.h>
using namespace std;
class Graph
{
    vector<list<pair<int,int> > > adjlist;
    public:

    Graph(int size)
    {
        adjlist.resize(size);
    }

    void add_edges(int src,int dest,int wt)
    {
        pair<int,int>my_pair1(dest,wt);
        pair<int,int>my_pair2(src,wt);
        adjlist[src].push_back(my_pair1);
        adjlist[dest].push_back(my_pair2);
    }

    vector<int> my_function(int src)
    {
        vector<int> dis(adjlist.size(),INT_MAX);
        vector<bool> visited(adjlist.size(),false);
        class compare
        {
            public:

            bool operator () (pair<int,int> & p1, pair<int,int> & p2)
            {
                return p1.second > p2.second;
            }

        };

        priority_queue < pair<int,int > , vector<pair<int,int> > , compare > Q;
        pair<int,int> my_pair(src,0);
        Q.push(my_pair);
        dis[src]=0;
        while(!Q.empty())
        {
            pair<int,int> temp=Q.top();
            Q.pop();
            if(visited[temp.first]==true)
            {
                //cout<<"hello";
                   continue;
            }

            visited[src]=true;
            auto it=adjlist[temp.first].begin();
            while(it!=adjlist[temp.first].end())
            {
                if(visited[it->first]==false && dis[it->first] > dis[temp.first] + it->second)
                {
                    dis[it->first]=dis[temp.first]+it->second;
                    pair<int,int> P(it->first,dis[it->first]);
                    Q.push(P);
                }
                it++;
            }
        }

        dis[src]=-1;
        return dis;
    }

};
int main()
{
    int t;
    cin>>t;
    vector<vector<int> > sol;
    sol.resize(t);
    for(int c=0;c<t;c++)
    {
        int n,m;
        cin>>n>>m;
        Graph G(n+1);
        for(int i=0;i<m;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            G.add_edges(x,y,w);
        }
        int src;
        cin>>src;
       sol[c]=G.my_function(src);
    }

    for(int i=0;i<t;i++)
    {
        for(int j=1;j<sol[i].size();j++)
        {
            if(sol[i][j]!=-1)
                cout<<sol[i][j]<<" ";
            else if(sol[i][j]==INT_MAX)
                cout<<-1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
