#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main ()
{
    int flag=10;
    string expression;
    cout<<"enter the string"<<endl;
    cin>>expression;   //getline(cin,expression,'\n') will read till new line character

     stack<char> s;
    for(int i=0;expression[i]!='\0';i++)
    {
          if(expression[i]=='{' || expression[i]=='[' || expression[i]=='(')
                {
                    s.push(expression[i]);
                }
                else if(expression[i]!='{' && expression[i]!='[' && expression[i]!='(')
                            {
                                char temp=expression[i];

                                if(temp==']' && s.top()=='[')
                                {
                                    s.pop();
                                   continue;
                                }
                                else if(temp=='}' && s.top()=='{')
                                    {
                                        s.pop();
                                        continue;
                                    }
                                    else if(temp==')' &&  s.top()=='(')
                                    {
                                        s.pop();
                                        continue;
                                    }
                                else
                                {
                                    flag=1;
                                    break;
                                }
                            }

    }

    if(flag==1)
    {
        cout<<"no";
    }
    else if(!s.empty())
    {
        cout<<"no";
    }
     else   cout<<"yes";


    return 0;

}
