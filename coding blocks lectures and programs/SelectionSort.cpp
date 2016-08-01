#include<iostream>
using namespace std;
int main() {
    int arr[100];
    int N;
    int i = 0,j;
    int pos, temp;
    cout << "Enter total numbers ( < 100) ";
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (i = 0; i < N-1; i++) {
        pos = i;
        j = i+1;
        while (j <= N-1) {
            if (arr[j] < arr[pos]) {
                pos = j;
            }
            j = j+1;
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
    cout << "Array after sorting " << endl;
    for (i = 0; i < N; i++) {
        cout << arr[i] <<  " ";
    }
    cout << endl;
    return 0;
}
