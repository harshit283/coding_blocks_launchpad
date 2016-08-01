
/*#include<iostream>
using namespace std;
struct node{
int data;
node*next;
};

void begin(node*&head,int el)
{
    node*temp=new node;
    temp->data=el;
    temp->next=head;
    head=temp;
    return ;
}
void print(node*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"NULL";
    return ;
}

void printrev(node*head)
{
    if(head==NULL)
    {
        return;
    }
    printrev(head->next);
    cout<<head->data<<" ";
    return ;
}

void deletefromend(node*&head)
{
    if(head==NULL)
    {
        return ;
    }
    if(head->next==NULL)
    {
        delete head;
        head=0;
        return ;
    }

    node*it=head;
    while(it->next->next!=NULL)
    {
        it=it->next;
    }
    delete it->next;
    it->next=0;
    return ;

}

void deletefromhead(node*&head)
{
    node*temp=head->next;
    delete head;
    head=temp;
    return ;

}
void insertend(node*head,int el)
{
    node*temp=new node;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=temp;
    temp->next=0;
    temp->data=el;
    return ;
}

void insertk(node*&head,int k,int el)
{
    if(k==0)
    {
        return ;
    }
    int i=1;
    node*it=head;
    node*temp=new node;
    if(k==1)
    {
        temp->next=head;
        temp->data=el;
        head=temp;
        return ;
    }
    while(i<k-1)
    {
        it=it->next;
        i++;
    }
    temp->next=it->next;
    temp->data= el;
    it->next=temp;
    return ;

}
int length(node*head)
{
    int i=0;
    while(head!=NULL)
    {
        i++;
        head=head->next;
    }
    return i;
}

void deleteatk(node*&head,int k)
{
    if(k==0)
    {
        return ;
    }
    node*it=head;
    if(k==1)
    {
        node*temp=head->next;
        delete head;
        head=temp;
        return ;

    }

    int i=1;
    while(i<k-1)
    {
        it=it->next;
        i++;
    }
    node*temp=it->next->next;
    delete it->next;
    it->next=temp;
    return ;

}
int main ()
{
    node*head=0;
    cout<<"enter the total number of elements "<<endl;
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
    {
        begin(head,i);
    }

    print(head);
    cout<<endl;
    printrev(head);
   /* cout<<endl;
    deletefromend(head);
    print(head);
    */
   /* cout<<endl;

    deletefromhead(head);
    print(head);
    */
    /*
    cout<<endl;
    insertend(head,25);
    print(head);
    */
    /*
    cout<<endl;
    cout<<"enter k"<<endl;
    int k;
    cin>>k;
    if(k>length(head))
    {
        cout<<"enter correct values";
    }
    else{
    insertk(head,k,56);
    print(head);
    }
    *//* cout<<endl;
    cout<<"enter k"<<endl;
    int k;
    cin>>k;
    if(k>length(head))
    {
        cout<<"enter correct values";
    }
    else{
    deleteatk(head,k);
    print(head);
    }

    return 0;

}
*/
#include<iostream>
using namespace std;
struct Node {
    int data;
    Node * next;
};
void insertAtTheBegining(Node * &head, int el) {
    Node * temp = new Node;
    temp->data = el;
    temp->next = head;
    head = temp;
}
/*void insertAtTheBegining(Node **head, int el) {
    Node * temp = new Node;
    temp->data = el;
    temp->next = *head;
    *head = temp;
}*/
void printList(Node * head) {
    while (head != NULL) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
void reversePrint(Node *head) {
    if(head == NULL) {
        return;
    }
    reversePrint(head->next);
    cout << head->data << " ";
    return;
}
void deleteFromEnd(Node * & head) {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = 0;
        return;
    }
    Node *it = head;
    while (it->next->next != NULL) {
        it = it->next;
    }
    delete it->next;
    it->next = 0;
    return;
}
Node * removeSmallestAndReturn(Node * &head) {
    Node * smallest = head;
    Node * it = head->next;
    Node * prevOfit = head;
    Node * prevOfSmallest = NULL;
    while(it != NULL) {
        if (it->data < smallest->data) {
            prevOfSmallest = prevOfit;
            smallest = it;
        }
        prevOfit = it;
        it = it->next;
    }
    if(smallest == head) {
        head = head->next;
    } else {
        prevOfSmallest->next = smallest->next;
    }
    smallest->next = 0;
    return smallest;
}
void selectionSort(Node *&head) {
    Node * sortHead = 0, *sortTail = 0;
    while (head != NULL) {
        Node * smallest = removeSmallestAndReturn(head);
        if (sortHead == NULL) {
            sortHead = sortTail = smallest;
        } else {
            sortTail->next = smallest;
            sortTail = smallest;
        }
    }
    head = sortHead;
}

Node * mergeTwoSorted(Node *&head1, Node * &head2) {
    Node * it1 = head1, *it2 = head2;
    Node * sortHead = 0, *sortTail = 0;
    while (it1!= NULL && it2!= NULL) {
        Node * smallest = 0;
        if (it1->data < it2->data) {
            smallest = it1;
            it1 = it1->next;
        } else {
            smallest = it2;
            it2 = it2->next;
        }
        smallest->next = 0;
        if (sortHead == NULL) {
            sortHead = sortTail = smallest;
        } else {
            sortTail->next = smallest;
            sortTail = smallest;
        }
    }
    if (it1 != NULL) {
        sortTail->next = it1;
    } else {
        sortTail->next = it2;
    }
    /*
    head1 = 0;
    head2 = 0;*/
    return sortHead;
}
Node * previousOfMid(Node * head) {
    Node * it1 = head;
    Node * it2 = head;
    Node * prevOfit1 = 0;
    while (it2 && it2->next) {
        prevOfit1 = it1;
        it1 = it1->next;
        it2 = it2->next->next;
    }
    return prevOfit1;
}
void mergeSort(Node * &head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    Node *prevOfMid = previousOfMid(head);
    Node * head1 = head;
    Node * head2 = prevOfMid->next;
    prevOfMid->next = NULL;
    mergeSort(head1);
    mergeSort(head2);
    head = mergeTwoSorted(head1, head2);
}
struct mypair{
    Node * addr;
    bool ans;
};
mypair checkPalindromeApproach1(Node * head, Node * curr) {
    mypair var;
    if (curr->next == NULL) {
        if (curr->data == head->data) {
            var.addr = head->next;
            var.ans = 1;
            return var;
        }else {
            var.addr = NULL;
            var.ans = 0;
            return var;
        }
    }
    mypair subvar = checkPalindromeApproach1(head, curr->next);
    if (subvar.ans == 0) {
        return subvar;
    }
    if ( subvar.addr->data != curr->data) {
        var.addr = NULL;
        var.ans = 0;
        return var;
    }
    var.addr = subvar.addr->next;
    var.ans = 1;
    return var;
}


int main() {
    Node * head = 0;
    int N, value;
    cin >> N;
    for (int i =0; i < N; i++) {
        cin >> value;
        insertAtTheBegining(head, value);
    }
    printList(head);
    mergeSort(head);
//    selectionSort(head);
    printList(head);
    return 0;
}
