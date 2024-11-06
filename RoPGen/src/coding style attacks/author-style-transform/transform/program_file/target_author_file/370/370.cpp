#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int n,m,x,p[maxn],q[maxn],v[maxn],w[maxn],dp[maxn];
int main(){
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    
    
    cin >> n >> m >> x;
    
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=m;i++){
        cin >> q[i];
    }
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=x;j>=p[i];j--){
            dp[j] = max(dp[j],dp[j-p[i]]+v[i]);
        }
    }
    
    for(int i=1;i<=m;i++){
        for(int j=x;j>=q[i];j--){
            if(dp[j] != 0){
                dp[j] = max(dp[j],dp[j-q[i]]+w[i]);
            }
        }
    }
    
    cout << dp[x];
    
    
    return 0;
}
