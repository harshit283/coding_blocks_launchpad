#include<iostream>
using namespace std;
int main() {
    int arr[10];
    cout << sizeof(arr) << endl;
    int i = 0;
    for (i = 0; i <= 9; i++) {
        cin >> arr[i];
    }
    int sum = 0;
    for (i = 0; i < 10; i++) {
        sum += arr[i];
    }
    cout << "sum of elements = " << sum << endl;
    cout << "array in reverse : ";
    for (i = 9; i>=0; i--) {
        cout << arr[i] << " ";
    }
    int largest  = arr[0];
    for (i = 1; i < 10; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    cout << "largest element in the array = " << largest << endl;
    return 0;
}
