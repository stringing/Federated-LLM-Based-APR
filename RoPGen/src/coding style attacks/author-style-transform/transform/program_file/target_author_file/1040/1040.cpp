#include <iostream>
#include <cstdio>
using namespace std;
int a[51][51];
int sum(int u, int d, int l, int r) {
    int ans = 0;
    for (int i = u; i <= d; i++) {
        for (int j = l; j <= r; j++) {
            ans += a[i][j];
        }
    }
    return ans;
}
int main() {
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int max = -100000000;
    for (int u = 0; u < m; u++) {
        for (int d = 0; d < m; d++) {
            for (int l = 0; l < n; l++) {
                for (int r = 0; r < n; r++) {
                    if (sum(u, d, l, r) > max) {
                        max = sum(u, d, l, r);
                    }
                }
            }
        }
    }
    cout << max;
    return 0;
}
