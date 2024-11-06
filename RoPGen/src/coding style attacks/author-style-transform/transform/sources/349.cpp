#include<bits/stdc++.h>
using namespace std;
int a[1024][1024],dp[1024][1024],dx[4]={-1,-1,1,1},dy[4]={-1,1,-1,1};
int main()
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    int n,m,x,y,v,c;
    cin>>n>>m>>x>>y>>v>>c;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    for(int t=0;t<4;++t)
    {
        for(int i=x;i>0&&i<=n;i-=dx[t])
            for(int j=y;j>0&&j<=m;j-=dy[t])
            {
                if(i==x&&j==y)
                    dp[i][j]=v;
                else if(i==x)
                    dp[i][j]=min(c,a[i][j]+dp[i][j+dy[t]]);
                else if(j==y)
                    dp[i][j]=min(c,a[i][j]+dp[i+dx[t]][j]);
                else
                    dp[i][j]=min(c,max(dp[i][j+dy[t]],dp[i+dx[t]][j]));
                if(dp[i][j]<=0)
                    dp[i][j]=-123456789;
            }
    }
    int ans=max(max(dp[1][1],dp[1][m]),max(dp[n][1],dp[n][m]));
    
    if(ans<=0)cout<<-1;
    else cout<<ans;
}
