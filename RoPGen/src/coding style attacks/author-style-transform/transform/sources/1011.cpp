#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int N,M,X;
int p[maxn],v[maxn],q[maxn],w[maxn];
int dp[maxn];
int main(){
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    cin>>N>>M>>X;
    for(int i=1;i<=N;i++){
        cin>>p[i];
    }
    for(int i=1;i<=N;i++){
        cin>>v[i];
    }
    for(int i=1;i<=M;i++){
        cin>>q[i];
    }
    for(int i=1;i<=M;i++){
        cin>>w[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=X;j>=p[i];j--){
            dp[j]=max(dp[j],dp[j-p[i]]+v[i]);
        }
    }
    for(int i=1;i<=M;i++){
        for(int j=dp[X];j>=q[i];j--){
            if(dp[j]!=0){
                dp[j]=max(dp[j],dp[j-q[i]]+w[i]);
            }
        }
    }
    cout<<dp[X];
    return 0;
}
