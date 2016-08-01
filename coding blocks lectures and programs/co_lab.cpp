/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    vector<int>a,b;
    a.resize(256,0);
    b.resize(256,0);
    for(int i=0;i<s.size();i++)
        a[s[i]]++;

    string r;
    for(int i='a';i<='z';i++)
    {
        if(a[i])
        {
            b[i]=a[i]/2;
            int k=1;
            while(k<=b[i])
            {
                r.push_back(i);
                k++;
            }
        }
    }

   // sort(s.begin(),s.end());-

    char smallest=r[0];
    string sol;
    int prev=0;
    char temp_small='\0';
    int index;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]!=smallest && b[s[i]]>0)
        {

            if(temp_small=='\0')
            {
                 temp_small=s[i];
                 index=i;
            }

            else if(temp_small > s[i])
            {
                 temp_small=s[i];
                 index=i;
            }


            if(a[s[i]]-1 < b[s[i]])
            {
                if(s[i]=='i')
            {
                cout<<sol;
                cout<<" "<<temp_small<<endl;;
            }
                if(temp_small < s[i])
                {
                    sol.push_back(temp_small);
                    a[temp_small]--;
                    b[temp_small]--;
                    i=index;
                    temp_small='\0';
                }
                else{
                    sol.push_back(s[i]);
                    a[s[i]]--;
                    b[s[i]]--;
                    temp_small='\0';
                }
            }

        }
        else if(s[i]==smallest)
          {

           sol.push_back(s[i]);
            b[s[i]]--;
            a[s[i]]--;
            if(b[s[i]]==0)
            {
                int k=prev;
                while(r[k]==smallest && k<r.size())
                k++;
                prev=k;
                if(k==r.size())
                    break;
                smallest=r[k];
                temp_small='\0';
            }
        }
    }

   //cout<<sol;

//cout<<endl<<s<<endl<<r;
    return 0;

}           djjcddjggbiigjhfghehhbgdigjicafgjcehhfgifadihiajgciagicdahcbajjbhifjiaajigdgdfhdiijjgaiejgegbbiigida
            aaaaabccigicgjihidfiejfijgidgbhhehgfhjgiibggjddjjd
            aaaaabchadcigaicgjaihidafiecjfacijgidgbhehgfhjgiibggjdcjjd
            aaaaabiijiidigfhecjgfcijgidgbhhehgfhjgiibggjddcjjd
*/


#include<bits/stdc++.h>
using namespace std;
int sol[100];
void my_function(int n,int size)
{
    if(n==0 && size!=1)
    {
        for(int i=0;i<size;i++)
            cout<<sol[i]<<" ";
        cout<<endl;
        return ;
    }


    for(int i=1;i<=n;i++)
    {
        sol[size]=i;
        my_function(n-i,size+1);
    }

    return;
}

int main()
{
    int n;
   cin>>n;
   my_function(n,0);
    return 0;
}

