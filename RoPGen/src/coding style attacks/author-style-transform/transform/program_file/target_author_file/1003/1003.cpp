#include<bits/stdc++.h>
using namespace std;
int n,m,x,sp[105],sw[105],hp[105],hw[105];
int dp[5005];
int main(){
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++) cin>>sp[i];
    for(int i=1;i<=n;i++) cin>>sw[i];
    for(int i=1;i<=m;i++) cin>>hp[i];
    for(int i=1;i<=m;i++) cin>>hw[i];
    for(int i=1;i<=n;i++){
        for(int j=x;j>=sp[i];j--){
            dp[j] = max(dp[j-sp[i]]+sw[i] , dp[j]);
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}
