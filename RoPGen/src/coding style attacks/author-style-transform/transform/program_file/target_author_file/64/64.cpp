#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[1000000],b[1000000];
bool vis[1000000];
struct jkl{
    int l = 0, r1 = 0;
}ans[1000000];
int tot = 1;
int n;
int dfs(int i,int j,int r,int k) {
    if (vis[a[j]]) return 0;
    vis[a[j]] = true;
    int s = 0;
    for (int l = r; l <= k; l++) {
        if (a[j] == b[l]) {
            s = l;
        }
    }
    ans[a[j]].l = dfs(i, i + s - r - 1, r, s - 1);
    ans[a[j]].r1 = dfs(i + s - r, j - 1, s + 1, k);
    return 0;
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
    int x = dfs(1, n, 1, n);
    for (int i = 1; i < 1010; i++ ){
        if (vis[i]) cout << ans[i].l << " " << ans[i].r1 << endl;
    }
    return 0;
}
