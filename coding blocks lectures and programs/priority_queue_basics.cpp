#include<iostream>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
/*class compare
{
    public:
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
         return a.first < b.first;
    }
};
*/
class compar
{
    public:
    bool operator()(int a,int b)  //// still no idea about() so learn for now
    {
        return a>b;
    }
};
int main ()
{
    priority_queue< pair<int,int> ,vector<pair<int,int> > , greater<pair<int,int> > >my_queue;///continer adapters like priority_queue uses object as comparator
    for(int i=1;i<=3;i++)  //if first objest is same them compares with second
    {
        int val;
        cin>>val;
        int val2;
        cin>>val2;
        pair<int,int>temp(val,val2);              ///BEST APPROACH WILL BE TO USE INBUILT FUNCTIONAL LIBRARY TO GET RID OF ALL THIS HEADACHE
                                                 ///JUST REMEMBER TO PASS OBJEST IN CASE OF CONTAINER ADAPTERS WHILE FUNCTORS() IN OTHERS
                                                /// ANOTHER CONCEPT OF FUNCTION POINTERS EXISTS IN THIS WHICH CAN BE LEFT AT THIS MOMENT
        my_queue.push(temp);
    }
    while(!my_queue.empty())
    {
        pair<int,int> temp=my_queue.top();
        cout<<temp.second<<" ";
        my_queue.pop();
    }

/*
int a[100]={1,3,2,5,4};
sort(a,a+5,compar());   ///in sort function and many func in algoritnm library ,function has to be passed or the one we did
for(int i=0;i<5;i++)
{
    cout<<a[i]<<" ";
}
   */
    return 0;
}
