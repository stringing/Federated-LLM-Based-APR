#include <bits/stdc++.h>

using namespace std;

long long ans, cnt, n, m, k, x, y, c, ext[20][20], a[20], f[1 << 20][20];

bool check(int t){
    x = t, y = 0;
    while(x) y += (x - (x / 2) * 2 == 1 ? 1 : 0), x /= 2;
    return y == m;
}

int main(){
    freopen("meal.in", "r", stdin);
    freopen("meal.out", "w", stdout);
    memset(ext, 0, sizeof(ext));
    scanf("%lld%lld%lld", &n, &m, &k);
    for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for(int i = 0; i < k; ++i) scanf("%lld%lld%lld", &x, &y, &c), ext[x][y] = c;
    for(int i = 0; i < n; ++i) f[1 << i][i] = a[i];
    for(int i = 1; i < (1 << n); ++i)
        for(int j = 0; j < n; ++j)
            if(!(i & (1 << j)))
                for(int k = 0; k < n; ++k)
                    if(i & (1 << k))
                        f[i | (1 << j)][j] = max(f[i][k] + a[j] + ext[k][j], f[i | (1 << j)][j]);
    for(int i = 1; i < (1 << n); ++i){
        if(!check(i)) continue;
        for(int j = 0; j < n; ++j) ans = max(ans, f[i][j]);
    }
    printf("%lld\n", ans);
    
    return 0;
}
