#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100005], sum[100005], l, r, maxx, tmp, cnt; 
int main () {
    freopen("pair.in", "r", stdin);
    freopen("pair.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) { 
            a[i] = -1;
        }
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        tmp = lower_bound(sum + 1, sum + n + 1, sum[i]) - sum; 
        cnt = i - tmp + 1;
        if (tmp != i && sum[tmp] == sum[i] && maxx < cnt) { 
            maxx = cnt;
        }
    }
    cout << maxx;
    return 0;
}
