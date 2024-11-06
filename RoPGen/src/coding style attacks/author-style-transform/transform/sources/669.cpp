#include <iostream>
using namespace std;
int n, m, x, p[105], v[105], q[105], w[105], dp1[105][5005], dp2[105][1005];
int main() {
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
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
        for (int j = 0; j <= x; j++) {
            if (j >= p[i]) {
                dp1[i][j] = max(dp1[i - 1][j - p[i]] + v[i], dp1[i - 1][j]);
            } else {
                dp1[i][j] = dp1[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= x; j++) {
            if (j >= q[i]) {
                dp2[i][j] = max(dp2[i - 1][j - q[i]] + w[i], dp2[i - 1][j]);
            } else {
                dp2[i][j] = dp2[i - 1][j];
            }
        }
    }
    int ans = -1;
    for (int i = 0; i <= x; i++) {
        if (dp1[n][i] != 0) {
            ans = max(ans, dp1[n][i] + dp2[m][x - i]);
        }
    }
    cout << ans << endl;
    return 0;
}
