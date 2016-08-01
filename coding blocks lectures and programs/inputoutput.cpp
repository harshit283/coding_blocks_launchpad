#include<iostream>
using namespace std;
int main() {
    int c = 1;
    int num;
    char ch;
    while ( c <= 5) {
        cin >> num;
        cin >> ch;
        cout << "Entered number was " << num << endl;
        cout << "Entered character was " << ch << endl;
        c = c+1;
    }
    return 0;
}
