/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s2;
    int arr[s2.size()];
    arr[0]=0;
    int j=0,i=1;
    for(;i<s2.size();)
    {
        if(s2[i]==s2[j])
        {
            arr[i]=j+1;
            i++;j++;
            continue;
        }
        if(j)
            j=arr[j-1];
        else
        {
            arr[i]=0;
            i++;
        }
    }

    for(int i=0;i<s2.size();i++)
        cout<<arr[i]<<" ";

    return 0;

}
*/
/*
#include<iostream>
using namespace std;
int main()
{
    int sum,n;
    cin>>sum>>n;
    long long int a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];
   long long  int mat[54][253];

    for(int i=0;i<n;i++)
        mat[i][0]=1;

    for( int i=0;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(a[i]<=j)
            {
                mat[i][j]=mat[i-1][j]+mat[i][j-a[i]];
            }
            else {
                if(i==0)
                    mat[i][j]=0;
                else mat[i][j]=mat[i-1][j];
            }
        }
    }

    cout<<mat[n-1][sum];
    return 0;
}

*/
/*
#include<iostream>
#include<limits.h>
using namespace std;
int dp[2500];
int func(int *a,int n,int k)
{
    if(dp[k]!=-1)
        return dp[k];
    if(k==0)
    {
        dp[k]=0;
        return 0;
    }

    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=k)
        {
           int val=a[i]+func(a,n,k-a[i]);
            if(ans < val)
                ans=val;
        }
    }
    if(ans==INT_MIN)
    {
        dp[k]=0;
        return 0;
    }
    dp[k]=ans;
    return ans;
}
int main()
{

    int t;
    cin>>t;
    int arr[10];
    int p=0;
    for(int c=1;c<=t;c++)
    {
        int n,k;
        cin>>n>>k;
        int a[3000];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<2500;i++)
        dp[i]=-1;
        arr[p]=func(a,n,k);
        p++;
    }

//cout<<endl<<"OUTPUT IS:"<<endl;
    for(int i=0;i<p;i++)
        cout<<arr[i]<<endl;

    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        a.push_back(val);
    }

    vector<int> dp;
    for(int i=0;i<=n;i++)
        dp.push_back(1);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i] >=a[j])
            {
                if(dp[i] < 1+dp[j])
                    dp[i]=1+dp[j];
            }
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<=n;i++)
    {
        if(dp[i] > ans)
            ans=dp[i];
    }
    cout<<ans;
    return 0;

}
*/
/*
#include<bits/stdc++.h>
using namespace std;
  vector<long long int> v;
   vector<pair<long long int,long long int> > sol;

pair<long long int,long long int> my_func()
{
    long long int non_cont=0,temp=LONG_LONG_MIN;
    for(long long int i=0;i<v.size();i++)
    {
        if(v[i]>0)
            non_cont+=v[i];
        if(temp < v[i])
            temp=v[i];
    }
    if(non_cont==0)
        non_cont=temp;

     vector<long long int> dp;
     dp.push_back(v[0]);
     for(long long int i=1;i<v.size();i++)
     {
        if(v[i] < 0)
        {
            if(v[i-1]<0)
                dp.push_back(v[i]);
            else  dp.push_back(dp[i-1]+v[i]);
        }

        else{
            if(v[i-1] >=0)
                dp.push_back(dp[i-1]+v[i]);
            else{
                if(dp[i-1] < 0)
                dp.push_back(v[i]);
                else dp.push_back(dp[i-1]+v[i]);
            }
        }
     }
         temp=LONG_LONG_MIN;
     for(long long int i=0;i<v.size();i++)
     {
         if(temp < dp[i])
            temp=dp[i];
     }
     pair<long long int,long long int> my_pair(temp,non_cont);
     return my_pair;
}
int main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            v.push_back(val);
        }
        sol.push_back(my_func());
        v.clear();
    }

    for(int i=0;i<sol.size();i++)
        cout<<sol[i].first<<" "<<sol[i].second<<endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<vector<int> >arr;
    arr.resize(20);
    int x=0;
    int k=0;
    for(int c=0;c<t;c++)
    {
        int n;
        cin>>n;
         k=0;
        if(n==1 || n==2)
        {
            arr[x].push_back(-1);
            x++;
            continue;
        }
        if(n%15==0)
        {
            while(k<n)
            {
                arr[x].push_back(5);
                k++;
            }
            x++;
            continue;
        }
        int count_3=0;
        int count_5;
        while(1)
        {
            int p=n-count_3;
            if(p > 0)
            {
                 if(p%3==0)
                 {
                     int i=1;
                     while(i<=p)
                     {
                         arr[x].push_back(5);
                         i++;
                     }
                     i=1;
                     while(i<=n-p)
                     {
                         arr[x].push_back(3);
                         i++;
                     }
                     x++;
                     break;
                 }
                 if(count_3==0)
                    count_3=5;
                 else count_3+=5;
            }


            else if(p==0)
            {
                if(n<15)
                {
                    int i=1;
                    while(i<=n)
                    {
                        arr[x].push_back(3);
                        i++;
                    }
                    x++;
                    break;
                }
                int i=15;
                while(i<n)
                {
                    i=i*15;
                }
                if(i>n)
                    i=i/15;
                int j=1;
                while(j<=i)
                {
                    arr[x].push_back(5);
                    j++;
                }
                j=1;
                while(j<=n-i)
                {
                    arr[x].push_back(3);
                    j++;
                }
                x++;
                break;
            }


            else {
                arr[x].push_back(-1);
                x++;
                break;
            }
        }
    }

     for(int i=0;i<x;i++)
     {
         for(int j=0;j<arr[i].size();j++)
            cout<<arr[i][j];
         cout<<endl;
     }


    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
vector<vector<char> >mat;
    vector<vector<char> > pattern;
int m,n,r,c;
bool check_func2(int i,int j)
{
    int x=0,y=0;
    if(n-j < c)
        return false;
    if(m-i < r)
        return false;
        x=-1;
    for(int p=i;p<i+r;p++)
    {
        x++;y=0;
        for(int q=j;q<j+c;q++)
        {
            if(mat[p][q]!=pattern[x][y])
                return false;
                y++;
        }
    }
    return true;
}
bool check_func()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {

            if(mat[i][j]==pattern[0][0])
            {
                if(check_func2(i,j))
                {
                    return true;
                }

            }

        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    vector<bool> ans;
    for(int u=0;u<t;u++)
    {
        mat.resize(1000);
        pattern.resize(1000);
        cin>>m>>n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int val;
                cin>>val;
                mat[i].push_back(val);
            }
        }
        cin>>r>>c;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                char val;
                cin>>val;
                pattern[i].push_back(val);
            }
        }

        if(check_func())
        {
            ans.push_back(true);
        }
        else ans.push_back(false);
       mat.clear();
       pattern.clear();
    }


   for(int i=0;i<ans.size();i++)
    {
        if(ans[i])
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
/*
1
10 10
7 2 8 3 4 5 5 8 6 4
6 7 3 1 1 5 8 6 1 9
8 9 8 8 2 4 2 6 4 3
3 8 3 0 5 8 9 3 2 4
2 2 2 9 5 0 5 8 1 3
5 6 3 3 8 4 5 3 7 4
6 4 7 3 5 3 0 2 9 3
7 0 5 3 1 0 6 6 0 1
0 8 3 4 2 8 2 9 5 6
4 6 0 7 9 2 4 1 3 7
3 4
9 5 0 5
3 8 4 5
3 5 3 0
*/
/*
1
4 4
1 2 3 4
4 3 2 1
9 9 9 9
9 9 9 9
2 2
1 2
2 1
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<bool>ans;
    vector<int>v;
    for(int c=0;c<t;c++)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            v.push_back(val);
        }
        int count=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<=0)
                count++;
        }
        if(count>=k)
            ans.push_back(false);
        else ans.push_back(true);
        v.clear();
    }

    for(int i=0;i<t;i++)
        if(ans[i])
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a;
    vector<int>b;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        a.push_back(val);
    }
    sort(a.begin(),a.end());
    cout<<n<<endl;
    while(1)
    {
        int min=a[0];
        for(int i=0;i<a.size();i++)
        {
            a[i]=a[i]-min;
            if(a[i])
                b.push_back(a[i]);
        }
        a.clear();
        a=b;
        b.clear();
        if(a.size())
        cout<<a.size()<<endl;
        else break;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int func(int j,int m)
{
    if(m > j)
        return 0;
    int i=1;
    while(j-i*m >= 0)
        i++;
    i--;
    return i+func(i+j-i*m,m);
}
int main()
{
    int t;
    cin>>t;
    int a[1000];
    int p=0;
    for(int i=1;i<=t;i++)
    {
        int n,c,m;
        cin>>n>>c>>m;
        int j=1;
        while(n-j*c >= 0)
              j++;
        j--;
        a[p]=j;
        a[p]+=func(j,m);
        p++;
    }

    for(int i=0;i<p;i++)
        cout<<a[i]<<endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> problem;
    problem.push_back(INT_MAX);
    for(int i=1;i<=n;i++)
    {
        int val;
        cin>>val;
        problem.push_back(val);
    }

    vector<pair<int,int> > v;
    pair<int,int> temp(INT_MAX,INT_MAX);
    v.push_back(temp);
    for(int i=1;i<=n;i++)
    {

        if(problem[i] <= k)
        {
             temp.first=1;
             temp.second=problem[i];
             v.push_back(temp);
             continue;
        }
        temp.first=1;
        temp.second=k;
        v.push_back(temp);
        while(1)
        {

            temp.first=v[v.size()-1].second+1;
            if(temp.first+k-1 >= problem[i])
            {
                 temp.second=problem[i];
                 v.push_back(temp);
                 break;
            }
                temp.second=temp.first+k-1;
            v.push_back(temp);
        }
    }

   int count=0;
    for(int i=1;i<v.size();i++)
    {
       if(i>=v[i].first && i<=v[i].second)
        count++;
    }
    cout<<count;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
int func(int n,int size)
{
    int carry=0;
    for(int i=0;i<size;i++)
    {
        int prod=arr[i]*n+carry;
        arr[i]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        arr[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
}

int main()
{
    int n;
    cin>>n;
    arr[0]=1;
    int size=1;
    for(int i=2;i<=n;i++)
        size=func(i,size);
    for(int i=size-1;i>=0;i--)
        cout<<arr[i];
    return 0;

}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long int a[10];
    int p=0;
    for(int c=1;c<=t;c++)
    {
        long long int b,w,x,y,z;
        cin>>b>>w;
        cin>>x>>y>>z;
        long long int cost;

        if(z+min(x,y) > max(x,y))
            cost=x*b+y*w;
        else{
             if(x < y)
                cost=x*(b+w)+z*w;
            else cost=y*(b+w)+z*b;
        }
        a[p]=cost;
        p++;
    }

    for(int i=0;i<p;i++)
        cout<<a[i]<<endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
long long int sol[15];
long long int digit(long long int n)
{
    if(n==0)
        return 0;
    return 1+digit(n/10);
}

void func(long long int n)
{
    long long int i=0,j;
    while(n)
    {
        sol[i]=n%10;
        n=n/10;
        i++;
    }
    return ;
}

long long int my_func(long long int start,long long int end,long long int c)
{
    long long int k=1;
    while(c>0)
    {
        k=k*10;
        c--;
    }
    //cout<<k;
    long long int num=0;
    for(long long int i=end;i>=start;i--)
    {
        //cout<<sol[i]<<" ";
        num+=sol[i]*k;
        k=k/10;
    }
    //cout<<endl;
    return num;
}
 int main()
{
    long long int p,q;
    cin>>p>>q;
    long long int arr[100000];

    long long int it=0;
    for(long long int i=p;i<=q;i++)
    {
        long long int digit_count=digit(i);
        long long int sq=i*i;
        func(sq);

        long long int r=my_func(0,digit_count-1,digit_count-1);
        //cout<<r;
        long long int z=digit(sq);
        long long int l=my_func(digit_count,z-1,z-digit_count-1);
        //cout<<" "<<l;
        if(r+l==i)
        {
            arr[it]=i;
            it++;
        }
    }
   for(long long int i=0;i<it;i++)
        cout<<arr[i]<<" ";
    if(it==0)
        cout<<"INVALID RANGE";
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[1000];
    cin.getline(a,1000);
    int freq[256]={0};
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]<='Z' && a[i]>='A')
            a[i]=a[i]+32;
    }
    int count=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]<='z' && a[i]>='a')
        {
            if(freq[a[i]]==0)
            {
                freq[a[i]]++;
                count++;
                if(count==26)
                    break;
            }
        }
    }
    if(count==26)
        cout<<"panagram";
    else cout<<"not panagram";
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.get();
    int arr[10];
    int p=0;
    for(int c=0;c<t;c++)
    {
        char a[1000000];
        cin.getline(a,1000000);
        char prev=a[0];
        int count=0;
        for(int i=1;a[i]!='\0';i++)
        {
            if(a[i]==prev)
                count++;
            prev=a[i];
        }
        arr[p]=count;
        p++;
    }

    for(int i=0;i<p;i++)
        cout<<arr[i]<<endl;


    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.get();
    int arr[10];
    int p=0;
    for(int c=0;c<t;c++)
    {
        char a[10001];
        cin.getline(a,10001);
        int i=0;
        int j=strlen(a)-1;
        int count=0;
        while(j>i)
        {
            if(a[i] > a[j])
            {
                while(a[i]!=a[j])
                {
                    a[i]--;
                    count++;
                }
            }
            else if(a[j] > a[i])
            {
                while(a[i]!=a[j])
                {
                    a[j]--;
                    count++;
                }
            }
                i++;j--;
        }
        arr[p]=count;
        p++;
    }

    for(int i=0;i<p;i++)
        cout<<arr[i]<<endl;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.get();
    int mat[100][256]={0};
    for(int c=0;c<n;c++)
    {
        char a[1000];
        cin.getline(a,1000);
        for(int i=0;a[i]!='\0';i++)
        {
            if(a[i]<='z' && a[i]>='a')
            {
                mat[c][a[i]]++;
            }
        }
    }
    int ans=0;
    int count;
    for(int i='a' ;i<='z';i++)
    {
        int  j=0;
        count=0;
        while(j<n)
        {
            if(mat[j][i])
                count++;
            j++;
        }
        if(count==n)
            ans++;
    }

    cout<<ans;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
char a[100000];
char b[100000];
void reverse()
{
    int i=0;
    int j=strlen(a)-1;
    while(j>i)
    {
        b[i]=a[j];
        b[j]=a[i];
        i++;j--;
    }
    b[strlen(a)]='\0';
    return ;
}
int main()
{
    int t;
    cin>>t;
    cin.get();
    bool arr[10];
    int p=0;
    int flag=0;
    for(int c=0;c<t;c++)
    {
        flag=0;
        cin.getline(a,100000);
        reverse();
        for(int i=1;a[i]!='\0';i++)
        {
            int dif1=a[i]-a[i-1];
            dif1 =  dif1 <0 ? -dif1 : dif1;
            int dif2=b[i]-b[i-1];
            dif2 = dif2 < 0 ? -dif2 : dif2;
            if(dif1!=dif2)
            {
                flag=1;
                arr[p]=false;
                p++;
                break;
            }
        }
        if(flag==0)
        {
            arr[p]=true;
            p++;
        }
    }

    for(int i=0;i<p;i++)
    {
        if(arr[i])
            cout<<"Funny"<<endl;
        else cout<<"Not Funny"<<endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.get();
    int arr[100];
    int p=0;
    for(int c=0;c<t;c++)
    {
        char a[100000];
        cin.getline(a,100000);
        int freq1[26]={0};
        int freq2[26]={0};
        if(strlen(a)%2)
        {
            arr[p]=-1;
            p++;
            continue;
        }

        for(int i=0;i<strlen(a)/2;i++)
             freq1[a[i]-'a']++;
        for(int i=strlen(a)/2;a[i]!='\0';i++)
            freq2[a[i]-'a']++;

        int count=0;
        int dif,temp;
        for(int i=0;i<=25;i++)
        {
            if(freq1[i] > freq2[i])
            {
                dif=freq1[i]-freq2[i];
                for(int j=0;j<=25;j++)
                {
                     temp=dif;
                    if(freq2[j] > freq1[j])
                    {
                        while(freq2[j]!=freq1[j] && temp)
                        {
                            freq2[j]--;
                            count++;
                            temp--;
                        }
                        if(temp==0)
                            break;
                    }
                }
            }
        }
        arr[p]=count;
        p++;
    }

    for(int i=0;i<p;i++)
        cout<<arr[i]<<endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
char a[100006];
int n;
bool check_palindrome(int n)
{
    int i=0;
    int j=n-1;
    while(j>i)
    {
        if(a[i]=='\0')
        {
            i++;
            continue;
        }
        if(a[j]=='\0')
        {
            j--;
            continue;
        }

        if(a[i]!=a[j])
            return false;
        i++;j--;
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    int arr[20];
    int p=0;
    cin.get();
    for(int c=0;c<t;c++)
    {
        int index=-1;
        cin.getline(a,100006);
        int i=0;
        int j=strlen(a)-1;
        n=j+1;
        while(j>i)
        {
            if(a[i]==a[j])
            {
                i++;j--;
                continue;
            }

            if(a[i+1]==a[j] && a[i]==a[j-1])
            {
                char temp=a[i];
                a[i]='\0';
                bool ans1=check_palindrome(n);
                a[i]=temp;
                temp=a[j];
                a[j]='\0';
                bool ans2=check_palindrome(n);
                if(ans1)
                    index=i;
                else index=j;
                break;
            }
             if(a[i+1]==a[j])
            {
                index=i;
                break;
            }
            if(a[i]==a[j-1])
            {
                index=j;
                break;
            }
        }

        arr[p]=index;
        p++;
    }

    for(int i=0;i<p;i++)
        cout<<arr[i]<<endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    bool arr[10];
    int p=0;
    int flag=0;
    for(int c=0;c<t;c++)
    {
        flag=0;
        string a,b;
        cin>>a;
        cin>>b;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++)
        {
            if(binary_search(b.begin(),b.end(),a[i]))
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            arr[p]=true;
        else arr[p]=false;
        p++;
    }

    for(int i=0;i<p;i++)
    {
        if(arr[i])
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int freq[256]={0};
    for(int i=0;i<s.size();i++)
        freq[s[i]]++;
        int count=0;

        for(int i='a';i<='z';i++)
        {
            if(freq[i]%2)
                count++;
        }

       if(s.size()%2)
       {
           if(count==1)
            cout<<"YES";
           else cout<<"NO";
       }
       else{
           if(count)
            cout<<"NO";
           else cout<<"YES";
       }

    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int freq_a[26]={0};
    int freq_b[26]={0};
    for(int i=0;i<a.size();i++)
        freq_a[a[i]-'a']++;
    for(int i=0;i<b.size();i++)
        freq_b[b[i]-'a']++;

    int count =0;
    for(int i=0;i<=25;i++)
    {
        int dif=freq_a[i]-freq_b[i];
        dif= dif<0 ? -dif : dif;
        count+=dif;
    }

    cout<<count;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int val=arr[n-1];
    int flag=0;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i] > val)
            arr[i+1]=arr[i];
        else
        {
            arr[i+1]=val;
            flag=1;
        }
        for(int i=0;i<=n-1;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        if(flag==1)
            break;
    }
    if(flag==0)
    {
        arr[0]=val;
        for(int i=0;i<=n-1;i++)
            cout<<arr[i]<<" ";

    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int count=0;
    for(int i=1;i<=n-1;i++)
    {
        if(a[i-1] > a[i])
        {
            int val=a[i];
            int k=i;
            while( k && a[k-1] > val)
            {
                a[k]=a[k-1];
                k--;
                count++;
            }
            a[k]=val;
        }

    }
    cout<<count;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int val;
    cin>>val;
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    int index=-1;
    while(start <= end)
    {
        if(a[mid]==val)
        {
            index=mid;
            break;
        }

        else if(a[mid] > val)
        {
            end=mid-1;
            mid=(start+end)/2;
        }
        else {
            start=mid+1;
            mid=(start+end)/2;
        }
    }
    cout<<index;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];
      vector<int>left;
      vector<int>right;
    for(int i=0;i<=n-2;i++)
    {
        if(a[i] > a[n-1])
            right.push_back(a[i]);
        else left.push_back(a[i]);
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
        int count=0;
        int i=0;
        while(count<left.size())
        {
            a[i]=left[count];
            count++;
            i++;
        }
        a[i]=a[n-1];
        i++;
    count=0;
    while(count < right.size())
    {
        a[i]=right[count];
        count++;
        i++;
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
*/
/*
#include<iostream>
using namespace std;
int n;
int count;
int partition(int *a,int start,int end)
{
    count++;
    int pivot=end;
    int i,temp;
    for(i=start;i<pivot;i++)
    {
        if(a[i]<=a[pivot])
        {
            temp=a[start];
            a[start]=a[i];
            a[i]=temp;
            start++;
            //count++;
        }
    }
    temp=a[pivot];
    a[pivot]=a[start];
    a[start]=temp;
    //count++;
    return start;
}
void quicksort(int *a,int start ,int end)
{
    if(start>=end){                        //very important >= take example of 7 4 3 2
        return ;
    }
   int i= partition(a,start,end);
   for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
   cout<<endl;
   quicksort(a,start,i-1);
   quicksort(a,i+1,end);
   return ;
}
int main ()
{
    int a[100000];
    int i;
    count=0;
   // cout<<"enter the size"<<endl;
    n=40000;
   // cout<<"enter the array"<<endl;
    for(i=0;i<n;i++)
    {
        a[i]=n-i;
    }
    quicksort(a,0,n-1);
    //cout<<count;
   // cout<<"sorted array is:"<<endl;
   for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
*/


/*
#include<iostream>
using namespace std;
int a[100000];
int n;
int count;
int partition_logic(int start,int end)
{
    // count++;
    int pivot_index=end;
    for(int i=0;i<end;i++)
    {
        if(a[i] < a[end] && pivot_index!=end)
        {
            int temp=a[pivot_index];
            a[pivot_index]=a[i];
            a[i]=temp;
            pivot_index++;

        }
        else if(a[i] > a[end]  && pivot_index==end)
            pivot_index=i;
    }

    int temp=a[end];
    a[end]=a[pivot_index];
    a[pivot_index]=temp;
   // count++;
    return pivot_index;
}
void quicksort(int start,int end)
{
    if(start >= end)
        return ;

    int pivot_index=partition_logic(start,end);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
     cout<<endl;

    quicksort(start,pivot_index-1);
    quicksort(pivot_index+1,end);
}
int main()
{

    cin>>n;

    for(int i=0;i<n;i++)
    {
        a[i]=n-i;
    }
    int start=0;
    int end=n-1;
    count=0;
    quicksort(start,end);

    cout<<count;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<string> v;
    for(int c=0;c<t;c++)
    {
        string s;
        cin>>s;
        bool ans=next_permutation(s.begin(),s.end());
        if(ans)
            v.push_back(s);
        else {
            string Q;
            v.push_back(Q);
        }
    }

    for(int i=0;i<t;i++)
    {
        if(v[i].empty())
            cout<<"no answer"<<endl;
        else cout<<v[i]<<endl;
    }
    return 0;
}
*/

/*
#include<iostream>
using namespace std;
int count=0;
int partition(int *a,int start,int end)
{
    int pivot=end;
    int i,temp;
    for(i=start;i<pivot;i++)
    {
        if(a[i]<=a[pivot])
        {
            temp=a[start];
            a[start]=a[i];
            a[i]=temp;
            start++;
            count++;
        }
    }
    temp=a[pivot];
    a[pivot]=a[start];
    a[start]=temp;
    count++;
    return start;
}
void quicksort(int *a,int start ,int end)
{
    if(start>=end){                        //very important >= take example of 7 4 3 2
        return ;
    }
   int i= partition(a,start,end);
   quicksort(a,start,i-1);
   quicksort(a,i+1,end);
   return ;
}
int main()
{
    int n;
    cin>>n;
    int a[1000];
    int b[1000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
        count=0;
    quicksort(a,0,n-1);

    int count2=0;
    for(int i=1;i<=n-1;i++)
    {
        if(b[i-1] > b[i])
        {
            int val=b[i];
            int k=i;
            while( k && b[k-1] > val)
            {
                b[k]=b[k-1];
                k--;
                count2++;
            }
            b[k]=val;
        }

    }

    cout<<count2-count;
    return 0;
}

*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int arr[100]={0};
    for(int i=0;i<t;i++)
    {
        int val;
        cin>>val;
        arr[val]++;
    }
    for(int i=0;i<100;i++)
    {
        int count=0;
        while(count<arr[i])
        {
            cout<<i<<" ";
            count++;
        }
    }
    return 0;
}

*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int arr[100]={0};
    for(int i=0;i<t;i++)
    {
        int val;
        cin>>val;
        string s;
        cin>>s;
        arr[val]++;
    }
    int sum=0;
    for(int i=0;i<100;i++)
    {
          sum+=arr[i];
          cout<<sum<<" ";
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int ,vector<pair<int,string> > > my_map;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        string s;
        cin>>s;
        pair<int ,string> my_pair;
        if(i<=(n-1)/2)
        {
            my_pair.first=1;
            my_map[val].push_back(my_pair);
        }
        else{
            my_pair.first=2;
            my_pair.second=s;
            my_map[val].push_back(my_pair);
        }
    }

    map<int,vector<pair<int,string> > > :: iterator  it = my_map.begin();
    while(it!=my_map.end())
    {
         vector<pair<int,string> > ::iterator vit=it->second.begin();
         while(vit!=it->second.end())
         {
             if(vit->first==1)
                cout<<"- ";
             else cout<<vit->second<<" ";
             vit++;
         }
         it++;
    }
       return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[200000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    vector<pair<int,int> > v;
    int min_dif=INT_MAX;
    int dif;
    pair<int,int> temp;
    for(int i=0;i<=n-2;i++)
    {
        dif=a[i]-a[i+1];
        dif=dif < 0 ? -dif : dif;
        if(dif < min_dif)
        {
            min_dif=dif;
            temp.first=a[i];
            temp.second=a[i+1];
            v.clear();
            v.push_back(temp);
        }
        else if(dif==min_dif)
        {
            temp.first=a[i];
            temp.second=a[i+1];
            v.push_back(temp);
        }
    }

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<" ";
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    cout<<v[(v.size()-1)/2];
    return 0;
}
*/
/*
#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int k;
    cin>>k;
    unordered_set<long long int> my_set;
    long long int a[100000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        my_set.insert(a[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(my_set.count(a[i]+k))
             ans++;
    }
    cout<<ans;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
    bool sorted(int *a,int n)
    {
        int i=2;
        int prev=a[1];
        while(i<=n)
        {
            if(a[i] < prev)
                return false;
            prev=a[i];
            i++;
        }
        return true;
    }
int main()
{
    int n;
    int a[100001];
    int b[100001];
    cin>>n;

    for(int i=1;i<=n;i++)
    {
         cin>>a[i];
         b[i]=a[i];
    }


   vector<int>v;
   int prev=a[1];
   for(int i=2;i<=n;i++)
   {
       if(a[i] < prev)
       {
           v.push_back(i-1);
           int prev=a[i];
           int k=i+1;
           while(k<=n && a[k] < prev)
           {
               prev=a[k];
                k++;
           }
           v.push_back(k-1);
           break;
       }
       prev=a[i];
   }

  int i=v[0];
  int j=v[1];
  while(j>i)
  {
      int temp=a[i];
      a[i]=a[j];
      a[j]=temp;
      i++;j--;
  }
  if(v.size()==0)
  {
      cout<<"yes";
      return 0;
  }
  if(sorted(a,n))
  {
      if(v[1]-v[0]==1)
      cout<<"yes"<<endl<<"swap "<<v[0]<<" "<<v[1];
      else cout<<"yes"<<endl<<"reverse "<<v[0]<<" "<<v[1];
      return 0;
  }


     v.clear();
     prev=b[1];
   for(int i=2;i<=n;i++)
   {
       if(b[i] < prev)
       {
           v.push_back(i);
           if(v.size()==2)
             break;
       }
       prev=b[i];
   }

    if(v.size()==1)
    {
        cout<<"no";
    }
    else if(v.size()==2)
    {
        int temp=b[v[0]-1];
        b[v[0]-1]=b[v[1]];
        b[v[1]]=temp;
        if(sorted(b,n))
        {
            cout<<"yes"<<endl<<"swap "<<v[0]-1<<" "<<v[1];
        }
        else cout<<"no";
    }

    //cout<<endl<<v[0]<<" "<<v[1];
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int arr[100];
    int p=0;
for(int c=0;c<t;c++)
{
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int count=0;
    for(int i=1;i<=n-1;i++)
    {
        if(a[i-1] > a[i])
        {
            int val=a[i];
            int k=i;
            while( k && a[k-1] > val)
            {
                a[k]=a[k-1];
                k--;
                count++;
            }
            a[k]=val;
        }

    }
    arr[p]=count;
    p++;
}

   for(int i=0;i<p;i++)
    cout<<arr[i]<<endl;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long int arr[10];
    int p=0;
    for(int c=0;c<t;c++)
    {
        int n;
        cin>>n;
        int a[100000];
        unordered_map<int,vector<int> > my_map;
        for(int i=0;i<n;i++)
            {
                cin>>a[i];
                my_map[a[i]].push_back(i);
            }
        unordered_map<int,vector<int> > ::iterator it=my_map.begin();
        long long int count=0;
        long long int k;
        while(it!=my_map.end())
        {
            k=it->second.size();
            count+=k*(k-1);
            it++;
        }
        arr[p]=count;
        p++;
    }

    for(int i=0;i<p;i++)
        cout<<arr[i]<<endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,q;
    cin>>n>>k>>q;
    int a[100000];
    int query[100000];
    int arr[501];
    int p=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(k > n )
            k=k%n;

        if(i+k < n)
        {
            query[i+k]=a[i];
        }
        else {
            query[k-n+i]=a[i];
        }
    }

    for(int i=0;i<q;i++)
    {
        int val;
        cin>>val;
        arr[p]=query[val];
        p++;
    }

    for(int i=0;i<p;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    bool arr[10];
    for(int c=0;c<t;c++)
    {
        int n;
        cin>>n;
        int a[100000];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(n==1)
        {
            arr[c]=true;
            continue;
        }
        int c_sum=a[0];
        bool ans=false;
        for(int i=1;i<n;i++)
        {
            if(c_sum==sum-c_sum-a[i])
            {
                ans=true;
                arr[c]=true;
                break;
            }
            c_sum+=a[i];
        }
        if(ans==false)
            arr[c]=false;
    }

    for(int i=0;i<t;i++)
    {
        if(arr[i])
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int>b)
{
    if(a.first < b.first)
        return true;
      return false;
}
int main()
{
    int t;
    cin>>t;
    vector<pair<int,int> >ans;
    for(int c=0;c<t;c++)
    {
        vector<pair<int,int> > v;
        pair<int,int>my_pair(-1,-1);
        v.push_back(my_pair);
        int m,n;
        cin>>m>>n;
        for(int i=1;i<=n;i++)
        {
            int val;
            cin>>val;
            pair<int,int> temp(val,i);
            v.push_back(temp);
        }

        sort(v.begin(),v.end(),compare);
        int i=1;
        int j=v.size()-1;
        pair<int,int>temp;
        while(j > i)
        {
            if(v[i].first+v[j].first==m)
            {
                temp.first=v[i].second;
                temp.second=v[j].second;
                ans.push_back(temp);
                break;
            }
            else if( v[i].first+v[j].first > m)
                j--;
            else i++;
        }
    }

    for(int i=0;i<ans.size();i++)
    {
        if(ans[i].first < ans[i].second)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
        else cout<<ans[i].second<< " " <<ans[i].first<<endl;
    }

    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int index=0;
    long long arr[100000];
    for(int c=0;c<t;c++)
    {
        long long int m,n;
        cin>>n>>m;
        long long int a[100000];
        for(int i=0;i<n;i++)
            cin>>a[i];
        long long int max_sum=-1,temp_sum=0;

        for(int i=0;i<n;i++)
        {
            temp_sum=0;
            for(int j=i;j<n;j++)
            {
                temp_sum+=a[j];
                if(temp_sum%m > max_sum)
                    max_sum=temp_sum%m;
            }
        }
        arr[index]=max_sum;
        index++;
    }
   for(int i=0;i<index;i++)
    cout<<arr[i]<<endl;

   return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    vector<int>a;
    vector<int>b;
    int freq_a[10001]={0};
    int freq_b[10001]={0};
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        a.push_back(val);
        freq_a[val]++;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int val;
        cin>>val;
        b.push_back(val);
        freq_b[val]++;
    }

    vector<int>solution;
    for(int i=0;i<=10000;i++)
    {
        if(freq_a[i]!=freq_b[i])
            solution.push_back(i);
    }
    sort(solution.begin(),solution.end());

    for(int i=0;i<solution.size();i++)
        cout<<solution[i]<<" ";
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int mat[10][10];
int max_len;
int m,n;
int main()
{

    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
  int count;
  max_len=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            count=0;
            if(mat[i][j]==1)
            {
                mat[i][j]=2;
                queue<pair<int,int> >Q;
                pair<int,int>my_pair(i,j);
                Q.push(my_pair);
                count++;
                while(!Q.empty())
                {
                    pair<int,int>temp=Q.front();
                    Q.pop();
                    int delta[8][2]={{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0}};
                    for(int k=0;k<8;k++)
                    {
                        int newx=temp.first+delta[k][0];
                        int newy=temp.second+delta[k][1];
                        if(newx >=0 && newx <m && newy >=0 && newy <n && mat[newx][newy]==1)
                        {
                            mat[newx][newy]=2;
                            pair<int,int> p;
                            p.first=newx;
                            p.second=newy;
                            Q.push(p);
                            count++;
                        }
                    }
                }
                if(max_len < count)
                    max_len=count;
            }
        }
    }
    cout<<max_len;
    return 0;
}

*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ///for(int i=0;i<INT_MAX/2000000000;i++){}
    int n,q;
    vector<int> v;
    vector<int>query;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        v.push_back(val);
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int val;
        cin>>val;
        query.push_back(val);
    }

    for(int i=0;i<q;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            v[j]=v[j]+query[i];
            int val = v[j] < 0 ? -v[j] : v[j];
            sum+=val;
        }
        cout<<sum<<" \n";
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<bool>solution;
    for(int c=0;c<t;c++)
    {
        int n;
        cin>>n;
        vector<string> v;
        v.resize(n);
        for(int i=0;i<n;i++)
        {
             cin>>v[i];
             sort(v[i].begin(),v[i].end());
        }
        bool ans=true;
        for(int i=0;i<=n-2;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j] > v[i+1][j])
                {
                    ans=false;
                    break;
                }
            }
        }
        solution.push_back(ans);


    }

    for(int i=0;i<solution.size();i++)
    {
        if(solution[i])
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
*/

/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    int pos1=0;
    int pos2=k-1;
    int min_dif=INT_MAX;
    while(pos2 <= n-1)
    {
        if(v[pos2]-v[pos1] < min_dif)
            min_dif=v[pos2]-v[pos1];
        pos2++;pos1++;
    }
    cout<<min_dif;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int arr[100];
    int p=0;
    for(int c=0;c<t;c++)
    {
        int n;
        cin>>n;
        int a[100000];
        if(n==0)
        {
            arr[p]=0;
            p++;
            continue;
        }
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int ans=INT_MAX;
        vector<vector<int> > my_vector;
        vector<int>v;
        v.push_back(a[0]);
        my_vector.push_back(v);
        priority_queue< pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > Q;
        int prev=a[0];
        pair<int,int> my_pair(1,0);
        Q.push(my_pair);
        int flag=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]-prev==1)
            {
                pair<int,int> temp=Q.top();
                cout<<temp.first<<" "<<temp.second<<endl;
                Q.pop();
                my_vector[temp.second].push_back(a[i]);
                temp.first=my_vector[temp.second].size();
                temp.second=temp.second;
                Q.push(temp);

            }
            else if(a[i]-prev==0)
            {
                     pair<int,int>temp;
                     bool par=false;
                for(int i=0;i<my_vector.size();i++)
                {
                    if(my_vector[i][my_vector[i].size()-1]==prev-1)
                    {
                        par=true;
                        my_vector[i].push_back(a[i]);
                    }
                }
                if(par==true)
                {

                    while(!Q.empty())
                         Q.pop();
                    for(int i=0;i<my_vector.size();i++)
                    {
                       // cout<<"hjfdj";
                        temp.first=my_vector[i].size();
                        temp.second=i;
                        Q.push(temp);
                    }
                }
                else
                {
                   // cout<<"hjk\n";
                  vector<int> v;
                  v.push_back(a[i]);
                  my_vector.push_back(v);
                  pair<int,int> temp(1,my_vector.size()-1);
                  Q.push(temp);
                }

            }
            else{
                    flag=1;
                pair<int,int>temp=Q.top();
                if(ans > my_vector[temp.second].size())
                    ans=my_vector[temp.second].size();
                my_vector.clear();
                while(!Q.empty())
                    Q.pop();
                vector<int>v;
                v.push_back(a[0]);
                my_vector.push_back(v);
                temp.first=1;
                temp.second=0;
                Q.push(temp);
                flag=0;
            }

            prev=a[i];
        }
        if(flag==0)
        {
           // cout<<"hello\n";
            pair<int,int>temp=Q.top();
            if(ans > temp.first)
            {
                ans=temp.first;
                //cout<<ans;
            }
           // cout<<my_vector.size()<<endl;
            //for(int i=0;i<my_vector.size();i++)
            //{
          //      for(int j=0;j<my_vector[i].size();j++)
           //         cout<<my_vector[i][j]<<" ";
            //    cout<<endl;
           // }


        }
        arr[p]=ans;
        p++;
    }

   // for(int i=0;i<p;i++)
      //  cout<<arr[i]<<endl;

    return 0;
}
*/
/*
1
6
1 1 2 2 3 3
*/


/*
#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100000];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int sum=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(sum+a[i] <=k)
        {
            sum=sum+a[i];
            count++;
        }

        else break;
    }
    cout<<count;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
void reverse_array(int *a,int n)
{
    int i=0;
    int j=n-1;
    while(j>i)
    {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        j--;i++;
    }
    return ;
}
int main()
{
    int t;
    cin>>t;
    bool arr[10];
    int p=0;
    for(int c=0;c<t;c++)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        int a[1000];
        int b[1000];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        reverse_array(b,n);
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(a[i]+b[i] < k)
            {
                ans=false;
                break;
            }
        }
        if(ans)
            arr[p]=true;
        else arr[p]=false;
        p++;
    }

    for(int i=0;i<p;i++)
    {
        if(arr[i])
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int sum=a[0]+4;
    int count=0;
    vector<int> v;
    for(int i=1;i<n;i++)
    {
        if(a[i] <= sum)
        {
            count++;
            if(i==n-1)
                v.push_back(count);
        }
        else {
               v.push_back(count);
            count=0;
            sum=a[i]+4;
        }
    }
    sum=0;
    for(int i=0;i<v.size();i++)
        sum+=v[i];
    // sum+=v[i];
    // cout<<sum;
    cout<<n-sum;
    return 0;

}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,r;
    cin>>l>>r;
    int max_val=INT_MIN;
    for(int i=l;i<=r;i++)
    {
        for(int j=l;j<=i;j++)
        {
            if( (i^j) > max_val)
                max_val=i^j;
        }
    }

    cout<<max_val;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    bool arr[100];
    int p=0;
    for(int c=0;c<t;c++)
    {
       unsigned long long int n;
       cin>>n;

    if(n==1)
    {
        cout<<"RICHARD"<<endl;
        continue;
    }
 int l=1;
while(1)
{
        unsigned long long int i=1;
        int count=0;
        while(i<=n/2)
        {
            i=i*2;
            count++;
        }
        if(i==n)
            n=n/2;
        else
          n=count;
        l=1-l;
        if(n==1)
        {
            if(l==0)
            arr[p]=false;
            else arr[p]=true;
            p++;
            break;
        }
}

    }

    for(int i=0;i<p;i++)
    {
        if(arr[i])
            cout<<"RICHARD"<<endl;
        else cout<<"LOUISE"<<endl;
    }
    return 0;

}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int arr[100];
    int p=0;
    for(int c=0;c<t;c++)
    {
        unsigned long long int n;
        int l=1;
        cin>>n;
        if(n==1)
        {
            cout<<"Richard";
            continue;
        }
    while(1)
    {
        int count=0;
        int k=0;
        while(k<64)
        {
            if(n&(1ll<<k))
                count++;
            k++;
        }
        if(count==1)
            n=n/2;
        else {
            k=63;
            count=0;
            unsigned long long int temp=n;
            while(k>=0)
            {
                if((temp&(1ll<<k))==0)
                      count++;
                else {
                    temp=1ll<<k;
                    temp=~temp;
                    n=n&temp;
                    break;
                }
                k--;
            }
        }
        l=1-l;
        if(n==1)
        {
            if(l==0)
            arr[p]=false;
            else arr[p]=true;
            p++;
            break;
        }

    }
    }

    for(int i=0;i<p;i++)
        if(arr[i])
        cout<<"Richard"<<endl;
    else cout<<"Louise"<<endl;
    return 0;
}
*/
/*
1
6703734870638684097
*/

/*
#include<stdio.h>
int setBits(unsigned long long int n) {
    int count = 0 ;
    while(n) {
        n &= (n-1) ;
        count ++ ;
    }
    return count ;
}

int main() {
    int t ;
    scanf("%d\n",&t) ;
    while(t--) {
        unsigned long long int n ;
        scanf("%llu\n",&n) ;
        if (setBits(n-1) & 1) printf("Louise\n") ;
        else printf("Richard\n") ;
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    unsigned int arr[100];
    for(int i=0;i<t;i++)
    {
        unsigned int n;
        cin>>n;
        arr[i]=~n;
    }

    for(int i=0;i<t;i++)
        cout<<arr[i]<<endl;
    return 0;
}

*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int index=0;
    long long arr[10000];
    for(int c=0;c<t;c++)
    {
        int n;
        long long int m;
        cin>>n>>m;
        vector< pair< long long int , int > > v;
        for(int i=0;i<n;i++)
        {
            long long int val;
            cin>>val;
            pair<  long long int , int > my_pair;
            my_pair.first=val;
            my_pair.second=i;
            v.push_back(my_pair);
        }

        v[0].first=v[0].first%m;
        long long int maxx=v[0].first;
        for(int i=1;i<n;i++)
        {
            v[i].first=(v[i].first%m+v[i-1].first%m)%m;
            if(v[i].first > maxx)
                maxx=v[i].first;
        }
        sort(v.begin(),v.end());
        long long int min_val=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            if(v[i].second > v[i+1].second)
            {
                if(v[i+1].first - v[i].first < min_val)
                    min_val=v[i+1].first-v[i].first;
            }
        }
        arr[index]=max(maxx,m-min_val);
        index++;
    }
   for(int i=0;i<index;i++)
    cout<<arr[i]<<endl;
   return 0;
}
*/


/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int index=0;
    long long arr[10000];
    for(int c=0;c<t;c++)
    {
        int n;
         unsigned long long int m;
        cin>>n>>m;
        vector< pair<  unsigned long long int , int > > v;
        for(int i=0;i<n;i++)
        {
             unsigned long long int val;
            cin>>val;
            pair<  unsigned long long int , int > my_pair;
            my_pair.first=val;
            my_pair.second=i;
            v.push_back(my_pair);
        }

        v[0].first=v[0].first%m;
        unsigned long long int maxx=v[0].first;
        for(int i=1;i<n;i++)
        {
            v[i].first=(v[i].first%m+v[i-1].first%m)%m;
            if(v[i].first > maxx)
                maxx=v[i].first;
        }
        sort(v.begin(),v.end());
        unsigned long long int min_val=ULLONG_MAX;
        //int flag=0;
        for(int i=0;i<n;i++)
        {
            if(v[i].second > v[i+1].second)
            {
                if(v[i+1].first - v[i].first < min_val)
                    min_val=v[i+1].first-v[i].first;
            }
        }

        arr[index]=max(maxx,m-min_val);
        index++;
    }
   for(int i=0;i<index;i++)
    cout<<arr[i]<<endl;

   return 0;
}

*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    int width[100000];
    int arr[1000];
    for(int i=0;i<n;i++)
        cin>>width[i];
    for(int c=0;c<t;c++)
    {
        int i,j;
        cin>>i>>j;
        int min_val=INT_MAX;
        for(int k=i;k<=j;k++)
        {
            if(width[k] < min_val)
                min_val=width[k];
        }
        arr[c]=min_val;
    }

    for(int i=0;i<t;i++)
        cout<<arr[i]<<endl;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> v;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    if(n==1)
    {
        cout<<v[0];
        return 0;
    }
    for(int i=1;i<=v.size()-2;i++)
    {
        for(int j=1;j<=v[i].size()-2;j++)
        {
            int delta[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
            bool ans=true;
            for(int k=0;k<4;k++)
            {
                if(v[i+delta[k][0]][j+delta[k][1]]=='X')
                {
                    ans=false;
                    break;
                }

                if(v[i+delta[k][0]][j+delta[k][1]] >= v[i][j])
                {
                    ans=false;
                    break;
                }
            }
            if(ans)
            {
                 v[i][j]='X';
                 j++;
            }

        }
    }

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k;
    cin>>k;
    if(k%26==0)
    {
        cout<<s;
        return 0;
    }
    if(k>26)
    k=k%26;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='z' && s[i]>='a')
        {
            if(s[i]+k > 'z')
                s[i]='a'+k-1-'z'+s[i];
            else s[i]=s[i]+k;
        }
        else if(s[i]<='Z' && s[i]>='A')
        {
            if(s[i]+k > 'Z')
                s[i]='A'+k-1-'Z'+s[i];
            else s[i]=s[i]+k;
        }
    }
    cout<<s;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
set<int> s;
int a,b;
int main()
{
    int t;
    cin>>t;
    vector<vector<int> > my_vector;
    my_vector.resize(t);
    for(int c=0;c<t;c++)
    {
        int n;
        cin>>n>>a>>b;
        for(int i=0;i<=n-1;i++)
            s.insert(i*a+(n-1-i)*b);
        set<int>::iterator it=s.begin();
        while(it!=s.end())
        {
            my_vector[c].push_back(*it);
            it++;
        }
        s.clear();
    }
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<my_vector[i].size();j++)
            cout<<my_vector[i][j]<<" ";
            cout<<endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> v;
    v.resize(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int count=0;
    int max_count=-1;
    int temp_count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            count=0;
            for(int k=0;k<m;k++)
            {
                if(v[i][k]=='1' || v[j][k]=='1')
                    count++;
            }
            if(count > max_count)
            {
                max_count=count;
                temp_count=1;
            }
            else if(count==max_count)
                temp_count++;

        }
    }
    cout<<max_count<<endl;
    cout<<temp_count;
    return 0;
}
*/
///STILL INCOMPLETE
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    bool ans[10];
    for(int c=0;c<t;c++)
    {
        int n;
        cin>>n;
        map<int ,int> my_map;
        int a[1001];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            my_map[val]=i+1;
        }
        map<int,int> ::iterator it=my_map.begin();
        int count=1;
        int temp_count=0;
        while(it!=my_map.end())
        {
            if(it->second==count && temp_count!=3 && temp_count!=0)
                break;
            if(it->second==count)
                count++;
            else {
                temp_count++;
                count++;
                if(temp_count==3)
                    temp_count=0;
            }
          it++;
        }

        if(temp_count==0)
            ans[c]=true;
        else ans[c]=false;
    }

    for(int i=0;i<t;i++)
    {
        if(ans[i])
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
     int m,n,r;
    cin>>m>>n>>r;
    int mat[302][302];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>mat[i][j];
    }


    int ver_upper=1;
    int ver_lower=m;
    int hor_upper=1;
    int hor_lower=n;
    while(ver_upper < ver_lower && hor_upper < hor_lower)
    {
        int x=ver_upper;
        int y=hor_upper;
        int k=2*(ver_upper-ver_lower + hor_upper - hor_lower);
        int temp=r%k;
        if(temp)
        {
            int count=0;
            while(count < temp)
            {
                 int c=ver_lower;
                 int val=mat[c][hor_upper];
                 while(c >= ver_upper+1)
                 {
                     mat[c][hor_upper]=mat[c-1][hor_upper];
                     c--;
                 }
                 c=hor_lower;
                 int val2=mat[ver_lower][c];
                 while(c>=hor_upper+2)
                 {
                     mat[ver_lower][c]=mat[ver_lower][c-1];
                     c--;
                 }
                 mat[ver_lower][c]=val;
                 c=ver_upper;
                 val=mat[c][hor_lower];
                 while(c <= ver_lower-2)
                 {
                     mat[c][hor_lower]=mat[c+1][hor_lower];
                     c++;
                 }
                 mat[c][hor_lower]=val2;
                 c=hor_upper;
                 while(c <= hor_lower-2)
                 {
                     mat[ver_upper][c]=mat[ver_upper][c+1];
                     c++;
                 }
                 mat[ver_upper][c]=val;
                 count++;
            }
        }
        ver_upper++;
        ver_lower--;
        hor_upper++;
        hor_lower--;

    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    vector<string> v;
    int m=floor(sqrt(s.size()));
    int n=ceil(sqrt(s.size()));
    if(m*n <= s.size())
        m=n;

    v.resize(m);
    int index=0;
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        v[index].push_back(s[i]);
        count++;
        if(count==n)
        {
            index++;
            count=0;
        }

    }
    //cout<<"hello";
    s.clear();
    int size=v[v.size()-1].size();
    for(int i=0;i<v[0].size();i++)
    {
        for(int j=0;j<=v.size()-1;j++)
        {
            if(j==v.size()-1 && i>=size)
                 break;
            else {
                s.push_back(v[j][i]);
            }
        }
           char ch=' ';
           s.push_back(ch);
    }

    for(int i=0;i<s.size();i++)
        cout<<s[i];
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
     int arr[10];
    for(int c=0;c<t;c++)
    {
        string s;
        cin>>s;
        vector<string> v;
        string helper;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                string helper;
                for(int k=i;k<=j;k++)
                {
                    helper.push_back(s[k]);
                }
                v.push_back(helper);
            }
        }

        for(int i=0;i<v.size();i++)
            sort(v[i].begin(),v[i].end());

        sort(v.begin(),v.end());

        int count=1;
        int sum=0;
        string prev=v[0];
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==prev)
                count++;
            else{
                sum+=(count*(count-1))/2;
                count=1;
                prev=v[i];
            }
        }
        sum+=(count*(count-1))/2;
        arr[c]=sum;
    }

    for(int i=0;i<t;i++)
        cout<<arr[i]<<endl;

    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[1000];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(k >= n)
    {
        cout<<sum;
        return 0;
    }
    sort(a,a+n);
    sum=0;
    int count=0;
    int f_sum=0;
    int p=1;
    for(int i=n-1;i>=0;i--)
    {
        sum=sum+a[i]*p;
        count++;
        if(count==k)
        {
            f_sum+=sum;
            sum=0;
            count=0;
            p++;
        }
    }
    f_sum+=sum;
    cout<<f_sum;
    return 0;
}

*/


/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long int arr[20];
    for(int c=0;c<t;c++)
    {
        int m,n;
        cin>>m>>n;
        vector<long long int > a;
        vector<long long int> b;
        for(int i=1;i<=m-1;i++)
        {
            int val;
            cin>>val;
            a.push_back(val);
        }

        for(int i=1;i<=n-1;i++)
        {
            int val;
            cin>>val;
            b.push_back(val);
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=m-2;
        int j=n-2;
        long long int vertical_count=1,hor_count=1;
        long long int sum=0;
        while(i>=0 && j>=0)
        {
            if(a[i]==b[j])
            {
                sum+=a[i]*vertical_count;
                hor_count++;
                sum+=b[j]*hor_count;
                vertical_count++;
                i--;j--;
            }
            else if(a[i] > b[j])
            {
                sum+=a[i]*vertical_count;
                hor_count++;
                i--;
            }
            else{
                sum+=b[j]*hor_count;
                vertical_count++;
                j--;
            }
        }

        if(i<0)
        {
            while(j>=0)
            {
                sum+=b[j]*hor_count;
                j--;
            }
        }

        else if(j<0)
        {
            while(i>=0)
            {
                sum+=a[i]*vertical_count;
                i--;
            }
        }
        sum=sum%(1000000007);
        arr[c]=sum;
    }

    for(int i=0;i<t;i++)
        cout<<arr[i]<<endl;

    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<pair<int , int> > v;
    for(int c=0;c<t;c++)
    {
        int n;
        cin>>n;
        int a[100000];
        for(int i=0;i<n;i++)
            cin>>a[i];
        pair<int,int>temp;
        int curr_max=a[0];
        int max_so_far=a[0];
        for(int i=1;i<n;i++)
        {
            curr_max=max(a[i],curr_max+a[i]);
            max_so_far=max(max_so_far,curr_max);
        }
        temp.first=max_so_far;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i] > 0)
                sum+=a[i];
        }
        if(sum==0)
            temp.second=temp.first;
        else temp.second=sum;
        v.push_back(temp);
    }


    for(int i=0;i<v.size();i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long int arr[10];
    for(int c=0;c<t;c++)
    {
        long long int n;
        cin>>n;
        long long int a[50000];
        for(int i=0;i<n;i++)
            cin>>a[i];

        long long int curr_max=-1;
        long long int profit=0;
        for(int i=n-1;i>=0;i--)
        {
            if(curr_max < a[i])
                curr_max=a[i];
            else profit+=curr_max-a[i];
        }
        arr[c]=profit;
    }

    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int arr[10]={0};
    for(int c=0;c<t;c++)
    {
        int a[100001];
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]-i > 2 || i-a[i] >2)
            {
                arr[c]=-1;
                break;
            }
            int temp=a[i]-i;
            temp= temp < 0 ? -temp : temp;
            sum+=temp;
        }
        if(arr[c]==-1)
            continue;
        else arr[c]=sum/2;
    }

    for(int i=0;i<t;i++)
    {
        if(arr[i]==-1)
            cout<<"Too chaotic";
        else cout<<arr[i];
        cout<<endl;
    }


    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
int my_func(int index,int sum)
{
    if(index==n)
        return 0;
    if(sum==0)
        return 1;
    if(sum<0)
        return 0;
    return my_func(index+1,sum)+my_func(index,sum-a[index]);
}
int main()
{
    int sum;
    cin>>sum;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<my_func(0,sum);
    return 0;
}
*/

///2nd
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[100000];
    priority_queue< pair<int,int> >Q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pair <int,int> my_pair(a[i],i);
        Q.push(my_pair);
    }

   int count=0;
   int i=0;
   while(Q.empty()==false && count<k)
    {
        pair<int,int> my_pair=Q.top();
        Q.pop();
        swap(a[i],a[my_pair.second]);
        i++;
        count++;
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}


///1ST
#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[100000];
    map<int,int> my_map;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        my_map[a[i]]=i;
    }

   int count=0;
   int i=0;
   while(my_map.empty()==false && count<k)
    {
           map<int,int> ::reverse_iterator it= my_map.rbegin();
           //cout<<it->first<<" " <<it->second<<endl;
           if(it->second!=it->first)
           {
                swap(a[i],a[it->second]);
                count++;
           }
           my_map.erase(it->first);
           i++;
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
*/

