#include<bits/stdc++.h>
using namespace std;
int n;
int stonea[15];
int stoneb[15];
bool flag;
long long ans=1000000000000LL;
void dfs(int now,int a,int b,int cnt)
{
    if(now>n&&cnt>0)
    {
        if(max(a,b)-min(a,b)<ans)
        {
            ans=max(a,b)-min(a,b);
        }
        return;
    }
    dfs(now+1,a*stonea[now],b+stoneb[now],cnt+1);
    dfs(now+1,a,b,cnt);
}
int main()
{
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>stonea[i];
        cin>>stoneb[i];
    }
    dfs(1,1,0,0);
    cout<<ans;
    return 0;
}
