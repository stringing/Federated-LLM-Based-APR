#include <iostream>
#include <vector>
using namespace std;
int t, n, p;
vector<int> G[1010]; 
int fa[1010];
int main () {
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    cin >> t;
    int flag = 1; 
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
            fa[y] = x;
        }
        for (int i = 1; i <= n; i++) {
            int cnt = G[i].size(); 
            flag = 1;
            if (!fa[i]) {
                cnt++;
            }
            for (int j = 0; j < G[i].size(); j++) {
                if (G[G[i][j]].size() > cnt) {
                    flag = 0;
                    break;
                }
            }
            p += flag;
        }
        cout << p << endl;
        p = 0;
        for (int i = 1; i <= n; i++) { 
            vector<int>().swap(G[i]);
        }
    }
    return 0;
}
