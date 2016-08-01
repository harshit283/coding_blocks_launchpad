#include<iostream>
#include<stack>
using namespace std;

int main ()
{
    char a[100];
    stack<char>s;
    int i=0;
    int j=0,k=0;
    bool ans=false;

    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    while(a[i]!='\0')
    {
        if(a[i]=='(' || a[i]==')')
        {
                s.push(a[i]);
        }
        i++;

    }
    while(!s.empty())
    {
        while(s.top()!='(' )
        {
            s.pop();
            j++;
        }
        while(  !s.empty() && s.top()!=')')
        {
            s.pop();
            k++;
        }
        if(j>=2 && k>=2)
        {
            ans=true;
            break;
        }
        else
        {
            j=0;
            k=0;
        }
    }
    s.clear();
    if(ans){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;

}
