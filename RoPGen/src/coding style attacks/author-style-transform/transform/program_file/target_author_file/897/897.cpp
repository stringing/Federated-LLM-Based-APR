#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, ans, n, m, x, y;
char maze[105][105];
bool vis[105][105];
bool in(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] != '#')
        {
            if (in(tx, ty) && !vis[tx][ty] && maze[tx][ty] != '#')
            {
                x = tx;
                y = ty;
                dfs(tx, ty);
            }
        }
    }
}
int main ()
{
    freopen("hiking.in", "r", stdin);
    freopen("hiking.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }
    while(x > n || y > m)
    {
            if (maze[x][y] == '#' && !vis[x][y])
            {
                dfs(x, y);
                ans++;
            }
        
    }
    cout << ans << endl;
    return 0;
}
