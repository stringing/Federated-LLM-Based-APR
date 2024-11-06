#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,v,c,a[1001][1001],dp[1001][1001];
int main(){
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    cin>>n>>m>>x>>y>>v>>c;
    int ans=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=x;i>0;i--){
        for(int j=y;j<=m;j++){
            if(i==x&&j==y)dp[i][j]=a[i][j];
            else if(i==x)dp[i][j]=min(c,dp[i][j-1])+a[i][j];
            else if(j==y)dp[i][j]=min(c,dp[i+1][j])+a[i][j];
            else dp[i][j]=min(c,max(dp[i+1][j],dp[i][j-1]))+a[i][j];
            if(dp[i][j]<0)dp[i][j]=-0x3f3f3f3f;
        }
    }
    ans=max(ans,dp[1][m]);
    for(int i=x;i>0;i--){
        for(int j=y;j>0;j--){
            if(i==x&&j==y)dp[i][j]=a[i][j];
            else if(i==x)dp[i][j]=min(c,dp[i][j+1])+a[i][j];
            else if(j==y)dp[i][j]=min(c,dp[i+1][j])+a[i][j];
            else dp[i][j]=min(c,max(dp[i+1][j],dp[i][j+1]))+a[i][j];
            if(dp[i][j]<0)dp[i][j]=-0x3f3f3f3f;
        }
    }
    ans=max(ans,dp[1][1]);
    for(int i=x;i<=n;i++){
        for(int j=y;j>0;j--){
            if(i==x&&j==y)dp[i][j]=a[i][j];
            else if(i==x)dp[i][j]=min(c,dp[i][j+1])+a[i][j];
            else if(j==y)dp[i][j]=min(c,dp[i-1][j])+a[i][j];
            else dp[i][j]=min(c,max(dp[i-1][j],dp[i][j+1]))+a[i][j];
            if(dp[i][j]<0)dp[i][j]=-0x3f3f3f3f;
        }
    }
    ans=max(ans,dp[n][1]);
    for(int i=x;i<=n;i++){
        for(int j=y;j<=m;j++){
            if(i==x&&j==y)dp[i][j]=a[i][j];
            else if(i==x)dp[i][j]=min(c,dp[i][j-1])+a[i][j];
            else if(j==y)dp[i][j]=min(c,dp[i-1][j])+a[i][j];
            else dp[i][j]=min(c,max(dp[i-1][j],dp[i][j-1]))+a[i][j];
            if(dp[i][j]<0)dp[i][j]=-0x3f3f3f3f;
        }
    }
    ans=max(ans,dp[n][m]);
    cout<<ans;
    return 0;
}

