#include <bits/stdc++.h>
using namespace std;
int n, a[9][9], ans;
void dfs(vector<int> b, vector<int> w) {
    if (b.size() == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[b.size()][i] == 0) continue;
        b.push_back(i);
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (a[w.size()][j] == 0) continue;
            w.push_back(j);
            dfs(b, w);
            w.pop_back();
        }
        b.pop_back();
    }
}
int main() {
    freopen("queen.in", "r", stdin);
    freopen("queen.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> b, w;
    dfs(b, w);
    cout << ans << endl;
    return 0;
}
