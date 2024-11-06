#include <bits/stdc++.h>
using namespace std;
int n, b, h[25], ans = 2147483647;
void dfs(int depth, int sum, int last) {
    if (depth == 0) {
        if (sum > b) ans = min(sum - b, ans);
        return;
    }
    if (sum - b >= ans) return;
    for (int i = last + 1; i <= n - depth; i++) {
        dfs(depth - 1, sum + h[i], i);
    }
    return;
}
int main() {
    freopen("shelf.in", "r", stdin);
    freopen("shelf.out", "w", stdout);
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    dfs(n, 0, 0);
    cout << ans << endl;
    return 0;
}
