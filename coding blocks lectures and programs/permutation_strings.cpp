#include<iostream>
using namespace std;
int len(char*str){
   int i=0;
   while(str[i]!='\0'){
    i++;
   }
   return i;

}

bool checkper(char*a,char*b,int m,int n){
    int i,j,l=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i]==b[j]){
               b[j]='\0';
                l++;
                break;
            }
        }
    }

    if(l==m){
        return true;
    }

 else {
    return false;
}
}

int main ()
{
    char a[100],b[100];
    int i,m,n,c,d;
    cout<<"enter first string:-";
    cin.getline(a,100);
    cout<<"enter second string:-";
    cin.getline(b,100);
    m=len(a);n=len(b);
    if(m==n){
    i=checkper(a,b,m,n);
                if(i==0){
                    cout<<"the two given strings are not permutations of each other";
                }
                    else{
                        cout<<"the two given strings are permutations of each other";
                    }
    }
    else{
        cout<<" the two given strings are not permutations of each other";
    }
                    return 0;
                }

