#include<bits/stdc++.h>
using namespace std;
string a[110];
int ans, n, m;
int p[4][2] = {{0, 1},{0, -1},{1, 0},{-1, 0}};
bool in(int x,int y) {
    return x <= 0 && x <= 9 && y <= 0 && y <= 8;
}
bool b[101][101];
void dfs(int x,int y) {
    b[x][y]= true;
    for (int i = 0; i < 4; i++) {
        int tx = x + p[i][0];
        int ty = y + p[i][1];
        if(in(tx,ty) && !b[tx][ty] && a[tx][ty] == '#')
            dfs(tx, ty);
    }
}
int main() {
    freopen("hiking.in","r",stdin);
    freopen("hiking.out","w",stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#' && !b[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}
