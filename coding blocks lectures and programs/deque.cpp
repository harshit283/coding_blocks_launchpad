#include<iostream>
using namespace std;
template<typename t>
class deque
{
    t*ptr;
    unsigned int s,c;
    int front ,rear;
public:
    deque():ptr(0),s(0),c(0),front(-1),rear(0){}
    deque(const deque & v):ptr(0),s(v.s),c(v.c),front(v.front),rear(v.rear)
    {
        if(s==0)
        {
            return ;
        }
        ptr=new t [c];
        for(int i=0;i<c;i++)
        {
            ptr[i]=v.ptr[i];
        }
        return ;
    }

    void clear()
    {
        if(s==0)
        {
            return ;
        }
        delete ptr;
        front=-1;
        rear=0;
        s=0;
        c=0;
        return ;
    }

    ~deque()
    {
        clear();
    }

    void push_back(const t & el)
    {
        if(c==0)
        {
            c=2;
            s++;
            ptr=new t [c];
            ptr[0]=el;
            front=0;
            rear=1;
            return ;
        }
       else if(s==c)
        {
            c=c*2;
            t*temp=new t[c];
            int i,j;
            j=0;
            for(i=front;i<s;i++)
            {
                temp[j]=ptr[i];
                j++;
            }
            for(i=0;i<=rear-1;i++)
            {
                temp[j]=ptr[i];
                j++;
            }
            delete ptr;
            ptr=temp;
            ptr[s]=el;
            s++;
            front=0;
            rear=s;
            return ;
        }

        ptr[rear]=el;
        rear=(rear+1)%c;
        s++;
        if(s==1)
        {
            front=0;

        }
    }

    t  pop_front()
    {
        if(s==0)
        {
            throw "list is empty";
        }
        s--;
        t data=ptr[front];
        front=(front+1)%c;
        if(s==0)
        {
            front =-1;
            rear=0;
        }
        return data;
    }


    void push_front(const t & el)
    {
        if(c==0)
        {
            c=2;
            s++;
            ptr=new t [c];
            ptr[0]=el;
            front=0;
            rear=1;
            return ;
        }
        else if(s==c)
        {
            c=c*2;
            t*temp=new t [c];
            int j=0;
            int i;
            temp[j]=el;
            j++;
            for(i=front;i<s;i++)
            {
                temp[j]=ptr[i];
                j++;
            }
            for(i=0;i<rear;i++)
            {
                temp[j]=ptr[i];
                j++;
            }
            delete ptr;
            ptr=temp;
            s++;
            front=0;
            rear=s;
            return ;
        }

        if(front==0 )
        {
            front=c-1;
            ptr[front]=el;
            s++;
            return ;
        }
        else if(front==-1)
        {
            front=0;
            ptr[front]=el;
            s++;
            rear=1;
            return;
        }
        else {
            front--;
            ptr[front]=el;
            s++;
            return;
        }
    }


    t pop_back()
    {
        if(s==0)
        {
            throw "list is empty";
        }

        if(rear==0)
        {
            rear=c-1;
            s--;
        /* int temp=rear;
         if(s==0)
         {
             front =-1;
             rear=0;
         }
         */
            return ptr[rear];

        }
        rear--;
        s--;
        int temp=rear;
        if(s==0)
        {
            front=-1;
            rear=0;
        }
        return ptr[temp];
    }

    bool empty()
    {
        return s==0;
    }


};
int main ()
{
    //CHECK FOR POP_BACK
    //error when first push front and then pop back
    deque<int>d;
    for(int i=1;i<=15;i++)
    {
        d.push_front(i);
    }

/*
    while(!d.empty())
    {
        cout<<d.pop_front()<<" ";

    }

    cout<<endl;
      for(int i=1;i<=10;i++)
    {
        d.push_front(i);
    }

    while(!d.empty())
    {
        cout<<d.pop_front()<<" ";

    }
    */



    deque<int>e=d;
    while(!e.empty())
    {
        cout<<e.pop_front()<<" ";
    }


    return 0;
}
