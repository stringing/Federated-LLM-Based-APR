#include<bits/stdc++.h>
using namespace std;
int n,a[35],b[35],l[35],r[35];
int dfs(int l1,int r1,int l2,int r2)
{
    int k;
    for(k=l2;k<=r2;k++)
    {
        if(a[r1]==b[k])
        {
            break;
        }
    }
    if(l2!=k)
    {
        int len=k-l2;
        l[a[r1]]=dfs(l1,l1+len-1,l2,k-1);
    }
    if(r2!=k)
    {
        int len=r2-k;
        r[a[r1]]=dfs(r1,r1+len-1,r2,k-1);
    }
    return a[r1];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    dfs(1,n,1,n);
    for(int i=1;i<=n;i++)
    {
        cout<<l[i]<<" "<<r[i]<<endl;
    }
    return 0;
}
