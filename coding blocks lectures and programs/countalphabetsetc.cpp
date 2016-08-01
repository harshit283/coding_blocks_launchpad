#include<iostream>
using namespace std;
int main() {
    char ch;
    ch = cin.get();
    int alcount = 0, dcount = 0, wcount = 0, ocount = 0;
    while (ch != '$') {
        if (ch >= '0' && ch <= '9') {
            dcount++;
        }else if ((ch >='A' && ch <= 'Z')|| (ch >='a' && ch <='z')) {
            alcount++;
        }else if (ch == ' ' || ch == '\n' || ch == '\t') {
            wcount++;
        } else {
            ocount++;
        }
        ch = cin.get();
    }
    cout << "Total alphabets = " << alcount << endl;
    cout << "Total digits = " << dcount << endl;
    cout << "Total whitespaces = " << wcount << endl;
    cout << "Total other characters = " << ocount << endl;

    return 0;
}
