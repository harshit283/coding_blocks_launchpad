#include<iostream>
using namespace std;
void min_heapify(int *a,int heap_size,int i)
{
    int left=2*i+1;
    int right=left+1;
    int smallest=i;
    if(left < heap_size && a[i] > a[left])
    {
        smallest=left;
    }
    if(right < heap_size && a[smallest] > a[right])
    {
        smallest=right;
    }
    if(smallest!=i)
    {
        int temp=a[i];
        a[i]=a[smallest];
        a[smallest]=temp;
        min_heapify(a,heap_size,smallest);
    }
    return ;
}
int main ()
{
    cout<<"enter the number of elements:";
    int n;
    cin>>n;
    cout<<"enter the elements:"<<endl;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int heap_size=n;
    for(int i=(n-2)/2;i>=0;i--)
    {
        min_heapify(a,heap_size,i);
    }
    int sol[100];
    int size=n-1;
    int count=0;
    while(size)
    {
        sol[count]=a[0];
        a[0]=a[size];
        size--;
        count++;
        heap_size--;
        min_heapify(a,heap_size,0);
    }
    sol[count]=a[0];
    cout<<"sorted array is:"<<endl;
    for(int i=0;i<n;i++)
    {
        a[i]=sol[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
