#include<bits/stdc++.h>
using namespace std;
int n,a[1010],b[1010],l[1010],r[1010];
int dfs(int x,int y,int len)
{
    int p;
    if(len==0)
    {
        return a[x];
    }
    p=y;
    while(a[x]!=b[p])
    {
        p--;
    }
    int k=y-p;
    r[a[x]]=dfs(x-1,y,k);
    l[a[x]]=dfs(x-k-1,p-1,len-k-1);
    return a[x];
}
int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    dfs(n,n,n);
    for(int i=1;i<=n;i++)
    {
        cout<<l[i]<<" "<<r[i]<<endl;
    }
    return 0;
}
