#include<bits/stdc++.h>
using namespace std;
int get_word_count(char *a)
{
    int i=0;
    char prev='\0';
    int count=0;
    while(a[i]!='\0')
    {
        if(a[i]==' ')
        {
            if(prev!='\0' && prev!=' ')
                count++;
        }
        prev=a[i];
        i++;
    }
    if(prev!=' ')
        count++;
    return count;
}
int  main()
{
    char a[100];
    cout<<"enter the string :"<<endl;
    cin.getline(a,100);
    int word_count=get_word_count(a);
    word_count--;
    int count=word_count;
    cout<<word_count<<endl;
    int i=0;
    int flag=0;
    int pos=0;
    for(;a[i]!='\0';i++)
    {
        if(a[i]!=' ' && flag==0)
        {
            flag++;
            a[pos]=a[i];
            pos++;
            word_count--;
        }
       if(a[i]==' ')
        {
            flag=0;
            if(count!=word_count)
            {
                a[pos]='.';
                pos++;
            }
            if(word_count==0)
            {
               // cout<<i;
                i++;
                while(a[i]!='\0')
                {
                    a[pos]=a[i];
                    pos++;
                    i++;
                }
                a[pos]='\0';
                break;
            }
        }
    }
   cout<<"NEW STRING IS:"<<endl<<a;
    return 0;

}
