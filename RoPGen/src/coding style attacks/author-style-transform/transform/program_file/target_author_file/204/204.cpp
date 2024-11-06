#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
vector <int> G[maxn];
int fa[maxn];
int main(){
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t, ans = 0;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            fa[v] = u;
        }
      
        for(int i = 1; i <= n; i++){
            bool f = true;
            for(int j = 0; j < G[i].size(); j++){
                if(G[i].size() < G[G[i][j]].size()){
                    f = false;
                    break;
                }
            }
            if(f && G[i].size() >= G[fa[i]].size()){
                ans++;
            }
        } 
        cout << ans << endl;
        for(int i = 0; i < maxn; i++){
        G[i].clear();
        fa[i] = 0;
        }
    }   
    ans = 0;
    return 0;
}
