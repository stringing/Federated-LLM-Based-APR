#include <bits/stdc++.h>
using namespace std;
int dp[100005][100005];
int p[100005],v[100005];
int q[100005],w[100005];
int n,m,x;

int main(){
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    
    return 0;
}
