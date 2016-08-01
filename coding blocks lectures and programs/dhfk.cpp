/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    unordered_set<char> my_set;
    int freq[256]={0};
    for(int i=0;i<s2.size();i++)
    {
        freq[s2[i]]++;
        if(my_set.count(s2[i])!=1)
         my_set.insert(s2[i]);
    }

    int start,flag=0;
    int min_len=INT_MAX;
    int start_index;
    int end_index;
    int count=0;
    for(int i=0;i<s1.size();i++)
    {
        if(my_set.count(s1[i]))
        {
            if(flag==0)
            {
                start=i;
                flag++;
            }

            freq[s1[i]]--;
            count++;
            if(count==s2.size())
            {
                if(min_len > i-start+1)
                {
                    min_len=i-start+1;
                    start_index=start;
                    end_index=i;
                }
                flag=0;
                count=0;
                for(int j=0;j<s2.size();j++)
                    freq[s2[j]]++;
            }
        }
    }

    cout<<"REQUIRED SUBSRTING IS:"<<endl;
    for(int i=start_index;i<=end_index;i++)
        cout<<s1[i];
    return 0;
}
*/


