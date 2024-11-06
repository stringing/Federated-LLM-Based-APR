#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int n; int minDiff = 10e5;
int a[15], b[15];
bool vis[15];

void dfs(int u, int cnt) {
    if (u == n) {
        int angerSum = 1, temperSum = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                angerSum *= a[i];
                temperSum += b[i];
            }
        }
        minDiff = min(minDiff, abs(angerSum - temperSum));
        return;
    }
    vis[u] = true;
    dfs(u + 1, cnt + 1);
    vis[u] = false;
    if (cnt != 0) {
        dfs(u + 1, cnt);
    }
}
int main() {
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    dfs(0, 0);
    cout << minDiff << endl;
    return 0;
}
