#include<bits/stdc++.h>
using namespace std;
int a[1000000000];
int main() {
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    int k[1000000000];
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (binary_search(a, a + m, k[i])) {
                cout << "YES" << endl;
            }
            if (j == m - 1) {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
