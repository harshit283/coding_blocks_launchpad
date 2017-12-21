

/*#include <bits/stdc++.h>
#define MAX 10000001
using namespace std;
int arr[10000001];
int totient[10000001];
void sieve()
{
    fill_n(arr,10000001,0);
    for(int i=2;i<=sqrt(MAX);i++)
    {
        if(!arr[i])
        {
            for(int p=2;p*i<=MAX;p++)
                arr[i*p]=i;
        }
    }
    fill_n(totient,10000001,-1);
    return;
}

int totient_function(int n)
{
    int val=n;
    if(!arr[n])
        return n-1;
    if(totient[n]!=-1)
        return totient[n];
    int  result=n;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n=n/i;
            result-=result/i;
        }
    }

    if(n>1)
        result-=result/n;
    totient[val]=result;
    return result;
}
int my_func(int n)
{
    if(!arr[n])
        return n*(n-1);
    int ans=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0) {

            if (n / i == i)
            {
                ans += i*totient_function(i);
            }
            else
            {
                ans += i * totient_function(i);
                ans += (n / i) * totient_function(n / i);
            }
        }
    }
    return ans;
}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t)
    {
        t--;
        int n;
        scanf("%d",&n);
        printf("%d\n",my_func(n)+1);
    }
    return 0;
}

*/
/*
#include <bits/stdc++.h>
using namespace std;
#define MAX 10000001
#define ull unsigned long long
int arr[10000001];
void precompute()
{
    memset(arr,0,sizeof(arr));
    for(int i=2;i*i<=MAX;i++)
    {
        if(!arr[i])
        {
            for(int j=i;j*i<=MAX;j++)
                arr[i*j]=i;
        }
    }
}
int main()
{
    precompute();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ull n;
        scanf("%llu",&n);
        ull ans=1;
        while(n>1)
        {
            if(!arr[n])
            {
                ans=ans*(n*(n-1)+1);
                n=1;
            }
            else
            {
                ull temp=1;
                ull mul=arr[n];
                while(!(n%mul))
                {
                    n/=mul;
                    temp*=(mul*mul);
                }
                temp*=mul;
                ans=ans*((temp+1)/(mul+1));
            }
        }
        printf("%llu\n",ans);
    }
}
 */

/*
 * #include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define INFLL 1000000000000000000
#define range(a, b, c) (a>=b && a<c)
#define stlfor(a, b) for(auto a=b.begin(); a!=b.end(); a++)
#define rstlfor(a, b) for(auto a=b.rbegin(); a!=b.rend(); a++)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define li long long int
using namespace std;

const li N = 1001000;
const li MAXA = 500050;

li st[N << 2], a[N], f[MAXA + 1];

li ar[500500],b[500500];

void phi()
{
    li i,j;
    for(i=0;i<=500100;i++)
	{
		ar[i]=i;
		b[i]=0;
	}
	for(i=2;i<=500500;i++)
	{
		if(b[i]==0)
		{
			ar[i]=i-1;
			for(j=2;j*i<=500100;j++)
			{
				ar[i*j]*=((i-1));
				ar[i*j]/=i;
				b[i*j]=1;
			}
	    }
    }
}

void setF()
{
    memset(f, 0, sizeof f);
    for(li i=1; i<=MAXA; i++)
    {
        for(li j=i; j<=MAXA; j+=i)
            f[j] = (f[j] + (li)i*1LL*ar[i]) % MOD;
        f[i] = ((li)(f[i] + 1) * (li)500000004LL) % MOD;
    }
}

void build(li node, li i, li j)
{
    if(i == j)
    {
        st[node] = f[a[i]];
        return;
    }
    li mid = i+j >> 1;
    build(node+node, i, mid);
    build(node+node+1, mid+1, j);
    st[node] = (st[node+node] + st[node+node+1]) % MOD;
}

void update(li node, li i, li j, li p, li v)
{
    if(i == j)
    {
        st[node] = f[v];
        return;
    }
    li mid = i+j >> 1;
    if(p <= mid)
        update(node+node, i, mid, p, v);
    else
        update(node+node+1, mid+1, j, p, v);
    st[node] = (st[node+node] + st[node+node+1]) % MOD;
}

li query(li node, li i, li j, li l, li r)
{
    if(j<l || i>r)
        return 0;
    if(i>=l && j<=r)
        return st[node];
    li mid = i+j >> 1;
    return (query(node+node, i, mid, l, r) + query(node+node+1, mid+1, j, l, r)) % MOD;
}

int main()
{
	li n,x,y;
    phi();
    setF();
    cin>>n;
//    int n = readLI();
    for(int i=0; i<n; i++)
    cin>>a[i];
//        a[i] = readLI();
    build(1, 0, n-1);
    li q;
    cin>>q;
    while(q--)
    {
        char c;
        cin >> c;
        cin>>x;
        cin>>y;
        if(c == 'C')
            cout << query(1, 0, n-1, x-1, y-1) << endl;
        else
            update(1, 0, n-1, x-1, y);
    }
    return 0;
}
 */
/*
#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
double avg;
vector<std::list<pp>> adjlist;

void util(double count,double  sum,int dest,int curr)
{
    if(curr==dest)
    {
        if(avg == -1 || sum/count < avg )
            avg = sum/count;
        return;
    }

    auto it = adjlist[curr].begin();
    while(it!=adjlist[curr].end())
    {
        util(count+1,sum+it->second,dest,it->first);
        it++;
    }
    return;
}
void my_function(int src,int dest)
{
    double sum=0,count=1;
    auto it = adjlist[src].begin();
    while(it!=adjlist[src].end())
    {
        util(count,sum+it->second,dest,it->first);
        it++;
    }
    return ;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        adjlist.clear();
        adjlist.resize(n+1);
        while(m--)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            adjlist[x].push_back(pp(y,z));
        }
        int a,b;
        scanf("%d%d",&a,&b);
        avg=-1;
        my_function(a,b);
        printf("%.10lf\n",avg);
    }
    return 0;
}
 */


//CHEF AND STRING
/*
#include <bits/stdc++.h>
using namespace std;
#define li long long int
vector<vector<li> > sol;
int cnt;
void subsets(li n,vector<li>&v,li *arr,li index)
{

    if(index==n)
    {
        sol[cnt]=v;
        cnt++;

        return;
    }
    subsets(n,v,arr,index+1);
    v.push_back(arr[index]);
    subsets(n,v,arr,index+1);
    v.pop_back();
    return;
}
bool check(string &s)
{
    int i;
    for( i=0;i<s.size();)
    {
        if(i==s.size()-1)
            break;
        if(s[i]=='1')
            i++;
        else i=i+2;

    }
    return i == s.size()-1;
}

bool func(string a,string b,int i)
{
    for(int j=0;j<sol[i].size();j++)
        swap(a[sol[i][j]-1],b[sol[i][j]-1]);
    return (check(a)&&check(b));
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        int size = a.size();
        li arr[size];
        for(li i=0;i<size;i++)
            arr[i]=i+1;
        vector<li>v;
        sol.clear();
        sol.resize(1025);
        cnt=0;
        subsets(a.size(),v,arr,0);

        li ans=0;

       if(check(a)&&check(b))
            ans++;
        for(int i=1;i<cnt;i++)
        {
            if(func(a,b,i))
                ans++;
        }
        printf("%lld\n",ans%1000000009);

        /*for(int i=0;i<cnt;i++)
        {
            for(int j=1;j<sol[i].size();j++)
                cout<<sol[i][j]<<" ";
            cout<<endl;
        }
        cout<<cnt;
    }
    return 0;
}*/

/*
#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define pp pair<li,li>
li my_func(li a,li b)
{
    return a*a+b*b;
}
int main()
{
    li n;
    scanf("%lld",&n);
    vector<pp>v;
    int x,y;
    while(n--)
    {
        pp p;
        scanf("%lld%lld",&p.first,&p.second);
        v.push_back(p);
        if(v.size()==1)
        {
            printf("0\n");
            continue;
        }

        if(v.size()==2)
        {
            printf("%lld\n",my_func(v[0].first-v[1].first,v[0].second-v[1].second));
            x=0;
            y=1;
            continue;
        }


        int val = v.size()-1;
        li val1 = my_func(v[x].first-v[y].first,v[x].second-v[y].second);
        li val2 = my_func(v[x].first-v[val].first,v[x].second-v[val].second);
        li val3 = my_func(v[y].first-v[val].first,v[y].second-v[val].second);
        if(val1 > max(val2,val3))
            printf("%lld",val1);
        else if(val2 > max(val1,val3))
        {
            printf("%lld",val2);
            y=val;
        }
        else
        {
            printf("%lld",val3);
            x=val;
        }

        printf("\n");
    }

    return 0;
}
 */

//TANYA AND STONES
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string s;
        cin>>s;
        int count=0;
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='N')
            {
                count++;
                int k=i+1;
                while(k<s.size())
                {
                    if(s[k]!='N')
                        break;
                    k++;
                }
                i=k+1;
            }
            else i++;
        }

        cout<<count<<endl;
    }
    return 0;
}*/


/*
#include <bits/stdc++.h>
using namespace std;
#define li  long long int
class pp
{
    public:
    li first,second,third;
    pp(){}
    pp(li a,li b,li c=0):first(a),second(b),third(c){}
};
pp s[400001],arr[100001],lazy[400001];
pp get_powers(li num)
{
    pp my_pair;
    li count=0;
    if(num%2==0)
    {
        while(num && num%2==0)
        {
            count++;
            num=num/2;
        }
    }
    my_pair.first=count;
    count=0;

    if(num%5==0)
    {
        while(num && num%5==0)
        {
            count++;
            num=num/5;
        }
    }
    my_pair.second=count;
    return my_pair;
}

void create_tree(li start,li end,li curr)
{
    if(start==end)
    {
        s[curr]=arr[start];
        return;
    }
    li mid=(start+end)/2;
    create_tree(start,mid,2*curr+1);
    create_tree(mid+1,end,2*curr+2);
    s[curr].first = s[2*curr+1].first + s[2*curr+2].first;
    s[curr].second = s[2*curr+1].second + s[2*curr+2].second;
    return;
}

pp get_query(li start,li end,li a,li b,li curr)
{
    if(start>end)
        return pp(0,0);

    if(lazy[curr].first || lazy[curr].second)
    {
        s[curr].first+=lazy[curr].first*(end-start+1);
        s[curr].second+=lazy[curr].second*(end-start+1);
        if(start!=end)
        {
            lazy[2*curr+1].first+=lazy[curr].first;
            lazy[2*curr+1].second+=lazy[curr].second;
            lazy[2*curr+2].first+=lazy[curr].first;
            lazy[2*curr+2].second+=lazy[curr].second;
        }
        lazy[curr].first=0;
        lazy[curr].second=0;
    }

    if(start>b || end <a)  // No overlap
        return pp(0,0);

    if(start>=a && end<=b)  // Total overlap
        return s[curr];

    li mid=(start+end)/2;  //Partial overlap
    pp l,r;
    l = get_query(start,mid,a,b,2*curr+1);
    r = get_query(mid+1,end,a,b,2*curr+2);
    l.first+=r.first;
    l.second+=r.second;
    return l;
}

void update_1(li start,li end,li a,li b,li curr,pp x)
{
    if(start > end)
        return;

    if(lazy[curr].first || lazy[curr].second)
    {
        s[curr].first+=lazy[curr].first*(end-start+1);
        s[curr].second+=lazy[curr].second*(end-start+1);
        if(start!=end)
        {
            lazy[2*curr+1].first+=lazy[curr].first;
            lazy[2*curr+1].second+=lazy[curr].second;
            lazy[2*curr+2].first+=lazy[curr].first;
            lazy[2*curr+2].second+=lazy[curr].second;
        }
        lazy[curr].first=0;
        lazy[curr].second=0;
    }

    if(start>b || end <a)  // No overlap
        return;

    if(start>=a && end<=b)
    {
        s[curr].first+=x.first*(end-start+1);
        s[curr].second+=x.second*(end-start+1);
        if(start!=end)
        {
            lazy[2*curr+1].first+=x.first;
            lazy[2*curr+1].second+=x.second;
            lazy[2*curr+2].first+=x.first;
            lazy[2*curr+2].second+=x.second;
        }
        return;
    }

    li mid=(start+end)/2;  //Partial overlap
    update_1(start,mid,a,b,2*curr+1,x);
    update_1(mid+1,end,a,b,2*curr+2,x);
    s[curr].first=s[2*curr+1].first + s[2*curr+2].first;
    s[curr].second = s[2*curr+1].second + s[2*curr+2].second;
    return;
}

void update_2(li start,li end,li a,li b,li curr,pp y)
{
    if(start > end)
        return;

    if(lazy[curr].first || lazy[curr].second)
    {
        s[curr].first+=lazy[curr].first*(end-start+1);
        s[curr].second+=lazy[curr].second*(end-start+1);
        if(start!=end)
        {
            lazy[2*curr+1].first+=lazy[curr].first;
            lazy[2*curr+1].second+=lazy[curr].second;
            lazy[2*curr+2].first+=lazy[curr].first;
            lazy[2*curr+2].second+=lazy[curr].second;
        }
        lazy[curr].first=0;
        lazy[curr].second=0;
    }



    if(start>b || end <a)  // No overlap
        return;

    if(start==end)
    {
        pp temp = get_powers((start-a+1));
        s[curr].first = temp.first+y.first;
        s[curr].second = temp.second+y.second;
        return;
    }

    li mid=(start+end)/2;  //Partial overlap
    update_2(start,mid,a,b,2*curr+1,y);
    update_2(mid+1,end,a,b,2*curr+2,y);
    s[curr].first=s[2*curr+1].first + s[2*curr+2].first;
    s[curr].second = s[2*curr+1].second + s[2*curr+2].second;
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        li n,m,val;
        scanf("%lld%lld",&n,&m);
        for(li i=0;i<n;i++)
        {
            scanf("%lld",&val);
            arr[i]=get_powers(val);
        }

        li count=0;
        create_tree(0,n-1,0);
        int cnt=1;
        while(cnt<n)cnt*=2;
        fill_n(lazy,2*cnt-1,pp(0,0));
        li x,l,r,y;
        while(m--)
        {
            scanf("%lld",&x);
            if(x==3)
            {
                scanf("%lld%lld",&l,&r);
                pp temp =get_query(0,n-1,l-1,r-1,0);
                count+=min(temp.first,temp.second);
            }
            else
            {
                scanf("%lld%lld%lld",&l,&r,&y);
                if(x==1)
                {
                    pp my_pair = get_powers(y);
                    if(my_pair.first || my_pair.second)
                    update_1(0,n-1,l-1,r-1,0,my_pair);
                }

                if(x==2)
                {
                    pp my_pair = get_powers(y);
                    update_2(0,n-1,l-1,r-1,0,my_pair);
                }

            }

        }
        printf("%lld\n",count);

    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define li long long int
void my_function(vector<li>&factors,li num)
{
    for(li i=1;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            if(num/i==i)
                factors.push_back(i);
            else
                factors.push_back(i), factors.push_back(num/i);
        }
    }
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        li n,m;
        scanf("%lld%lld",&n,&m);
        li arr[n+1];
        for(li i=1;i<=n;i++)
            scanf("%lld",&arr[i]);
        sort(arr+1,arr+n+1);
        li ans=0,min_val=LONG_LONG_MAX;
        vector<li>factors;
        my_function(factors,m);
        for(int i=0;i<factors.size();i++)
        {
            ans=0;
            if(factors[i] > n)
                continue;

            if(factors[i]==n)
            {
                min_val=0;
                break;
            }

            for(int j=1;j<=n-factors[i];j++)
                ans+=arr[j]*factors[i];
            if(ans < min_val)
                min_val=ans;
        }

        printf("%lld\n",min_val);
    }
    return 0;
}*/

//CHEF AND TWO STRINGS
/*
#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define MOD 1000000007
bool check(char*s,int index,int sum,int*freq,int len)
{
    if(freq[index])
        return false;
    if(index>=len || index<0)
        return false;

    if(index==(len-1))
        return sum==(len-1);

    freq[index]=1;
    if(s[index]=='1')
        return check(s,index-1,sum+1,freq,len) || check(s,index+1,sum+1,freq,len);
    if(s[index]=='2')
        return check(s,index-2,sum+1,freq,len) || check(s,index+2,sum+1,freq,len);

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        char a[100000], b[100000];
        scanf("%s%s", a, b);
        int k=0;
        while (a[k] != '\0')k++;

        li ans=0;
        int freq[k]={0};

        bool val1 = check(a,0,0,freq,k);
        fill_n(freq,k,0);
        bool val2 = check(b,0,0,freq,k);
        if(val1 && val2)
        {
            li same=0;
            for(int i=0;i<k;i++)
            {
                if(a[i]==b[i])
                    same++;
            }
            li val=1;
            if(same<k)same++;
            for(int i=1;i<=same;i++)
                val=((val%MOD)*2)%MOD;
            ans=val;
            if(a[k]!=b[k])
                ans=((ans%MOD)*2)%MOD;
        }

        else if(!val1 && !val2)
        {

        }



        printf("%lld\n",ans);
    }

    return 0;
}
*/


/*
#include <bits/stdc++.h>
using namespace std;
#define li  long long int
class pp
{
public:
    li first,second,third,fourth;
    pair<li,li> fifth;
    pp(){}
    pp(li a,li b,li c=0):first(a),second(b),third(c){}
};

pp s[400001],arr[100001],lazy[400001];
mapp<li,pp> my_map;
pp get_powers(li num)
{

    if(my_map.count(num))
        return my_map[num];

    li val = num;
    pp my_pair;
    li count=0;
    if(num%2==0)
    {
        while(num && num%2==0)
        {
            count++;
            num=num/2;
        }
    }
    my_pair.first=count;
    count=0;

    if(num%5==0)
    {
        while(num && num%5==0)
        {
            count++;
            num=num/5;
        }
    }

    my_pair.second=count;
    my_map[val]=my_pair;
    return my_pair;
}

void create_tree(li start,li end,li curr)
{
    if(start==end)
    {
        s[curr]=arr[start];
        return;
    }
    li mid=(start+end)/2;
    create_tree(start,mid,2*curr+1);
    create_tree(mid+1,end,2*curr+2);
    s[curr].first = s[2*curr+1].first + s[2*curr+2].first;
    s[curr].second = s[2*curr+1].second + s[2*curr+2].second;
    return;
}

pp get_query(li start,li end,li a,li b,li curr)
{
    if(start>end)
        return pp(0,0);

    if(lazy[curr].third)
    {
        pp temp = get_powers((end-start+1)*(2+end+start-(2*lazy[curr].fourth)));
        temp.first--;
        s[curr].first = s[curr].first + temp.first+lazy[curr].fifth.first;
        s[curr].second =s[curr].second+ temp.second+lazy[curr].fifth.second;
        if(start!=end)
        {
            li l=2*curr+1,r=2*curr+2;
            lazy[l].third=1;
            lazy[l].fourth=lazy[curr].fourth;
            lazy[l].fifth=lazy[curr].fifth;
            lazy[r].third=1;
            lazy[r].fourth=lazy[curr].fourth;
            lazy[r].fifth=lazy[curr].fifth;
        }

        lazy[curr].third=0;
    }

    if(lazy[curr].first || lazy[curr].second)
    {
        s[curr].first+=lazy[curr].first*(end-start+1);
        s[curr].second+=lazy[curr].second*(end-start+1);
        if(start!=end)
        {
            lazy[2*curr+1].first+=lazy[curr].first;
            lazy[2*curr+1].second+=lazy[curr].second;
            lazy[2*curr+2].first+=lazy[curr].first;
            lazy[2*curr+2].second+=lazy[curr].second;
        }
        lazy[curr].first=0;
        lazy[curr].second=0;
    }

    if(start>b || end <a)  // No overlap
        return pp(0,0);

    if(start>=a && end<=b)  // Total overlap
        return s[curr];

    li mid=(start+end)/2;  //Partial overlap
    pp l,r;
    l = get_query(start,mid,a,b,2*curr+1);
    r = get_query(mid+1,end,a,b,2*curr+2);
    l.first+=r.first;
    l.second+=r.second;
    return l;
}

void update_1(li start,li end,li a,li b,li curr,pp x)
{
    if(start > end)
        return;

    if(lazy[curr].third)
    {
        pp temp = get_powers((end-start+1)*(2+end+start-(2*lazy[curr].fourth)));
        temp.first--;
        s[curr].first = s[curr].first + temp.first+lazy[curr].fifth.first;
        s[curr].second =s[curr].second+ temp.second+lazy[curr].fifth.second;
        if(start!=end)
        {
            li l=2*curr+1,r=2*curr+2;
            lazy[l].third=1;
            lazy[l].fourth=lazy[curr].fourth;
            lazy[l].fifth=lazy[curr].fifth;
            lazy[r].third=1;
            lazy[r].fourth=lazy[curr].fourth;
            lazy[r].fifth=lazy[curr].fifth;
        }

        lazy[curr].third=0;
    }


    if(lazy[curr].first || lazy[curr].second)
    {
        s[curr].first+=lazy[curr].first*(end-start+1);
        s[curr].second+=lazy[curr].second*(end-start+1);
        if(start!=end)
        {
            lazy[2*curr+1].first+=lazy[curr].first;
            lazy[2*curr+1].second+=lazy[curr].second;
            lazy[2*curr+2].first+=lazy[curr].first;
            lazy[2*curr+2].second+=lazy[curr].second;
        }
        lazy[curr].first=0;
        lazy[curr].second=0;
    }

    if(start>b || end <a)  // No overlap
        return;

    if(start>=a && end<=b)
    {
        s[curr].first+=x.first*(end-start+1);
        s[curr].second+=x.second*(end-start+1);
        if(start!=end)
        {
            lazy[2*curr+1].first+=x.first;
            lazy[2*curr+1].second+=x.second;
            lazy[2*curr+2].first+=x.first;
            lazy[2*curr+2].second+=x.second;
        }
        return;
    }


    li mid=(start+end)/2;  //Partial overlap
    update_1(start,mid,a,b,2*curr+1,x);
    update_1(mid+1,end,a,b,2*curr+2,x);
    s[curr].first=s[2*curr+1].first + s[2*curr+2].first;
    s[curr].second = s[2*curr+1].second + s[2*curr+2].second;
    return;
}

void update_2(li start,li end,li a,li b,li curr,pp y)
{
    if(start > end)
        return;

    if(start>=a && end<=b)
    {
        s[curr].first=s[curr].second=0;
        pp temp = get_powers((end-start+1)*(2+end+start-(2*a)));
        temp.first--;
        s[curr].first = temp.first+y.first;
        s[curr].second = temp.second+y.second;
        if(start!=end)
        {
            li l=2*curr+1,r=2*curr+2;
            lazy[l].third=1;
            lazy[l].first=0;
            lazy[l].second=0;
            lazy[l].fourth=a;
            lazy[l].fifth.first=y.first;
            lazy[l].fifth.second=y.second;
            lazy[r].third=1;
            lazy[r].first=0;
            lazy[r].second=0;
            lazy[r].fourth=a;
            lazy[r].fifth.first=y.first;
            lazy[r].fifth.second=y.second;
        }
        lazy[curr].third=0;
        lazy[curr].first=0;
        lazy[curr].second=0;
        return;
    }


    if(lazy[curr].third)
    {
        pp temp = get_powers((end-start+1)*(2+end+start-(2*lazy[curr].fourth)));
        temp.first--;
        s[curr].first = s[curr].first + temp.first+lazy[curr].fifth.first;
        s[curr].second =s[curr].second+ temp.second+lazy[curr].fifth.second;
        if(start!=end)
        {
            li l=2*curr+1,r=2*curr+2;
            lazy[l].third=1;
            lazy[l].fourth=lazy[curr].fourth;
            lazy[l].fifth=lazy[curr].fifth;
            lazy[r].third=1;
            lazy[r].fourth=lazy[curr].fourth;
            lazy[r].fifth=lazy[curr].fifth;
        }

        lazy[curr].third=0;
    }


     if(lazy[curr].first || lazy[curr].second)
    {
        s[curr].first+=lazy[curr].first*(end-start+1);
        s[curr].second+=lazy[curr].second*(end-start+1);
        if(start!=end)
        {
            lazy[2*curr+1].first+=lazy[curr].first;
            lazy[2*curr+1].second+=lazy[curr].second;
            lazy[2*curr+2].first+=lazy[curr].first;
            lazy[2*curr+2].second+=lazy[curr].second;
        }
        lazy[curr].first=0;
        lazy[curr].second=0;
    }


    if(start>b || end <a)  // No overlap
        return;


    li mid=(start+end)/2;  //Partial overlap
    update_2(start,mid,a,b,2*curr+1,y);
    update_2(mid+1,end,a,b,2*curr+2,y);
    s[curr].first=s[2*curr+1].first + s[2*curr+2].first;
    s[curr].second = s[2*curr+1].second + s[2*curr+2].second;
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        li n,m,val;
        scanf("%lld%lld",&n,&m);
        for(li i=0;i<n;i++)
        {
            scanf("%lld",&val);
            arr[i]=get_powers(val);
        }

        li count=0;
        create_tree(0,n-1,0);
        int cnt=1;
        while(cnt<n)cnt*=2;
        fill_n(lazy,2*cnt-1,pp(0,0));
        li x,l,r,y;
        while(m--)
        {
            scanf("%lld",&x);
            if(x==3)
            {
                scanf("%lld%lld",&l,&r);
                pp temp =get_query(0,n-1,l-1,r-1,0);
                count+=min(temp.first,temp.second);
            }
            else
            {
                scanf("%lld%lld%lld",&l,&r,&y);
                if(x==1)
                {
                    pp my_pair = get_powers(y);
                    if(my_pair.first || my_pair.second)
                        update_1(0,n-1,l-1,r-1,0,my_pair);
                }

                if(x==2)
                {
                    pp my_pair = get_powers(y);
                    update_2(0,n-1,l-1,r-1,0,my_pair);
                }

            }
        }
        printf("%lld\n",count);
    }
    return 0;
}

*/

//CHEF AND SOLUTIONS
/*
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>my_map;
int main()
{
    int n,p,k;
    scanf("%d%d%d",&n,&k,&p);
    int arr[n+1],temp[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]),temp[i]=arr[i];


    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++)
    {
        if(my_map.count(arr[i]))
            continue;
        my_map[arr[i]]=i;
    }

    vector<vector<int> > v;
    v.resize(100001);
    int flag=0;
    for(int i=1;i<=n-1;i++)
    {
        if(i>1)
        {
            if(arr[i] - arr[i-1] <=k)
            {
                if(!flag)
                    v[i].push_back(i-1),flag=1;
                else v[i].push_back(v[i-1][0]);
                continue;
            }
        }

        flag=0;
        for (int j = i+1; j <=n ; ++j) {
            if(arr[j]-arr[j-1]<=k)
                v[i].push_back(arr[j]);
            else break;
        }
    }


    int x,y;
    for(int i=1;i<=p;i++)
    {
        scanf("%d%d",&x,&y);
        if(x==y)
        {
            printf("Yes\n");
            continue;
        }

        if(x>y)
            swap(x,y);
        int index = my_map[temp[x]];
        if(v[index].size()==1 && v[index][0] < index)
        {
            auto it1 = v[v[index][0]].begin();
            auto it2 = v[v[index][0]].end();
            if(binary_search(it1,it2,temp[y]))printf("Yes\n");
            else printf("No\n");
        }
        else
        {
            auto it1 = v[index].begin();
            auto it2 = v[index].end();
            if(binary_search(it1,it2,temp[y]))printf("Yes\n");
            else printf("No\n");
        }


    }

    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define MOD 1000000007
bool check(char*s,int index,int sum,int*freq,int len)
{
    if(freq[index])
        return false;
    if(index>=len || index<0)
        return false;

    if(index==(len-1))
        return sum==(len-1);

    freq[index]=1;
    if(s[index]=='1')
        return check(s,index-1,sum+1,freq,len) || check(s,index+1,sum+1,freq,len);
    if(s[index]=='2')
        return check(s,index-2,sum+1,freq,len) || check(s,index+2,sum+1,freq,len);

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        char a[100000], b[100000];

    }

    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
int primes[100001];
vector<int>v;
vector<vector<int>>sol;
void sieve()
{
    for(int i=2;i<=sqrt(100000);i++)
    {
        if(!primes[i])
        {
            for(int j=2;i*j<=100000;j++)
                primes[i*j]++;
        }
    }

    for(int i=2;i<=100000;i++)
    {
        if(primes[i]==0 || primes[i]==1)
            sol[1].push_back(i);
        else if(primes[i]<=5)
            sol[primes[i]].push_back(i);
    }
    return;
}

int main()
{
    sol.resize(6);
    fill_n(primes,100001,0);
    sieve();
    int t;
    scanf("%d",&t);
   while(t--)
    {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        if(a==b)
        {
           if(primes[a]==k)
               printf("1\n");
            else printf("0\n");
        }
        else
        printf("%d\n",upper_bound(sol[k].begin(),sol[k].end(),b)-lower_bound(sol[k].begin(),sol[k].end(),a));
    }
    return  0;
}
*/


/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    scanf("%d",&t);
    ll a,b,c,d;
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(b<a || d<c)
        {
            printf("0\n");
            continue;
        }

        ll cnt=0;
        ll end;
        if(b<d)end=b;
        else end=d-1;
        if(a<c)
        {
            cnt+=(c-a)*(d-c+1);
            ll val=(d-c);
            for(ll k=c;k<=end;k++)
                cnt+=val,val--;
        }
        else
        {
            ll val=(d-a);
            for(ll k=a;k<=end;k++)
            {
                if(val<0)
                    break;
                cnt+=val,val--;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
bool compare(int a,int b)
{
    return a>b;
}
int main()
{
    int t;
    scanf("%d",&t);
    int n,val;
    while(t--)
    {
        unordered_map<int,vector<int> > my_map;
        int ans=0,dif=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&val),my_map[val].push_back(val);
        int arr[n+1],index=0;
        fill_n(arr,n+1,0);
        auto it= my_map.begin();
        while(it!=my_map.end())
        {
            if(it->second.size()==1)dif++;
            else arr[index]=it->second.size(),index++;
            it++;
        }
        sort(arr,arr+index,compare);
        int i;
        val=arr[0];
        for( i=1;i<index;i++)
        {
            if(val > arr[i])val-=arr[i],ans+=arr[i],arr[i]=0;
            else if(val == arr[i])ans+=arr[i],val=arr[i+1];
            else ans+=val,arr[i]-=val,val=arr[i];
        }


            if(val >= dif)ans+=val;
            else ans+=val,dif-=val,ans+=dif/2+dif%2;
        printf("%d\n",ans);
    }
    return 0;
}

*/



/*
int main()
{
    ll t;
    r1(t);
    while(t--)
    {
        ll n,m;
        r2(n,m);
        ll ans=-1,sum=0;
        ll cost[n+1];
        for(int i=1;i<=n;i++)r1(cost[i]),sum+=cost[i];
        ans=sum;
        ll values[m+1],helper[n+1];
        vector<unordered_set> v;
        v.resize(m+1);
        ll p,q,val;
        for(int i=1;i<=m;i++)
        {
             r2(p,q);
             values[i]=p;
            helper[p]=i;
            unordered_set<ll>temp;
            while(q--)r1(val),temp.insert(val);
            v[i] = temp;
        }
        sort(values+1,values+m+1);
        unordered_set<ll>complete;
        for(ll i=1;i<=n;i++)complete.insert(i);

        for(int i=1;i<=m;i++)
        {
            unordered_set<ll>temp;
            temp = v[helper[values[i]]];
            sum=0;

        }

    }
    return 0;
}

*/

// REIGN2
// Reign 2
//
// Author: Kanstantsin Sokal
// Complexity: O(N ^ 2) per testcase
//
// Expected verdict: AC

/*
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5005;
const long long INF = (long long)1e18;

int n;
pair<int, int> castles[MAX_N];
long long dp[MAX_N][MAX_N];

bool castles_comparator(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

void update(long long &to, long long from) {
    to = max(from, to);
}

void solve_one_case() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &castles[i].first);
    }


    for (int i = 1; i <= n; i++) {
        scanf("%d", &castles[i].second);
    }


    sort(castles + 1, castles + n + 1, castles_comparator);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -INF;
        }
    }

    dp[1][1] =
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {

            update(dp[i + 1][j], dp[i][j]);
            update(dp[i + 1][j + 1], dp[i][j]
                                     + castles[i + 1].second * 1ll * j
                                     + castles[i + 1].first);
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            if(dp[i][j]==-INF)cout<<-1<<" ";
        else
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    printf("\n");
}

int main() {
    int cases; scanf("%d", &cases);
    for (int i = 0; i < cases; i++) {
        solve_one_case();
    }
}
 */


/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define rf3(x,y,z) scanf("%Lf%Lf%Lf",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000

using namespace std;
void create_prefix()
{
    prefix.resize(pattern.size(),0);
    //value at any index stores length of the longest prefix which is also a suffix
    int j=0;
    for(int i=1;i<pattern.size();)
    {
        if(pattern[i]==pattern[j])
        {
            prefix[i] = j+1;
            i++;j++;
        }
        else
        {
            if(j==0)
            {
                prefix[i]=0;
                i++;
            }


            else
            {
                j=prefix[j-1];
            }
        }
    }

}
ll p2(ll n)
{
    if(n==0)return 1ll;
    ll temp = p2(n/2);
    if(n%2)return (2ll*temp*temp)%MOD;
    else return (temp*temp)%MOD;
}
int main()
{
    ll t;
    r1(t);
    while(t--)
    {
        cin>>s>>f;

        ll cnt=0;
        ll i=0,j=0;
        while(i<s.size())
        {
            if(s[i]==f[j])j++;
            else j=0;
            if(j==f.size())j=0,cnt++;
            i++;
        }
        pn(p2(cnt)-1);
    }
    return 0;



#include<bits/stdc++.h>
using namespace std;
string text,pattern;
vector<int> prefix;

void create_prefix()
{
    prefix.resize(pattern.size(),0);
    //value at any index stores length of the longest prefix which is also a suffix
    int j=0;
    for(int i=1;i<pattern.size();)
    {
        if(pattern[i]==pattern[j])
        {
            prefix[i] = j+1;
            i++;j++;
        }
        else
        {
            if(j==0)
            {
                prefix[i]=0;
                i++;
            }


            else
            {
                j=prefix[j-1];
            }
        }
    }

}

int get_index()
{
    int i=0;
    int j=0;
    while(i<text.size() && j<pattern.size())
    {
        if(text[i] == pattern[j])
        {
            i++;j++;
        }
        else
        {
            if(j==0)
                i++;
            else
            {
                j = prefix[j-1];
            }
        }
    }

    if(j==pattern.size())
        return i-pattern.size();

    else
        return -1;
}


int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        //cin>>text;
        cin>>pattern;
        create_prefix();
        for(int i=0;i<prefix.size();i++)cout<<prefix[i];
        cout<<endl;
    }

    return 0;
}
*/


/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define rf3(x,y,z) scanf("%Lf%Lf%Lf",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
using namespace std;
int main()
{

    ll n,k;
    r2(n,k);
    ll arr[n+1];
    for(int i=1;i<=n;i++)r1(arr[i]);
    ll cnt=0;
    for(ll i=1;i<=n;)
    {
        ll j=i,pos=-1;
        while(j<i+k && j<=n){
            if(arr[j]==1)pos=j;
            j++;
        }
        if(arr[j]==1)i=j+1,cnt++;
        else if(pos==-1){
            cout<<-1;
            break;
        }
        else i=pos+1,cnt++;
    }

    if(cnt<=k)cout<<cnt;
    else cout<<-1;
    return 0;
}
*/
/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
ll arr[100001];
ll n,m;
int main()
{

    ll t;
    r1(t);
    while(t--)
    {
        vector<vector<ll>>v;
        r2(n,m);
        for(ll i=0;i<n;i++)r1(arr[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                vector<ll>temp;
                for(int k=i;k<=j;k++)
                    temp.push_back(arr[k]);
                v.push_back(temp);
            }
        }

        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl<<v.size()<<endl;

        ll q;
        while(m--){
            r1(q);
            ll val=LONG_LONG_MIN;
            for(ll c=0;c<v[v.size()-q].size();c++)val=max(val,v[v.size()-q][c]);
            pn(val);
        }

    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3+5;
bool vis[MAXN];
int ar[MAXN];
int pre[MAXN];
vector<int> v;
int dp[MAXN];
void sieve() {
    v.push_back(2);
    for(int i=3;i<MAXN;i+=2) if(!vis[i]) {
            v.push_back(i);
            for(int j=i*i;j<MAXN;j+=2*i) vis[j]=true;
        }
}
int main() {
    // freopen("TASK.in","r",stdin);
    // freopen("TASK.out","w",stdout);
    int n;
    cin>>n;
    assert(n<=5000);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ar[i]);
        assert(ar[i]<=100000);
        pre[i]=pre[i-1]+ar[i];
    }
    sieve();
    dp[0]=dp[1]=0;
    for(int i=2;i<=n;i++) {
        dp[i]=dp[i-1];
        for(int j=0;j<(int)v.size() and v[j]<=i;j++) {
            int p=i-v[j]-1;
            if(p==-1) dp[i]=max(dp[i],pre[i]);
            else dp[i]=max(dp[i],dp[p]+pre[i]-pre[p+1]);
        }
    }

    for(int i=0;i<=n;i++)cout<<pre[i]<<" ";
    cout<<endl;
    for(int i=0;i<=n;i++)cout<<dp[i]<<" ";

    //cout<<dp[n]<<endl;
    return 0;
}
 */


/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
int main()
{
    ll t;
    //r1(t);
    t=1000;
    ld q=0;
    while(t--)
    {
        ld n;
        //rf(n);
        n=q;
        cout<<q<<" ";
        q++;
        if(n==0){
        printf("0");
        continiue;
        }
        if(n==1){
            printf("INFINITY\n");
            continue;
        }
        if(nn==2 || n==3){
            n--;
            pn((ll)n);
            continue;
        }
        ld ans=0;
        ld it=1;
        ld x,y,z;
        ld k = (n+1)/2;
        x=n,y=ceil(k);
        while(1)
        {
            if(x==1 || y==1){
                break;
            }
            if(x>=y)
            ans=ans+x-y+1.0;
            it++;
            z= pow(it,(ld)-1);
            x=floor(pow(n,z));
            y=ceil(pow(k,z));
            //cout<<x<<" "<<y<<" "<<ans<<endl;
        }
        pn((ll)ans);
    }
    return 0;
}

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000

ll n;
int main() {
    ll t;
    r1(t);
    while (t--) {
        r1(n);
        ll arr[n+1];
        ll dp[n+1];
        for (int i = 0; i < n; i++){
            r1(arr[i]);
            if(arr[i]==1)dp[i]=0;
            else dp[i]=1;
        }
        for(int i=1;i<=n-1;i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                if(dp[i]==0)continue;
                if(__gcd(arr[i],arr[j])>1)dp[i]=max(dp[i],1ll+dp[j]);
            }

        }
        ll ans=-1;
        for(int i=0;i<=n-1;i++)ans=max(ans,dp[i]);
        pn(ans);
    }
    return 0;
}*/


/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
int main()
{
    ll t;
    r1(t);
    while(t--)
    {
        ll n;
        r1(n);
        cin.get();
        char ch;
        vector<ll >v;
        for(ll i=1;i<=n;i++){
            rc(ch);
            if(ch=='1')v.push_back(i);
        }

        ll arr[n+1];
        for(int i=1;i<=n;i++)r1(arr[i]);

        ll sum=0;
        if(v.size()==1){
            if(v[0]!=1){
                sum=sum+arr[v[0]]-arr[1]+arr[n]-arr[v[0]];
            }
            else sum+=arr[n]-arr[1];
            pn(sum);
        }


        else
        {

            if(v[0]!=1){
                sum=sum+arr[v[0]]-arr[1];
            }
            for(ll i=0;i<(ll)v.size()-1;i++){
                //cout<<v[i]<<  " ";
                ll k=v[i]+1;
                while(k<=v[i+1]-1){
                    if(arr[k] - arr[v[i]] > arr[v[i+1]]-arr[k])break;
                    k++;
                }
                //cout<<k<< " ";
                sum=sum+arr[v[i+1]]-arr[k]+arr[k-1]-arr[v[i]];
                //cout<<sum<<" "<<endl;
            }
            sum=sum+arr[n]-arr[v[v.size()-1]];
            pn(sum);
        }


    }
}

*/

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld  double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000

int main()
{

    vector<pp>v;
    v.resize(1000);
    ll t;
    //r1(t);
    t=1000;
    ld q=0;
    while(t--)
    {
        ld n;
        //rf(n);
        n=q;
        q++;
        if(n==0){
            //printf("0");
            continue;
        }
        if(n==1){
            //printf("INFINITY\n");
            continue;
        }
        if(n==2 || n==3){
            n--;
           // pn((ll)n);
            continue;
        }
        ld ans=0;
        ld it=1;
        ld x,y,z;
        ld k = (n+1)/2;
        x=n,y=ceil(k);
        while(1)
        {

            if(x==2 && y==2) {
                ans++;
                break;
            }
            if(x>=y)
                ans=ans+x-y+1.0;
            it++;
            z= pow(it,(ld)-1);
            //printf("%0.100Lf\n",pow(k,z));
            x=floor(pow(n,z+0.000000000000001));
            y=ceil(pow(k,z-0.000000000000001));
            //cout<<x<<" "<<y<<" "<<ans<<endl;
        }
        v[n].first=(ll)ans;
    }
    q=0;
    cout<<"sf";
    long long int Test, N, r,  A, B;
    Test=1000;
    for (long long int i = 0; i < Test ; ++i) {

        N=q;
        q++;
        if(N == 0)
        {
            printf("%d\n", 0);
            continue;
        }
        if(N == 1)
        {
            printf("INFINITY\n");
            continue;
        }
        if(N == 2)
        {
            printf("%d\n",1);
            continue;
        }
        if(N == 3)
        {
            printf("%d\n", 2);
            continue;
        }
        //      unordered_set<long long int> :: iterator it;
        long long int ans = 0;
        A = N;
        B = N;
        double power = 1.0;
        while(B > 1)
        {

            double AA = pow(N,(1.0 / power) + 0.0000000000000001);
            //printf("%.35f\n", AA);
            A = AA;



            //cout<<"A is "<<A<<endl;


            if(A <= 1)
            {
                break;
            }
            double BB = pow((double)((double)(N * 1.0)/(2.0)), (double)(1.0 / power) + 0.0000000000000001);
            //cout<<"BB is "<<BB<<endl;
            B = BB;

            //cout<<"B is "<<B<<endl
            ans += (A - B);
            power = power + 1;
        }
        //   cout<<"Answer is "<<endl;
        v[N].second=(ll)ans;

    }

    for(int i=0;i<v.size();i++){

       if(v[i].first!=v[i].second)cout<<i<< " ";
    }
    return 0;
}

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
int main()
{
    ll t;
    r1(t);
    while(t--)
    {
        ld n;
        rf(n);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        if(n==1){
            printf("INFINITY\n");
            continue;
        }
        if(n==2 || n==3){
            n--;
            pn((ll)n);
            continue;
        }
        ld ans=0;
        ld it=1;
        ld x,y,z;
        ld k = (n+1)/2;
        x=n,y=ceil(k);
        while(1)
        {
            if(x==1 || y==1){
                break;
            }
            if(x>=y)
                ans=ans+x-y+1.0;
            it++;
            ll temp = z*1000000;
            z=temp/1000000.000000;
            x=floor(pow(n,z));
            y=ceil(pow(k,z));
            cout<<pow(n,z)<<" "<<pow(k,z)<<endl;
            cout<<x<<" "<<y<<endl;
        }
        pn((ll)ans);
    }
    return 0;
}*/

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
bool comp(pp a,pp b){
    return (a.first >b.first);
}
int main()
{
    ll t;
    r1(t);
    pp arr[100001];
    ll aux[100001];
    while(t--)
    {
        ll n,m;
        r2(n,m);
        for(int i=0;i<n;i++)r1(arr[i].first);
        for(int i=0;i<n;i++){
            ll a=0,b=0;
                ll k=i-1;
                while(k>=0){
                    if(arr[k].first>=arr[i].first)break;
                    k--;a++;
                }
                 k=i+1;
                while(k<=n-1){
                    if(arr[k].first>arr[i].first)break;
                    k++;b++;
                }
            arr[i].second=a*b+a+b+1;
        }
        sort(arr,arr+n,comp);
        aux[0]=arr[0].second;
        for(ll i=1;i<=n-1;i++)arr[i].second+=arr[i-1].second,aux[i]=arr[i].second;
        for(int i=0;i<n;i++)cout<<aux[i]<<" ";
        while(m--)
        {
            ll q;
            r1(q);
            auto it=lower_bound(aux,aux+n,q);
            pn(arr[it-aux].first);
        }
    }
    return 0;
}
*/
/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
ll arr[100000], s[400000];
void create_tree(ll curr,ll start,ll end){
    if(start > end)return;
    if(start==end){
        s[curr]=arr[start];
        return;
    }
    ll mid=(start+end)/2;
    create_tree(2*curr+1,start,mid);
    create_tree(2*curr+2,mid+1,end);
    s[curr]=min(s[2*curr+1],s[2*curr+2]);
    return;
}

ll get(ll curr,ll start,ll end,ll a,ll b)
{
    if(start > end)return LONG_LONG_MAX;
    if(start > b || end<a)return LONG_LONG_MAX;
    if(start>=a && end<=b)return s[curr];
    ll mid=(start+end)/2;
    return min(get(2*curr+1,start,mid,a,b),get(2*curr+2,mid+1,end,a,b));
}

void  update(ll curr,ll start,ll end,ll index , ll val)
{
    if(start>end)return;
    if(start==end){
        arr[index]=val;
        s[curr]=val;
        return;
    }
    ll mid=(start+end)/2;
    if(start<=index && mid>=index)
    update(2*curr+1,start,mid,index,val);
    else
    update(2*curr+2,mid+1,end,index,val);
    s[curr] = min(s[2*curr+1],s[2*curr+2]);
    return;

}
int main()
{
    ll n,q;
    r2(n,q);
    for(int i=0;i<n;i++)r1(arr[i]);
    create_tree(0,0,n-1);
    char ch;
    ll a,b;
    while(q--){
        cin>>ch>>a>>b;
        if(ch=='q')a--,b--,pn(get(0,0,n-1,a,b));
        else a--,update(0,0,n-1,a,b);
    }
    return 0;
}

 */

/*
#include<bits/stdc++.h>

using namespace std;

string st;
long long pw[1<<20];
unordered_set <long long> S;
long long s[1<<20];

int check(int span)
{
    S.clear();

    for (int i=0;i<=st.size()-span;i++)
    {
        long long Q=s[i+span]-s[i];
        Q*=pw[1000000-i];
        //cout<<Q<<" ";
        if (S.find(Q)!=S.end())
            return true;
        S.insert(Q);
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
//cin.tie(0);

    cin>>st;
    pw[0]=1;
    for (int i=1;i<=1000000;i++)
        pw[i]=pw[i-1]*173;

    for (int i=1;i<=st.size();i++)
        s[i]=s[i-1]+st[i-1]*pw[i-1];

    for(int i=0;i<=st.size();i++)cout<<s[i]<<" ";
    int l,r;
    l=0;
    r=(int)st.size();
    while (l<r)
    {
        int mid=l+r+1;
        mid/=2;
        if (check(mid))
            l=mid;
        else
            r=mid-1;
    }

    cout<<l<<endl;
    return 0;
    }
    */

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
vector<std::list<ll> >adjlist;
int main()
{
    ll n,m;
    r2(n,m);
    adjlist.resize(n+1);
    unordered_set<ll>my_set;
    ll u,v;
    for(int i=0;i<m;i++){
        r2(u,v);
        my_set.insert(u),my_set.insert(v);
        adjlist[u].push_back(v),adjlist[v].push_back(u);
    }

    ll x;
    r1(x);
    V temp;
    auto it = adjlist[x].begin();
    while(it!=adjlist[x].end())
    {
        temp.push_back(*it);
        it++;
    }
    for(int i=0;i<temp.size();i++){
        adjlist[temp[i]].remove(x);
    }


    queue<ll>Q;
    vector<bool>visited((ull)n+1,false);
    ll cnt=0;
    for(ll i=0;i<=n;i++){
        if(visited[i] || i==x || my_set.count(i)==0)
            continue;
        Q.push(i);
        visited[i] = true;
        while(!Q.empty())
        {
            ll curr = Q.front();
            Q.pop();
            it= adjlist[curr].begin();
            while(it!=adjlist[curr].end())
            {
                if(visited[*it]!=true)Q.push(*it),visited[*it]=true;
                it++;
            }
        }
        cnt++;
        if(cnt>1)
        {
            printf("Not Connected");
            return 0;
        }
    }
    printf("Connected");

    return 0;
}


*/


/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
#define M 1000000000
vector<std::list<pp> >v;
ll n,m;
int main()
{
    cin>>n>>m;
    v.resize(n+1);
    unordered_map<string , ll>my_map;
    string s,t;
    for(ll i=1;i<=n;i++)cin>>s,my_map[s]=i;

    ll w;
    ll dp[n+1][n+1];
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=INT32_MAX;
    ll a,b;
    for(int i=1;i<=m;i++){
        cin>>s>>t;
        cin>>w;
        a=my_map[s],b=my_map[t];
        //cout<<a<<" "<<b<<" "<<w<<endl;
        v[a].push_back(pp(b,w)),v[b].push_back(pp(a,w));
        dp[a][b]=w,dp[b][a]=w;
    }

    /*for(int i=0;i<=n;i++){

            for (int j = 0; j <= n; j++)cout << dp[i][j] << " ";
            cout << endl;
        }


    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    ll q;
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>s;
        cin>>t;
        a=my_map[s],b=my_map[t];
        cout<<dp[a][b]<<endl;
    }
    return 0;
}
*/
/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
int main()
{
    ll n,m;
    r2(n,m);
    ll a,b,c;
    vector<std::list<pp>>v;
    v.resize((ull)n+1);
    for(int i=0;i<n;i++){
        r3(a,b,c);
        v[a].push_back(pp(b,c)),v[b].push_back(pp(a,c));
    }

    vector<ll>dist(n+1,LONG_LONG_MAX);
    vector<bool>visited(n+1,false);
    dist[1]=0;
    set<pp>my_set;
    my_set.insert(pp(0,1));
    while(!my_set.empty())
    {
        pp curr = *my_set.begin();
        my_set.erase(curr);
        if(visited[curr.second])continue;
        visited[curr.second]=true;
        auto it  = v[curr.second].begin();
        while(it!=v[curr.second].end())
        {
            if(dist[it->first] > dist[curr.second]+it->second)
            {
                if(dist[it->first]!=LONG_LONG_MAX)my_set.erase(my_set.find(pp(dist[it->first],it->first)));
                dist[it->first]=dist[curr.second]+it->second;
                my_set.insert(pp(dist[it->first],it->first));
            }
            it++;
        }

    }

    for(int i=2;i<=n;i++)
    {
        if(dist[i]==LONG_LONG_MAX)printf("1000000000 ");
        else p_(dist[i]);
    }
    return 0;
}
*/

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
ll n,m,q;
ll mat[1001][1001],dp[1001][1001],visited[1001][1001];
ll func(ll cx,ll cy)
{
    if(dp[cx][cy]!=-1)
        return dp[cx][cy];
    visited[cx][cy]=1;
    ll delta[8][2] = {{2,1},{1,2},{2,-1},{-1,2},{-2,1},{1,-2},{-2,-1},{-1,-2}};
    ll ans=0,temp;
    for(int i=0;i<8;i++){
        ll nx = cx + delta[i][0];
        ll ny  = cy + delta[i][1];
        if(nx>=1 && nx<=n && ny>=1 && ny<=m && mat[nx][ny]==1 && visited[nx][ny]==0)
        {
            temp = 2*func(nx,ny);
            ans+=temp;
        }
    }
    if(!ans)ans++;
    dp[cx][cy]=ans%MOD;
    return ans%MOD;

}
int main()
{

    ll t;
    r1(t);
    while(t--)
    {
        r3(n,m,q);
        for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)mat[i][j]=0,dp[i][j]=-1,visited[i][j]=0;
        ll x,y;
        for(int i=1;i<=q;i++){
            r2(x,y);
            mat[x][y]=1;
        }
        ll ans=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(visited[i][j]==0 && mat[i][j]==1)
                {
                    ans+=func(i,j);
                    ans%=MOD;
                    //cout<<ans<<endl;
                }
            }
        }
        //cout<<endl;
        pn(ans);
    }
    return 0;
}
 */
/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
ll n,x,m;
ll fact[100001],arr[100001];
ll p,q;
void euclid(ll a,ll b)
{
    if(b==0){
        p=1,q=0;
        return ;
    }
    euclid(b,a%b);
    ll temp = p;
    p=q;
    q=temp-(a/b)*q;
    return;
}
ll inv(ll n){

    euclid(n,MOD);
    return (p%MOD+MOD)%MOD;
}
void func(V &temp)
{
    ll cnt=1;
    ll val;
    temp.push_back(1);
    while(cnt<=n-1)
    {
        ll s = min(cnt,m-cnt);
        ll k=1,j=m;
        val=1;
        while(k<=s){
            val=((val%MOD)*(j%MOD))%MOD,j--,k++;
        }
        val*=inv(fact[s]);
        val%=MOD;
        temp.push_back(val);
        cnt++;m++;
    }
    for(int i=0;i<temp.size();i++)cout<<temp[i]<<" ";
    cout<<endl;
}
int main()
{
    cout<<inv(1);
    ll t;
    r1(t);
    fact[0]=fact[1]=1;
    for(ll i=2;i<=100000;i++)fact[i]=(i*fact[i-1])%MOD;
    while(t--)
    {
        r3(n,x,m);
        for(int i=1;i<=n;i++)r1(arr[i]);
        vector<ll>temp;
        func(temp);
        ll sum=0;
        for(int i=0;i<temp.size();i++){
            if(arr[x] >MOD)arr[x]%=MOD;
            sum+=temp[i]*arr[x];
            if(sum>MOD)sum%=MOD;
            x--;
        }
        pn(sum);
    }
    return 0;
}
*/

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
ll cnt=0;
void func(int index)
{
    cnt++;
    if(index==20)return;
    func(index+1);
    func(index+1);
}
ll n,m;
vector<list<ll>>adjlist,temp;
vector<V>sol;
stack<ll>s,stk;
void util(ll curr,vector<bool>&visited){
    visited[curr]=true;
    rep(adjlist[curr]){
        if(visited[*it]==false)util(*it,visited);
    }
    s.push(curr);
    return;
}
void util2(ll curr,vector<bool>&visited){
    visited[curr]=true;
    rep(adjlist[curr]){
        if(visited[*it]==false)util2(*it,visited);
    }
    stk.push(curr);
    return;
}
void func()
 {
    vector<bool>visited((ull)n+1,0);
    for(int i=1;i<=n;i++){
        if(visited[i]==false)util(i,visited);
    }
    return;
}
void kosaraju()
{
    vector<bool>visited((ull)n+1,0);
    while(!s.empty())
    {
        ll curr = s.top();
        s.pop();
        if(visited[curr]==false){
            util2(curr,visited);
            vector<ll>v;
            while(!stk.empty()){
                ll val =stk.top();
                v.push_back(val);
                stk.pop();
            }
            sol.push_back(v);
        }
    }
}
int main()
{

    func(0);
    cout<<cnt;
    r2(n,m);
    ll a,b;
    adjlist.sz(n+1);
    temp.sz(n+1);
    ll out_deg[n+1],in_deg[n+1];
    fill_n(out_deg,n+1,0);
    fill_n(in_deg,n+1,0);
    for(int i=1;i<=m;i++){
        r2(a,b);
        adjlist[a].push_back(b);
        in_deg[b]++;
        out_deg[a]++;
    }
    func();

    unordered_map<ll,ll>my_map;
    for(int i=1;i<=n;i++){
        //my_map[i] = out_deg[i]-in_deg[i];
        cout<<i<<" "<<out_deg[i]<<" "<<in_deg[i]<<endl;
    }



    //while(!s.empty())cout<<s.top()<<" ",s.pop();

    for(ll i=1;i<=n;i++){
        if(adjlist[i].size())
        rep(adjlist[i])temp[*it].push_back(i);
    }
    adjlist = temp;
    //kosaraju();


    return 0;
}

*/

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define debug cout<<"hello ";
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
class node
{
public:
    ll data;
    ll rank;
    node * parent;
    node(ll val){
        data = val;
        rank=0;
        parent = this;
    }
};

node* my_map[100001];

void make_set(ll data){
    node * curr = new node(data);
    my_map[data] = curr;
}

node* find_set(node* curr){
    if(curr->parent== curr)return curr;
    curr->parent = find_set(curr->parent);
    return curr->parent;
}


ll find_set(ll data){
    return find_set(my_map[data])->data;
}

void Union(ll data1 , ll data2){

    node*curr1 = my_map[data1];
    node*curr2 = my_map[data2];

    node * parent1 = find_set(curr1->parent);
    node * parent2 = find_set(curr2->parent);

    if(parent1->data == parent2->data)return;
    if(parent1->rank >= parent2->rank){
        if(parent1->rank == parent2->rank)parent1->rank++;
        parent2->parent = parent1;
    }
    else parent1->parent = parent2;
    return;
}
int main()
{
    ll n,m;
    r2(n,m);
    for(int i=1;i<=n;i++)make_set(i);

    ll a,b;
    ll x,y;
    for(int i=1;i<=m;i++){
        r2(a,b);
        x=a,y=b;
        while(y>x){
            Union(x,y);
            y--,x++;
        }
    }
    ll arr[1001];
    fill_n(arr,1001,0);

    for(int i=1;i<=n;i++){
        ll val  = find_set(i);
        arr[val]=1;
    }
    ll cnt=1;
    for(int i=1;i<=n;i++){
       if(arr[i])cnt*=10;
        if(cnt>MOD)cnt%=MOD;
    }
    pn(cnt);
    return 0;
}
*/


/*
#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a[4][100001],dp[4][100001];
int main()
{
    cin>>n;
    for(i=0;i<3;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    dp[2][n-1]=a[2][n-1];
    dp[1][n-1]=dp[2][n-1]+a[1][n-1];
    dp[0][n-1]=dp[1][n-1]+a[0][n-1];
    for(i=n-2;i>=0;i--)
    {
        dp[0][i]=a[0][i]+max(max(max(dp[0][i+1],a[1][i]+dp[1][i+1]),a[1][i]+a[2][i]+dp[2][i+1]),a[0][i+1]+a[1][i+1]+a[1][i]+a[2][i]+a[2][i+1]+dp[2][i+2]);
        dp[1][i]=a[1][i]+max(max(dp[1][i+1],a[0][i]+dp[0][i+1]),a[2][i]+dp[2][i+1]);
        dp[2][i]=a[2][i]+max(max(max(dp[2][i+1],a[1][i]+dp[1][i+1]),a[1][i]+a[0][i]+dp[0][i+1]),a[2][i+1]+a[1][i+1]+a[1][i]+a[0][i]+a[0][i+1]+dp[0][i+2]);
    }
    cout<<dp[0][0];
}

*/



/*
int main()
{
    clock_t s,e;
    s=clock();
    for(int i=1;i<=50;i++){
        get_ncr(1,500000);
        power(1000000);
    }
    e=clock();

    cout<<(e-s)/1000000.00;
    return 0;
}

*/

/*
#include <iostream>
#include <string.h>
using namespace std;
#define mod 1000000007
string s;
int arr[26],dp[1005],dp2[1005];
int main()
{
    int n,l=0;
    cin >> n >> s;
    for (int i=0;i<26;i++)
        cin >> arr[i];
    dp[0]=1;
    dp2[0]=0;
    for (int i=1;i<=n;i++)
    {
        int f=0;
        dp2[i]=n;
        for (int x=i-1;x>=0;x--)
        {
            f=max(f,i-arr[s[x]-'a']);
            if (f>x)
                continue;
            dp[i]=(dp[i]+dp[x])%mod;
            dp2[i]=min(dp2[i],1+dp2[x]);
            l=max(l,i-x);
        }
    }
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)cout<<dp2[i]<<" ";
    cout<<endl;
    cout << dp[n] << endl << l << endl << dp2[n] << endl;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long  double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n+1)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define debug cout<<"hello"<<endl;
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000

ll  tonum(const string &s) { stringstream ss; ss << s; ll  x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}


bool comp(pp a,pp b){
    if(a.first < b.first)return true;
    else if(a.first > b.first)return true;
    return a.second < b.second;
}

bool comp2(string a,string b){
    return a+b<b+a;
}

//priority_queue<pp,vector<pp>,greater<pp>>pq;  for min priority queue
// priority_queue<pp>  default max priority queue

int main()
{

    int n,k,x;
    cin>>n>>k>>x;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    if(k<=7){
        for(int i=0;i<k;i++){
            sort(arr,arr+n);
            for(int j=0;j<n;j+=2)arr[j]=arr[j]^x;
        }
        sort(arr,arr+n);
        cout<<arr[n-1]<<" "<<arr[0];
        return 0;
    }
    cout<<endl;
    vector<vector<int>>v;
    v.sz(18);
    for(int i=1;i<=18;i++){
        sort(arr,arr+n);
        for(int j=0;j<n;j+=2)arr[j]=arr[j]^x;
        for(int j=0;j<n;j++)cout<<arr[j]<<" ";
        cout<<endl;
        for(int j=0;j<n;j++)v[i-1].push_back(arr[j]);
    }

    if(k%2){
        sort(v[6].begin(),v[6].end());
        cout<<v[6].back()<<" "<<v[6][0];
    }
    else {
        sort(v[7].begin(),v[7].end());
        cout<<v[7].back()<<" "<<v[7][0];
    }
    return 0;
}
*/


/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n+1)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define debug cout<<"hello ";
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    ll fibo[n+1];
    fibo[1]=1,fibo[2]=2;
    for(int i=3;i<=n;i++)fibo[n]=(fibo[n-1]+fibo[n-2])%MOD;

    ll q,l,r;
    while(m--){
        cin>>q>>l>>r;
        if(q==1){

        }
        else {

        }
    }
    return 0;
}
*/

//DIJKSTRA'S ALGORITHM
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n+1)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define debug cout<<"hello ";
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
ll  tonum(const string &s) { stringstream ss; ss << s; ll  x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

bool comp(pp a,pp b){
    if(a.first < b.first)return true;
    else if(a.first > b.first)return true;
    return a.second < b.second;
}

bool comp2(string a,string b){
    return a+b<b+a;
}

//priority_queue<pp,vector<pp>,greater<pp>>pq;  for min priority queue
// priority_queue<pp>  default max priority queue
ll n,m;
ll a,b,w,src;
vector<std::list<pp>>v;
void dijkstra(ll src){
    vector<ll>dist;
    dist.resize((ull)n+1,INT_MAX);
    dist[src]=0;
    set<pp>my_set;
    for(ll i=1;i<=n;i++){
        if(i==src)continue;
        my_set.insert(pp(INT_MAX,i));
    }
    my_set.insert(pp(0,src));
    while(!my_set.empty()){
        pp curr = *my_set.begin();
        my_set.erase(curr);
        rep(v[curr.second]){
            if(dist[it->first] > dist[curr.second]+it->second){
                my_set.erase(pp(dist[it->first],it->first));
                dist[it->first] = dist[curr.second]+it->second;
                my_set.insert(pp(dist[it->first],it->first));
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(i==src)continue;
        if(dist[i]==INT_MAX)cout<<1e9<<" ";
        else cout<<dist[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        cin>>n>>m;
        v.clear();
        v.sz(n);
        for(int i=0;i<m;i++){
            cin>>a>>b>>w;
            v[a].push_back(pp(b,w));
            v[b].push_back(pp(a,w));
        }

        dijkstra(1);

    return 0;
}
 */


//KRUSKALS ALGORITHM
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n+1)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define debug cout<<"hello ";
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
ll  tonum(const string &s) { stringstream ss; ss << s; ll  x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

bool comp(pp a,pp b){
    if(a.first < b.first)return true;
    else if(a.first > b.first)return true;
    return a.second < b.second;
}

bool comp2(string a,string b){
    return a+b<b+a;
}

//priority_queue<pp,vector<pp>,greater<pp>>pq;  for min priority queue
// priority_queue<pp>  default max priority queue

class node
{
public:
    ll data;
    ll rank;
    node * parent;
    node(ll val){
        data = val;
        rank=0;
        parent = this;
    }
};

node* my_map[100000];

void make_set(ll data){
    node * curr = new node(data);
    my_map[data] = curr;
}


node* find_set(node* curr){
    if(curr->parent== curr)return curr;
    curr->parent = find_set(curr->parent);  //path compression
    return curr->parent;
}

ll find_set(ll data){
    return find_set(my_map[data])->data;
}

void Union(ll data1 , ll data2){

    node*curr1 = my_map[data1];
    node*curr2 = my_map[data2];

    node * parent1 = find_set(curr1->parent);
    node * parent2 = find_set(curr2->parent);

    if(parent1->data == parent2->data)return;
    if(parent1->rank >= parent2->rank){
        if(parent1->rank == parent2->rank)parent1->rank++;
        parent2->parent = parent1;
    }
    else parent1->parent = parent2;
    return;
}


ll n,m;
ll a,b,w;
vector<std::list<pp>>v;
vector<pair<ll,pp>>wt;
void kruskals(){
    for(int i=1;i<=n;i++)make_set(i);

    ll mst_weight=0;
    ll cnt=0;
    for(int i=0;i<wt.size();i++){
        ll a = find_set(wt[i].second.second);
        ll b = find_set(wt[i].second.first);
        if(a==b)continue;
        Union(wt[i].second.first,wt[i].second.second);
        mst_weight+=wt[i].first;
        cnt++;
        if(cnt==n-1)break;
    }
    cout<<mst_weight;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    v.sz(n);
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        v[a].push_back(pp(b,w));
        v[b].push_back(pp(a,w));
        pair<ll,pp> temp;
        temp.first=w,temp.second=pp(a,b);
        wt.push_back(temp);
    }
    sort(wt.begin(),wt.end());
    kruskals();

    return 0;
}
 */

//PRIMS ALGORITHM

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n+1)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define debug cout<<"hello ";
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
ll  tonum(const string &s) { stringstream ss; ss << s; ll  x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

bool comp(pp a,pp b){
    if(a.first < b.first)return true;
    else if(a.first > b.first)return true;
    return a.second < b.second;
}

bool comp2(string a,string b){
    return a+b<b+a;
}

//priority_queue<pp,vector<pp>,greater<pp>>pq;  for min priority queue
// priority_queue<pp>  default max priority queue
ll n,m;
ll a,b,w;
vector<std::list<pp>>v;
void prims(ll src){
    vector<ll>dist,visited;
    ll mst_weight=0;
    dist.resize((ull)n+1,INT_MAX);
    visited.resize((ull)n+1,1);
    dist[src]=0;
    set<pp>my_set;
    for(ll i=1;i<=n;i++){
        if(i==src)continue;
        my_set.insert(pp(INT_MAX,i));
    }

    my_set.insert(pp(0,src));
    ll cnt=0;
    while(!my_set.empty()){
        pp curr = *my_set.begin();
        visited[curr.second]=0;
        mst_weight+=curr.first;
        cnt++;
        if(cnt==n)break;
        my_set.erase(curr);
        rep(v[curr.second]){
            if(visited[it->first] && dist[it->first] > it->second){
                my_set.erase(pp(dist[it->first],it->first));
                dist[it->first] = it->second;
                my_set.insert(pp(dist[it->first],it->first));
            }
        }
    }

   cout<<mst_weight;

}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    v.clear();
    v.sz(n);
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        v[a].push_back(pp(b,w));
        v[b].push_back(pp(a,w));
    }

    prims(1);

    return 0;
}
*/



// FENWICK FUNCTIONS
/*
  void update(ll x,ll val){
    while(x<=n){
        bit[x]+=val,
        x+=x&-x;
    }
}
ll  get(ll x){
    ll sum=0;
    while(x){
        sum+=bit[x];
        x-=x&-x;
    }
    return sum;
}*/

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n+1)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define debug cout<<"hello"<<endl;
#define pn(x) printf("%d\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000

ll  tonum(const string &s) { stringstream ss; ss << s; ll  x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

bool comp(pp a,pp b){
    if(a.first < b.first)return true;
    else if(a.first > b.first)return true;
    return a.second < b.second;
}

bool comp2(string a,string b){
    return a+b<b+a;
}

//priority_queue<pp,vector<pp>,greater<pp>>pq;  for min priority queue
// priority_queue<pp>  default max priority queue

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout.tie(NULL);
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    int val;
    if(max(a,b)%k==0)val=max(a,b)/k,val--;
    else val=max(a,b)/k;
    int big=max(a,b),sm=min(a,b);
    vector<string>v;

    if(min(a,b)>=val){

        val=big/(sm+1);
        string s;
        int cnt;
        if(big/(sm+1) > big%(sm+1))cnt=big%(sm+1);
        else cnt=val+big%(sm+1);
            for(int c=1;c<=cnt;c++){
                if(a==b){
                    s.push_back('G');
                }
                else{
                    if(big==a){s.push_back('G');}
                    else {s.push_back('B');}
                }
            }
            v.push_back(s);
            s.clear();
            v.push_back(".");

        for(int j=1;j<=sm;j++){
            for(int c=1;c<=val;c++){
                if(a==b){
                    s.push_back('G');
                }
                else{
                    if(big==a){s.push_back('G');}
                    else {s.push_back('B');}
                }
            }
            v.push_back(s);
            s.clear();
            if(j!=sm)
            v.push_back(".");
        }

        rep(v){cout<<*it<<endl;}
        for(int i=0;i<v.size();i++){
            if(v[i]=="."){
                if(a==b)v[i]="B";
                else {
                    if(big==a)v[i]="B";
                    else v[i]="G";
                }
            }
        }
        rep(v)cout<<*it;
    }
    else cout<<"NO";
    return 0;
}
*/
/*

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ru(x) scanf("%llu",&x)
#define ld long double
#define rc(x) scanf("%c",&x)
#define rf(x) scanf("%Lf",&x)
#define r1(x) scanf("%lld",&x)
#define r2(x,y) scanf("%lld%lld",&x,&y)
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n+1)
#define r3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define r4(x,y,z,q) scanf("%lld%lld%lld%lld",&x,&y,&z,&q)
#define MOD 1000000007
#define debug cout<<"hello ";
#define pn(x) printf("%lld\n",x)
#define p_(x)  printf("%lld ",x)
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
string s;
pair<char,ll>  sg[400004];
void create(ll curr,ll st,ll end){
    if(st>end)return;
    if(st==end){
        sg[curr].first=s[st];
        sg[curr].second=st;
        return;
    }
    ll mid=(st+end)/2;
    create(2*curr+1,st,mid);
    create(2*curr+2,mid+1,end);
    if(sg[2*curr+1].first<sg[2*curr+2].first){
        sg[curr].first=sg[2*curr+1].first,sg[curr].second=sg[2*curr+1].second;
    }
    else
        sg[curr].first=sg[2*curr+2].first,sg[curr].second=sg[2*curr+2].second;
}

pp get(ll curr,ll start,ll end,ll a,ll b){
    if(start>end || start>b || end<a)return pp(10000000,1000000);
    if(start==end)return sg[curr];
    ll mid=(start+end)/2;
    pp t1=get(2*curr+1,start,mid,a,b);
    pp t2 = get(2*curr+2,mid+1,end,a,b);
    if(t1.first>t2.first)return t2;
    return t1;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>s;
    string tempp=s;
    sort(tempp.begin(),tempp.end());
    if(s==tempp){
        cout<<tempp;
        return 0;
    }
    V v;
    ll n=(ll)s.size();
    create(0,0,n-1);
    ll i=0,j=n-1;
    while(1){
        pp temp=get(0,0,n-1,i,j);

        v.push_back(temp.second);
        if(i==n-1){
            break;
        }
        i=temp.second+1;
        if(i>=n)break;
    }
    for( i=0;i<v.size();i++){
        cout<<s[v[i]];
        s[v[i]]='@';
    }
    reverse(s.begin(),s.end());
    for(i=0;i<s.size();i++){
        if(s[i]=='@')continue;
        cout<<s[i];
    }
    return 0;
}*/

//  MAXIMUM SUBARRAY SUM
// X[I] STORES MAXIMUM SUM UPTO I
// Y[I] STORES START AND END INDICES
/*
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ull unsigned long long
#define ld  long double
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n+1)
#define MOD 1000000007
#define debug cout<<"hello"<<endl
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
#define stime  clock_t start=clock();double duration;
#define etime duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;cout<<duration<<endl;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll  tonum(const string &s) { stringstream ss; ss << s; ll  x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

bool comp(pp a,pp b)
{
    if(a.first < b.first)return true;
    else if(a.first > b.first)return true;
    return a.second < b.second;
}

bool comp2(string a,string b){
    return a+b<b+a;
}

ll lcm(ll a,ll b){
    return (a*b)/__gcd(a,b);
}

//priority_queue<pp,vector<pp>,greater<pp>>pq;  for min priority queue
// priority_queue<pp>  default max priority queue
// __builtin_popcount int
// __builtin_popcountll long long


int main()
{
    fastio
    int t;
    int arr[1001],n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>arr[i];
        vector<int>x;
        vector<pp>y;
        x.sz(n),y.sz(n);
        x[0]=INT32_MIN;
        int curr_max=0;
        int p=1;
        for(int i=1;i<=n;i++){
            curr_max+=arr[i];
            if(x[i-1] <= curr_max){
                x[i]=curr_max;
                y[i]=pp(p,i);
            }
            else x[i]=x[i-1],y[i]=y[i-1];
            if(curr_max<0) {
                curr_max = 0;
                p = i + 1;
            }
        }

    }
    return 0;
}

 */
/*

#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ull unsigned long long
#define ld  long double
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n+1)
#define MOD 1000000007
#define debug cout<<"hello"<<endl
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
#define stime  clock_t start=clock();double duration;
#define etime duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;cout<<duration<<endl;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll  tonum(const string &s) { stringstream ss; ss << s; ll  x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

bool comp(pp a,pp b)
{
    if(a.first < b.first)return true;
    else if(a.first > b.first)return true;
    return a.second < b.second;
}

bool comp2(string a,string b){
    return a+b<b+a;
}

ll lcm(ll a,ll b){
    return (a*b)/__gcd(a,b);
}

//priority_queue<pp,vector<pp>,greater<pp>>pq;  for min priority queue
// priority_queue<pp>  default max priority queue
// __builtin_popcount int
// __builtin_popcountll long long


int main()
{
    fastio
    int t;
    int arr[1001],n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>arr[i];
        vector<int>x,v;
        vector<pp>y,w;
        x.sz(n),y.sz(n),v.sz(n),w.sz(n);
        x[0]=INT32_MIN;
        v[0]=INT32_MAX;
        int curr_max=0,curr_min=0;
        int p=1,c=1;
        for(int i=1;i<=n;i++){
            curr_max+=arr[i];
            curr_min+=arr[i];
            if(v[i-1] >curr_min){
                v[i]=curr_min;
                w[i]=pp(c,i);
            }
            else v[i]=v[i-1],w[i]=w[i-1];
            if(x[i-1] < curr_max){
                x[i]=curr_max;
                y[i]=pp(p,i);
            }
            else x[i]=x[i-1],y[i]=y[i-1];
            if(curr_max<0) {
                curr_max = 0;
                p = i + 1;
            }
            if(curr_min > 0){
                curr_min=0;
                c=i+1;
            }
        }

        for(int i=1;i<=n;i++)cout<<w[i].first<< " " << w[i].second <<"  "<<y[i].first<<" "<<y[i].second<<endl;
//        for(int i=1;i<=n;i++)cout<<x[i]<<" ";
//        cout<<endl;
//        for(int i=1;i<=n;i++)cout<<v[i]<< " ";
//        cout<<endl;

        int ans=INT32_MIN;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){

                if(y[i].second < w[j].first || y[i].first > w[j].second){
                    ans=max(ans,abs(x[i]-v[j]));
                }

            }
        }


        for(int i=1;i<=n;i++){
           if(w[i].first==2 && w[i].second==80 || w[i].first==81&& w[i].second==84)debug;
        }

        int pre[n+1];;

        pre[1]=arr[1];
        for(int i=2;i<=n;i++)pre[i]=pre[i-1]+arr[i];
        cout<<pre[57]<<" "<<pre[45]<<endl;
        int ans2=INT32_MIN;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int l=1;l<=i-1;l++){
                    for(int u=l+1;u<=i-1;u++){
                        int s1,s2;
                        if(i==1)s1=pre[j];
                        else s1=pre[j]-pre[i-1];
                        if(l==1)s2=pre[u];
                        else s2=pre[u]-pre[l-1];
                        if(ans2 < abs(s2-s1)){
                            cout<<i<<" "<<j<<" "<<l<<" "<<u<<endl;
                        }
                        ans2=max(ans2,abs(s2-s1));
                    }
                }

                for(int l=j+1;l<=n;l++){
                    for(int u=l+1;u<=n;u++){
                        int s1,s2;
                        if(i==1)s1=pre[j];
                        else s1=pre[j]-pre[i-1];
                        if(l==1)s2=pre[u];
                        else s2=pre[u]-pre[l-1];
                        if(12220==abs(s2-s1)){
                            cout<<i<<" "<<j<<" "<<l<<" "<<u<<endl;
                            cout<<s1<<" "<<s2<<endl;
                        }
                        ans2=max(ans2,abs(s2-s1));

                    }
                }
            }
        }


        cout<<ans2<<endl;
        cout<<ans<<endl;
    }
    return 0;
}

*/


/*
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ull unsigned long long
#define ld  long double
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define sz(n) resize((ull)n+1)
#define MOD 1000000007
#define debug cout<<"hello"<<endl
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
#define stime  clock_t start=clock();double duration;
#define etime duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;cout<<duration<<endl;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll  tonum(const string &s) { stringstream ss; ss << s; ll  x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

bool comp(pp a,pp b)
{
    if(a.first < b.first)return true;
    else if(a.first > b.first)return true;
    return a.second < b.second;
}

bool comp2(string a,string b){
    return a+b<b+a;
}

ll lcm(ll a,ll b){
    return (a*b)/__gcd(a,b);
}

//priority_queue<pp,vector<pp>,greater<pp>>pq;  for min priority queue
// priority_queue<pp>  default max priority queue
// __builtin_popcount int
// __builtin_popcountll long long


struct S{
    int sum;
    int x,y;
};

bool compare(S a,S b){
    return a.sum<b.sum;
}
int main()
{
    int t;
    int n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int arr[n+1];
        for(int i=1;i<=n;i++)cin>>arr[i];
        sort(arr+1,arr+n+1);
        vector<S>v;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                S tmp;
                tmp.sum=arr[i]+arr[j];
                tmp.x=i,tmp.y=j;
                v.push_back(tmp);
            }
        }
        sort(v.begin(),v.end(),compare);
        vector<vector<int>>sol,ans;
        int i=0,j=(int)v.size()-1;
        while(i<j){
            if(v[i].sum+v[j].sum==k){
                if(v[i].x==v[j].x || v[i].y==v[j].x || v[i].x==v[j].y || v[i].y==v[j].y){}
                else{
                    vector<int>tmp={arr[v[i].x],arr[v[i].y],arr[v[j].x],arr[v[j].y]};
                    sol.push_back(tmp);
                }
                i++,j--;
            }
            else if(v[i].sum+v[j].sum >k)j--;
            else i++;
        }
        rep(sol){
            sort(it->begin(),it->end());
        }
        sort(sol.begin(),sol.end());

        if(sol.size()==0){
            cout<<-1<<endl;
            continue;
        }


        ans.push_back(sol[0]);
        for(i=1;i<sol.size();i++){
            if(sol[i]!=ans.back())ans.push_back(sol[i]);
        }
        for(i=0;i<ans.size();i++){
            for(j=0;j<4;j++)cout<<ans[i][j]<<" ";
            cout<<"$";
        }
        cout<<endl;
    }


    return 0;
}

 1
27 179
88 84 3 51 54 99 32 60 76 68 39 12 26 86 94 39 95 70 34 78 67 1 97 2 17 92 52
 */




/*Going from left to right, keep track of the number of sequences until the current position, which are of these three forms:
1) a^i
2) a^i b^j
3) a^i b^j c^k
Suppose that these are stored in three variables a,b,c respectively. Whenever you see the character 'a',
 it can extend the strings of type 1, and also, be the starting position for a string of type 1, so a+=(a+1),
 whenever you see a 'b', it can extend previous strings of type 1 and 2, so b+=(a+b), for 'c',
 it will extend all strings of type 2 and 3, so c+=(b+c).

 //REFER TO CODECHEF SOLUTION AS WELL

 */

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld  long double
#define rep(x)  for(auto it = x.begin();it!=x.end();it++)
#define repi(x,y) for(int i=x;i<=y;i++)
#define repj(x,y) for(int j=x;j<=y;j++)
#define sz(n) resize((ull)n+1)
#define MOD 1000000007
#define debug cout<<"hello"<<endl
#define pp pair<ll,ll>
#define V vector<ll>
#define LM 1000000000000000000
#define stime  clock_t start=clock();double duration;
#define etime duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;cout<<duration<<endl;
#define fastio ios_base::sync_with_stdio(false);


ll tonum(const string &s) { stringstream ss; ss << s; ll  x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}





bool comp(pp a,pp b)
{
    if(a.first < b.first)return true;
    else if(a.first > b.first)return true;
    return a.second < b.second;
}

bool comp2(string a,string b){
    return a+b<b+a;
}

ll lcm(ll a,ll b){
    return (a*b)/__gcd(a,b);
}

//priority_queue<pp,vector<pp>,greater<pp>>pq;  for min priority queue
// priority_queue<pp>  default max priority queue
// __builtin_popcount int
// __builtin_popcountll long long

//ll  dp[52][10010];
//int delta[8][2]={{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1},{1,1}};
//int mat[3][110],dp[3][110];
//ll arr[110],dp[2][10010];
//int a[110],b[110],c[110];

int arr[110];
string s;
int n;
bool flag=0;
set<vector<int>>mm;
void func(int i,vector<int>v,int sum){

    if(sum==0){
        flag=1;
        mm.insert(v);
        return;
    }
    if(i>n)return;
    if(arr[i]<=sum){
        v.push_back(arr[i]);
        func(i,v,sum-arr[i]);
        v.pop_back();
    }
    func(i+1,v,sum);
}
int main()
{
    fastio
    int t,sum;
    cin>>t;
    stime
    while(t--){
        n=12;
        repi(1,n)arr[i]=i;
        sum=20;
        sort(arr+1,arr+n+1);
        vector<int>v;
        flag=0,mm.clear();
        func(1,v,sum);
        if(!flag)cout<<"Empty";
        else {
            rep(mm){
                cout<<"(";
                v=*it;
                for(int i=0;i<v.size();i++){
                    if(i==v.size()-1)cout<<v[i];
                    else cout<<v[i]<<" ";
                }
                cout<<")";
            }
        }
        cout<<endl;
    }

    etime
    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*next,*bottom;
};

Node * copyList(Node *head)
{
   auto it = head;
    unordered_map<Node*,Node*>mm;

    Node * ptr=NULL;
    while(it){
        Node*curr=new Node;
        curr->data=it->data;
        curr->next=NULL;
        mm[it]=curr;
        if(!ptr)ptr=curr;
        else ptr->next=curr,ptr=curr;
        it=it->next;
    }
    it=head;
    ptr=mm[it];
    while(it){
        ptr->arb=mm[it->arb];
        it=it->next,ptr=ptr->next;
    }
    return mm[head];
}

int  func(Node* head1, Node* head2,int n,int m){
    int k=n-m;
    auto it1=head1,it2=head2;
    int pos=1;
    while(pos<=k)it1=it1->next,pos++;
    while(it1){
        if(it1==it2)return it1->data;
        it1=it1->next,it2=it2->next;
    }
    return -1;
}
int intersectPoint(Node* head1, Node* head2)
{
    int n=0,m=0;
    auto it = head1;
    while(it){
        n++;
        it=it->next;
    }
    it=head2;
    while(it)m++,it=it->next;
    if(n>m)return func(head1,head2,n,m);
    else return func(head2,head1,m,n);
}



Node *compute(Node *head) {
    if (!head || !head->next)return head;
    auto it = head;
    Node*prev=NULL,*tmp;
    while(it){
        tmp=it->next,it->next=prev,prev=it,it=tmp;
    }
    it=prev;
    Node*ans=NULL;
    while(it){
        if(it->next && it->data>it->next->data){
            tmp=it->next->next;
            delete it->next;
            it->next=tmp;
        }
        else {
            if(!ans)ans=it;
            it=it->next;
        }
    }
    it=ans;
    prev=NULL;
    while(it){
        tmp=it->next,it->next=prev,prev=it,it=tmp;
    }
    return prev;
}


Node* deleteAllOccurances(Node *head,int x)
{
    if(!head)return head;

    auto it=head;
    Node*prev=NULL,*tmp,*ans=head;
    while(it){
        if(it->data==x){
            tmp=it->next;
            delete it;
            if(ans==it)
                ans=tmp,prev=tmp;
            else prev->next=tmp;
            it=tmp;
        }
        else prev=it,it=it->next;
    }
    return ans;
}
*/

/*
struct node *reverse (struct node *head, int k)
{
    if(!head || !head->next)
        return head;
    auto it = head;
    int pos=1;
    node*st=NULL;
    while(it){
        if(pos==k){
            node*prev=reverse(it->next,k);
            auto curr= head;
            pos=1;
            while(pos<=k){
                st=curr->next,curr->next=prev,prev=curr,curr=st;
                pos++;
            }
            return prev;
        }
        else pos++,it=it->next;
    }
    node*prev=NULL;
    it=head;
    while(it)st=it->next,it->next=prev,prev=it,it=st;
    return prev;
}

Node* SortedMerge(Node* head1,   Node* head2) {
    Node *it = NULL, *head = NULL;
    auto it1 = head1, it2 = head2;
    while (it1 && it2) {
        if (it1->data < it2->data) {
            if (!it)head = it1, it = head;
            else it->next = it1, it = it1;
            it1 = it1->bottom;
        } else {
            if (!it)head = it2, it = head;
            else it->bottom = it2, it = it2;
            it2 = it2->bottom;
        }
    }
    while (it1)it->bottom = it1, it = it1, it1 = it->bottom;
    while (it2)it->bottom = it2, it = it2, it2 = it->bottom;
    return head;
}

Node *flatten(Node *root)
{
    if(!root || !root->next)return root;
    Node*prev=root,*it=root->next;
    Node*head=SortedMerge(prev,it);
    while(it->next){
        head=SortedMerge(head,it->next);
        it=it->next;
    }
    return head;
}


int main()
{

    return 0;
}*/




/*
struct Node
{
    int data;
    Node*next;
};

int getMiddle(Node *head)
{
    if(!head)return -1;
    if(!head->next)return head->data;
    if(!head->next->next)return head->next->data;

    auto it = head->next,prev=head;
    while(it &&it->next){
        it=it->next->next,prev=prev->next;
    }
    return prev->data;
}*/


/*
void postOrder(Node* root)
{
    if(!root)return;
    stack<pair<Node*,bool>>s;

    s.push(make_pair(root,0));
    while(!s.empty()){

        auto curr=s.top();
        if(!curr.first->left && !curr.first->right || curr.second){
            cout<<curr.first->data<<" ";
            s.pop();
        }
        else{
            s.top().second=1;
            curr=s.top();
            if(curr.first->right)s.push(make_pair(curr.first->right,0));
            if(curr.first->left)s.push(make_pair(curr.first->left,0));
        }
    }
}

void inOrder(Node* root)
{

    if(!root)return;
    stack<pair<Node*,bool>>s;

    s.push(make_pair(root,0));
    while(!s.empty()){

        auto curr=s.top();
        if(curr.first->left==NULL || curr.second){
            cout<<curr.first->data<<" ";
            curr=s.top();
            s.pop();
            if(curr.first->right)s.push(make_pair(curr.first->right,0));
        }
        else{
            while(s.top().first->left){
                s.top().second=1;
                curr=make_pair(s.top().first->left,0);
                s.push(curr);
            }
        }
    }
}


void preOrder(Node* root)
{
    if(!root)return;
    stack<Node*>s;

    s.push(root);
    while(!s.empty()){

        auto curr=s.top();
        cout<<curr->data<<" ";
        s.pop();
        if(curr->right)s.push(curr->right);
        if(curr->left)s.push(curr->left);
    }
}
*/


//NEXT PERM
/*
    vector<int>v={1,2,2,3,3};

    int n=(int)v.size()-1;
    while(1) {
        int i = n - 1, k;
        while (i >= 0) {
            if (v[i] < v[i + 1]) {
                k = n;
                while (k > i) {
                    if (v[k] > v[i])break;
                    k--;
                }
                swap(v[i], v[k]);
                int j = i + 1;
                k = n;
                while (j < k)swap(v[j], v[k]), j++, k--;
                for (k = 0; k <= n; k++)cout << v[k] << " ";
                cout << endl;
                break;
            }
            i--;
        }
        if (i < 0)break;
    }
    */



/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp pair<ll,ll>
int n,p;

int arr[110];
int mat[10010][9];

bool func() {
    vector<int> v;
    for (int i = 1; i <= p; i++) {
        if (arr[i]%2==0)v.push_back(arr[i]);
    }
    int i, j, k = 0;
    int cn=0;
    while (1 && v.size()) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= 2; j++) {
                mat[i][j] = 1;
                v[k]--;
                if (v[k] == 0) {
                    k++;
                    if (k == v.size())break;
                }
            }
        }
        if (k == v.size())break;


        for (i = 1; i <= n; i++) {
            for (j = 7; j <= 8; j++) {
                mat[i][j] = 1;
                v[k]--;
                if (v[k] == 0) {
                    k++;
                    if (k == v.size()){
                        cn=1;
                        break;
                    }
                }
            }
        }
        if (k == v.size())break;

        for (i = 1; i <= n; i++) {
            for (j = 3; j <= 6; j++) {
                mat[i][j] = 1;
                v[k]--;
                if (v[k] == 0) {
                    k++;
                    j++;
                    if (k == v.size()){
                        cn=2;
                        break;
                    }
                }
            }
            if (k != v.size())return 0;

        }

    }

   if(k==v.size())
       return 1;
    int x=i,y=j;
    if(x==n+1)x=1,cn++;
    v.clear();
    for(int c=1;c<=p;c++){
        if(arr[c]%2)v.push_back(arr[c]);
    }
    if(cn==0){
        for (i = x; i <= n; i++) {
            for (j = y; j <= 2; j++) {
                mat[i][j] = 1;
                v[k]--;
                if (v[k] == 0) {
                    k++;
                    if (k == v.size())return 1;
                }
            }
        }



        for (i = 1; i <= n; i++) {
            for (j = 7; j <= 8; j++) {
                mat[i][j] = 1;
                v[k]--;
                if (v[k] == 0) {
                    k++;
                    if (k == v.size())return 1;
                }
            }
        }

        for (i = 1; i <= n; i++) {
            for (j = 3; j <= 6; j++) {
                mat[i][j] = 1;
                v[k]--;
                if (v[k] == 0) {
                    k++;
                    j++;
                    if (k == v.size())return 1;
                }
            }
        }
    }



    else if(cn==1){
        for (i = x; i <= n; i++) {
            for (j = y; j <= 8; j++) {
                mat[i][j] = 1;
                v[k]--;
                if (v[k] == 0) {
                    k++;
                    if (k == v.size())return 1;
                }
            }
        }

        for (i = 1; i <= n; i++) {
            for (j = 3; j <= 6; j++) {
                mat[i][j] = 1;
                v[k]--;
                if (v[k] == 0) {
                    k++;
                    j++;
                    if (k == v.size())return 1;
                }
            }

        }
    }




    else if(cn==2){
        for (i = x; i <= n; i++) {
            for (j = y; j <= 6; j++) {
                mat[i][j] = 1;
                v[k]--;
                if (v[k] == 0) {
                    k++;
                    j++;
                    if (k == v.size()){
                        return 1;
                    }
                }
            }
        }

    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>p;
    for(int i=1;i<=p;i++)cin>>arr[i];
    if(func())cout<<"YES";
    else cout<<"NO";
    return 0;
}*/

/*
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define pp pair<int,int>

int n;
int arr[310];
vector<vector<int>>v;

int get(int idx){

    int val=-1,pos=0;
    for(int i=idx;i<=n;i++){
        if(val>arr[i])val=arr[i],pos=i;
    }
    return pos;
}

void  path(int curr,vector<int>&p,vector<bool>&vis){
    vis[curr]=true;
    for(auto it:v[curr]){
        if(!vis[it])path(it,p,vis);
    }
    p.push_back(curr);
}

bool get_path(int curr,int dest,vector<int>&p,vector<bool>&vis){

    vis[curr]=true;
    if(curr==dest){
        p.push_back(dest);
        return true;
    }
    for(auto it:v[curr]){
        if(!vis[it]){
            if(get_path(it,dest,p,vis)){
                p.push_back(curr);
                return true;
            }
        }
    }
    return false;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];

    int val;
    v.resize(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>val;
            if(val==1)v[i].push_back(j),v[j].push_back(i);
        }
    }

    val=1;
    vector<bool>vis;
    vis.resize(n+1);
    while(val<=n){
        int idx=get(val);
        vector<int>p,tmp;
        for(auto &it:vis)it=0;
        path(idx,p,vis);
        for(int i=0;i<p.size();i++){
            if(p[i]>=val && p[i]<=idx)tmp.push_back(i);
        }
        auto tp=min_element(tmp.begin(),tmp.end());
        val=*tp;
        p.clear();
        tmp.clear();
        for(auto &it:vis)it=0;
        get_path(idx,*tp,p,vis);
        reverse(p.begin(),p.end());
        for(int i=1;i<p.size();i++)swap(arr[p[i]],arr[p[i-1]]);
        val++;
    }
    for(int i=1;i<=n;i++)cout<<arr[i]<<" ";
    return 0;

}
*/

// EXTENDED EUCLID
/*
ll  d, x, y;


void extendedEuclid(ll A, ll B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

ll  modInverse(ll  A, ll  M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}

*/


/*
int main(){


//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    char s[100010],p[100010];
    cin.getline(s,100010);
    cin.getline(p,100010);
    int n;
    cin>>n;

    int pre[100010];
    pre[0]=0;
    int i=1,j=0;
    auto lenp=(int)strlen(p);
    while(i<lenp){
        if(s[i]==s[j]){
            pre[i]=j+1;
            j++,i++;
        }
        else{
            if(j==0)pre[i]=0,i++;
            else j=pre[j-1];
        }
    }

    unordered_map<int,int>mm;
    auto  lent = (int)strlen(s);
    for(i=0;i<lenp;i++)cout<<pre[i]<<" ";
    cout<<endl;
    i=0,j=0;
    while(i<lent){
        if(s[i]==p[j])i++,j++;
        if(j==lenp){
            mm[j]++;
            j=pre[j-1];
            cout<<j<<endl;

        }
        else if(i<lent && s[i]!=p[j]){
            mm[j]++;
            if(j)j=pre[j-1];
            else i++;
        }
    }

    int maxx=-1,len=0;
    rep1(mm){
        cout<<it.first<<" "<<it.second<<endl;
        if(maxx<=it.second){
            maxx=it.second;
            if(len<it.first)len=it.first;
        }
    }
    i=0;
    while(i<len)cout<<p[i],i++;
    if(len==0)cout<<"IMPOSSIBLE";

    return 0;
}*/


/*
ostream & operator <<(ostream &cout,vector<ll>&v){
    rep(v)cout<<it<<" ";
    cout<<endl;
    return cout;
}

istream & operator >>(istream & cin,vector<ll>&v){
    rep(v)cin>>it;
    return cin;
}*/


// create and save segment trees

/*ll sgt[100000], arr[25000],lazy[100000];

void create(ll curr,ll st,ll ed){

    if(st>ed)return;
    if(st==ed){
        sgt[curr]=arr[st];
        return;
    }
    ll mid=(st+ed)/2;
    create(2*curr+1,st,mid);
    create(2*curr+2,mid+1,ed);
    sgt[curr]=min(sgt[2*curr+1],sgt[2*curr+2]);
}

ll get(ll curr,ll st,ll ed,ll a,ll b){

    if(st>ed || st>b || ed<a)return LONG_LONG_MAX;
    if(st>=a && ed<=b)return sgt[curr];
    ll mid=(st+ed)/2;
    return min(get(2*curr+1,st,mid,a,b),get(2*curr+2,mid+1,ed,a,b));
}

ll getLazy(ll curr,ll st,ll ed,ll a,ll b){

    if(st>ed)return LONG_LONG_MAX;

    if(lazy[curr]){
        sgt[curr]+=lazy[curr];
        if(st!=ed){
            lazy[2*curr+1]+=lazy[curr];
            lazy[2*curr+2]+=lazy[curr];
        }
        lazy[curr]=0;
    }

    if(st>b || ed<a)return LONG_LONG_MAX;

    if(st>=a && ed<=b)return sgt[curr];

    ll mid=(st+ed)/2;
    return min(getLazy(2*curr+1,st,mid,a,b),getLazy(2*curr+2,mid+1,ed,a,b));

}
void updatePoint(ll curr,ll st,ll ed,ll idx,ll val){

    if(st>ed || ed<idx || st>idx)return;
    ll mid=(st+ed)/2;
    if(ed==st){
        sgt[curr]+=val;
        return;
    }
    updatePoint(2*curr+1,st,mid,idx, val);
    updatePoint(2*curr+2,mid+1,ed,idx, val);
    sgt[curr]=min(sgt[2*curr+1],sgt[2*curr+2]);
}

void updateRange(ll curr,ll st,ll ed,ll a,ll b,ll val){

    if(st>ed)return;

    if(lazy[curr]){
        sgt[curr]+=lazy[curr];
        if(st!=ed){
            lazy[2*curr+1]+=lazy[curr];
            lazy[2*curr+2]+=lazy[curr];
        }
        lazy[curr]=0;
    }

    if(st>b || ed<a)return;

    if(st>=a && ed<=b){
        sgt[curr]+=val;
        if(st!=ed){
            lazy[2*curr+1]+=val;
            lazy[2*curr+2]+=val;
        }
        return;
    }

    ll mid=(st+ed)/2;

    updateRange(2*curr+1,st,mid,a,b,val);
    updateRange(2*curr+2,mid+1,ed,a,b,val);
    sgt[curr]=min(sgt[2*curr+1],sgt[2*curr+2]);

}*/



#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long
#define pp pair<ll,ll>
#define stime  clock_t start=clock();double duration;
#define etime duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;cout<<duration<<endl;
#define rep(v) for(auto&it:(v))
#define repp(a) for(auto&ptr:(a))
#define dbg cout<<"hello\n";
#define MOD 1000000007
#define loop(n) for(int i=1;i<=(n);i++)
#define V vector<ll>
#define sz(n) resize((ull)(n))

ll power(ll a,ll p,ll m=MOD)
{ll res=1;while(p>0){if(p&1)res=(res*a)%m;a=(a*a)%m;p>>=1;}return res;}


ll n,k;
void func(){
    cin>>n>>k;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        func();
    }


    return 0;
}





#include<bits/stdc++.h>
using namespace std;
template<typename type>
 class binary_tree;
template<typename t>
class bt_node
{
    t data;
    bt_node*left;
    bt_node*right;
public:
    bt_node(const t & el):data(el),left(NULL),right(NULL){}
    template<typename type>
    friend class binary_tree;
};

template<typename t>
class binary_tree
{
    bt_node<t>*root;
public:
    binary_tree():root(NULL){}

    void create_tree()
    {
        if(root!=NULL)
           throw"TREE ALREADY EXISTS";
           root=create_tree_helper();
    }

    static bt_node<t>*create_tree_helper()
    {
        cout<<"enter the data for the node ";
        int el;
        cin>>el;
        bt_node<t>*node=new bt_node<t>(el);

        cout<<"does " <<el<<" has a left child (y/n) ";
        char ch;
        cin>>ch;
        if(ch=='y' || ch=='Y')
            node->left=create_tree_helper();
        cout<<"does " <<el<<" has a right child (y/n) ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
            node->right=create_tree_helper();
        return node;
    }

    void print_preorder() const
    {
        print_preorder_helper(root);
        cout<<endl;
    }

    static void print_preorder_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
            return ;
        cout<<curr->data<<" ";
        print_preorder_helper(curr->left);
        print_preorder_helper(curr->right);
        return ;
    }

    void print_postorder() const
    {
        print_postorder_helper(root);
        cout<<endl;
    }

    static void print_postorder_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
            return ;
        print_postorder_helper(curr->left);
        print_postorder_helper(curr->right);
        cout<<curr->data<<" ";
        return ;
    }

    void print_inorder() const
    {
        print_inorder_helper(root);
        cout<<endl;
    }

    static void print_inorder_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
            return ;
        print_inorder_helper(curr->left);
         cout<<curr->data<<" ";
        print_inorder_helper(curr->right);
        return ;
    }

    void print_height() const
    {
        if(root==NULL)
            return;
        cout<<"HEIGHT IS:"<<print_height_helper(root);
    }
    static int print_height_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
            return -1;
        return 1+max(print_height_helper(curr->left),print_height_helper(curr->right));
    }

    void delete_half_nodes()
    {

        root=delete_half_nodes_helper(root);
    }

    static bt_node<t>*delete_half_nodes_helper( bt_node<t>*curr)
    {
        if(curr==NULL)
            return NULL;
        curr->left=delete_half_nodes_helper(curr->left);
        curr->right=delete_half_nodes_helper(curr->right);
        if(curr->left==NULL && curr->right!=NULL)
        {
            bt_node<t>*ptr=curr->right;
            delete curr;
            return ptr;
        }
        else if(curr->left!=NULL && curr->right==NULL)
        {
            bt_node<t>*ptr=curr->left;
            delete curr;
            return ptr;
        }
        return curr;
    }

    void delete_leaf()
    {
        root=delete_leaf_helper(root);
    }
    static bt_node<t>*delete_leaf_helper(bt_node<t>*curr)
    {
        if(curr==NULL)
            return NULL;
        if( !curr->left && ! curr->right)
        {
            delete curr;
            return NULL;
        }
        curr->left=delete_leaf_helper(curr->left);
        curr->right=delete_leaf_helper(curr->right);
        return curr;
    }

    bool operator == (const binary_tree & T) const
    {
        return helper(root,T.root);
    }

   static bool helper(const bt_node<t>*curr,const bt_node<t>*add)
    {
        if(!curr && ! add)
        return true;
        if(!curr && add || curr &&  !add)
            return false;
        if(curr->data != add->data)
            return false;
        if(helper(curr->left,add->left))
        {
            if(helper(curr->right,add->right))
               return true;
            else return false;
        }
        return false;
    }


    void create_from_post_in(int *post,int*in,int n)
    {
        root=create_from_post_in_helper(post,in,n);
    }

    static bt_node<t>*create_from_post_in_helper(int *post,int *in ,int n)
    {
        ///BASE CASE
        if(n<=0)
            return NULL;
        bt_node<t>*node=new bt_node<t>(post[n-1]);
        int i;
        for( i=0;i<n;i++)
        {
            if(post[n-1]==in[i])
                break;
        }
        node->left=create_from_post_in_helper(post,in,i);
        node->right=create_from_post_in_helper(post+i,in+i+1,n-i-1);
        return node;
    }

    void print_diameter() const
    {
        if(root==NULL)
            return ;
        pair<int,int> my_pair=print_diameter_helper(root);
        cout<<my_pair.first<<" "<<my_pair.second;
    }
    static pair<int,int> print_diameter_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
        {
               pair<int,int>temp(0,0);
               return temp;
        }
          pair<int,int> left,right;
          left=print_diameter_helper(curr->left);
          right=print_diameter_helper(curr->right);
          left.first= max(max(left.first,right.first),1+left.second+right.second);
          left.second=1+max(left.second,right.second);
          return left;
    }

    void is_balanced() const
    {
        if(root==NULL)
            return false;
        pair<int,bool>temp=is_balanced_helper();
        if(temp.second==false)
            cout<<"no";
        else cout<<"yes";
        return ;
    }
    static pair<int ,bool>  is_balanced_helper(const bt_node<t>*curr)
    {
        if(curr==NULL)
            {
                 pair<int,bool> temp(0,true);
            }
        pair<int,bool> l=is_balanced_helper(curr->left);
        pair<int,bool> r=is_balanced_helper(curr->right);
        if(l.second == false || r.second==false)
        {
            l.second=false;
            return l;
        }
        l.first=1+max(l.first,r.first);
        l.second=true;
        return l;
    }

    void print_nodes_with_no_sibling() const
    {
        if(root==NULL)
            return ;
        print_nodes_with_no_sibling_helper(root);
    }

    static void print_nodes_with_no_sibling_helper(const bt_node<t>*curr)
    {
        if(curr==NULL || curr->left==NULL && curr->right==NULL)
            return ;
        if(!curr->left && curr->right)
        {
            cout<<curr->right->data<<" ";
            print_nodes_with_no_sibling_helper(curr->right);
            return ;
        }
        if(curr->left && !curr->right)
        {
            cout<<curr->left->data<<" ";
            print_nodes_with_no_sibling_helper(curr->left);
            return ;
        }

        print_nodes_with_no_sibling_helper(curr->left);
        print_nodes_with_no_sibling_helper(curr->right);
        return ;
    }

   void max_sum_path() const
   {
      ///REFER BINARY TREE CLASS(binary_tree.cpp)
   }

   void leaf_at_same_level() const
   {
       if(root==NULL)
        return ;
        int height=-1;
       leaf_at_same_level_helper(root,0,height)==true ? cout<<"yes" : cout<<"no";
       return ;
   }


   static bool leaf_at_same_level_helper(const bt_node<t>* curr, int temp ,int &height)  ///NEW VARIABLE HEIGHT WILL BE FORMED EVERY TIME ( ON THAT PARTICULAR STACK)
                                                                                        /// HENCE WHEN WE RETURN height will be same as original so here temp and height are
                                                                                         ///  modified in same way

   {
       if(curr==NULL)
        return true;
       if( ! curr->left  &&  ! curr->right)
       {
           if(height==-1)
            {
                height=temp;
                cout<<height<<endl;
                return true;
            }
           else
           {    if(temp!=height)
                return false;
                else return true;
           }
       }
       if(leaf_at_same_level_helper(curr->left,temp+1,height))
       {
        if(leaf_at_same_level_helper(curr->right,temp+1,height))
             return true;
       else return false;
       }
       return false;
   }

     const bt_node<t>*is_present( t  el) const
     {
         return is_present_helper(el,root);
     }

    static const bt_node<t>* is_present_helper( t & el,const  bt_node<t>*curr)
     {
         if(curr==NULL)
            return NULL;
         if(curr->data==el)
            return curr;
        const bt_node<t>*l=is_present_helper(el,curr->left);
         if(l==NULL)
            return is_present_helper(el,curr->right);
         else return l;
     }

     void node_with_sum(  t sum) const
     {
         if(root==NULL)
            return ;
         if(nodes_with_sum_helper(sum,root))
            cout<<"yes";
         else cout<<"no";
         return ;
     }

    bool nodes_with_sum_helper( t sum, const bt_node<t>*curr) const
     {
         if(curr==NULL)
            return false;
        const bt_node<t>*ptr=is_present(sum-curr->data);
         if(ptr)
            return true;
         if(nodes_with_sum_helper(sum,curr->left))
            return true;
         if(nodes_with_sum_helper(sum,curr->right))
            return true;
         return false;
     }

     ///LOWEST COMMON ANCESTOR
     /// MAKE SURE THAT BOTH ROOTS ARE PRESENT
     /*
     struct Node *findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL) return NULL;

    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1 || root->key == n2)
        return root;

    // Look for keys in left and right subtrees
    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);

    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}
*/

///MIRROR THE TREE


/// JUST LARGER THAN K SAME AS WE DID IN GENERIC TREE

   void min_depth()
   {
       cout<<min_depth_helper(root);
   }
   static int min_depth_helper(const bt_node<t>*curr)
   {
       if(curr==NULL)
        return -1;
       return 1+min(min_depth_helper(curr->left),min_depth_helper(curr->right));
   }

   void check_bst()
   {
      cout<< check_bst_helper(root);
   }

   ///ALTHOUGH THIS SOLUTION IS INCORRECT
   ///BUT STILL WE COUNLD HAVE WRITTEN IN MORE PRESENTABLE MANNER
    /*
int isBST(struct node* node)
{
  if (node == NULL)
    return(true);

  if (node->left!=NULL && maxValue(node->left) > node->data)
    return(false);

  if (node->right!=NULL && minValue(node->right) < node->data)
    return(false);

  if (!isBST(node->left) || !isBST(node->right))
    return(false);

  return(true);
} */
   ///CORRECT AND BETTER SOLUTION WILL BE TO TRAVERSE INORDER
   /// AND MAINTAINING A PREVIOuS POINTER
   static bool check_bst_helper(const bt_node<t>*curr)
   {
       if(curr==NULL)
        return true;
       if(check_bst_helper(curr->left))
       {
           if(check_bst_helper(curr->right))
           {
               if(curr->left && curr->right)
               {
                   if(curr->data >= curr->left->data  && curr->data < curr->right->data)
                    return true;
               }
               else if(curr->left && ! curr->right)
               {
                   if(curr->data >=curr->left->data)
                    return true;
               }
               else if(!curr->left  &&  curr->right)
               {
                   if(curr->data < curr->right->data)
                    return true;
               }
               else if(! curr->left  &&  ! curr->right)
                      return true;
           }

       }
       return false;
   }


   void pre_order_it()
   {
       stack<bt_node<t>*> s;
       s.push(root);
       while(!s.empty())
       {
           bt_node<t>*temp=s.top();
           s.pop();
           cout<<temp->data<<" ";
           if(temp->right)
            s.push(temp->right);
           if(temp->left)
            s.push(temp->left);
       }
   }

   void inorder_it()
   {
       if(root==NULL)
        return;
       stack<bt_node<t>*> s;
       s.push(root);
       bt_node<t>*temp=s.top();
       left_push(s,root);
       while(!s.empty())
       {
           temp=s.top();
           cout<<temp->data<<" ";
           s.pop();
           if(temp->right)
            {
                s.push(temp->right);
                left_push(s,temp->right);
            }
       } return ;
   }

   void left_push(stack<bt_node<t>*> & s ,bt_node<t>*node)
   {
        while(node)
        {
            if(node->left)
                s.push(node->left);
            else break;
            node=node->left;
        }
        return ;
   }

   void inorder_iterative_method2()
   {
       stack<bt_node<t>*> s;
       bool bool_value=false;
       bt_node<t>*it=root;
       while(bool_value==false)
       {
           if(it)
           {
               s.push(it);
               it=it->left;
           }
           else{
              if(!s.empty())
              {
                  cout<<s.top()->data<<" ";
                  it=s.top()->right;
                  s.pop();
              }
              else bool_value=true;
           }
       }

   }

     /* void post_order_iterative()
            {
                if(root==0)
                {
                    return ;
                }
                stack<const node<t>*>s,r;

                s.push(root);
                while(!s.empty())
                {
                    r.push(s.top());
                    s.pop();
                    if(r.top()->left!=NULL)
                    {
                        s.push(r.top()->left);
                    }
                    if(r.top()->right!=NULL)
                    {
                        s.push(r.top()->right);
                    }
                }
                while(!r.empty())
                {
                    cout<<r.top()->data<<" ";
                    r.pop();
                }
                return ;
            }*/
///SEE ONE STACK SOLUTION FROM GEEKS



 void print_at_distance_k(t  el,int k)
    {
        if(root==NULL)
            return ;
        bt_node<t>*node=address_of_node_helper(root,el);
        print_at_distance_k_helper(root,node,k);
        return ;
    }
    static int  print_at_distance_k_helper( bt_node<t>*curr,bt_node<t>*target,int k)
    {
       if(curr==NULL)
          return -1;
       if(curr==target)
       {
           print_at_depth_k_helper(target,k);
           return 0;
       }

       int ld=print_at_distance_k_helper(curr->left,target,k);
       if(ld!=-1)
       {
           ld++;
           if(ld==k)
            cout<<curr->data<<" ";
           else print_at_depth_k_helper(curr->right,k-ld-1);
           return ld;
       }
       int rd=print_at_distance_k_helper(curr->right,target,k);
       if(rd!=-1)
       {
           rd++;
           if(rd==k)
            cout<<curr->data<<" ";
           else print_at_depth_k_helper(curr->left,k-rd-1);
           return rd;
       }
       return -1;
    }

    void print_at_depth_k(bt_node<t>*target,int k)
    {
        print_at_depth_k_helper(target,k);
    }
    static void print_at_depth_k_helper( bt_node<t>*curr,int k)
    {
        if(curr==NULL)
            return ;
        if(k==0)
        {
            cout<<curr->data<<" ";
            return ;
        }
        print_at_depth_k_helper(curr->left,k-1);
        print_at_depth_k_helper(curr->right,k-1);
        return ;
    }

    void address_of_node(const t & el) const
   {
          address_of_node_helper(root,el);
   }
   static bt_node<t>*address_of_node_helper( bt_node<t>*curr,const t &el)
   {
       if(curr==NULL)
        return NULL;
       if(curr->data==el)
        return curr;
       if(curr->data < el)
        return address_of_node_helper(curr->right,el);
       else return address_of_node_helper(curr->left,el);
   }
};
int main()
{
    binary_tree<int> T;
    /*int a[]={4,5,2,6,7,3,1};
    int b[]={4,2,5,1,6,3,7};
     T.create_from_post_in(a,b,7);
     */
     T.create_tree();
     T.print_preorder();
     T.print_at_distance_k(10,4);
    /* T.pre_order_it();
     cout<<endl;
     T.inorder_iterative_method2();*/


     //T.check_bst();
   //  T.print_preorder();
     //T.node_with_sum(18);
     //T.print_nodes_with_no_sibling();
     //T.is_balanced();
     //T.print_diameter();
    /*T.create_tree();
    T.print_preorder();
    T.delete_half_nodes();
    T.print_preorder();*/
    return 0;
}
