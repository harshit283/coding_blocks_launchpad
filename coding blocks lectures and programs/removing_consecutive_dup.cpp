#include<iostream>
using namespace std;
/*
int pos=1;
void duplicate(char *a,int index)
{
    if(a[index]=='\0')
        return ;
    if(a[index]!=a[index-1])
    {
        a[pos]=a[index];
        pos++;
    }
    duplicate(a,index+1);
    return ;
}
*/
/*
int pos=0;
void remove_x(char * a,int index)
{
    if(a[index]=='\0')
        return ;
    if(a[index]!='x')
    {
        a[pos]=a[index];
        pos++;
    }
    remove_x(a,index+1);
    return ;

}
*/
int main()
{
    char a[100];
        cin.getline(a,100);
        //duplicate(a,1);
        /*remove_x(a,0);
        a[pos]='\0';
        cout<<a;*/
        /*int pos=1;
        for(int i=1;a[i]!='\0';i++)
        {
            if(a[i]!=a[i-1])
            {
                a[pos]=a[i];
                pos++;
            }
        }
        a[pos]='\0';
        cout<<a;
        */
    return 0;
}
