#include <bits/stdc++.h>
using namespace std;
int n, a[10][10], ans = 0;
int c[15][4], x1[30][4], x2[30][4];
bool check(int dep, int i, int co) {
    return !c[i][co] && !x1[i + dep][co] && !x2[dep - i + n][co] && a[dep][i] == 1;
}
void dfs(int dep) {
    if(dep >= n) {
        ans++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(check(dep, i, 2)) {
            a[dep][i] = 2;
            c[i][2] = x1[dep + i][2] = x2[dep - i + n][2] = true; 
            for(int j = 0; j < n; j++) {
                if(check(dep, j, 3)) {
                    a[dep][j] = 3;
                    c[i][3] = x1[dep + i][3] = x2[dep - i + n][3] = true;
                    dfs(dep + 1);
                    a[dep][j] = 1;
                    c[i][3] = x1[dep + i][3] = x2[dep - i + n][3] = false;
                }
            }
            c[i][2] = x1[dep + i][2] = x2[dep - i + n][2] = false;
            a[dep][i] = 1;
        }
    }
}
int main() {
    freopen("queen.in", "r", stdin);
    freopen("queen.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;    
}
