#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> ladders;
unordered_map<int,int> snakes;
vector<int> sol;

class Graph
{
    vector<list<int> > adjlist;

    public:

    Graph(int size)
    {
        adjlist.resize(size);
    }
    void add_edges()
    {
        for(int i=1;i<=100;i++)
        {
            if(ladders.count(i))
                continue;

            else if(snakes.count(i))
                continue;

            else {

                int k=1;
                while(k<=6 && i+k<=100)
                {
                    if(ladders.count(i+k))
                       adjlist[i].push_back(ladders[i+k]);

                    else if(snakes.count(i+k))
                        adjlist[i].push_back(snakes[i+k]);

                    else adjlist[i].push_back(i+k);
                        k++;
                }
            }
        }
    }


    void my_function()
    {
        vector<bool> visited(101,false);
        vector<int> parent(101,-1);
        queue<int> Q;
        Q.push(1);
        visited[1]=true;
        int count=0;
        while(!Q.empty())
        {
            int curr=Q.front();
            Q.pop();
            auto it = adjlist[curr].begin();
            while(it!=adjlist[curr].end())
            {
                if(*it==100)
                {
                    parent[*it]=curr;
                    int val=100;
                    while(val!=1)
                    {
                        val=parent[val];
                        count++;
                    }
                    sol.push_back(count);
                    return ;
                }
                if(visited[*it]==false)
                {
                    Q.push(*it);
                    visited[*it]=true;
                    parent[*it]=curr;
                }
                it++;
            }
        }

        if(count==0)
            sol.push_back(-1);

    }


};
int main()
{
    int t;
    cin>>t;
    for(int c=0;c<t;c++)
    {
        int n,m;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            ladders[a]=b;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            snakes[a]=b;
        }

        Graph G(101);
        G.add_edges();
        G.my_function();
        ladders.clear();
        snakes.clear();

    }
         for(int i=0;i<sol.size();i++)
            cout<<sol[i]<<endl;

            return 0;
}

