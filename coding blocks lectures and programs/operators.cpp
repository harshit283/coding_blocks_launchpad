#include<iostream>
using namespace std;
int main() {
   cout << (5 & 4) << endl;          // similiar to rules in logic gates
    cout << (5 | 9) << endl;
    cout << (5 ^ 3) << endl;
    cout << (~5) << endl;
    cout << (4 << 3) << endl;
    cout << (4 >> 2) << endl;
    cout<<(-1>>5)<<endl;
    int a = 10;
    int c = a++;
    int d = ++a;
    cout<<endl<<endl;
    cout << c << endl;
    cout << d << endl;
    cout << a << endl;
    int k=10;
    cout<<(1 || (++k))<<endl;    //since this is a logical statement it will evaluate to 0 or 1 hence when it reads 1 or --- it will not
                                              //proceed further since answer will be one
    cout << k << endl;
    cout<<(0 || (++k))<<endl;
    cout << k << endl;
    return 0;
}
