#include<bits/stdc++.h>
using namespace std;
char a[100];
  int freq[256]={0};
  int n;
   char  sol[100];
   int x=1;
   ///NOTE THAT THIS LOGIC IS CORRECT BUT WE HAVE TO REMOVE DUPLICATE FROM THE GIVEN STRING
   /// ALSO BEFORE IT SAVE THE FREQ OF ALL THE CHARACTERS
   ///AT LAST IN THE CONDITION SIZE==N+1 THIS SIZE WILL BE THE ORIGINAL LENGHT OF STRING
  void permutations(int size,int len)
  {
      for(int i=0;i<len;i++)
      {
          if(freq[a[i]]!=0)
          {
              freq[a[i]]--;
              sol[size]=a[i];
              permutations(size+1,len);
              freq[a[i]]++;
          }
      }
      if(size==n)
      {
          cout<<x<<" ";
          x++;
           for(int i=0;i<size;i++)
              cout<<sol[i];
           cout<<endl;
      }
      return ;
  }
int main()
{
    cin.getline(a,100);
     n=strlen(a);
    for(int i=0;i<a[i]!='\0';i++)
        freq[a[i]]++;
    int m=n;
    int flag=0;
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]==a[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            int k;
            k=i;
            while(k<=m-2)
            {
                a[k]=a[k+1];
                k++;
            }
            i--;m--;flag=0;
        }
    }
   a[m]='\0';
    cout<<"REQUIRED PERMUTAIONS ARE"<<endl;
    permutations(0,m+1);
    return 0;
}
