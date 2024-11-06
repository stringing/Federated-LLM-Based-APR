#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll n, m, a[55][55], max_;
int main () {
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int u = 1; u <= n; u++) {
        
        for (int p = u; p <= n; p++) {
            
            for (int l = 1; l <= m; l++) {
                for (int r = l; r <= m; r++) {
                    ll x = 0;
                    for (int i = u; i <= p; i++) {
                        for (int j = l; j <= r; j++) {
                            x += a[i][j];
                        }
                    }
                    max_ = max(x, max_);
                }
            }
        }
    }
    cout << max_;
    return 0;
}
