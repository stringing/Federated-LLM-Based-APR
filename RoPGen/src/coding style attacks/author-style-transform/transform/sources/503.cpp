#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int main()
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    
    
    
    
    int n,m,x,y,v,c;
    cin>>n>>m>>x>>y>>v>>c;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>dp[i][j];
        }
    }
    dp[x][y]=min(v,c);
    for(int i=x;i>=1;--i)
    {
        for(int j=y;j>=1;--j)
        {
            if(i==x&&j==y)  continue;
            dp[i][j]=min(c,max(dp[i+1][j],dp[i][j+1]));
            if(dp[i][j]<0)  dp[i][j]=-1e8;
        }
    }
    for(int i=x;i>=1;--i)
    {
        for(int j=y;j<=m;++j)
        {
            if(i==x&&j==y)  continue;
            if(j==y)
            {
                dp[i][j]=min(c,dp[i+1][j]);
            }else
                dp[i][j]=min(c,max(dp[i+1][j],dp[i][j-1]));
            if(dp[i][j]<0)  dp[i][j]=-1e8;
        }
    }
    for(int i=x;i<=n;++i)
    {
        for(int j=y;j>=1;--j)
        {
            if(i==x&&j==y)  continue;
            if(i==x)
            {
                dp[i][j]=min(c,dp[i][j+1]);
            }else
                dp[i][j]=min(c,max(dp[i-1][j],dp[i][j+1]));
            if(dp[i][j]<0)  dp[i][j]=-1e8;
        }
    }
    for(int i=x;i<=n;++i)
    {
        for(int j=y;j<=m;++j)
        {
            if(i==x&&j==y)  continue;
            if(i==x)
            {
                dp[i][j]=min(c,dp[i][j-1]);
            }else if(j==y)
            {
                dp[i][j]=min(c,dp[i-1][j]);
            }else
                dp[i][j]=min(c,max(dp[i-1][j],dp[i][j-1]));
            if(dp[i][j]<0)  dp[i][j]=-1e8;
        }
    }
    int ans=max(max(dp[1][1],dp[1][m]),max(dp[n][1],dp[n][m]));
    if(ans<=0)
    {
        cout<<-1;
    }else
    {
        cout<<ans;
    }
}
