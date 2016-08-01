#include<iostream>
using namespace std;
int len(char *a)
{
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    return i;
}
bool searchword(char str[][100],char*a)
{
    int i=0,n=len(a),j=0;
    for(i=0;i<n;i++)
    {
       if(str[i][100]=a[j])
       {
           j++;
           if(j==n-1){
            return true;
           }

       }
       else{
        j=0;
       }
    }
    if(j==0)
    {
        return false;
    }

}
int main ()
{
    char str[100][100],a[100];
    int i,n;
    cout<<"enter total number of strings";
    cin>>n;
    cin.getch();
    cout<<"enter the word you want to find";
    cin.getline(a,100);
    for(i=0;i<n;i++){
    cout<<"enter the string";
    cin.getline(str[i],100);
    }

    i=searchword(str,a);

    if(i==0){
        cout<<"no";

    }
    else{
        cout<<"yes";
    }

    return 0;


}
