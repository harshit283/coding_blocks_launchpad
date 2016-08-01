#include<iostream>
using namespace std;
int n;
int partition(int *a,int start,int end)
{
    int pivot=end;
    int i,temp;
    for(i=start;i<pivot;i++)
    {
        if(a[i]<=a[pivot])      /// LOMUTO PARTITIONING LOGIC
        {
            temp=a[start];
            a[start]=a[i];
            a[i]=temp;
            start++;
        }
    }
    temp=a[pivot];
    a[pivot]=a[start];
    a[start]=temp;
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
int main ()
{
    int a[100];
    int i;
    cout<<"enter the size"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    cout<<"sorted array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

/*
#include<iostream>
using namespace std;
int partition(int *a,int start,int end)
{
    int pivot_index=0;
    for(int i=0;i<=end-1;i++)
    {
        if(a[i] < a[end])       /// = very imp
        {
            int temp=a[i];
            a[i]=a[pivot_index];
            a[pivot_index]=temp;
            pivot_index++;
        }
    }
    int temp=a[end];
    a[end]=a[pivot_index];
    a[pivot_index]=temp;
    return pivot_index;
}
void quicksort(int *a,int start,int end)
{
    if(start >= end)
        return;
    int pivot=partition(a,start,end);
    quicksort(a,start,pivot-1);
    quicksort(a,pivot+1,end);
    return ;
}

int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
*/
