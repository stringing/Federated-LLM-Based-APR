#include <bits/stdc++.h>
using namespace std;
int ans = 0, n, a[10][10];
bool row[10], x1[20], x2[20];
bool check(int i, int c) {
    return !row[i] && !x1[i + c] && !x2[i - c + n];
}
void dfs(int c) {
    if (c == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check(i, c) && a[c][i]) {
            row[i] = x1[i + c] = x2[i - c + n] = true;
            dfs(c + 1);
            row[i] = x1[i + c] = x2[i - c + n] = false;
        }
    }
}
int main() {
    freopen("queen.in", "r", stdin);
    freopen("queen.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;    
}
