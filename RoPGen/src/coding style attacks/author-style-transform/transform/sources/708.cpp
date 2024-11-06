#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int mp [N][N];
bool vy[N], vd[2 * N], uvd[2 * N];
bool vis[N][N];
bool vy1[N], vd1[2 * N], uvd1[2 * N];
int n;
int ans;
void dfs_w(int a);
void dfs_b(int x) {
    if (x == n) {
        dfs_w(0);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (mp[x][i] != 0 && !vy[i] && !uvd[i - x + n]) {
            vis[x][i] = true;
            vy[i] = vd[x + i] = uvd[i - x + n] = 1;
            dfs_b(x + 1);
            vy[i] = vd[x + i] = uvd[i - x + n] = 0;
            vis[x][i] = false;
        }
    }
}

void dfs_w(int a) {
    if (a == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (mp[a][i] != 0 && !vy1[i] && !vd1[a + i] && !uvd1[i - a + n] && !vis[a][i]) {
            vis[a][i] = true;
            vy1[i] = vd1[a + i] = uvd1[i - a + n] = 1;
            dfs_w(a + 1);
            vy1[i] = vd1[a + i] = uvd1[i - a + n] = 0;
            vis[a][i] = false;
        }
    }
}
int main() {
    freopen("queen.in", "r", stdin);
    freopen("queen.out","w",stdout);
    cin >> n;
    for (int i = 0; i = n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }
    dfs_b(0);
    cout << ans << endl;
    return 0;
}
