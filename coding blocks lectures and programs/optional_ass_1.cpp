#include<iostream>
#include<limits.h>
using namespace std;
int main ()
{
    char a[1000];
    cin.getline(a,100);
    int pos1=0,pos2,start=0;
    char ch1=a[0];
    char ch2='\0';
    int max_len=INT_MIN;
    int end_index;
    int start_index;
    int i=1;
    for(;a[i]!='\0';i++)
    {
        if(a[i]==ch1)
            pos1=i;
        else if(ch2=='\0')
        {
            ch2=a[i];
            pos2=i;
        }
        else if(a[i]==ch2)
            pos2=i;
        else if(a[i]!=ch1 && a[i]!=ch2)
        {
            int index=max(pos1,pos2);
            if(max_len < index-start+1)
            {
                max_len=index-start+1;
                start_index=start;
                end_index=index;
            }
            start=min(pos1,pos2)+1;
            ch1=a[index];pos1=index;
            ch2=a[i];pos2=i;
        }
    }
     int index=max(pos1,pos2);
            if(max_len < index-start+1)
            {
                max_len=index-start+1;
                start_index=start;
                end_index=index;
            }
    cout<<"REQUIRED STRING IS "<<endl;
    for(int i=start_index;i<=end_index;i++)
        cout<<a[i];


        ///APPROACH 2
        ///BY CALCULATING FREQUENCIES

   /* char a[100];
    int count[256]={0};
    int msi,fsi,startindex=0,finalindex,nonzero=0,len,maxlen=-1,intindex,i=0,flag=0;
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    while(a[i]!='\0')
    {
        if(count[a[i]]==0)
        {
            count[a[i]]++;
            nonzero++;
        }
        if(nonzero==1 && a[i+1]=='\0')
        {
            cout<<"required string is:"<<endl;
            cout<<a;
            return 0 ;
        }
        if(nonzero==2 && a[i+1]=='\0')
        {
            finalindex=i;
            len=finalindex-startindex;
            if(len>maxlen)
            {
                msi=startindex;
                fsi=finalindex;
                break;
            }
            break;
        }
        if(nonzero==2 && flag==0)
        {
            intindex=i;
            flag=1;
        }
        if(nonzero==3)
        {
            finalindex=i-1;
            len=finalindex-startindex+1;
            if(len>maxlen)
            {
                 msi=startindex;
                fsi=finalindex;
                maxlen=len;
            }
            count[a[intindex-1]]=0;
            count[a[i]]=0;
            i=intindex-1;
            startindex=intindex;
            nonzero=nonzero-2;
            flag=0;
        }
        i++;
    }
    cout<<"required string is:"<<endl;
    for(int k=msi;k<=fsi;k++)
    {
        cout<<a[k];
    }
*/
    return 0;

}
