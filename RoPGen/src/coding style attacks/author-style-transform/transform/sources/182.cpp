#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to, next;
} e[20010];
int ecnt; 
int head[10010];
void addEdge(int u, int v) { 
    ++ecnt;
    e[ecnt].to = v;
    e[ecnt].next = head[u];
    head[u] = ecnt;
}
int n;            
int m;               
int dfn[10010];   
int low[10010];   
int timer;       
int scc_cnt;     
vector<int> scc[10010];
stack<int> S;
short a[10010];
bool in_stack[10010];
int sccno[10010];

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    S.push(u);
    in_stack[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        scc_cnt++;
        while (!S.empty()) {
            int now = S.top();
            S.pop();
            scc[scc_cnt].push_back(now);
            sccno[now] = scc_cnt;
            in_stack[now] = false;
            if (now == u) break;
        }
    }
}
Edge new_edge[20010];
int new_ecnt;

int new_head[10010];
void addNewEdge(int u,int v){
    ++new_ecnt;
    new_edge[new_ecnt].to=v;
    new_edge[new_ecnt].next=new_head[u];
    new_head[u]=new_ecnt;
}
int chuansong[10010]; 
int pos=0;
bool vis[10100];
long long ans=0;
void dfs(int u){
    if(vis[u]) return;
    vis[u]=1;
    for(int i=0;i<scc[u].size();i++){
        ans+=a[scc[u][i]];
        
    }
    cout << "cnm" << endl;
    for(int i=new_head[u];i;i=new_edge[i].next){
        dfs(new_edge[i].to);
    }
}
int main() {
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    scanf("%d%d", &n, &m);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i*m+j-m]=getchar()-'0';
            if(a[i*m+j-m]=='*'-'0'){
                a[i*m+j-m]=0;
                chuansong[pos++]=i*m-m+j;
            }
            else if(a[i*m+j-m]==' '-'0')a[i*m-m+j]=0;
            else a[i*m-m+j-m]=-1;
        }
        getchar();
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i*m+j-m]!='#' && a[i*m-m+j+1]!='#'){
                addEdge(i*m-m+j,i*m-m+j+1);
            }
            if(a[i*m+j-m]!='#' && a[i*m+j]!='#'){
                addEdge(i*m+j-m,i*m+j);
            }
        }
    }
    for(int i=0;i<pos;i++){
        int x,y;
        
        scanf("%d %d",&x,&y);
        x++;
        y++;
        if(a[chuansong[i]]!=-1 && a[x*m+y-m]!=-1)addEdge(chuansong[i],x*m+y);
    }
    for(int i=1;i<=n*m;i++){
        if(dfn[i]==0){
            tarjan(i);
        }
    }
    for(int u=1;u<=n;u++){
        for(int i=head[u];i;i=e[i].next){
            int v=e[i].to;
            
            if(sccno[u]!=sccno[v]){
                addNewEdge(sccno[u],sccno[v]);
            }
        }
    }
    dfs(sccno[1]);
    cout << ans << endl;
    return 0;
}
