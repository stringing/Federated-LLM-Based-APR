#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
bool vis[105][105];
char maze[105][105];
int ans, cnt;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
void dfs(int x, int y) {
    cnt++;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(in(tx,ty)&&!vis[tx][ty]&&maze[tx][ty]=='#'){
            dfs(tx,ty);
        }
        
    }
}
int main() {
    freopen("hiking.in", "r", stdin);
    freopen("hiking.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '#' && !vis[i][j]) {
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

