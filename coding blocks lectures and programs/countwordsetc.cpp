#include<iostream>
using namespace std;
int main() {
    int lcount = 0, wcount = 0, ccount = 0;
    char prev , ch = cin.get();
    while (ch != '$') {
        ccount++;
        if (ch == '\n') {
            lcount++;
        }
        if ((ch == '\n' || ch == '\t' || ch == ' ') && (prev != ' '  && prev != '\t' && prev != '\n')) {
            wcount++;
        }
        prev = ch;
        ch = cin.get();
    }

   if (prev != ' ' && prev != '\t' && prev != '\n') {
       wcount++;
    }
    cout << "Total chars " << ccount << endl;
    cout << "Total lines " << lcount + 1<< endl;
    cout << "Total words " << wcount << endl;
    return 0;
}
