#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[30];
int x[30],y[30],c[30];
int cc[30][30];
long long ans;
int vis[1000000];
void dfs(int num,int whi,int last,long long C)
{
    if(C<vis[whi]) return;
    vis[whi]=C;
    if(num>=m)
    {
        ans=max(ans,C);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(whi&(1<<i)==(1<<i)) continue;
        dfs(num+1,whi|(1<<i),i,C+a[i]+cc[last][i]);
    }
}
int main()
{
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    memset(vis,0,sizeof(vis));
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++)
    {
        cin>>x[i]>>y[i]>>c[i];
        cc[x[i]][y[i]]=c[i];
    }
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}
