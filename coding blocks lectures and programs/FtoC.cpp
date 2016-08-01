#include<iostream>
using namespace std;
int main() {
    int initial, final, step;
    cout << " Enter initial, final and step ";
    cin >> initial >> final >> step;
    while (initial <= final) {
        int c = (5.0/ 9) *(initial - 32);
        cout << initial << '\t' << c << endl;

        initial = initial+ step;
    }
    return 0;
}
