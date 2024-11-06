#include <iostream>
#include <map>
using namespace std;
int n, tmp, sum[100005], maxx; 
int main () {
    freopen("pair.in", "r", stdin);
    freopen("pair.out", "w", stdout);
    map<int, int> vis;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (tmp == 0) { 
            tmp = -1;
        }
        sum[i] = sum[i - 1] + tmp;
        if (!vis.count(sum[i])) {
            vis[sum[i]] = i;
        } else {
            if (maxx < i - vis[sum[i]]) {
                maxx = i - vis[sum[i]];
            }
        }
    }
    cout << maxx;
    return 0;
}
