#include<iostream>
using namespace std;
void mergeTwoSorted(int A[], int B[], int M, int N) {
    int i = M-1, j = N-1, k = M+N-1;
    while(i>=0 && j>=0) {
        if (A[i] < B[j]) {
            A[k] = B[j];
            k--;
            j--;
        } else {
            A[k] = A[i];
            k--;
            i--;
        }
    }
    if (i< 0) {
        int l = 0; 
        for(;l <=j ; l++) {
            A[l] = B[l];
        }
    }
    return;
}
int sumofelements(int arr[], int N) {
    int sum = 0, i; 
    for (i = 0; i < N; i++) {
        sum = sum + arr[i];
    }
    return sum;
}
void incrementALLElements(int arr[], int N, int K) {
    int i = 0; 
    for(i = 0; i < N; i++) {
        arr[i]= arr[i] + K;
    }
    return;
}
void selectionsort(int arr[], int N) {
    int i, j, pos, temp;
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
}
void printArray(int arr[], int N) {
    int i = 0;
    for(; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void dummyfunction(int a) {
    a = a+ 20;
    cout << a << endl;
    return;
}
int main() {
    int A[100],B[50];
    int M, N;
    cout << "Enter values of M and N ( less than 50) ";
    cin >> M >> N;
    cout << "Enter first array in sorted order ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    cout <<"Enter second array in sorted order";
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }
    mergeTwoSorted(A,B,M,N);
    printArray(A, M+N);

/*    int a = 10;
    dummyfunction(a);
    cout << a << endl;
    int A[100];
    int N, i;
    cout << "Enter number of elements in the array ";
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }
    int K;
    cout << "Enter value by which you want to increment all the elements " ;
    cin >> K;
    incrementALLElements(A, N, K);
    printArray(A,N);
    selectionsort(A, N);
    printArray(A,N);*/

/*    int sum =  sumofelements(A, N);
    cout << "Sum of elements in the array is " << sum << endl;*/
    return 0;
}
