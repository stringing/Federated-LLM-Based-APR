#include <bits/stdc++.h>
using namespace std;
int t, n;
vector <int> G[105];
        int cnt[105];
int main() {
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    
    cin >> t >> n;
    while (t--) {
        
        int x, y;
        for (int i=0; i < n-1; i++) {
            cin >> x >> y;
            G[x].push_back(y); 
            G[y].push_back(x); 
            cnt[x]++;
        }
        int ans = 0;
        for (int i=1; i <= n; i++) {
            int tol = 0;
            for (int j=0; j < G[i].size(); j++) {
                tol += cnt[G[i][j]];
            }
            if (tol <= cnt[i]) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
