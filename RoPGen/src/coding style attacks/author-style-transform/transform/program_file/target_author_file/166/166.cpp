
#include <iostream>
using namespace std;
int a[25], dp[200005][35], n, m, k, x[25], y[25], c[25][25];
int main() {
    freopen("meal.in", "r", stdin);
    freopen("meal.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        int l;
        cin >> x[i] >> y[i] >> l;
        c[x[i] - 1][y[i] - 1] = l;
    }
    for (int i = 0; i <= n; i++) {
        dp[1 << i][i] = a[i];
    }
    for (int i = 0; i < (1 << n) - 1; i++) {
        for (int j = 0; j < n; j++) {
            if(!(i & (1 << j))) {
                dp[i | (1 << j)][j] = dp[i][k] + a[j] + c[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n) - 1; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
