#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10005;
vector<int> G[maxn];
int main () {
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t, x, y, n, a[10005];
    cin >> t >> n;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x >> y;
            G[x].push_back(y);
            if (x >= j) {
                a[i]++;
            }
        }
    }
    for (int i = 1; i <= t; i++) {
        cout << a[i];
    }
    return 0;
}
