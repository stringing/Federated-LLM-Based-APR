#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,v,c,a[1110][1110],dp[1110][1110];
int main(){
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    cin>>n>>m>>x>>y>>v>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int xx[10]={-1,-1,1,1},yy[10]={-1,1,-1,1};
    for(int t=0;t<4;t++){
        for(int i=x;i>0&&i<=n;i-=xx[t]){
            for(int j=y;j>0&&j<=m;i-=yy[t]){
                if(i==x&&j==y)dp[i][j]=v;
                else if(i==x)dp[i][j]=min(c,dp[i][j+yy[t]]+a[i][j]);
                else if(j==y)dp[i][j]=min(c,dp[i+xx[t]][j]+a[i][j]);
                else dp[i][j]=min(c,max(dp[i][j+yy[t]],dp[i+xx[t]][j])+a[i][j]);
                if(dp[i][j]<=0)dp[i][j]=-999999;
            }
        }
    }
    int ans=max(dp[1][1],max(dp[1][m],max(dp[n][1],dp[n][m])));
    if(ans<=0)cout<<-1;
    else cout<<ans;
    return 0;
}
