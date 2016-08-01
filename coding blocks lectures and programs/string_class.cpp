// You need to complete this class as assignment - 13
// This is a header file for your flexible string. I have already included function declarations.
// All you need to do is complete the functions.
// Make sure to append null character to end of the array!!

#include<iostream>
#include<cstring>
using namespace std;
class mystring {
    public :char * name;     // Pointer variable to store address of the dynamic allocated memory
    int len;        // To store length of the string
       // To store the capacity of the string
    public:
         // This is the zero parameterized constructor. It should create a empty string of initial length 0 and capacity 0;
    mystring():len(0),name(0) {
    }

    // Another constructor which takes a 'C' type string [ character array terminated by Null Character] and creates an object
    // which is same as str.
    mystring(const char *str){
         len=strlen(str);
        name=new char[len+1];
        strcpy(name,str);
        return ;

    }

    // Copy constructor
    mystring(const mystring & b) :len(b.len)
    {
        name=new char[len+1];
        strcpy(name,b.name);
        return ;

    }

    // Destructor
    ~mystring() {

        delete name;
    }

    // Copy Assignment Operator
    mystring & operator=(const mystring & b) {

        if(b.name==0)
        {
            len=b.len;
            name=0;
            return *this;
        }
        len=b.len;
        delete name;
        name=new char[len+1];
        strcpy(name,b.name);
        return *this;

    }

    // It adds ch at the end of the string
    void append(char ch) {
        if(name==0)
        {
            len=1;
            name=new char[2];
            *(name)=ch;
            *(name+1)='\0';
            return ;
        }

        char *ptr=new char[len+1];
        strcpy(ptr,name);
       delete name;
       name=new char[len+2];
       strcpy(name,ptr);
       delete ptr;
       *(name+len)=ch;
       *(name+len+1)='\0';
       len=strlen(name);
       return ;

    }


    // It adds all characters of 'C' type string str to the end.
    void append(const char *str) {
        if(name==0)
        {
            name=new char[strlen(str)+1];
            strcpy(name,str);
            len=strlen(name);
            return ;
        }
        char *ptr=new char [len+1];
        strcpy(ptr,name);
        delete name;
        int i=strlen(str);
        name=new char[len+i+1];    //number of elements including null
        strcpy(name,ptr);
        delete ptr;
        int j,k;
        for(j=len,k=0;j<=i+len-1;k++,j++)
        {
            *(name+j)=*(str+k);
        }
        *(name+len+i)='\0';
          len=strlen(name);                              //index of null
        return;

    }

    // It adds all character of string b to the end.
    void append(const mystring & b){

        if(name==0 && b.name==0)
        {
            return ;
        }
        else if(name==0 && b.name!=0)
        {
            name=new char[strlen(b.name)+1];
            strcpy(name,b.name);
            len=strlen(name);
            return;
        }
        else if(name!=0 && b.name==0)
        {
            return ;
        }

           char *ptr=new char [len+1];
        strcpy(ptr,name);
        delete name;
        int i=strlen(b.name);
        name=new char[len+i+1];    //number of elements including null
        strcpy(name,ptr);
        delete ptr;
        int j,k;
        for(j=len,k=0;j<=i+len-1;k++,j++)
        {
            *(name+j)=*(b.name+k);
        }
        *(name+len+i)='\0';    //index of null
        len=strlen(name);
        return;

    }

    // returns length of the string
    int length() const{
        if(name==0)
        {
            return 0;
        }
        int i=0;
        while(*(name+i)!='\0')
        {
            i++;
        }
        return i;
    }


    // returns true if string is empty
    bool empty() const{

        if(name==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // empty the content - free the allocated memory and reset your state to empty string
    void clear(){
        delete name;
        name=0;
        return ;

    }

    // It removes the last character
    void pop_back(){
        if(name==0)
        {
            return ;
        }
        *(name+len-1)='\0';
        char *ptr=new char[len];
        strcpy(ptr,name);
        delete name;
        name =new char[len];
        strcpy(name,ptr);
        delete ptr;
        len=strlen(name);
        return ;
    }

    // It removes characters of the string from start to end
    void remove(int start, int end) {
        int i=0;
        char*ptr = new char[100];
        while(i<start)
        {

            *(ptr+i)=*(name+i);
            i++;
        }
        int j=end+1;
        while(j<len)
        {
            *(ptr+i)=*(name+j);
            j++;i++;
        }

        delete name;
        name =new char[len-(end-start+1)+1];
        strcpy(name,ptr);
        delete ptr;
        len=strlen(name);
        return ;

    }

    // It removes characters of the string from start to len
    void remove(int start) {
        int i=0;
        char*ptr = new char[100];
        while(i<start)
        {
            *(ptr+i)=*(name+i);
            i++;
        }
        *(ptr+i)='\0';
        delete name;
        name =new char[start+1];   //ask
        strcpy(name,ptr);
        delete ptr;
        len=strlen(name);
        return ;
    }

    // It deletes characters at the index.
    void deleteAt(int index) {
        int i=0;
        char *ptr=new char[100];
        while(i<index)
        {
            *(ptr+i)=*(name+i);
            i++;
        }
       int j=index+1;
        while(j<=len)
        {
            *(ptr+i)=*(name+j);
            j++;i++;
        }
        delete name;
        name=new char[len];
        strcpy(name,ptr);
        delete ptr;
        len=len-1;
        return ;
    }

    // Returns a mystring Object which has characters of this string from start to end
    mystring substring(int start, int end) const {

        mystring ans= *this;
        int i=start;
        int j=0;
        char *ptr=new char[100];
        while(i<=end)
        {
            *(ptr+j)=*(ans.name+i);
            i++;j++;
        }
        delete ans.name;
        ans.name=new char[end-start+2];
        strcpy(ans.name,ptr);
        ans.len=strlen(ans.name);
        delete ptr;
        return ans;
    }


    // Returns a mystring Object which has characters of this string from start to length
    mystring substring(int start)  {

        int i=start;
        char *ptr=new char [100];
        int j = 0;
        while(i<=len)
        {
            *(ptr+j)=*(name+i);
            i++;
            j++;
        }

        delete name;
        name=new char[len-start+2];
        strcpy(name,ptr);
        len=strlen(name);
        delete ptr;
        return *this;

    }

    // Returns character at the index
    char getAt(int index) const {
    }

    // Returns first index of string b in this string after pos index
    int find(const mystring &b, int pos = 0) const {
    }

    // Returns first index of "C" type string str in this string after pos index
    int find(const char *str, int pos = 0) const {
    }

    // Compare function for "C" type string
    int compare(const char * str) const {
    }

    // Compare function for mystring type string
    int compare(const mystring & b) const {
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

    bool operator==(const mystring &b) const {
    }

    mystring & operator+=(char ch) {
    }

    mystring & operator+=(const char * str) {
    }

    mystring & operator+=(const mystring & b) {
    }

    const char & operator[](int index) const {
    }

    char & operator[](int index) {
    }

    // Return a new string which is concatination of the two
    mystring operator+(const mystring & b) const {
    }

    mystring operator+(const char * str) const {
    }

    const char*getstring()
    {
        return name;
    }

    void setname(const char*ptr)
    {
        delete name;
        len=strlen(ptr);
        name=new char[len+1];
        strcpy(name,ptr);
        return ;
    }

};


int main ()
{

   mystring str1("HARSHITAGGARWAL");

   //cout << "printing done\n";
  /* str1.append('a');
   cout<<str1.getstring();
  // mystring str2("harshit");
   /*str1.append(str2);
   cout<<str1.getstring();
   */
/*
    cout<<str1.getstring();
    mystring str2("harshit");
    cout<<endl<<str2.getstring();
    str1=str2;
    cout<<str1.getstring();
    cout<<endl<<str1.getstring();
    */
/*
    str1.append('Z');
    cout<<str1.getstring();
    /*
    mystring str2;
    str2=str1;
    cout<<str2.getstring();
    */
    /*
    str1.append("aggarwal");
    cout<<str1.getstring();
    */
/*
    mystring str1("harshit");
    mystring str2=str1;
    cout<<str2.getstring();
    str1.append(str2);
    cout<<str1.getstring();
    str1.clear();
    //cout<<str1.getstring();   //try not to do this
    str1.append("harshit");
    cout<<endl;
    cout<<str1.getstring();
    str1.append(str2);
    cout<<endl<<str1.getstring();
*/

/*
str1.pop_back();
   cout<<str1.getstring();
   */

     mystring str2=str1.substring(3,7);
     cout<<str2.getstring();


    return 0;
}

