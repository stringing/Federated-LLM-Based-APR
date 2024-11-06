#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
int n, cnt, flag;
int ans[MAX_N], tot;
char mat[1005][1005];
int main() {
    freopen("zip.in", "r", stdin);
    freopen("zip.out", "w", stdout);
    cin >> mat[1] + 1;
    n = strlen(mat[1] + 1); 
    for (int i = 2; i <= n; i++) {
        cin >> mat[i] + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mat[i][j] - '0' == flag) {
                cnt++;
            } else {
                ans[tot++] = cnt;
                flag ^= 1;
                cnt = 1;
            }
        }
    }
    ans[tot++] = cnt;
    cout << n << " ";
    for (int i = 1; i <= tot; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
