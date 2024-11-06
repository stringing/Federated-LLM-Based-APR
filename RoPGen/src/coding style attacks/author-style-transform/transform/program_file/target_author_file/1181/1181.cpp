#include <bits/stdc++.h>
using namespace std;
vector<int> tree[1010];
int main() {
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            tree[x].push_back(y);
        }
        for (int i = 0; i <= 1010; i++) {
            tree[i].clear();
        }
    }
    return 0;
}
