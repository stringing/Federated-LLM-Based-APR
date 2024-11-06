#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    int n,m,x,p[105],v[105],q[105],w[105],dp[5005];
    cin >> n >> m >> x;
    for(int i = 1;i <= n;i++){
        cin >> p[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> v[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> q[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++){
            dp[j] = max(dp[j-p[i]] + v[i],dp[j]);
            if(dp[j] != 0){
                dp[j] = max(dp[j-q[i]] + w[i],dp[j]);
            }
        }
    }
    cout << dp[x];
    return 0;
}
