#include<iostream>
using namespace std;
bool checkisprime(int);
void printFToCTable(int, int, int);    //declaralation of functions

void printFToCTable(int start, int end, int step) {
    int i;
    for (i =start ;i <= end; i+=step) {
        cout << i << '\t' << (5/9.0) * (i - 32) << endl;
    }
    return;
}
void printPrime2ToN(int N) {
    if (N <= 1) {
        return;
    }
    int i = 2;
    while (i <= N) {
        bool ans = checkisprime(i);
        if (ans == true) {
            cout << i << endl;
        }
        i++;
    }

}
bool checkisprime(int N) {
    int i = 2;
    while (i < N) {
        if (N % i == 0) {
            return false;
        }
        i = i + 1;
    }
    return true;
}
int main() {
    cout << checkisprime(10) << endl;
    cout << checkisprime(17) << endl;
    printPrime2ToN(33);
/*    printFToCTable(10, 35, 4);
    int st, ed, step;
    cin >> st >> ed >> step;
    printFToCTable (ed,st,step);
    cout << " Blah Blah Blah" << endl;*/
    return 0;
}
