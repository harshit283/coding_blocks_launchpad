#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int m,n;
    cin>>m>>n;
    int a[100][100];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
   vector<vector<pair<int,int> > v;
   v.resize(m+1);
      pair<int,int>temp;
  for(int i=0;i<n;i++)
  {
      if( i==0 && mat[0][i] >=0)
      {
          temp(1,1+mat[0][i]);
          v[0].push_back(temp);
          continue;
      }
      if(i==0 && mat[0][i]<0)
      {
          temp((-1)*mat[0][i]+1,1);
          v[0].push_back(temp);
          continue;
      }
      if(mat[0][i] >=0)
      {
          temp(v[0][i].first,v[0][i].second+mat[0][i]);
          v[0].push_back(temp);
          continue;
      }
      temp(v[0][i].first+(-1)*mat[0][i],v[0][i].second);
      v[0].push_back(temp);
  }
  ///CONTINUE IF YOU WANT
  ///LOGIC IS TO STORE PAIR IN THE MATRIX
  ///FIRST WILL BE STORING LEAST NUMBER OF KEYS REQUIRED TO CROSS THAT CELL AND SECOND WILL BE STORING KEYS LEFT AFTER CROOSIONG THAT CELL
  ///NOW IMPLEMENT IT FURTHER

    return 0;
}
