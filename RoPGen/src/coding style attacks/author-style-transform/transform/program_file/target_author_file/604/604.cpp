#include<bits/stdc++.h>
using namespace std;
int sum(int x)
{
    int s = 0;
    while(x)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}
bool cmp(int x,int y)
{
    int sx = sum(x);
    int sy = sum(y);
    if(sx<sy)
    {
        return x<y;
    }
    else
    {
        return sx<sy;
    }
}
int main()
{
    int n,a[10000];
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i = 0;i<n;i++)
    {  
        cout<<a[i]<<' ';
    }
}
