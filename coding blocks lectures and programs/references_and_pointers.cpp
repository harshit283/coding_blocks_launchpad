#include<iostream>
using namespace std;
int &  fun()
{
    static int y=10;
    return y;
}

void func(int * &p)
{
    p=new int;
    *p=6;
    return ;
}

void fun2(int **p)
{
    *p=new int;
    **p=6;
}
int main()
{
    /*int & t=fun();
    t++;
    cout<<t<<endl;
    ;
    int &a=fun();
    a++;
    cout<<a<<endl<<t;
    */
    int *p;
    cout<<*p<<endl;
    fun2(&p);
    cout<<*p;
    return 0;
}
