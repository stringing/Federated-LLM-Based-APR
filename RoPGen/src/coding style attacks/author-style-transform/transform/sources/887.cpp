#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[5010],dp1[5010];
int w[102],c[102];
int main() {
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    int N,M,V;
    cin>>N>>M>>V;
    for (int i=1;i<=N;i++) {
        cin>>c[i];
    }
    for (int i=1;i<=N;i++) {
        cin>>w[i];
    }
    for (int i=1;i<=N;i++) {
        for (int j=V;j>=c[i];j--) {
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    for (int i=1;i<=M;i++) {
        cin>>c[i];
    }
    for (int i=1;i<=M;i++) {
        cin>>w[i];
    }
    for (int i=1;i<=M;i++) {
        for (int j=V;j>=c[i];j--) {
            if (dp[j]!=0) dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}
