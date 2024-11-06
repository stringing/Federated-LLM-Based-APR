#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ans = 0;
int p[10][10];
int n;
bool row[10], x1[20], x2[20];
bool check(int c, int i) {
    return !row[i] && !x1[c + i] && !x2[c - i + 8] && p[i][c];
}
void dfs(int c) {
    if (c == n) {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (check(c, i)) {
            row[i] = x1[c + i] = x2[c - i + 8] = true;
            p[i][c] = 0;
            dfs(c + 1);
            row[i] = x1[c + i] = x2[c - i + 8] = false;
            p[i][c] = 1;
        }
    }
}
int main() {
    freopen ("queen.in", "r", stdin);
    freopen ("queen.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    dfs(0);
    memset(row, 0, sizeof(row));
    memset(x1, 0, sizeof(x1));
    memset(x2, 0, sizeof(x2));
    dfs(0);
    cout << ans << endl;
    return 0;    
}
