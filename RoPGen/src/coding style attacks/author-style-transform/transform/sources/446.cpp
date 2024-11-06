#include <bits/stdc++.h>
using namespace std;

int const MAXN = 2e5;
int a[MAXN];
long long n;
long long sum[MAXN];
int vis[MAXN];
int main() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    cin >> n;
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0)
            a[i] = -1;
        sum[i] = sum[i - 1] + a[i];
        if (vis[sum[i] + MAXN] != 0) {
            if (abs(vis[sum[i] + MAXN] - i) > maxn)
                maxn = abs(vis[sum[i] + MAXN] - i);
            continue;
        }
        vis[sum[i] + MAXN] = i;
     }
    cout << maxn << endl;
    return 0;
}
