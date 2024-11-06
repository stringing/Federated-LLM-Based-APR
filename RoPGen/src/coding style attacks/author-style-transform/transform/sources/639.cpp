#include <iostream>
#include <algorithm>

using namespace std;

int a[110]={};

int cmp(int a,int b)
{
    int d=a;
    int e=b;       
    if(a>9&&a<100)
    {
        a=a/10+a%10;
    }
    if(b>9&&b<100)
    {
        b=b/10+b%10;
    }
    if(b>=100&&b<=999)
    {
        b=b/100+b/10%10+b%10;
    }
    if(a>=100&&a<=999)
    {
        a=a/100+a/10%10+a%10;
    }
    if(b>=1000&&b<=9999)
    {
        b=b/100+b/100%10+b/10%10+b%10;
    }
    if(a>=1000&&a<=9999)
    {
        a=a/1000+a/100%10+a/10%10+a%10;
    }
    if(a==b)
    {
        return d<e;
    }
    return a<b;
}

int main()
{
    int n=0;
    int max=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
