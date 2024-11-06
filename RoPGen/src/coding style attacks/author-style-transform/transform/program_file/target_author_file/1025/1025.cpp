#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> g[1005];
int fa[1005];
int main () {
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            fa[v] = u;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            bool f = true;
            for (int j = 0; j < g[i].size(); j++)
            {
                if (g[i].size() < g[g[i][j]].size())
                {
                    f = false;
                    break;
                }
            }
            if (f && g[i].size() >= g[fa[i]].size())
                ans++;
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++)
            vector<int>().swap(g[i]);
        memset(fa, 0, sizeof(fa));
    }
    return 0;
}
