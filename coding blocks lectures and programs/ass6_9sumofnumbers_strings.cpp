#include<bits/stdc++.h>
using namespace std;
int get_value(char);
void reverse(char*);
void update(char*a,char*b)
{
    if(strlen(a)==strlen(b))return ;

    if(strlen(a) > strlen(b))
    {
        reverse(b);
        int l=strlen(b);
        while(l<strlen(a))
        {
            b[l]='0';
            l++;
        }
        b[l]='\0';
        reverse(b);
        return ;
    }

    if(strlen(a) < strlen(b))
    {
        reverse(a);
        int l=strlen(a);
        while(l<strlen(b))
        {
            a[l]='0';
            l++;
        }
        a[l]='\0';
        reverse(a);
        return ;
    }
}
void reverse(char *a)
{
    int i=0;
    int j=strlen(a)-1;
    while(j>i)
    {
        char temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;j--;
    }
    return ;
}
void add(char *a,char *b)
{
    update(a,b);
    int i=strlen(a)-1;
    int j=strlen(b)-1;
    int sum;
    char ans[1000];
    int x,y;
    int flag=0;
    int l=0;
    while(i>=0 && j>=0)
    {
        if(flag==0)
            sum=get_value(a[i])+get_value(b[j]);
        else
            sum=get_value(a[i])+get_value(b[j])+1;
        y=sum%10;
        sum=sum/10;
        x=sum%10;
        if(y==0)
            ans[l]='0';
        else if(y==1)
            ans[l]='1';
        else if(y==2)
            ans[l]='2';
        else if(y==3)
            ans[l]='3';
        else if(y==4)
            ans[l]='4';
        else if(y==5)
            ans[l]='5';
        else if(y==6)
            ans[l]='6';
        else if(y==7)
            ans[l]='7';
        else if(y==8)
            ans[l]='8';
        else if(y==9)
            ans[l]='9';

        if(x==0)flag=0;
        else flag=1;
        l++;i--;j--;
    }
    if(i<0 && j<0 && flag==1)
    {
        ans[l]='1';
        l++;
    }
    ans[l]='\0';
    reverse(ans);
    cout<<ans;
    return ;


}
int get_value(char ch)
{
    if(ch=='0')
        return 0;
    else if(ch=='1')
        return 1;
    else if(ch=='2')
        return 2;
    else if(ch=='3')
        return 3;
    else if(ch=='4')
        return 4;
    else if(ch=='5')
        return 5;
    else if(ch=='6')
        return 6;
    else if(ch=='7')
        return 7;
    else if(ch=='8')
        return 8;
    else if(ch=='9')
        return 9;
}
int main()
{
    char a[1000];
    char b[1000];
    cin.getline(a,1000);
    cin.getline(b,1000);
    cout<<"ANSWER IS:"<<endl;
    add(a,b);
    return 0;
}
