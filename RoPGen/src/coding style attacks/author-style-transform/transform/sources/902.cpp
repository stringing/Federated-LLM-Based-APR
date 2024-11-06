#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int dp[50010];
struct shop {
    int v;
    int p;
    int q;
};
shop s[50010];
bool cmp(shop l,shop r) {
    return l.q - l.p < r.q - r.p;
}
int main() {
    freopen("noble.in","r",stdin);
    freopen("noble.out","w",stdout);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> s[i].p >> s[i].v >> s[i].q;
    }
    sort(s,s + N + 1,cmp);
    for(int i = 1; i <= N; i++) {
        if(M < s[i].q) {
            s[i].p = 0;
            s[i].v = 0;
            s[i].q = 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        for(int j = M; j >= s[i].p; j--) {
            dp[j] = max(dp[j],dp[j-s[i].q] + s[i].v);
        }
    }
    cout << dp[M] << endl;
    return 0;
}
