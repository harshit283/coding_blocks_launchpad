#include<iostream>
#include<stack>
using namespace std;
struct node
{
    int x,y,dir;
};
bool canrateatcheese(int a[][100],int m,int n,int currx,int curry,int destx,int desty)
{
    stack<node> s;
    node el={currx,curry,0};
    s.push(el);
    while(!s.empty() && (s.top().x!=destx || s.top().y!=desty))
    {
        int i=s.top().dir;
        currx=s.top().x;
        curry=s.top().y;
        int delta[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        for(;i<4;i++)
        {
            int newx =currx+delta[i][0];
           int  newy=delta [i][1]+curry;
            if(newx>=0&&newx<m &&newy>=0 && newy<n && a[newx][newy]==0)
            {
                s.top().dir++;
                node  temp={newx,newy,0};
                s.push(temp);
                a[newx][newy]=2;
                break;
            }
        }
        if(i==4)
        {
            a[currx][curry]=1;
            s.pop();
        }
    }
    if(s.empty())
    {
        return false;
    }
    else
    {
        while(!s.empty())
        {
            cout<<s.top().x<<","<<s.top().y<<"   ";
            s.pop();
        }
        return true;
    }

}

int main ()
{
    int a[100][100];
    int m,n,i,j,ratx ,raty,cheezx,cheezy;
    cout<<"enter the number of rows:"<<endl;
    cin>>m;
    cout<<"enter the number of columns"<<endl;
    cin>>n;
    cout<<"enter the array(only 1 and 0):"<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"enter the x coordinate of rat"<<endl;
    cin>>ratx;
    cout<<"enter the y coordinate of rat"<<endl;
    cin>>raty;
    cout<<"enter the x coordinate of cheese"<<endl;
    cin>>cheezx;
    cout<<"enter the y coordinate of cheese"<<endl;
    cin>>cheezy;
    if(canrateatcheese(a,m,n,ratx,raty,cheezx,cheezy))
    {
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}
