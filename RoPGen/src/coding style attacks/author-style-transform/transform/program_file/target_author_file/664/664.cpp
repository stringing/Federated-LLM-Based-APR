#include <bits/stdc++.h>
using namespace std;
int t,n,cnt = 0,ans = 0,x,y,g[1005];
vector<int> G[1005];
int main() {
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> x >> y;
            g[x] == y;
            G[x].push_back(y);
        }
        for (int j = 1; j <= n; j++) {
            if (G[j].size() >= G[g[x]].size()) {
                for (int k = 1; k <= G[j].size(); k++) {
                    if (G[j].size() < G[G[x][k]].size()) break;
                    else {
                        cnt++;
                    }
                }
                if (cnt == G[j].size()) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
