#include <iostream>
using namespace std;
int n, ans;
int map[15][15];
bool rowWhite[15], x1White[20], x2White[20];
bool rowBlack[15], x1Black[20], x2Black[20];
bool check(int i, int c, bool col) {
    if (col == 0) {
        return map[c][i] != 0 && !rowBlack[i] && !x1Black[i + c] && !x2Black[i - c + n];
    }
    if (col == 1) {
        return map[c][i] != 0 && !rowWhite[i] && !x1White[i + c] && !x2White[i - c + n];
    }
}
void dfs(int c, bool nowCol) {
    if (c == n) {
        if (nowCol == 0) {
            dfs(0, nowCol + 1);
        } else {
            ans++;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if (check(i, c, nowCol)) {
            if (nowCol == 0) {
                rowBlack[i] = x1Black[i + c] = x2Black[i - c + n] = true;
                dfs(c + 1, nowCol);
                rowBlack[i] = x1Black[i + c] = x2Black[i - c + n] = false;
            } else {
                rowWhite[i] = x1White[i + c] = x2White[i - c + n] = true;
                dfs(c + 1, nowCol);
                rowWhite[i] = x1White[i + c] = x2White[i - c + n] = false;
            }
        }
    }
    return;
}
int main() {
    freopen("queen.in", "r", stdin);
    freopen("queen.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    dfs(0, 0);
    cout << ans;
    return 0;    
}
