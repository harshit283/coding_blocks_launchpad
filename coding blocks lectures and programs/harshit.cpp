#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    int a[100],b[100];
    cout<<"enter the fisrt array";
    for(int i=0;i<=5;i++)
    {
        int val;
        cin>>val;
        a[i]=val;

    }
   /* cout<<"enter the second array";
    for(int i=0;i<=4;i++)
    {
        cin>>b[i];
    }
    */
    unordered_set<int> set;
    for(int i=0;i<=5;i++ )
    {
        set.insert(a[i]);
    }

    //set.erase(a[6]);
    //cout<<set.bucket_count();
    cout<<endl;
    for(int i=0;i<=5;i++)
    {
        cout<<set.bucket_size(set.bucket(a[i]))<<" ";
    }

    /*for(int i=0;i<=4;i++)
    {
        int temp=set.count(b[i]);
        if(temp==1)
        {
            cout<<b[i]<<" ";
        }
    }
    */
    return 0;
}
/*#include<iostream>
#include<unordered_set>
using namespace std;
int main ()
{
    int a[100];
    int n;int sum;
    cout<<"enter the number of elements:"<<endl;
    cin>>n;
    cout<<"enter the array";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the sum value";
    cin>>sum;
    unordered_set<int> set;
    for(int i=0;i<n;i++)
    {
        int temp=set.count(sum-a[i]);
        if(temp==1)
        {
            cout<<a[i]<<" "<<sum-a[i]<<endl;
        }
        set.insert(a[i]);
    }




return 0;
}

