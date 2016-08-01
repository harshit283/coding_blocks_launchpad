#include<iostream>
using namespace std;
int main() {
    int num;
    cin >> num;
    int rev, digit;
    for(rev = 0;num > 0; num = num/10) {
        digit = num % 10;
        rev = rev * 10 + digit;
    }
    cout << rev << endl;
    return 0;
}
