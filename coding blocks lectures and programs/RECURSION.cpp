#include<bits/stdc++.h>
using namespace std;
void print_string( char*a)
{
    if(*a=='\0')
     return ;
     cout<<*a;
     print_string(a+1);
}
int sum( int *a,int n)
{
   return  n==0 ?  0 : *a+sum(a+1,n-1);
}

int fact(int n)
{
   return  n==0?  1 : n*fact(n-1);
}

int binary_search(int *a,int k,int start,int end)
{
    if(start > end)
        return -1;
    int mid=(start+end)/2;
    if(k==a[mid])
        return mid;
    else if(k> a[mid])
        return binary_search(a,k,mid+1,end);
    else return binary_search(a,k,start,mid-1);
}

int maximum(int *a,int n)
{
    if(n==0)
        return INT_MIN;
    return *a >= maximum(a+1,n-1) ? *a : maximum(a+1,n-1);
}

int minimum(int *a,int n)
{
    if(n==0)
        return INT_MAX;
    return *a <= minimum(a+1,n-1) ? *a : minimum(a+1,n-1);
}

int  minimum_index(int *a,int n,int index)
{
    if(index==n)
        return -1;
    int temp_index=minimum_index(a,n,index+1);
    if(temp_index==-1)
        return index;
    return a[index] > a[temp_index] ? temp_index : index;

}
void selection_sort(int *a,int n,int index)
{
    if(index==n)
        return ;
    int temp_index=minimum_index(a,n,index);
    int val=a[index];
    a[index]=a[temp_index];
    a[temp_index]=val;
    selection_sort(a,n,index+1);
    return ;
}
bool check_sorted(int*a,int n)
{
    if(n==0)
        return false;
     if(n==1)
        return true;
    if(*a > *(a+1))
        return false;
    return check_sorted(a+1,n-1);
}
int last_index(int*a,int n,int index)
{
    if(index==-1)
        return false;
    if(a[index]==7)
        return index;
    else return last_index(a,n,index-1);
}
int c=0;
void all_index(int *a,int *sol,int n,int index)
{
    if(index==n)
         return;
    if(a[index]==7)
    {
        sol[c]=index;
        c++;
    }
     all_index(a,sol,n,index+1);
    return ;
}

long long int  power(int a,int x)
{
    if(x==0)
        return 1;
    if(x==1)
        return a;
    if(x==2)
        return a*a;
    if(x%2==0)
    {
        long long  int ans=power(a,x/2);
        return ans*ans;
    }
    return power(a,x/2)*power(a,x/2+1);
}

 int zeros( long long int n)
{
    if(n==0)
        return 0;
    if(n%10==0)
        return 1+zeros(n/10);
    else return zeros(n/10);
}
int rev(int n,int reverse)
{
    return n==0 ? reverse : rev(n/10,reverse*10+n%10);
}

void subsets(char*a,char *sol,int size)
{
    if(*a=='\0')
    {
        for(int i=0;i<size;i++)
            cout<<sol[i]<<" ";
        cout<<endl;
        return ;
    }
    subsets(a+1,sol,size);
    sol[size]=*a;
    subsets(a+1,sol,size+1);
    return ;
}
void merge_two_sorted(int *a,int n)
{
    int c[100];
    int i=0;
    int j=n/2;
    int k=0;
    while(i < n/2 && j < n)
    {
        if(a[i] > a[j])
        {
            c[k]=a[j];
            j++;k++;
        }
        else{
            c[k]=a[i];
            i++;k++;
        }
    }
    if(i==n/2)
    {
        while(j<n)
        {
            c[k]=a[j];
            j++;k++;
        }
    }
    else if(j==n)
    {
        while(i<n/2)
        {
            c[k]=a[i];
            i++;k++;
        }
    }

    for(i=0;i<n;i++)
    {
        a[i]=c[i];
    }
    return ;

}
void merge_sort(int *a,int n)
{
    if(n==1)
        return ;
    merge_sort(a,n/2);
    merge_sort(a+n/2,n-n/2);
    merge_two_sorted(a,n);
    return ;
}

void sum_of_subsets(int *a,int n,int index,int sum,int *sol,int size)
{
    if(sum==0)
    {
        for(int i=0;i<size;i++)
            cout<<sol[i]<<" ";
            cout<<endl;
        return ;
    }
    else if(index==n)
        return ;
    sum_of_subsets(a,n,index+1,sum,sol,size);
    sol[size]=a[index];
    sum_of_subsets(a,n,index+1,sum-a[index],sol,size+1);
    return ;
}

void permutations(char*a,int n,int index)
{
    if(index==n)
    {
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        return ;
    }
    int i=index;
    while(i<n)
    {
        char temp=a[index];
        a[index]=a[i];
        a[i]=temp;
        permutations(a,n,index+1);
        temp=a[index];
        a[index]=a[i];
        a[i]=temp;
        i++;
    }
   return ;
}
bool check_bb(char*);
bool check_a(char *a)
{
    if(*a=='\0')
       return true;
    if(*a=='a')
        return check_a(a+1);
    else if(*a=='b' && *(a+1)=='b')
        return check_bb(a+2);
    return false;
}
bool check_bb(char *a)
{
    if(*a=='\0')
        return true;
    if(*a=='a')
     return check_a(a+1);
    return false;
}
int main()
{
    /*int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    int index=binary_search(a,k,0,n-1);
    index==-1?cout<<"no":cout<<"yes and index is:"<<index;
    */
    /*int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
       /* pair<int,int>temp=minimum_index(a,n,0);
        cout<<temp.first<<" "<<temp.second;*/

       /* cout<<"maximum is:"<<maximum(a,n)<<endl;;
        cout<<"minimum is:"<<minimum(a,n)<<endl;
        cout<<"sorted array is:";
        selection_sort(a,n,0);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
            */

      /*int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        int sol[100];
        all_index(a,sol,n,0);
        for(int i=0;i<c;i++)
            cout<<sol[i]<<" ";
            */
        //cout<<last_index(a,n,n-1);
        //cout<<check_sorted(a,n);

       /* int a,x;
        cout<<"enter the base"<<endl;
        cin>>a;
        cout<<"enter the exp"<<endl;
        cin>>x;
        cout<<power(a,x);
        */
       /* long long int n;
        cin>>n;
        cout<<zeros(n);
        */
        /*int n;
        cin>>n;
        cout<<rev(n,0);
        */
        /*char a[100];
        cin.getline(a,100);
        char sol[100];
        cout<<"SUBSETS ARE:"<<endl;
        subsets(a,sol,0);
        */

        int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        merge_sort(a,n);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";


    /*int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        int sum;
        cin>>sum;
        int sol[100];
        cout<<"REQUIRED SUBSETS ARE:"<<endl;
        sum_of_subsets(a,n,0,sum,sol,0);
        */
        /*char a[1000];
        cin.getline(a,1000);
        cout<<"PERMUTATIONS ARE:"<<endl;
        permutations(a,strlen(a),0);
        */

    return 0;
}
