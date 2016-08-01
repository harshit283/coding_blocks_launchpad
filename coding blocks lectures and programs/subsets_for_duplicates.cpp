#include<bits/stdc++.h>
using namespace std;
char a[100];
  int freq[256]={0};
  int n;
   char  sol[100];
  void combo(int size,int len,int index)
  {
      for(int i=index;i<len;i++)
      {
          if(freq[a[i]])
          {
              sol[size]=a[i];
              freq[a[i]]--;
              for(int j=0;j<size+1;j++)
                cout<<sol[j]<<" ";
              cout<<endl;
              combo(size+1,len,i);
              freq[a[i]]++;
          }
      }
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
    cout<<"REQUIRED COMBINATIONS ARE"<<endl;
    combo(0,m+1,0);
    return 0;
}

