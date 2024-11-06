#include<bits/stdc++.h>
using namespace std;
int n;
int minn=INT_MAX;
int a[100];
int b[110];
void dfs(int k,int t,int p,int cnt)
{
    if(k==n)
    {
        if(cnt>0)
            minn=min(minn,abs(t-p));
        return;
    }
    if(k>n)
        return;
    dfs(k+1,t*a[k],p+b[k],cnt+1);
    dfs(k+1,t,p,cnt);
}
int main()
{
    freopen("stone,in","r",stdin);
    freopen("stone.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    dfs(1,1,0,1);
    cout<<minn;

    return 0;
}

