#include<iostream>
using namespace std;

int length(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}

int string_compare(char A[], char B[])
{
    int i,j,k=0;
    for(i=0;;i++)
    {
        if(A[i]<B[i])
        {
            break;
        }
        else if(A[i]>B[i])
        {
            k=1;
            break;
        }

    }
    return k;

}
void swap_string(char A[],char B[])
{
    char temp[100];
    int i;
    for(i=0;A[i]!='\0';i++)
    {
        temp[i]=A[i];

    }
    temp[i]='\0';
    for(i=0;B[i]!='\0';i++)
    {
        A[i]=B[i];
    }
    A[i]='\0';
    for(i=0;temp[i]!='\0';i++)
    {
        B[i]=temp[i];

    }
    B[i]='\0';

}
void sorted_lex(char str[][100], int N, int i)
{
     if(i==N)
     {
         return;
     }
    int j;

    for(j=0;j<N-1-i;j++)
    {
        if(string_compare(str[j],str[j+1])==1)
        {
            swap_string(str[j],str[j+1]);
        }
    }
    sorted_lex(str,N,i+1);



}

void int_to_char(int n, char *ans)
{
    int i=0,j=n;
    while(j>0)
    {
        j=j/10;
        i++;

    }
    char ch;
    int k;
    for(j=i-1;j>=0;j--)
    {
        k=n%10;
        if(k==1)
        {
            ans[j]='1';
        }
        else if(k==2)
        {
            ans[j]='2';
        }
        else if(k==3)
        {
            ans[j]='3';
        }
        else if(k==4)
        {
            ans[j]='4';
        }
        else if(k==5)
        {
            ans[j]='5';
        }
        else if(k==6)
        {
            ans[j]='6';
        }
        else if(k==7)
        {
            ans[j]='7';
        }
        else if(k==8)
        {
            ans[j]='8';
        }
        else if(k==9)
        {
            ans[j]='9';
        }
        else if(k==0)
        {
            ans[j]='0';
        }

        n=n/10;
    }
}

int main()
{
    char str[10000][100];
    cout<<"Enter the number";
    int N;
    cin>>N;
    int i,j;

    for(i=0;i<N;i++)
    {
        int_to_char(i,str[i]);

    }

    sorted_lex(str,N,0);


    cout<<"\nStrings in lexicographical order "<<endl;
    for(i=0;i<N;i++)
    {
        cout<<str[i]<<endl;
    }
    return 0;

}


