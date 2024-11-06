#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int n, ans = 1e9;
    cin >> n;
    for (int a = 0; a * a <= n; a++) {
        for (int b = a; b * b + a * a <= n; b++) {
            for (int c = b; a * a + b * b + c * c <= n; c++) {
                int d;
                d = sqrt(n - a * a - b * b - c * c);
                if (d * d + a * a + b * b + c * c == n) {
                    ans = min(ans, min(a, d) * 1000 + max(a, d) * 100 + b * 10 + c);
                }
            }
        }
    }
    cout << ans / 1000 << " " << ans % 1000 / 100 << " " << ans % 100 / 10 << " " << ans % 10 ; 
    return 0;
}
