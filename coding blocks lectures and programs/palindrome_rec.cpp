#include<iostream>
using namespace std;
int len(char*a)
{
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    return i;
}
int rev(char *a,int j,int i)
{

    if(j<=i){
        return 1;
    }
    else{
        if(a[i]==a[j]){

            return rev(a,j-1,i+1);
        }
        else{
            return 0;
        }
    }

}

int main ()
{
    char a[100] ="uxxdlselxmwyiguugtpsypfudffswvwyswyyiiyywsywvsffdufpysptguugiywmxlesldxxu";
    int n,i;
    cout<<"enter the string"<<endl;
    //cin.getline(a,100);
   i= rev(a,len(a)-1,0);
   if(i==1)
    cout<<"yes";
   else
    cout<<"no";

    return 0;
}
