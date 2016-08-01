#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool higher_precedence(char a,char b)
{
    if(a==b)
    {
        return true;
    }
    else if(a=='/' &&(b=='+' || b=='-'))
    {
        return true;
    }
    else if(a=='/' && b=='*')
    {
        return true;
    }

    else if(a=='*' && (b=='+' || b=='-'))
    {
           return true;
    }
    else if(a=='*' && b=='/' )
    {
        return true;
    }
    else if(a=='+' && b=='-')
    {
        return true;
    }
    else if(a=='-' && b=='+')
    {
        return true;
    }
    else
    {
        return false;
    }

}
int main ()
{
    char a[100];
    char b[100];
    int size=0;
    int i=0,flag=0;
    cout<<"enter the string (infix):"<<endl;
    cin.getline(a,100);
    stack<char> s;

    while(a[i]!='\0')
    {

    if(a[i]!='*' && a[i]!='/' && a[i]!='-' && a[i]!='+' && a[i]!=')' && a[i]!='(')
    {
        b[size]=a[i];
        size++;
    }
    else
    {
        if(s.empty())
        {
            b[size]=' ';
            size++;
            s.push(a[i]);
        }
        else if(a[i]=='(')
        {
            b[size]=' ';
            size++;
            s.push(a[i]);
        }
        else if(a[i]==')')
        {
             b[size]=' ';
            size++;
            while(s.top()!='(')
            {
                b[size]=s.top();
                size++;
                s.pop();
            }
            s.pop();
        }
        else
        {
            while( !s.empty() && s.top()!='(' && higher_precedence(s.top(),a[i]))
            {
                if(flag==0)
                {
                     b[size]=' ';
                     size++;
                     flag++;
                }
                b[size]=s.top();
                size++;
                s.pop();
            }
             b[size]=' ';
            size++;
            s.push(a[i]);
            flag=0;
        }
    }
    i++;
    }

    while(!s.empty())
    {
        if(flag==0)
        {
            b[size]=' ';
            size++;
            flag++;
        }
        b[size]=s.top();
        size++;
        s.pop();
    }


    cout<<endl<<"postfix expression is:"<<endl;
    for(i=0;i<size;i++)
    {
        cout<<b[i];
    }
    cout<<endl;

    return 0;
}
