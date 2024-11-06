#include<bits/stdc++.h>
using namespace std;
int dp[5010];
struct g{
    int w,c,p;
}a[5005];
bool cmp(g x,g y){
    return x.c-x.p<y.c-y.p;
}
int main() {
    freopen("noble.in","r",stdin);
    freopen("noble.out","w",stdout);
    int N, M;
    cin >> N>>M;
    for(int i=0;i<N;i++)cin>>a[i].w>>a[i].c>>a[i].p;
    sort(a,a+N+1,cmp);
    for (int i = 1; i <=N; i++)
        for (int j =M; j>=a[i].w; j--)dp[j]=max(dp[j],dp[j-a[i].w]+a[i].c);
    cout<<dp[M]+1<<endl;
    return 0;
}
