#include<bits/stdc++.h>
using namespace std;
long long a[100001],i=0;
int abc(int m)
{
    if(i!=0)
    {
        for(int j=0;j<=i;j++)
        {
            if(a[j]==m)
            {
                cout<<", "<<m;
                return 0;
            }
        }
    }
    a[i]=m;
    i++;
    if(m%2==0)
    {
        cout<<", "<<m;
        return abc(m/2);
    }
    else
    {
        cout<<", "<<m;
        return abc((m-1)*3+6);
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<n;
    if(n%2==0)
    {
        abc(n/2);
    }
    else
    {
        abc((n-1)*3+6);
    }
    return 0;
}
