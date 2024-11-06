#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int NR = 30;
bool flag[NR][NR];
int n, ans;
int h[2][NR], lx[2][NR], rx[2][NR];

bool check(int i, int u, int o) {
    return !(h[o][i] || lx[o][i + u] || rx[o][i - u + 8]) && flag[i][u];
}

void dfs(int u) {
    if(u > n) {
        ans++;
        return;
    }
    for(int j = 1; j <= n; j++) { 
        for(int i = 1; i <= n; i++) { 
            if(check(i, u, 1) && check(j, u, 0)) {
                h[1][i] = lx[1][i + u] = rx[1][i - u + 8] = true;
                h[0][j] = lx[0][j + u] = rx[0][j - u + 8] = true;
                dfs(u + 1);
                h[1][i] = lx[1][i + u] = rx[1][i - u + 8] = false;
                h[0][j] = lx[0][j + u] = rx[0][j - u + 8] = false;
            }
        }
    }
}

int main() {
    freopen("queen.in", "r", stdin);
    freopen("queen.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            int x;
            scanf("%d", &x);
            if(x == 1) flag[i][j] = true;
        }
    dfs(1);
    printf("%d", ans);
    return 0;
}
