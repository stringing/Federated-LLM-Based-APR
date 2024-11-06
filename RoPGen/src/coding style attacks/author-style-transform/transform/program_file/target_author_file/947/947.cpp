#include <bits/stdc++.h>
using namespace std;
int n;
int a[11][11];
bool row[10], x1[20], x2[20];
int ans;
bool check(int i, int c) {
    return !row[i] && !x1[i + c] && !x2[i - c + n];
}
void dfs(int c, int p) {
    if(c == n) {
        if(p >= 1) {
            ans++;
            return;
        }
        dfs(0, p + 1);
    }
    for(int i = 0; i < n; i++) {
        if(check(i, c) && a[i][c] != 0) {
            row[i] = x1[i + c] = x2[i - c + n] = true;
            dfs(c + 1, p);
            row[i] = x1[i + c] = x2[i - c + n] = false;
        }
    }
}
int main() {
    freopen("queen.in", "r", stdin);
    freopen("queen.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}
