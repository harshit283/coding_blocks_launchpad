#include<iostream>
using namespace std;
void func(int arr[]) {
    cout << arr << endl;                        //aray is not actually a pointer but behaves like a pointer, copy of first elements is passed is passed into thefunc
                                                  //firstly arr prints address of the first element but later &add ptints add of the copy of thefirst element
    cout << &arr << endl;
   cout << sizeof(arr) << endl;
    return;
}
void func2(int * arr) {
    cout << arr << endl;
    cout << sizeof(arr) << endl;
    return;
}
int * fun2() {
    int arr[] = {1,2,3};
    cout << arr << endl;
    return arr;
}
int main() {
   /* int * ptr = fun2();
    cout << ptr << endl;
    cout << *ptr << endl;
    return 0;*/

    int arr[] = {1,2,3,4,5};
    cout << arr << endl;
    cout<<&arr<<endl;
    cout << sizeof(arr) << endl;
    func(arr);

    cout << arr << endl;
    cout << *(arr+0) << endl;
    cout << *(arr+2) << endl;
    cout << *(arr+ 10) << endl;
    return 0;
}
