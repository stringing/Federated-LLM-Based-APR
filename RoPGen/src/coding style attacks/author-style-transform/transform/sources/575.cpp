#include<bits/stdc++.h>
using namespace std;
int n,a[35],b[35],l[35],r[35];
void dfs(int l1,int r1,int l2,int r2)
{
    int k;
    if(l1==r1)
    {
        return;
    }
    for(k=l2;k<=r2;k++)
    {
        if(a[r1]==b[k])
        {
            break;
        }
    }
    if(l2==k)
    {
        r[a[r1]]=a[r1-1];
        dfs(l1,r1-1,l2+1,r2);
    }
    else if(r2==k)
    {
        l[a[r1]]=a[r1-1];
        dfs(l1,r1-1,l2,r2-1);
    }
    else
    {
        l[a[r1]]=a[k-l2+l1-1];
        r[a[r1]]=a[r1-1];
        dfs(l1,k-l2+l1-1,l2,k-1);
        dfs(k-l2+l1,r1-1,k+1,r2);
    }
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
    dfs(1,n,1,n);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        cout<<l[a[i]]<<" "<<r[a[i]]<<endl;
    }
    return 0;
}
