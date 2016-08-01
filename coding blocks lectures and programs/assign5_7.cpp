#include<iostream>
using namespace std;

float find_median(int A[],int B[],int M, int N)
{
    float median;
    int i=0,j=0,k=0;
    if((M+N)%2==0)
    {
        while(k<((M+N)/2-1))
        {
           if(A[i]<B[j])
           {
              k++;
              i++;

           }
           else
           {
              k++;
              j++;
           }
       }

       median=0;
       for(k=0;k<2;)
       {


       if(A[i]<B[j])
       {
          median+=A[i];
          i++;
          k++;
       }
       else
       {
          median+=B[j];
          j++;
          k++;
       }
       }
       median=median/(2.0);
    }
    else
    {
        while(k<(M+N)/2)
        {
           if(A[i]<B[j])
           {
              k++;
              i++;

           }
           else
           {
              k++;
              j++;
           }
       }

       if(A[i]<B[j])
       {
          median=A[i];
       }
       else
       {
          median=B[j];
       }
    }


    return median;


}

int main()
{
    int A[100], B[100];
    int i;
    int M,N;
    cout<<"Enter the size of first array ";
    cin>>M;
    cout<<"\nEnter the size of second array ";
    cin>>N;
    cout<<"\nEnter the elements of first array  (sorted)"<<endl;
    for(i=0;i<M;i++)
    {
        cin>>A[i];
    }
    cout<<"\nEnter the elements of second array (sorted) "<<endl;
    for(i=0;i<N;i++)
    {
        cin>>B[i];
    }

    cout<<"\nThe median is "<<find_median(A,B,M,N);
    return 0;





}















