#include<stdio.h>
void merge_two_sorted(int *a,int n)
{
    int i=0;
    int j=n/2;
    int c[100];
    int k=0;
    while(i<n/2 && j<n)
    {
        if(a[i] > a[j])
        {
            c[k]=a[j];
            j++;
            k++;
        }
        else{
            c[k]=a[i];
            i++;
            k++;
        }
    }

    if(i==n/2)
    {
        while(j<n)
        {
            c[k]=a[j];
            k++;
            j++;
        }
    }
    else if(j==n)
    {
        while(i<n/2)
        {
            c[k]=a[i];
            i++;
            k++;
        }
    }

    for( i=0;i<n;i++)
        a[i]=c[i];

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
int main()
{
    int a[100];
    int n;
    scanf("%d",&n);
    int i=0;
    for(;i<n;i++)
        scanf("%d",&a[i]);
    merge_sort(a,n);
    printf("sorted array is\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
