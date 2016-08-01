#include<bits/stdc++.h>
using namespace std;
int sum;
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

    void my_function(int src)
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
                continue;
            }
            visited[temp.first]=true;
            auto it=adjlist[temp.first].begin();
            while(it!=adjlist[temp.first].end())
            {
                if(visited[it->first]==false && dis[it->first] >  it->second)
                {
                    dis[it->first]=it->second;
                    pair<int,int> P(it->first,dis[it->first]);
                    Q.push(P);
                }
                it++;
            }
        }

        for(int i=1;i<dis.size();i++)
             sum+=dis[i];

    }

};
int main()
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
        sum=0;
       G.my_function(src);
        cout<<sum;

    return 0;
}


