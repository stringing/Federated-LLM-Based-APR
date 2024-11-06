#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    int n,m,x;
    cin >> n >> m >> x;
    int p[105],v[105],q[105],w[105],dp[300][300];
    for(int i = 0; i <= n; i++){
        cin >> p[i];
    }
    for(int i = 0; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 0; i <= m; i++){
        cin >> q[i];
    }
    for(int i = 0; i <= m; i++){
        cin >> w[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j >= p[i]) {
                dp[i][j] = max(dp[i - 1][j - p[i]] + v[i], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    ans += dp[n][x];
    for (int i = n + 1; i <= n + m; i++) {
        for (int j = 0; j <= x; j++) {
            if (j >= q[i] && dp[i+n-1][j-q[i]]) {
                dp[i+n][j] = max(dp[i+n-1][j] + v[i], dp[i+n-1][j-q[i]]+w[i]);
            }
        }
    }
    ans += dp[n][x];
    cout << ans << endl;
    return 0;
}
