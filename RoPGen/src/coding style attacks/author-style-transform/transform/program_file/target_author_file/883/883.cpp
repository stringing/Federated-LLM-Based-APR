#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int const MAXN = 2e5;
int a[MAXN];
int ans;
long long n;
long long sum[MAXN];
int vis[MAXN];
int main() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) a[i] = -1;
        sum[i] = sum[i - 1] + a[i];
        if (vis[sum[i] + MAXN] != 0 || sum[i] == 0) {
            ans = max(ans, abs(vis[sum[i] + MAXN] - i));
            continue;
        }
        vis[sum[i] + MAXN] = i;
    }
    cout << ans << endl;
    return 0;
}
