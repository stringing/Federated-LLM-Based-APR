#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[1000000],b[1000000];
bool vis[1000000];
struct jkl{
    int l, r;
}ans[1000000];
int tot = 1;
int n;
void dfs(int i,int j,int r) {
    if (vis[r]) return ;
    if (i == j) return ;
    vis[r] = true;
    int s = 0;
    for (int k = 1; k <= n; k++) {
        if (b[k] == a[r]) {
            s = k;
            break;
        }
    }
    ans[a[r]].l = a[s - 1];
    ans[a[r]].r = a[j];
    dfs(i, s - 2, s - 1);
    dfs(s, j - 1, j);
    return ;
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
    dfs(1, n - 1, n);
    for (int i = 1; i < tot; i++ ){
        cout << ans[i].l << " " << ans[i].r << endl;
    }
    return 0;
}
