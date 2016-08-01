// You need to complete this class as assignment - 13
// This is a header file for your flexible string. I have already included function declarations.
// All you need to do is complete the functions.
// Make sure to append null character to end of the array!!

#ifndef MYSTRING_H
#define MYSTRING_H
class MyString {
    char * arr;     // Pointer variable to store address of the dynamic allocated memory
    int len;        // To store length of the string
    int capcity;    // To store the capacity of the string
    public:
    // This is the zero parameterized constructor. It should create a empty string of initial length 0 and capacity 10;
    MyString() {
    }

    // Another constructor which takes a 'C' type string [ character array terminated by Null Character] and creates an object
    // which is same as str.
    MyString(const char *str) {
    }

    // Copy constructor
    MyString(MyString & b) {
    }

    // Destructor
    ~MyString() {
    }

    // Copy Assignment Operator
    MyString & operator=(const MyString & b) {
    }

    // It adds ch at the end of the string
    void append(char ch) {
    }

    // It adds all characters of 'C' type string str to the end.
    void append(const char *str) {
    }

    // It adds all character of string b to the end.
    void append(const MyString & b) {
    }

    // returns length of the string
    int length() const {
    }

    // returns capacity of the string
    int capacity() const {
    }

    // returns true if string is empty
    bool empty() const {
    }

    // empty the content - free the allocated memory and reset your state to empty string
    void clear() {
    }

    // It removes the last character
    void pop_back() {
    }

    // It removes characters of the string from start to end
    void remove(int start, int end) {
    }

    // It removes characters of the string from start to len
    void remove(int start) {
    }

    // It deletes characters at the index.
    void deleteAt(int index) {
    }

    // Returns a MyString Object which has characters of this string from start to end
    MyString substring(int start, int end) const {
    }

    // Returns a MyString Object which has characters of this string from start to length
    MyString substring(int start) const {
    }

    // Returns character at the index
    char getAt(int index) const {
    }

    // Returns first index of string b in this string after pos index
    int find(const MyString &b, int pos = 0) const {
    }

    // Returns first index of "C" type string str in this string after pos index
    int find(const char *str, int pos = 0) const {
    }

    // Compare function for "C" type string
    int compare(const char * str) const {
    }

    // Compare function for MyString type string
    int compare(const MyString & b) const {
    }

    // return reference of the first character
    char & front() {
    }

    // same as above but for constant string
    const char & front() const {
    }

    // return reference of the last character
    char & back() {
    }

    // same as above but for constant string
    const char & back() const {
    }


    //Operator Overloading

    bool operator==(const MyString &b) const {
    }

    MyString & operator+=(char ch) {
    }

    MyString & operator+=(const char * str) {
    }

    MyString & operator+=(const MyString & b) {
    }

    const char & operator[](int index) const {
    }

    char & operator[](int index) {
    }

    // Return a new string which is concatination of the two
    MyString operator+(const MyString & b) const {
    }

    MyString operator+(const char * str) const {
    }

};
