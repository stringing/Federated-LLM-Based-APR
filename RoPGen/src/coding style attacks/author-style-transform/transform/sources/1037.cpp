#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
long long dp[(1 << 19) - 1];
long long a[1000];
long long g[50][50];
struct node{
    long long u1, len;
};
long long count(long long x) {
    long long cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1; 
    }
    return cnt;
}
int main() {
    freopen("meal.in", "r", stdin);
    freopen("meal.out", "w", stdout);
    long long n,m,k;
    cin >> n >> m >> k;
    queue<node> q;
    for(long long i = 0; i < n; i++) {
        cin >> a[i];
        dp[(1 << i)] = a[i];
        q.push((node){i, 1});
    }
    dp[0] = 0;
    for (long long i = 0; i < k; i++) {
        long long u,v,w;
        cin >> u >> v >> w;
        g[u - 1][v - 1] = w;
    }
    for (int s = 0; s < (1 << n); s++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = (1 << j) + (1 << i);
                if (j != i && (cnt & s) == cnt) {
                    dp[s] = max(dp[s], g[j][i] + a[i] + dp[s ^ (1 << i)]);
                }
            }
        }
    }
    long long ans = -1;
    for (long long i = 0; i < (1 << n); i++) {
        if (count(i) == m) {
            ans = max(ans, dp[i]);
        }
    }
    cout <<ans << endl;
    return 0;
}
