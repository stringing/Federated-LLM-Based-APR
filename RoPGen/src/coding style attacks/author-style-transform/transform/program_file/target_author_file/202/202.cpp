#include<bits/stdc++.h>
using namespace std;
int n1,n2,sx,sy,l1,l2,a[1010][1010],dp[1010][1010];
int main(){
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    int i,j;
    scanf("%d%d%d%d%d%d",&n1,&n2,&sx,&sy,&l1,&l2);
    for(i = 1;i <= n1;i++) for(j = 1;j <= n2;j++) scanf("%d",&a[i][j]);
    dp[sx][sy] = l1 - a[i][j];
    if(dp[sx][sy] <= 0){
        printf("-1");
        return 0;
    }for(i = sx;i >= 1;i--){
        for(j = sy;j >= 1;j--){
            if(i == sx && j == sy) continue;
            else if(i == sx) dp[i][j] = min(l2,dp[i][j+1]);
            else if(j == sy) dp[i][j] = min(l2,dp[i+1][j]);
            else dp[i][j] = min(l2,max(dp[i+1][j],dp[i][j+1]));
            if(dp[i][j] <= 0) dp[i][j] = INT_MIN;
        }
    }for(i = sx;i >= 1;i--){
        for(j = sy;j <= n2;j++){
            if(i == sx && j == sy) continue;
            else if(i == sx) dp[i][j] = min(l2,dp[i][j-1]);
            else if(j == sy) dp[i][j] = min(l2,dp[i+1][j]);
            else dp[i][j] = min(l2,max(dp[i+1][j],dp[i][j-1]));
            if(dp[i][j] <= 0) dp[i][j] = INT_MIN;
        }
    }for(i = sx;i <= n1;i++){
        for(j = sy;j >= 1;j--){
            if(i == sx && j == sy) continue;
            else if(i == sx) dp[i][j] = min(l2,dp[i][j+1]);
            else if(j == sy) dp[i][j] = min(l2,dp[i-1][j]);
            else dp[i][j] = min(l2,max(dp[i-1][j],dp[i][j+1]));
            if(dp[i][j] <= 0) dp[i][j] = INT_MIN;
        }
    }for(i = sx;i <= n1;i++){
        for(j = sy;j <= n2;j++){
            if(i == sx && j == sy) continue;
            else if(i == sx) min(l2,dp[i][j-1]);
            else if(j == sy) min(l2,dp[i-1][j-1]);
            else dp[i][j] = min(l2,max(dp[i-1][j],dp[i][j-1]));
            if(dp[i][j] <= 0) dp[i][j] = INT_MIN;
        }
    }printf("%d",max(dp[1][1],max(dp[1][n2],max(dp[n1][1],dp[n1][n2]))));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
