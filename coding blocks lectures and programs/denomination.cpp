#incliude<iostream>
using namespace std;
int func(int s,int *a,int n)
{
    for(i=0;i<n;i++)
    {
        if(a[i]==s)
        {
            return 1;
        }
    }


    for(i=0;i<n;i++)
    {
        return func(s-a[i],a,n);
    }
}
int main()
{
    cout<<"enter the size"<<endl;
    cin>>n;
    cout<<"enter the denominations"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<"enter the sum"<<endl;
    cin>>s;
    func(s,a,n);

}
