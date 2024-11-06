#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000;
int a[maxn][maxn], dp[maxn][maxn];
int n, m, x, y, v, c;
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int dper() {
    int x, b, c, d;
    memset(dp, 0, sizeof(dp));
    for (int i = x; i <= n; i++) {
        for (int j = y; j <= m; j++) {
            if (i == x && j == y) {
                dp[i][j] = v;
            } else if (i == x) {
                if (dp[i][j - 1] + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j - 1] + a[i][j];
                }
            } else if (j == y) {
                if (dp[i - 1][j] + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + a[i][j];
                }
            } else {
                if (max(dp[i - 1][j], dp[i][j - 1]) + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
                }
            }
        }
    }
    x = dp[n][m];
    memset(dp, 0, sizeof(dp));
    for (int i = x; i >= 1; i--) {
        for (int j = y; j <= m; j++) {
            if (i == x && j == y) {
                dp[i][j] = v;
            } else if (i == x) {
                if (dp[i][j - 1] + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j - 1] + a[i][j];
                }
            } else if (j == y) {
                if (dp[i + 1][j] + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i + 1][j] + a[i][j];
                }
            } else {
                if (max(dp[i + 1][j], dp[i][j - 1]) + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]) + a[i][j];
                }
            }
        }
    }
    b = dp[1][m];
    memset(dp, 0, sizeof(dp));
    for (int i = x; i <= n; i++) {
        for (int j = y; j >= 1; j--) {
            if (i == x && j == y) {
                dp[i][j] = v;
            } else if (i == x) {
                if (dp[i][j + 1] + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j + 1] + a[i][j];
                }
            } else if (j == y) {
                if (dp[i - 1][j] + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + a[i][j];
                }
            } else {
                if (max(dp[i - 1][j], dp[i][j + 1]) + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]) + a[i][j];
                }
            }
        }
    }
    c = dp[n][1];
    memset(dp, 0, sizeof(dp));
    for (int i = x; i >= 1; i--) {
        for (int j = y; j >= 1; j--) {
            if (i == x && j == y) {
                dp[i][j] = v;
            } else if (i == 1) {
                if (dp[i][j + 1] + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j + 1] + a[i][j];
                }
            } else if (j == 1) {
                if (dp[i + 1][j] + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i + 1][j] + a[i][j];
                }
            } else {
                if (max(dp[i + 1][j], dp[i][j + 1]) + a[i][j] > c) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + a[i][j];
                }
            }
        }
    }
    d = dp[1][1];
    int ans = max(max(x, b), max(c, d));
    if (ans == 0) {
        cout << -1;
    } else {
        cout << ans;
    }
}
int main() {
    freopen ("escape.in","r", stdin);
    freopen ("escape.out", "w", stdout);
    cin >> n >> m >> x >> y >> v >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i <= m; j++) {
            cin >> a[i][j];
        }
    }
    dper();
    return 0;
}
