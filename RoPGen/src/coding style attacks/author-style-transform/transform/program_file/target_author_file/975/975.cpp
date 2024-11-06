#include<bits/stdc++.h>
#define x first
#define y second
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<long,long> PLL;
typedef pair<char,char> PCC;
typedef long long LL;
const int N=2*1e5+10;
const int M=150;
const int INF=0x3f3f3f3f;
const int MOD=998244353;
int h[25],n,b,sum[25];
int ans=INF;
void dfs(int u,int num){
    if(num>=b) ans=min(ans,num);
    if(u==n+1) return;
    dfs(u+1,num);
    dfs(u+1,num+h[u]);
}
void solve(){
    cin>>n>>b;
    for(int i=1;i<=n;i++) cin>>h[i];
    dfs(1,0);
    cout<<ans-b<<endl;
}
int main(){
        freopen("shelf.in","r",stdin);
        freopen("shelf.out","W",stdout);
    IOS;
    solve();
    return 0;
}
