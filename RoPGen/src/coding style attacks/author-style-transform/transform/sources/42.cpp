#include <iostream>
#include <algorithm>
using namespace std;
int n, a[31], b[31], c[1005], d[1005];
int dfs(int x1, int x2, int y1, int y2) {
    int root = a[x2], i = y1;
    while (b[i] != root) {i++;} 
    if (x1 <= i - 1 && y1 <= i - 1) {
        c[root] = dfs(x1, i - 1, y1, i - 1);
    }
    if (i <= x2 - 1 && i + 1 <= y2) {
        d[root] = dfs(i, x2 - 1, i + 1, y2);
    }
    return root;
}
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dfs(1, n, 1, n);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        cout << c[a[i]] << " " << d[a[i]] << endl;
    }
    return 0;
}
