#include <bits/stdc++.h>
using namespace std;
int n;
int a[40], b[40], c[40];
int Right[40], Left[40];
void dfs(int l1, int r1, int l2, int r2) {
    int pos;
    if (l1 == r1) {
        return ;
    }
    for (int i = l2; i <= r2; i++) {
        if (b[i] == a[r1]) {
            pos = i;
            break;
        }
    }
    if (pos == l2) {
        Right[a[r1]] = a[r1 - 1];
        dfs(l1, r1 - 1, l2 + 1, r2);
    } else if (pos == r2) {
        Left[a[r1]] = a[r1 - 1];
        dfs(l1, r1 - 1, l2, r2 - 1);
    } else {
        Left[a[r1]] = a[pos - l2 + l1 - 1];
        Right[a[r1]] = a[r1 - 1];
        dfs(l1, pos - l2 + l1 - 1, l2, pos - 1);
        dfs(pos - l2 + l1, r1 - 1, pos + 1, r2);
    }
}
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(c + 1, c + n + 1);
    dfs(1, n, 1, n);
    for (int i = 1; i <= n; i++) {
        cout << Left[c[i]] << " " << Right[c[i]] << endl;
    }
    return 0;
}
