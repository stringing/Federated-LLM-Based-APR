#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
int a[1005][1005];
int dp[1005][1005];
int dir[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int n, m, x, y, v, c;
void init() {
    dp[x][y] = v;
    for (int i = y + 1; i <= m; i++) {
        dp[x][i] = min(c, dp[x][i - 1] + a[x][i]);
        if (dp[x][i] <= 0) {
            dp[x][i] = -inf;
        }
    }
    for (int i = y - 1; i >= 1; i--) {
        dp[x][i] = min(c, dp[x][i + 1] + a[x][i]);
        if (dp[x][i] <= 0) {
            dp[x][i] = -inf;
        }
    }
    for (int i = x + 1; i <= n; i++) {
        dp[i][y] = min(c, dp[i - 1][y] + a[i][y]);
        if (dp[i][y] <= 0) {
            dp[i][y] = -inf;
        }
    }
    for (int i = x - 1; i >= n; i--) {
        dp[i][y] = min(c, dp[i + 1][y] + a[i][y]);
        if (dp[i][y] <= 0) {
            dp[i][y] = -inf;
        }
    }
}
int main() {
    freopen("escape.in", "r", stdin);
    freopen("escape.out", "w", stdout);
    cin >> n >> m >> x >> y >> v >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    init();
    for (int i = x + 1; i <= n; i++) {
        for (int j = y + 1; j <= m; j++) {
            dp[i][j] = min(c, max(dp[i - 1][j], dp[i][j - 1]) + a[i][j]);
            if (dp[i][j] <= 0) {
                dp[i][j] = -inf;
            }
        }
    }
    for (int i = x + 1; i <= n; i++) {
        for (int j = y - 1; j >= 1; j--) {
            dp[i][j] = min(c, max(dp[i - 1][j], dp[i][j + 1]) + a[i][j]);
            if (dp[i][j] <= 0) {
                dp[i][j] = -inf;
            }
        }
    }
    for (int i = x - 1; i <= 1; i--) {
        for (int j = y + 1; j <= m; j++) {
            dp[i][j] = min(c, max(dp[i + 1][j], dp[i][j - 1]) + a[i][j]);
            if (dp[i][j] <= 0) {
                dp[i][j] = -inf;
            }
        }
    }
    int ans = max(max(dp[1][1], dp[1][m]), max(dp[n][1], dp[n][m]));
    if (ans <= 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
