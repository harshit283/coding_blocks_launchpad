/*#include<iostream>
using namespace std;
int check(char*a,int i)
{

    if(a[i]=='\0'){
        return 1;
    }
    if(a[0]!='a'){
        return 0;
    }

        if(a[i]=='a'){
            if(a[i+1]=='\0'){
                return 1;
              }
            else if( a[i+1]=='a'){
                return check(a,i+2);
            }
            else if( a[i+1]=='b'){
                if(a[i+2]=='b'){
                    return check(a,i+3);
                }
                else{
                    return 0;
                }
            }
    }
        if(a[i]=='b'){
            if(a[i+1]=='b'){
                check(a,i+2);
            }
            else{
                return 0;
            }
        }
}
int main ()
{
    char a[100];
    int i;
    cout<<"enter the string(only a and b):"<<endl;
    cin.getline(a,100);
    i=check(a,0);
    if(i==0){
        cout<<"no";
    }
    else if(i==1){
        cout<<"yes";
    }

    return 0;
}
*/
#include<iostream>
using namespace std;
bool check_bb(char*);
bool check_a(char *a)
{
    if(*a=='\0')
       return true;
    if(*a=='a')
        return check_a(a+1);
    else if(*a=='b' && *(a+1)=='b')
        return check_bb(a+2);
    return false;
}
bool check_bb(char *a)
{
    if(*a=='\0')
        return true;
    if(*a=='a')
     return check_a(a+1);
    return false;
}

  int main()
  {
     char a[100];
        cin.getline(a,100);
        if(*a=='a')
            cout<<check_a(a+1);
        else cout<<"no";
        return 0;
  }
