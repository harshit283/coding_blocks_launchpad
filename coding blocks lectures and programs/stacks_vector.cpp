#include<iostream>
using namespace std;
template<typename t>
class stack
{
    t*ptr;
     int s;
     int c;
public:
    stack():ptr(0),s(0),c(0){}
    stack(const stack&v):ptr(0),s(v.s),c(v.c){
        ptr=new t[c];
        copy(ptr,v.ptr,s);
        return ;

    }

    void copy(t*dest,t*src,int s)
    {
        for(int i=0;i<s;i++)
        {
            dest[i]=src[i];
        }
        return ;
    }

    stack & operator = (const stack & v)
    {
        clear();
        s=v.s;
        c=v.c;
        ptr=new t [c];
        copy(ptr,v.ptr,s);

        return *this;

    }
    void clear()
    {
        if(!empty())
        {
            delete ptr;
        }
        ptr=0;
        s=0;
        c=0;
    }

    bool empty()
    {
        return s==0;
    }

    ~stack()
    {
        clear();
    }


    t & top()
    {
        if(s==0)
        {
            throw"stack is empty";
        }
        return ptr[s-1];
    }


    const t & top() const
    {
        if(s==0)
        {
            throw"stack is empty";
        }
        return ptr[s-1];

    }


    void pop()
    {
        if(s==0)
        {
            throw" stack is empty";
        }

        s--;
    }

    void push(const t&el)
    {
        if(s==c)
        {
            if(c==0)
            {
                c=2;
                s=1;
                ptr=new t[c];
                ptr[0]=el;
                return ;
            }

            c=2*c;
            t*temp=new t[c];
            copy(temp,ptr,s);
            delete ptr;
            ptr=temp;
            ptr[s]=el;
            s++;
            return ;
        }

        ptr[s]=el;
        s++;
        return ;
    }

};

int main()
{
    /*
    stack<int>s;
    int i;
    for( i=1;i<=10;i++)
    {
        s.push(i);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;
     for( i=1;i<=10;i++)
    {
        s.push(i);
    }

      stack<int>r;
    r=s;

    while(!r.empty())
    {
        cout<<r.top()<<" ";
        r.pop();
    }

    cout<<"hello";
    return 0;
    */
}
