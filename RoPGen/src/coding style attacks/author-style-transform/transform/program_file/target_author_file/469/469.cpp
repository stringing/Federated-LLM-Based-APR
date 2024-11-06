#include<iostream>
using namespace std;
int n,m,k,x,y,c,ans=0;
int dp[1<<18][25];
int vis[25][25],a[25];
int count(int x){
    int cnt=0;
    while(x){
        cnt+=x&1;
        x>>=1;
    }
    return cnt;
}
int main(){
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=k;i++){
        cin>>x>>y>>c;
        vis[x][y]=c;
    }
    for(int i=0;i<n;i++){
        dp[1<<i][i]=a[i];
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                for(int k=0;k<n;k++){
                    if(i&(1<<k))
                        dp[i|(1<<j)][j]=dp[i][k]+a[i]+vis[k][j];
                }
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        if(count(i)==m){
            for(int j=0;j<n;j++){
                ans=max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans;
    return 0;
}
