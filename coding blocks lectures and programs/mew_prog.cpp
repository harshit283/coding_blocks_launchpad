/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int freq[256]={0};
    for(int i=0;i<s.size();i++)
        freq[s[i]]++;
    unordered_set<int> my_set;
    for(int i='a';i<='z';i++)
    {
        if(freq[i])
            my_set.insert(freq[i]);
    }
    auto it=my_set.begin();
    int i=0;
    while(it!=my_set.end())
    {
        i++;
        it++;
    }
    if(i==1)
        cout<<"YES";
    else if(i>2)
        cout<<"NO";
    else if(i==2)
    {
        it=my_set.begin();
        int f1=*it;
        it++;
        int f2=*it;
        int count1=0;
        int count2=0;
        for(int i='a';i<='z';i++)
       {
           if(freq[i]==f1)
            count1++;
           else if(freq[i]==f2)
            count2++;
       }
       if(count1==1 || count2==1)
        cout<<"YES";
       else cout<<"NO";
    }
    return 0;
}
*//*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    vector<vector<int> >v;
    v.resize(b.size()+1);
    for(int i=0;i<=b.size();i++)
        v[i].resize(a.size()+1);
    for(int i=0;i<=a.size();i++)
        v[0][i]=0;
    for(int i=1;i<=b.size();i++)
        v[i][0];

    int max_val=-1;

    for(int i=1;i<=b.size();i++)
    {
        for(int j=1;j<=a.size();j++)
        {
            if(b[i-1]==a[j-1])
                v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=max(v[i-1][j],v[i][j-1]);
            if(v[i][j] > max_val)
                max_val=v[i][j];
        }
    }

    cout<<max_val;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

// suffixRank is table hold the rank of each string on each iteration
// suffixRank[i][j] denotes rank of jth suffix at ith iteration

int suffixRank[20][int(1E6)];

// Example "abaab"
// Suffix Array for this (2, 3, 0, 4, 1)
// Create a tuple to store rank for each suffix

struct myTuple {
    int originalIndex;   // stores original index of suffix
    int firstHalf;       // store rank for first half of suffix
    int secondHalf;      // store rank for second half of suffix
};


// function to compare two suffix in O(1)
// first it checks whether first half chars of 'a' are equal to first half chars of b
// if they compare second half
// else compare decide on rank of first half

int cmp(myTuple a, myTuple b) {
    if(a.firstHalf == b.firstHalf) return a.secondHalf < b.secondHalf;
    else return a.firstHalf < b.firstHalf;
}

int main() {

    // Take input string
    // initialize size of string as N

    string s; cin >> s;
    int N = s.size();

    // Initialize suffix ranking on the basis of only single character
    // for single character ranks will be 'a' = 0, 'b' = 1, 'c' = 2 ... 'z' = 25

    for(int i = 0; i < N; ++i)
        suffixRank[0][i] = s[i] - 'a';

    // Create a tuple array for each suffix

    myTuple L[N];

    // Iterate log(n) times i.e. till when all the suffixes are sorted
    // 'stp' keeps the track of number of iteration
    // 'cnt' store length of suffix which is going to be compared

    // On each iteration we initialize tuple for each suffix array
    // with values computed from previous iteration

    for(int cnt = 1, stp = 1; cnt < N; cnt *= 2, ++stp) {

        for(int i = 0; i < N; ++i) {
            L[i].firstHalf = suffixRank[stp - 1][i];
            L[i].secondHalf = i + cnt < N ? suffixRank[stp - 1][i + cnt] : -1;
            L[i].originalIndex = i;
        }

        // On the basis of tuples obtained sort the tuple array

        sort(L, L + N, cmp);

        // Initialize rank for rank 0 suffix after sorting to its original index
        // in suffixRank array

        suffixRank[stp][L[0].originalIndex] = 0;

        for(int i = 1, currRank = 0; i < N; ++i) {

            // compare ith ranked suffix ( after sorting ) to (i - 1)th ranked suffix
            // if they are equal till now assign same rank to ith as that of (i - 1)th
            // else rank for ith will be currRank ( i.e. rank of (i - 1)th ) plus 1, i.e ( currRank + 1 )

            if(L[i - 1].firstHalf != L[i].firstHalf || L[i - 1].secondHalf != L[i].secondHalf)
                ++currRank;

            suffixRank[stp][L[i].originalIndex] = currRank;
        }

    }

    // Print suffix array

    for(int i = 0; i < N; ++i) cout << L[i].originalIndex << endl;

    return 0;
}
