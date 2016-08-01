#ifndef LL_H
#define LL_H
#include<iostream>
using namespace std;
class LinkedList;
class Node {
    int data;
    Node * next;
    public:
    Node() : next(0) {}
    Node(int d) : next(0), data(d) {}
    void setData(int val) {
        data = val;
    }
    int getData() {
        return data;
    }
    friend class LinkedList;
};
class LinkedList {
    Node * head;
    Node * tail;
    void clear() {
        while(head) {
            Node * temp = head->next;
            delete head;
            head = temp;
        }
        head = tail = 0;
    }
    public:
    LinkedList() : head(0), tail(0) {}
    // Create a constructor with nodes from 1 to N
    LinkedList(int N): head(0), tail(0) {

    }
    LinkedList(const LinkedList & L2) : head(0), tail(0) {
        if (L2.head == 0) return;
        const Node * it = L2.head;
        while (it != NULL) {
 //           insertAtEnd(*(it).data);
            Node * cur = new Node(it->data);
            if (head == 0) {
                head = tail = cur;
            } else{
                tail->next = cur;
                tail = cur;
            }
            it = it->next;
        }
    }
    ~LinkedList() {
        clear();
    }
    LinkedList & operator=(const LinkedList &L) {
        clear();
        const Node * it = L.head;
        while (it != NULL) {
            insertAtEnd((*it).data);
            it = it->next;
        }
        return *this;
    }
    LinkedList & operator+=(int el) {
        insertAtEnd(el);
        return *this;
    }
    int & operator[](int index) {
        cout<<"hello";
        Node *it = head;
        while(index && it) {
            index--;
            it = it->next;
        }
        if (!it) {
            throw "Index out of bounds";
        }
        return it->data;
    }
    const Node * findMid() const {
        const Node * it1 = head;
        const Node * it2 = head;
        while (it2 && it2->next) {
            it1 = it1->next;
            it2 = it2->next->next;
        }
        return it1;
    }
    LinkedList & operator+=(const LinkedList & L) {
        const Node * it = L.head;
        while(it) {
            insertAtEnd(it->data);
            it = it->next;
        }
        return *this;
    }
    void insertAtEnd(int el) {
        Node * cur = new Node(el);
        if (head == 0) {
            head = tail = cur;
            return;
        }
        tail->next = cur;
        tail = cur;
        return;
    }
    void insertAtHead(int el) {
        Node * cur = new Node(el);
        if (head == 0) {
            head = tail = cur;
            return;
        }
        cur->next = head;
        head = cur;
        return;
    }
    void deleteFromHead() {
        if (head == 0) {
            return;
        }
        Node * temp = head;
        head = head->next;
        delete temp;
        if (head == 0) {
            tail = 0;
        }
    }
    LinkedList operator+(const LinkedList &L) const {
        LinkedList ans = *this;
        ans+=L;
        return ans;
    }
    // Post Increment
    LinkedList operator++(int val) {
        LinkedList ans = *this;
        ++(*this);
        return ans;
    }
    // Pre Increment
    LinkedList & operator++() {
        Node *it = head;
        while (it) {
            ++(it->data);
            it = it->next;
        }
        return *this;
    }
    LinkedList operator~() const {
        LinkedList ans = *this;
        Node *it = ans.head;
        while (it) {
            it->data = ~(it->data);
            it = it->next;
        }
        return ans;
    }

    void printList() const {

        Node *it = head;
        while (it) {
            cout << it->data << "-->";
            it = it->next;
        }
        cout << "NULL" << endl;
        return;
    }
    // Declaration of Member Method, defined outside
    const int & operator[](int) const;
    // Declaring friend to a function which is not a member method
    //friend bool operator==(const LinkedList &, const LinkedList &);
};
const int & LinkedList::operator[](int index) const {
    const Node *it = head;
  // cout<<"hello";
    while(index && it) {
        index--;
        it = it->next;
    }
    if (!it) {
        throw "Index out of bounds";
    }
    return it->data;
}
/*
bool operator==(const LinkedList & L1, const LinkedList & L2)  {
    const Node * it1 = L1.head;
    const Node * it2 = L2.head;
    while (it1!=NULL && it2!=NULL) {
        if (it1->data != it2->data) {
            return false;
        }
        it1 = it1->next;
        it2= it2->next;
    }
    if (it1 == NULL && it2 == NULL) {
        return true;
    } else {
        return false;
    }*/

#endif
