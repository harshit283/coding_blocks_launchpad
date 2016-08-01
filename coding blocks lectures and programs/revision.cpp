#include<iostream>
using namespace std;
int main (){

 double x1,x2,num;
 cout<<"enter a number";
 cin>>num;
 x1=num/2;
 x2=x1-(x1*x1-num)/(2*x1);
 while(x1-x2>=.00001 || x2-x1>=.00001){
    x1=x2;
    x2=x1-(x1*x1-num)/(2*x1);
 }
 cout<<x1;
                                                         /* here printing x1 0r x2 wont matter because once last time while loop is executed diff between x1 and x2 has reaches a
                                                         further
                                                         decimal place hence answer will remain same*/

return 0;

}
