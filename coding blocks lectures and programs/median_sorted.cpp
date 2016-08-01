#include<iostream>
using namespace std;
int getmedian(int a[],int b[],int m,int n){
    int i=0,j=0,k=0,flag=0,md;
    if((m+n)%2!=0){
        while(i<=m-1&& j<=n-1){
            k++;
            if(k<=(m+n)/2){
                if(a[i]<b[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
            else{
                    flag=1;
                break;
            }
        }
        if(flag==0){
                if(i==m){
                    md=b[(m+n)/2-i];
                    return md;
                }
                else if(j==n){
                    md=a[(m+n)/2-i];
                    return md;
                }
        }
                else if(flag==1){
                    if(a[i]>b[j]){
                        return b[j];
                    }
                    else{
                        return a[i];
                    }
                }

        }

        else{
            k=0,flag=0,i=0,k=0,md;
            while(i<=m-1 && j<=n-1){
                k++;
                if(k<=(m+n-2)/2){
                    if(a[i]<b[j]){
                        i++;
                    }
                    else{
                        j++;
                    }
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                if(i==m){
                    md=(b[(m+n-2)/2-i]+b[(m+n-2)/2-i+1])/2.0;
                    return md;
                }
                else if(j==n){
                    md=(a[(m+n-2)/2-j]+a[(m+n-2)/2-j+1])/2.0;
                }
            }
            else if(flag==1){
                if(a[i]>b[j]){
                    j++;
                if(j==n){
                    md=(b[j-1]+a[i])/2.0;
                    return md;
                }
                else if(j<n){
                    if(a[i]>b[j]){
                        md=(b[j-1]+b[j])/2.0;
                        return md;
                    }
                    else{
                        md=(b[j-1]+a[i])/2.0;
                    }
                }
        }
        else{
            i++;
            if(i==m){
                md=(a[i-1]+b[j])/2.0;
                return md;
            }
            else if(i<m){
                if(a[i]>b[j]){
                    md=(a[i-1]+b[j])/2.0;
                    return md;
                }
                else{
                    md=(a[i-1]+a[i])/2.0;
                    return md;
                }
            }
        }


        }

        }

                                             }
int main ()
{

    int a[100],b[100],m,n,i,ans;
    cout<<"enter the size of first array";
    cin>>m;
    cout<<"enter size of second array";
    cin>>n;
    cout<<"enter first sorted array";
    for(i=0;i<m;i++){
        cin>>a[i];
    }
    cout<<"enter second sorted array";
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    ans=getmedian(a,b,m,n);
    cout<<"median is"<<(float)ans;
    return 0;
}
