#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 110;
const int MAX_M = 5100;
int n, m, x;
int f[MAX_M], g[MAX_M];
int p[MAX_N], v[MAX_N];
int q[MAX_N], w[MAX_N];
void solve (int n, int m, int v[], int w[], int f[]){
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
}
int main() {
    freopen("health.in", "r", stdin);
    freopen("health.out", "w", stdout);
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
    solve (n, x, p, v, f);
    solve (m, x, q, w, g);
    int ans = 0;
    for (int i = 0; i <= x; i++) {
        if (f[i] != 0) {
            ans = max (ans, f[i] + g[x - 1]);
        }
    }
    cout << ans << endl;
    return 0;
}
