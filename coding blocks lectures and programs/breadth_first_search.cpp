#include<iostream>
using namespace std;
template<typename t>
class queue
{
    t*ptr;
    int front,rear,s,c;

  public:
      void copy(t*dest,t*src,int size)
      {
          for(int i=0;i<size;i++)
          {
              dest[i]=src[i];
          }
          return;
      }

      void clear()
      {
          if(ptr!=0)
          {
              delete ptr;
          }
          ptr=0;
          c=0;
          s=0;
          front=-1;
          rear=0;
          return ;
      }
      queue(): ptr(0),s(0),c(0),front(-1),rear(0){}
      //front represents index of first filled cell
      //rear represents index of first empty cell
      queue(const queue & v):ptr(0),s(v.s),c(v.c),front(v.front),rear(v.rear)
      {
          ptr=new t[c];
          copy(ptr,v.ptr,s);
          return ;

      }


      bool empty()
      {
          return s==0;
      }

      queue & operator = (const queue & v)
      {
          clear();
          s=v.s;
          c=v.c;
          front=v.front;
          rear=v.rear;
          ptr=new t[c];
          copy(ptr,v.ptr,s);
          return *this;
      }


      t& f()
      {
          if(empty())
          {
              throw"index out of bounds";
          }
          else{
            return ptr[front];
          }
      }


    const t& f() const
      {
          if(empty())
          {
              throw"index out of bounds";
          }
          else
            return ptr[front];
      }


      void enqueue(const t&el)
      {
          if(c==0 )
          {
              c=2;
              s=1;
              front=0;
              rear=1;
              ptr=new t[c];
              ptr[0]=el;
              return ;
          }
          else if(s==c)
          {
              c=2*c;
              t*temp=new t[c];
              int j=0;
              for(int i=front;i<s;i++)
              {
                  temp[j]=ptr[i];
                  j++;
              }

              for(int  i=0;i<rear;i++)
              {
                  temp[j]=ptr[i];
                  j++;
              }
              delete ptr;
              ptr=temp;
              ptr[s]=el;
              s++;
              rear=s;
              front=0;
              return ;
          }

          ptr[rear]=el;
          rear=(rear+1)%c;
          s++;
          if(s==1)
          {
              front=0;
          }
          return ;
      }



      void deque()
      {
          if(empty())
          {
              throw "queue is empty";
          }

          s--;
          front=(front+1)%c;

          if(s==0)       //check that this piece of code is aloso very important;
          {
              front=-1;
              rear=0;

          }
          return ;



      }


};

int main ()
{
    queue<char> q;
    for(char i='a';i<='z';i++)
    {
        q.enqueue(i);
    }


    cout<<endl<<endl;

        while(!q.empty())
        {
            cout<<q.f()<<" ";
            q.deque();
        }



    for(char i='a';i<='z';i++)
    {
        q.enqueue(i);
    }

    cout<<endl<<endl;

        while(!q.empty())
        {
            cout<<q.f()<<" ";
            q.deque();
        }


    return 0;
}
