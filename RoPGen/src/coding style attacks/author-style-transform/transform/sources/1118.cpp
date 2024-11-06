#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
vector <int> G[MAX_N];
int fa[MAX_N];
int main() {
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            fa[y] = x; 
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        bool f = true;
        for (int j = 0; j < G[i].size(); j++) {
            if (G[i].size() < G[G[i][j]].size()) {
                f = false;
                break;
            }
        }
        if (f && G[i].size() >= G[fa[i]].size()){
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
         G[i].clear();
    }
    memset(fa, 0, sizeof(fa));
    return 0;
}
