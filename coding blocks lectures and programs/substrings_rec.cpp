/*#include<iostream>
using namespace std;
int main()
{
    char a[100];
    int i,j,k;
    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    cout<<"substrings are:"<<endl;
    for(i=0;a[i]!='\0';i++)
    {
        for(j=i;a[j]!='\0';j++)
        {
            for(k=i;k<=j;k++)
            {
                cout<<a[k];
            }
            cout<<endl;
        }
    }

}
*/
#include<iostream>
using namespace std;
void substring(char*a,int i)
{
    int j,k;
    if(a[i]=='\0'){
        return ;
    }
    for(j=i;a[j]!='\0';j++)
    {
        for(k=i;k<=j;k++)
        {
            cout<<a[k];
        }
        cout<<endl;
    }

    substring(a,i+1);
}
int main ()
{
    char a[100];

    cout<<"enter the string"<<endl;
    cin.getline(a,100);
    cout<<"substrings are:"<<endl;
    substring(a,0);
}
