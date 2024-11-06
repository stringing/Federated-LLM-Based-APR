#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[5010];

int w[5005], c[5005],q[5005];

int main() {
    freopen("noble.in","r",stdin);
    freopen("noble.out","w",stdout);
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> c[i] >> q[i];
    }
    int mx = -1000000,mxi;
    for(int i = 1;i < N;i ++){
        for(int j = 1;j <= N;j ++){
            if( 0 - q[j] + w[j] > mx){
                mx = 0 - q[j] + w[j];
                mxi = j;
            }
        }
                swap(q[i],q[mxi]);
                swap(w[i],w[mxi]);
                swap(c[i],c[mxi]);
    }
    for (int i = 1; i <= N; i++) {
        for(int j = V; j >= q[i];j--){
            
            dp[j] = max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
