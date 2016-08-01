#include<iostream>
using namespace std;
int main() {
    char ch;
    ch = cin.get();
    int count = 0;
    while (ch != '$') {
        count = count+1;
        ch = cin.get();
    }
    cout << "Total Characters till $ are " << count << endl;
    return 0;

}
