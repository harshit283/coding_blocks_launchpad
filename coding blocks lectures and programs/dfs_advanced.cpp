#include<bits/stdc++.h>
using namespace std;
bool my_function_util(pair<int,int> , pair<int,int > );
vector<string> v;
vector<string>duplicate;
vector<int> sol;
vector<pair<int,int> > path;
int counter;
void my_function(int k)
{
    pair<int,int> src,dest;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j]=='M')
            {
                src.first=i;
                src.second=j;
            }
            if(v[i][j]=='*')
            {
                dest.first=i;
                dest.second=j;
            }
        }
    }
    v[src.first][src.second]='.';
    v[dest.first][dest.second]='.';
    duplicate[src.first][src.second]='.';
    duplicate[dest.first][dest.second]='.';

    my_function_util(src,dest);
    path.push_back(src);
    int temp_count;
    int delta[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    for(int i=1;i<path.size();i++)
    {
        temp_count=0;
        pair<int,int> curr=path[i];
        for(int k=0;k<4;k++)
        {
              int newx=curr.first+delta[k][0];
              int newy=curr.second+delta[k][1];

              if(newx >= 0 && newx < v.size() && newy >= 0 && newy < v[0].size() && duplicate[newx][newy]=='.')
              {

                  if(i+1 < path.size() && !(path[i+1].first==newx && path[i+1].second==newy))
                         temp_count++;

                  else if(i+1 >= path.size())
                    temp_count++;
              }
        }
        if(temp_count >=2)
            counter++;

    }

    if(counter==k)
        sol.push_back(1);
    else sol.push_back(0);

}

bool my_function_util(pair<int,int> curr, pair<int,int> dest)
{
    if(curr==dest)
       return true;
    int delta[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    for(int i=0;i<4;i++)
    {
        int newx=curr.first+delta[i][0];
        int newy=curr.second+delta[i][1];
        if(newx >= 0 && newx < v.size() && newy >= 0 && newy < v[0].size() && v[newx][newy]=='.')
        {
            pair<int,int> my_pair(newx,newy);
            v[curr.first][curr.second]='1';
            if(my_function_util(my_pair,dest))
            {
                path.push_back(my_pair);
                return true;
            }

        }
    }

    v[curr.first][curr.second]='X';
    return false;
}
int main()
{
    int t;
    cin>>t;
    for(int c=0;c<t;c++)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
           string s;
           cin>>s;
           v.push_back(s);
        }
        duplicate=v;
        int k;
        cin>>k;
        counter=0;
        my_function(k);
        v.clear();
        duplicate.clear();
        path.clear();
    }

    for(int i=0;i<sol.size();i++)
    {
        if(sol[i]==1)
            cout<<"Impressed";
        else cout<<"Oops!";
        cout<<endl;
    }

    return 0;
}
