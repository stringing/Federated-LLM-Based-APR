#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 9;
#define y1 ed
char mp[N][N];
int dx[5] = {-1, 1, 0, 0}, dy[5] = {0, 0, -1, 1};
int a, b, x, y, n, m, k, vis[N][N];
struct node {
    int k, x, y, dir;
    node(){}
    node(int x1, int y1, int k1, int dir1) {
        x = x1;
        y = y1;
        k = k1;
        dir = dir1;
    }
};
void BFS() {
    queue<node> q;
    q.push(node(a, b, -1, -1));
    memset(vis, 0x3f, sizeof vis);
    vis[a][b] = -1;
    while(!q.empty()) {
        node g = q.front();
        q.pop();
        if(x == g.x && y == g.y) {
            puts("yes");
            return;
        }
        for(int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            int kk = g.k + (g.dir != 1);
            if(tx >= 0 && tx < n && ty >= 0 && ty < m && mp[tx][ty] == '.' && k >= kk && vis[tx][ty] >= kk) {
                vis[tx][ty] = kk;
                q.push(node(tx, ty, kk, i));
            }
        }
    }
    puts("no");
}
int main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> mp[i];
        cin >> k >> b >> a >> y >> x;
        a--, b--, x--, y--;
        BFS();
    }
    return 0;
}
