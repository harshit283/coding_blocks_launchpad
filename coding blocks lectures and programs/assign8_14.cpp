#include<iostream>
using namespace std;



void print_substrings(char ch[], int start_string)
{
    if(ch[start_string]=='\0')
    {
        return;
    }

    int j,k,l,w,v=0;
    for(j=start_string;ch[j]!='\0';j++)
        {
               for(l=start_string;ch[l]!='\0';l++)
               {

                    w=0;
                    k=j+1;
                    if(!(k>l)||(v==0))
                    {


                      cout<<ch[start_string];
                       w=1;
                       v++;
                    }

                    for(k=j+1;k<=l;k++)
                     {
                        cout<<ch[k];
                     }

                   if((w==1))
                   cout<<"\n";
               }


        }

    print_substrings(ch, start_string+1);
}

int main()
{


   char ch[100];
   cout<<"Enter the string "<<endl;
   cin.getline(ch,100);
   print_substrings(ch,0);
   return 0;


}
