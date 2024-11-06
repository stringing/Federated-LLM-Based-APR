#include<bits/stdc++.h>
using namespace std;
vector<int> G[1005];
int t, n, x, y, fa[1005], cnt = 0;
int  son;
int main() {
    freopen("p.in", "r",stdin);
    freopen("p.out", "w", stdout);
    cin >> t >> n;
    while(t--) {
        cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            G[x].push_back(y);
            fa[x] = y;
        }
        for(int i = 1; i <= n; i++) {
            bool f = true;
            for(int j = 0; j < G[i].size(); j++) {
                if(G[i].size() < G[G[i][j]].size()) {
                    f = false;
                    break;
                }
            }
            if(f && (G[i].size() >= G[fa[i]].size())) {
                cnt++;
            }
        }
        cout << cnt << endl;
        for(int i = 0; i <= n; i++) {
            memset(fa, 0, sizeof(fa));
            G[i].clear();
            vector<int>().swap(G[i]);
        }
    }
    
    
    
    return 0;
}
