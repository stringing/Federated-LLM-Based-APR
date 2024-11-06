#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
char maze[110][110];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool vis[110][110];
int sx, sy, n, m, cnt, ans;
bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}
void dfs(int x, int y) {
    cnt++;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (in(tx, ty) && maze[tx][ty] == '#' && !vis[tx][ty]) {
            dfs(tx, ty);
        }
    }
}
int main() {
    freopen("hiking.in", "r", stdin);
    freopen("hiking.out", "w", stdout);
    cin >> n >> m;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '#' && !vis[i][j]) {
                
                cnt = 0; 
                dfs(i, j);
                mx = max(mx, cnt);
                ans++; 
            }
        }
    }
    cout << ans << endl;
}
