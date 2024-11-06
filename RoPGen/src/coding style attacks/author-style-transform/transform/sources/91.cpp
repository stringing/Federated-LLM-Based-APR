#include<bits/stdc++.h>
using namespace std;
int jo(int x)
{
    if(x%2==0)
    {
        return x/2;
    }
    else
    {
        int n;
        n=(x-1)/2;
        return 6*n+6;
    }
}
int main()
{
    int n,a[1001],ans=1;
    a[1]=n;
    for(int i=2;i>=0;i++)
    {
        ans++;
        a[i]=jo(a[i-1]);
        if(a[i]==n)
        {
            break;
        }
    }
    for(int i=1;i<ans;i++)
    {
        cout<<a[i]<<", ";
    }
    cout<<a[ans]<<endl;
    return 0;
}
