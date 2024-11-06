#include <bits/stdc++.h>
using namespace std;
int c1[110], w1[110], c2[110], w2[110];
int dp[5010];
int main() {
    freopen("health.in", "r", stdin);
    freopen("health.out", "w", stdout);
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        cin >> c1[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> w1[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c2[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> w2[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= c1[i]; j--) {
            dp[j] = max(dp[j], dp[j - c1[i]] + w1[i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = x; j >= c2[i]; j--) {
            dp[j] = max(dp[j], dp[j - c2[i]] + w2[i]);
        }
    }
    cout << dp[x];
    return 0;
}
