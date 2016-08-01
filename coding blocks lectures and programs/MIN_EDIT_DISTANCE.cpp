#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int mat[100][100];
    for(int i=0;i<=s1.size();i++)
    {
        mat[i][0]=i;
    }
    for(int i=0;i<=s2.size();i++)
    {
        mat[0][i]=i;
    }
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                mat[i][j]=mat[i-1][j-1];
                continue;
            }
            int temp=min(mat[i-1][j-1],mat[i-1][j]);  ///COMPARING THESE THREE MEANS COMPARING MIN OF DELETION,INSERTION AND CHANGING
                                                      ///mat[i-1][j-1]== replacing, mat[i-1][j]==delete , mat[i][j-1]==insert
                                                      ///provided d1 is converted to s2;
            mat[i][j]=min(temp,mat[i][j-1])+1;

        }
    }
    cout<<mat[s1.size()][s2.size()]<<endl;
    return 0;
}
