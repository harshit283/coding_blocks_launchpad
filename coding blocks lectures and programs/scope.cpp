#include<iostream>
using namespace std;
int main() {
  /*  for(int i = 0; i < 10; i++) {
        cout << i << endl;
    }
    int i = 0;
    do {
        cout << i << endl;
        i++;
    }while(i < 10);
*/



//    cout << i << endl;

    int a = 10;
    int x;
    {
        cout << a << endl;
        char a = 'A';
        cout << a << endl;
    }
    if (true) {
        x = 1;
    }
    int i = 0;
    while (i < 5) {
        int b  = 10;
        b++;
        cout << b << endl;
        i++;
    }
//    cout << b << endl;

    cout << a << endl;
    cout << x << endl;
    return 0;
}
