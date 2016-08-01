#include<bits/stdc++.h>
using namespace std;
int main()
{
    ///TUPPLE
    tuple<int,char,float> a(10,'b',4.19);
    tuple<int,char,int> b(11,'c',3.17);
     b=a;
     cout<<get<2>(b);


     ///ARRAYS

     /*array<int,10>my_array;
     for(int i=0;i<10;i++)
     {
         my_array.at(i)=i+1;
     }

     array<int,10> ::reverse_iterator it=my_array.rbegin();
     while(it!=my_array.rend())
     {
         cout<<*it<<" ";
         it++;
     }
     cout<<my_array[5];
     */

     ///VECTORS
     /*
     vector<int>first;
     //vector<int>first(10); size 10 with zeroes
     vector<int>second(4,100);
     auto it=second.begin();
     while(it!=second.end())
     {
         cout<<*it<<" ";
         it++;
     }
     cout<<endl;
     vector<int>third(second.begin(),second.end());
     it=third.begin();
     while(it!=third.end())
     {
         cout<<*it<<" ";
         it++;
     }

    // vector<int>fourth=third
     vector<int>fourth(third);
     cout<<endl;
     it=fourth.begin();
     while(it!=fourth.end())
     {
         cout<<*it<<" ";
         it++;
     }
     cout<<endl;
     int a[]={1,2,3,4,5};
     vector<int>fifth(a,a+sizeof(a)/sizeof(int));
     it=fifth.begin();
     while(it!=fifth.end())
     {
         cout<<*it<<" ";
         it++;
     }
*/
/*
     vector<float> v;
    // v.resize(5);

     for(int i=1;i<=10;i++)
     {
         v.push_back(i);
     }
     v.resize(5);
     v.shrink_to_fit();
     cout<<endl<<v.size()<<" "<<v.capacity();
     v.resize(8,100);
     cout<<endl<<v.size()<<" "<<v.capacity();
     v.resize(12);
     cout<<endl<<v.size()<<" "<<v.capacity();

     auto it=v.begin();
    /* while(it!=v.end())
     {
         cout<<*it<<" ";
         it++;
     }
     */
     /*
     vector<int>v;
     for(int i=1;i<=20;i++)
     {
         v.push_back(i);
     }
     */
    /*  v.erase(v.begin());
     auto it=v.begin();
     while(it!=v.end())
     {
         cout<<*it<<" ";
         it++;
     }
     */

     /*cout<<v.size()<<endl<<v.capacity();
     v.erase(v.begin(),v.end()-1);
     auto it=v.begin();
     while(it!=v.end())
     {
         cout<<*it<<" ";
         it++;
     }
     cout<<endl<<v.size()<<endl<<v.capacity();
     */

/// LIST

  /*list<int>first;
  list<int>second(4,100);
  list<int>third(second.begin(),second.end());
  list<int>::iterator it=third.begin();
  while(it!=third.end())
  {
      cout<<*it<<" ";
      it++;
  }
  */

 /* list<int>l;
  for(int i=1;i<=10;i++)
  {
      int val;
      cin>>val;
      l.push_back(val);
  }
  list<int>l2;
  for(int i=1;i<=10;i++)
  {
      int val;
      cin>>val;
      l2.push_back(val);
  }
  //l.sort();
  //l.reverse();
  l.merge(l2);
  cout<<l2.size()<<" "<<l.size();
  */

  /*
  //l.erase(l.begin());
  //l.erase(l.begin(),l.begin()+3);  ///  invalid operation in lists as they are not random access iterators
  list<int>::iterator it=l.begin();
  while(it!=l.end())
  {
      cout<<*it<<" ";
      it++;
  }
*/

   /* auto it1=l.begin();
    auto it2=l.begin();
    advance(it2,6);
    l.erase(it1,it2);
    //l.erase(it1);
   // l.erase(it2);
    it1=l.begin();
    while(it1!=l.end())
    {
        cout<<*it1<<" ";
        it1++;
    }
    */


    /*
    // list::remove_if
#include <iostream>
#include <list>

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

int main ()
{
  int myints[]= {15,36,7,17,20,39,4,1};
  std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

  mylist.remove_if (single_digit);           // 15 36 17 20 39

  mylist.remove_if (is_odd());               // 36 20

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
*/

/// DEQUE


  /* deque<int>my_deque(10);
   for(int i=0;i<10;i++)
   {
       my_deque[i]=i+1;
   }

   deque<int>::reverse_iterator it=my_deque.rbegin();
   while(it!=my_deque.rend())
   {
       cout<<*it<<" ";
       it++;
   }
*/

   ///STRING
   /*
   // string constructor
#include <iostream>
#include <string>

int main ()
{
  std::string s0 ("Initial string");

  // constructors used in the same order as described above:
  std::string s1;
  std::string s2 (s0);
  std::string s3 (s0, 8, 3);
  std::string s4 ("A character sequence", 6);
  std::string s5 ("Another character sequence");
  std::string s6a (10, 'x');
  std::string s6b (10, 42);      // 42 is the ASCII code for '*'
  std::string s7 (s0.begin(), s0.begin()+7);

  std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
  std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
  std::cout << "\ns6b: " << s6b << "\ns7: " << s7 << '\n';
  return 0;
}

*/
    return 0;
}
