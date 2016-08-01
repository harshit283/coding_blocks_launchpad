#include<iostream>
using namespace std;
int main ()
{
    char a[100];
    int count[256]={0};
    int fsi,msi,startindex=0,finalindex,i=0,len,max=-1;
    cout<<"enter the string:"<<endl;
    cin.getline(a,100);


    while(a[i]!='\0')
    {
        if(count[a[i]]==0 && a[i+1]=='\0')
        {
            finalindex=i;
            len=finalindex-startindex+1;
            if(len>max)
            {
                msi=startindex;
                fsi=finalindex;
                break;
            }
            break;
        }
         if(count[a[i]]==0)
        {
            count[a[i]]++;
            finalindex=i;
        }
        else{

            len=finalindex-startindex+1;
            if(len==26)
            {
                msi=startindex;
                fsi=finalindex;
                break;
            }
            if(len>max)
            {
                max=len;
                msi=startindex;
                fsi=finalindex;
            }

            for(int k=startindex;k<=finalindex;k++)
            {
                count[a[k]]=0;
            }
            startindex=i;
            i--;
        }
        i++;

    }
    cout<<"required string is:"<<endl;
    for(int j=msi;j<=fsi;j++)
    {
        cout<<a[j];
    }
    return 0;
}
