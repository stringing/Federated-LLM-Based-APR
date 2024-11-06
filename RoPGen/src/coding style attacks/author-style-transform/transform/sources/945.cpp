#include<bits/stdc++.h>
using namespace std;
int n,m,x,sp[105],sw[105],hp[105],hw[105];
int qzhp[105],qzhw[105],dp[5005],ans;
int price(int v){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=v;j>=hp[i];j--){
            dp[j] = max(dp[j-hp[i]]+hw[i] , dp[j]);
        }
    }
    return dp[v];
}
int main(){
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++){
        cin>>sp[i];
        qzhp[i] = qzhp[i-1]+sp[i];
    }
    for(int i=1;i<=n;i++){
        cin>>sw[i];
        qzhw[i] = qzhw[i-1]+sw[i];
    }
    for(int i=1;i<=m;i++) cin>>hp[i];
    for(int i=1;i<=m;i++) cin>>hw[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int tmp = qzhp[j]-qzhp[j-i];
            if(tmp <= x){
                ans = max(ans , price(x-tmp)+qzhw[j]-qzhw[j-i]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
