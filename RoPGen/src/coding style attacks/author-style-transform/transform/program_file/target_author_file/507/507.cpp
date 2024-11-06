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
void dfs(int i,int j,int r, int s) {
    if (vis[r]) return ;
    if (i == j) return ;
    vis[r] = true;
    ans[s].r = a[r - 1];
    ans[s].l = a[b[s] - 1];
    dfs(i,b[s] - 2,b[s] - 1 , a[b[s] - 1]);
    dfs(b[s] + 1, r - 2, r - 1, a[r - 1]);
    return ;
}
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dfs(1, n - 1, n, a[n]);
    for (int i = 1; i < tot; i++ ){
        cout << ans[i].l << " " << ans[i].r << endl;
    }
    return 0;
}
