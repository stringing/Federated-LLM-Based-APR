#include<iostream>
#include<stack>
#include<string.h>
#include<vector>
#define nn 105
#define N 105*105
using namespace std;
struct c{
    int v,nxt;
}e[N*2],E[N*2];
int h[N],dfn[N],low[N],idx,idr,H[N],idX,cnt,n,m,tt,dp[N],be,en;
bool ins[N];
int w[N],be_l[N];



stack <int> S;
vector <int> G[N];
char mp[nn][nn];int K[N];


struct ccc{
    int x,y;
}s[N];
int turn(int x,int y){
    return (x-1)*m+y;
}
void add(int u,int v){
    e[++idx]={v,h[u]};h[u]=idx;
}
void adD(int u,int v){
    E[++idX]={v,H[u]};H[u]=idX;
}
void tarjan(int u){
    dfn[u]=low[u]=++idr;
    ins[u]=true;S.push(u);
    for (int i=h[u];i;i=e[i].nxt){
        int v=e[i].v;
        if (!dfn[v]){
            tarjan(v);low[u]=min(low[u],low[v]);
        }else if (ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if (low[u]==dfn[u]){
        ++cnt;
        while(!S.empty()){
            int tm=S.top();S.pop();
            ins[tm]=false;
            be_l[tm]=cnt;
            w[cnt]+=K[tm];
            G[cnt].push_back(tm);
            if (tm==u) break;
        }
    }
    return;
}
void Do(){
    be=be_l[1];en=be_l[n*m];
    for (int u=1;u<=n*m;++u){
        for (int i=h[u];i;i=e[i].nxt){
            int v=e[i].v;
            if (be_l[u]!=be_l[v]){
                
                adD(be_l[u],be_l[v]);
            }
        }
    }
}
ccc turnb(int u){
    int x=(u-1)/n+1,y=(u-1)%n+1;
    return {x,y};
}
int dfs(int u){
    if (dp[u]!=-1) return dp[u];
    if (u==en) return dp[u]=w[en];
    int p=w[u];
    for (int i=H[u];i;i=E[i].nxt){
        int v=E[i].v;
        p=max(p,w[u]+dfs(v));
    }
    return dp[u]=p;
}
bool cant(int x,int y){
    return x<1||x>n||y<1||y>m||mp[x][y]=='#';
}
main(){
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    memset(dp,-1,sizeof dp);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%s",mp[i]+1);
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (isdigit(mp[i][j])){
                K[turn(i,j)]=mp[i][j]-'0';
            }
            if (mp[i][j]=='#') continue;
            if (!cant(i+1,j)){
                add(turn(i,j),turn(i+1,j));
                
            }
            if (!cant(i,j+1)){
                add(turn(i,j),turn(i,j+1));                   
            }
            if (mp[i][j]=='*') s[++tt]={i,j};
        }
    }
    for (int i=1;i<=tt;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        add(turn(s[i].x,s[i].y),turn(x+1,y+1));
        
    }
    for (int i=1;i<=n*m;++i) if (!dfn[i])tarjan(i);Do();
    dfs(be);
    



    cout<<dp[be]<<endl;
    
    
    return 0;
}
