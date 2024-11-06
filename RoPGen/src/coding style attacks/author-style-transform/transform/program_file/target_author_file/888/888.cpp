#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[10010];
int w[1005], c[1050];
int w2[1005], c2[1005];
int main() {
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    int N, V,M;
    cin >> N >> M >> V;
    for (int i = 1; i <= N; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> w2[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> c2[i];
    }
    int flag = 1;
    for (int i = 1; i <= N; i++) {
        for(int j = V; j >= w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+c[i]);
        }
    }for (int i = 1; i <= M; i++) {
        for(int j = V; j >= w2[i];j--){
            if(dp[j] != 0)
            dp[j] = max(dp[j],dp[j-w2[i]]+c2[i]);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
