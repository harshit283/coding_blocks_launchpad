#include<iostream>
using namespace std;
int main(){
int a[256],i;
char ch;
for(i=0;i<256;i++){
    a[i]=0;
}
cout<<"enter the text"<<endl;                //creates a buffer from which cin.get() operator will read the characters
ch=cin.get();
while(ch!='$'){
    i=ch;
    a[i]++;
    ch=cin.get();
}
for(i=0;i<256;i++){
        if(a[i]!=0){
    cout<<"frequency of "<<char(i)<<"="<<a[i]<<endl;
}

}
return 0;
}
