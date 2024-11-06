#include<bits/stdc++.h>
using namespace std;
int dp[5010];
int w[105], c[105],q,m;
int main() {
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    int N,M,X;
    cin >> N>>M>>X;
    for (int i = 1; i <= N; i++)cin>>c[i];
    for (int i = 1; i <= N; i++)cin>>w[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <=N; j++)
            if (j >= c[i])dp[j]=max(dp[j-c[i]]+w[i],dp[j]);
            else dp[j]=dp[j-1];
    }
    N=M;
    for (int i = 1; i <= N; i++)cin>>c[i];
    for (int i = 1; i <= N; i++)cin>>w[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <=N; j++){
            if(dp[j]==0)continue;
            if (j >= c[i])dp[j]=max(dp[j-c[i]]+w[i],dp[j]);
            else dp[j]=dp[j-1];
        }

    }
    cout<<dp[X]<<endl;
    return 0;
}
