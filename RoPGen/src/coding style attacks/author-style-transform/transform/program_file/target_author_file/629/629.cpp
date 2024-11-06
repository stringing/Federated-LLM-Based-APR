#include <bits/stdc++.h>
using namespace std;
int p[105], v[105];
int q[105], w[105];
int dp[5005];
int main() {
    freopen("health.in", "r", stdin);
    freopen("health.out", "w", stdout);
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; 
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i]; 
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i]; 
    }
    for (int i = 1; i <= m; i++) {
        cin >> w[i]; 
    }
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= p[i]; j--) {
            dp[j] = max(dp[j], dp[j - p[i]] + v[i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = x; j >= q[i]; j--) {
            if (dp[j] != 0) {
                dp[j] = max(dp[j], dp[j - q[i]] + w[i]);
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}
