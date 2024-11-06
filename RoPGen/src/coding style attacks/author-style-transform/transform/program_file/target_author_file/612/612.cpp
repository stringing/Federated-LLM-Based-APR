#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,v,c;
int a[1005][1005];
int dp[1005][1005];
void fun1(){
    for(int i=x;i>=1;i--){
        for(int j=y;j>=1;j--){
            if(i==x&&j!=y) dp[i][j]=min(c,dp[i][j+1]+a[i][j]);
            else if(j==y&&i!=x) dp[i][j]=min(c,dp[i+1][j]+a[i][j]);
            else dp[i][j]=min(c,max(dp[i+1][j],dp[i][j+1])+a[i][j]);
        }
    }
}void fun2(){
    for(int i=x;i>=1;i--){
        for(int j=1;j<=y;j++){
            if(i==1) dp[i][j]=min(c,dp[i][j+1]+a[i][j]);
            else if(j==y) dp[i][j]=min(c,dp[i-1][j]+a[i][j]);
            else dp[i][j]=min(c,max(dp[i-1][j],dp[i][j+1])+a[i][j]);
        }
    }
}void fun3(){
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(i==1) dp[i][j]=min(c,dp[i][j-1]+a[i][j]);
            else if(j==1) dp[i][j]=min(c,dp[i-1][j]+a[i][j]);
            else dp[i][j]=min(c,max(dp[i-1][j],dp[i][j-1])+a[i][j]);
        }
    }
}void fun4(){
    for(int i=1;i<=x;i++){
        for(int j=y;j>=1;j--){
            if(i==x) dp[i][j]=min(c,dp[i][j-1]+a[i][j]);
            else if(j==1) dp[i][j]=min(c,dp[i+1][j])+a[i][j];
            else dp[i][j]=min(c,max(dp[i+1][j],dp[i][j-1])+a[i][j]);
        }
    }
}
int main(){
    freopen("escape.in", "r", stdin);
    freopen("escape.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>x>>y>>v>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    dp[x][y]=v+a[x][y];
    fun1(),fun2(),fun3(),fun4();
    if(dp[1][1]<0&&dp[1][m]<0&&dp[n][1]<0&&dp[n][m]<0) cout<<-1;
    else cout<<max(dp[1][1],max(dp[1][m],max(dp[n][1],dp[n][m])));
    return 0;
}
