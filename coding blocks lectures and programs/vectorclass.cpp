#include<iostream>
using namespace std;
template <typename t>
class vector
{
    t*ptr;
    unsigned int size;
    unsigned int capacity;

public:
    vector():size(0),capacity(0),ptr(0){}  //default copy constructor

    vector(unsigned int n,const t&el):ptr(0),size(n),capacity(n)     //parametrised copy constructor
    {
        ptr=new t[capacity];
        for(int i=0;i<size;i++)
        {
            ptr[i]=el;
        }

    }
    unsigned int getsize()const
    {
        return size;
    }
    unsigned int getcapacity()const
    {
        return capacity;
    }
    void clear()
    {
        if(ptr==0)
        {
            return ;
        }

        delete ptr;
        ptr=0;
        size=0;
        capacity=0;
    }

    ~vector()
    {
        clear();

    }


    vector(const vector & v):size(v.size),capacity(v.capacity)
    {
        ptr=new t[capacity];
        for(int i=0;i<size;i++)
        {
            ptr[i]=v.ptr[i];
        }

    }

    vector & operator =(const vector&v)
    {
        if(ptr!=0)
        {
            delete ptr;
        }
        ptr=new t[v.capacity];
        copy(ptr,v.ptr,v.size);
        size=v.size;
        capacity=v.capacity;
        return *this;
    }


    void copy( t*dest,const t*src,unsigned int size)
    {
        for(int i=0;i<size;i++)
        {
            dest[i]=src[i];
        }
        return ;
    }

    t & operator [](int index)
    {
        if(index <0 || index>=size)
        {
            throw "index out of bounds";
        }
        return ptr[index];
    }

    const t & operator [](int index) const
    {
        if(index <0 || index>=size)
        {
            throw "index out of bounds";
        }
        return ptr[index];
    }

    bool empty() const{

    if(size==0)
        return true;
        else
            return false;
    }

    void pop_back()
    {
        if(ptr==0)
        {
            throw"vector is empty";
        }
        size--;
    }

    void pushback(const t&el)
    {
        if(size==capacity)
        {
            if(capacity==0)
            {
                capacity=2;
            }
            else
            {
                capacity=capacity*2;

            }

        t*ptr2=new t[capacity];.
        copy(ptr2,ptr,size);
        delete ptr;

        ptr=ptr2;
        //cout<<"hello";
        ptr[size]=el;
        size++;
        return ;
        }
        else
        {
            ptr[size]=el;
            size++;
            return ;
        }


    }
     template<typename u>
    friend ostream & operator <<( ostream & ,const vector<u> & );


};

   template <typename u>
  ostream & operator <<(  ostream &print ,const vector<u> & v)//we declare const only for methodsof a class
  {
      for(int i=0;i<v.size;i++)
      {
          print<<v.ptr[i]<<" ";
      }
      return print;
  }
int main ()
{

    vector<int> arr(10,1);
    /*
    cout<<arr.getcapacity();
    cout<<endl<<arr<<endl;;
    cout<<arr[6];
    */
    /*
    arr.pop_back();
    cout<<arr;
    vector <int>arr2;
    arr2=arr;
    cout<<arr2;
    */
    /*
    vector <int>arr2=arr;
    cout<<arr2;
    */
     arr.pushback(100);
     cout<<arr;
    return 0;
}
