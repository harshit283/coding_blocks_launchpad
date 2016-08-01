#include<iostream>
using namespace std;
int main()
{
    int N[256];
    char ch;
    int i;
    cout<<"Input the text "<<endl;
    for(i=0;i<256;i++)
    {
        N[i]=0;
    }
    ch=cin.get();
    while(ch!='$')
    {
        i=ch;
        N[i]++;
        ch=cin.get();
    }

    for(i=0;i<256;i++)
    {
        if(N[i]!=0)
        {
            cout<<"\nFrequency of character "<<(char)(i)<<" is "<<N[i];
        }
    }
    return 0;



}
