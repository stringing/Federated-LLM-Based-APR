#include <iostream>
using namespace std;
int n, m, ans;
char mn[115][115];
bool b[115][115], cb;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool in(int x, int y)
{
    return x >= 1 && y <= m && y >= 1 && x <= n;
}
void dfs(int x, int y)
{
    if(!in(x, y) && b[x][y])
    {
        return;
    }
    b[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        dfs(tx, ty);
    }
}
int main() 
{
    freopen("hiking.in", "r", stdin);
    freopen("hiking.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> mn[i][j];
            if(mn[i][j] == '.')
            {
                b[i][j] = true;
            }
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(!b[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans;
    return 0;
}
