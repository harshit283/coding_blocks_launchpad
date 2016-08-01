#include<bits/stdc++.h>
using namespace std;
int lcs(const string &s1,const string&s2,int index_s1,int index_s2,int a[][100])
{
    if(a[index_s1][index_s2]!=-1)
    {
        return a[index_s1][index_s2];
    }
    if(index_s1==s1.size() || index_s2==s2.size())
    {
        a[index_s1][index_s2]=0;
        return 0;
    }

    if(s1[index_s1]==s2[index_s2])
    {
        a[index_s1][index_s2]=1+lcs(s1,s2,index_s1+1,index_s2+1,a);
        return a[index_s1][index_s2];
    }

    a[index_s1][index_s2]= max(lcs(s1,s2,index_s1+1,index_s2,a),lcs(s1,s2,index_s1,index_s2+1,a));
    return a[index_s1][index_s2];

}
int main()
{

   string s1,s2;
    cout<<"enter the first string:"<<endl;
    cin>>s1;
    cout<<"enter the second string"<<endl;
    cin>>s2;
    int size=max(s1.size(),s2.size());
    int a[100][100];
    for(int i=0;i<size+1;i++)
    {
        for(int j=0;j<size+1;j++)
        {
            a[i][j]=-1;
        }
    }
    cout<<lcs(s1,s2,0,0,a);


    ///FOR LONGEST PALINDROMIC SUBSEQUENCE TAKE S2 AS REVERSE ON S1

    ///DP:BOTTOM UP SOLUTION
   /* string s1,s2;
    cout<<"enter the first string:"<<endl;
    cin>>s1;
    cout<<"enter the second string"<<endl;
    cin>>s2;
    int size=max(s1.size(),s2.size());
    int a[100][100];
    int count=0;
    for(int i=0;i<=s1.size();i++)
    {
        a[i][0]=0;
    }
    for(int i=0;i<s2.size();i++)
    {
        a[0][i]=0;
    }

    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else{
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }

    cout<<a[s1.size()][s2.size()]<<endl;
*/
    return 0;
}
