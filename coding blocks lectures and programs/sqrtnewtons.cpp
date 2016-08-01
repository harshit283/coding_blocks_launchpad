#include<iostream>
using namespace std;
int main() {
    float num;
    cout << " Enter number to calculate sqrt ";
    cin >> num;
    float x1 = num / 2.0;
    float x2 = x1 - ( x1 * x1 - num)/(2 * x1);
    while (x2 - x1 >= 0.00001 || x1 - x2 >= 0.00001) {
        x1 = x2;
        x2 = x1 - ( x1 * x1 - num)/(2 * x1);
    }
    cout << x2<< endl;
    return 0;
}
