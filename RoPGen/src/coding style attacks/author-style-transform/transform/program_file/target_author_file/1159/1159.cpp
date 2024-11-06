#include <bits/stdc++.h>
using namespace std;
int n,a[13],b[13],ans = 0x3f3f3f3f;
void dfs(int u, int cnt, int sum, int mul) {
    if (u == n) {
        if (cnt && (ans == -1 || abs(sum - mul) < ans)) {
            ans = abs(sum - mul);
        }
        return;
    }
    dfs(u + 1, cnt + 1, sum + b[u], mul * a[u]);
    dfs(u + 1, cnt, sum, mul);
}
int main() {
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i] >> b[i];
    }
    dfs(0,1,0,1);
    cout << ans << endl;
    return 0;
}
