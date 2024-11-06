#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> f[1005];
int du[1005];
int main() {
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i <= 1000; i++) {
            f[i].clear();
        }
        memset(du, 0, sizeof(du));
        int n;
        cin >> n;
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            f[x].push_back(y);
            f[y].push_back(x);
            du[x]++;
            du[y]++;
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int j = 1;
            for (j = 0; j < f[i].size(); j++) {
                if (du[i] < du[f[i][j]]) {
                    break;
                }
            }
            if (j == f[i].size()) {
                res++;
            }
        } 
        cout << res << endl;
    }
    return 0;
}
