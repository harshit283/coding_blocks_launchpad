#include<iostream>
using namespace std;
int main ()
{
    int count=0,wcount=0,lcount=0;
    char ch,prev='0';
    ch=cin.get();
    while(ch!='$'){

        if(ch=='\n'){
            lcount++;
        }
       else if(ch==' ' || ch=='\t')
        {
            if(prev <='z' && prev >= 'a')
            {
                count++;
            }
        }
        prev=ch;
        ch=cin.get();
    }

            if(prev <='z' && prev >= 'a')
            {
                count++;
            }

            cout<<endl;
            cout<<lcount+1<<endl;
            cout<<count;

}
