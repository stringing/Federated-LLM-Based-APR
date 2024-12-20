#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1000;
int n, a[N][N];
int ans = 0;
bool row1[N], x1[N], x2[N], row2[N], x3[N], x4[N];
bool check(int c1, int c2, int i) {
    return (!row1[i] && !x1[c1 + i] && !x2[c1 - i + n]) && (!row2[i] && !x3[c2 + i] && !x4[c2 - i + n]);
}
void dfs(int c1, int c2) {
    if(c1 == n && c2 == n) {
        ans ++;
        return ;
    }
    for(int i = 0; i < n; i++) {
           if(check(c1, c2, i)) {
               row1[i] = x1[c1 + i] = x2[c1 - i + n] = true;
               row2[i] = x3[c1 + i] = x4[c1 - i + n] = true;
               dfs(c1 + 1, c2 + 1);
               row1[i] = x1[c2 + i] = x2[c2 - i + n] = false;
               row2[i] = x3[c2 + i] = x4[c2 - i + n] = false;
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
    dfs(0, 0);
    cout << ans;
    return 0;
}
