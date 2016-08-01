#include<iostream>
using namespace std;
int main() {
    char ch;
    ch = cin.get(); // WILL CREATE BUFFER UNTIL NEW LINE CH. IS ENCOUNTERED
    // IF DELIMINATOR IS USED IT WILL READ UNTIL DEL. AND ALSO IT WILL NOT STORE IT
    while (ch != '#') {
        cout << ch;
        ch = cin.get();
    }
    cin.get();
    return 0;

}
