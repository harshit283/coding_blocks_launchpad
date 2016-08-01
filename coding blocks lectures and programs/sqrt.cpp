#include<iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter number to find square root ";
    cin >> num;
    int i = 1;
    while (i * i <= num) {
        i = i + 1;
    }
    float ans = i - 1;
    float fractionaldelta = 0.1;
    float tempans;
    int k = 1, p, digit;
    while (k <= 5) {
        p = 1;
        tempans = ans + fractionaldelta * p;
        while (tempans * tempans <= num) {
            p = p + 1;
            tempans = ans + fractionaldelta * p;
        }
        digit = p - 1;
        ans = ans + fractionaldelta * digit;
        fractionaldelta = fractionaldelta / 10;
        k = k + 1;
    }
    cout << " Ans is " << ans << endl;
    return 0;
}
