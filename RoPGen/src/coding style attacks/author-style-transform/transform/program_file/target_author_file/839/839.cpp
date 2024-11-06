#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxv = 5005;
int n, m, x;
int c1[maxn], w1[maxn], c2[maxn], w2[maxn], dp[2 * maxn][maxv];
int main() {
    freopen ("health.in", "r", stdin);
    freopen ("health.out", "w", stdout);
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
        for (int j = 0; j <= x; j++) {
            if (j >= c1[i]) {
                dp[i][j] = max(dp[i - 1][j - c1[i]] + w1[i], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= x; j++) {
            if (j >= c2[i] && dp[i + n - 1][j - c2[i]]) {
                dp[i + n][j] = max(dp[i + n - 1][j - c2[i]] + w2[i], dp[i + n - 1][j]);
            } else {
                dp[i][j] = dp[i + n - 1][j];
            }
        }
    }
    cout << dp[n + m][x];
    return 0;
}
