#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 7;
int n, last[maxn], mid[maxn], tree[2 * maxn];
inline void dfs(int pos, int root, int l, int r) {
    if (l == r) return;
    int ix, l1, l2, r1, r2, len1, len2, L, R, pos1, pos2;
    for (int i = l; i <= r; i++) {
        if (mid[i] == last[pos]) {
            ix = i;
            break;
        }
    }
    len1 = ix - l, len2 = r - ix;
    l2 = pos - len2, r2 = pos - 1;
    r1 = l2 - 1, l1 = r1 - len1 + 1;
    pos1 = r1, pos2 = r2;
    tree[root * 2] = last[pos1], tree[root * 2 + 1] = last[pos2];
    l1 = l, r1 = ix - 1, l2 = ix + 1, r2 = r;
    dfs(pos1, root * 2, l1, r1);
    dfs(pos2, root * 2 + 1, l2, r2);
}
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> last[i];
    for (int i = 1; i <= n; i++) cin >> mid[i];
    tree[1] = last[n];
    dfs(n, 1, 1, n);
    return 0;
}
