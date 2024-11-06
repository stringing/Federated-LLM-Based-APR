#include<bits/stdc++.h>
using namespace std;
int n,m,x,dp[2][5005];
int p[5005],v[5005],q[5005],w[5005];
int main()
{
    freopen("health.in","r",stdin);
     freopen("health.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        cin>>q[i];
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=x;j>=p[i];j--)
            dp[0][j]=max(dp[0][j],dp[0][j-p[i]]+v[i]);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=x;j>=q[i];j--)
        {
            dp[1][j]=max(dp[1][j],dp[1][j-q[i]]+w[i]);
        }
    }
    int maxx=0;
    for(int i=0;i<=x;i++)
    {
        if(dp[0][i]){
            maxx=max(maxx,dp[0][i]+dp[1][x-i]);
        }
    }
    cout<<maxx<<endl;
    return 0;
}
