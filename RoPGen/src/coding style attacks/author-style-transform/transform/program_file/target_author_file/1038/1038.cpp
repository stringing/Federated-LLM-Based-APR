#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10005;
vector<int> G[maxn];
int main () {
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t, x, y, n, a[10005], deg[10005], b[10005];
    cin >> t >> n;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> x >> y;
            G[x].push_back(y);
            deg[x]++;
            G[y].push_back(x);
            deg[y]++;
        }
    }
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= n; j++) {
            if (deg[i] >= deg[j]) {
                a[j]++;
            }
        }
    }
    for (int i = 1; i <= t; i++) {
        cout << a[i];
    }
    return 0;
}
