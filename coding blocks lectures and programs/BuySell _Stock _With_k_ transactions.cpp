/*
T[i][j]=max{ t[i][j-1],
price[j]-price[m] for m=0,1,2 .... j-1 + t[i-1][m]; ///this solution is in 0(day*day*k);
 see pic from phone
  for the further optimized solution i.e. in 0(day*k);
*/
///HACKER RANK STOCK MAXIMISE

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

/*
#include <bits/stdc++.h>
using namespace std;
#define li  long long int
#define pp pair<li,li>
pp s[400001],arr[100001];

pp get_powers(li num)
{
    pp my_pair;
    li count=0;
    if(num%2==0)
    {
        while(num%2==0)
        {
            count++;
            num=num/2;
        }
    }
    my_pair.first=count;
    count=0;

    if(num%5==0)
    {
        while(num%5==0)
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

    if(start==end)
    {
        s[curr].first+=x.first;
        s[curr].second+=x.second;
        return;
    }

    if(start>b || end <a)  // No overlap
        return;

    li mid=(start+end)/2;  //Partial overlap
    update_1(start,mid,a,b,2*curr+1,x);
    update_1(mid+1,end,a,b,2*curr+2,x);
    s[curr].first=s[2*curr+1].first + s[2*curr+2].first;
    s[curr].second = s[2*curr+1].second + s[2*curr+2].second;
    return;
}

void update_2(li start,li end,li a,li b,li curr,li y)
{
    if(start > end)
        return;

    if(start==end)
    {
        pp temp = get_powers((start-a+1)*y);
        s[curr].first+=temp.first;
        s[curr].second+=temp.second;
        return;
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
      /* for(int i=0;i<15;i++)
            cout<<s[i].first<<" "<<s[i].second<<endl;*/

        li x,l,r,y;
        while(m)
        {
            m--;
            scanf("%lld",&x);
            printf("hello");
            if(x==3)
            {
                scanf("%lld%lld",&l,&r);
                pp temp =get_query(0,n-1,l-1,r-1,0);
                count+=min(temp.first,temp.second);
                //cout<<count<<" ";
            }
            else
            {
                scanf("%lld%lld%lld",&l,&r,&y);
                if(x==1)
                {
                    pp my_pair = get_powers(y);
                    update_1(0,n-1,l-1,r-1,0,my_pair);
                }

                if(x==2)
                {
                    update_2(0,n-1,l-1,r-1,0,y);
                }
            }

        }
       printf("%lld\n",count);

    }
    return 0;
}
*/
