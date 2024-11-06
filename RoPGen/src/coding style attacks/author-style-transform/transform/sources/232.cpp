#include<bits/stdc++.h>
using namespace std;
const int maxm = 1010;
const int maxn = 110;
vector<int> G[maxn];
vector<int> G2[maxn];
int n;
int out[maxn],in[maxn];
int times = 0;
int dfn[maxn], low[maxn];
int scc_cnt = 0;
int sccno[maxn];
set<int> scc[maxn];
stack<int> S;
void dfs (int u) {
    dfn[u] = low[u] = ++times;
    S.push(u);
    for (int i=0;i<G[u].size();i++) {
        int v = G[u][i];
        if (dfn[v] == 0) { 
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (!sccno[v]) { 
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++scc_cnt;
        while (true) {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            scc[scc_cnt].insert(x);
            if (x == u) {
                break;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        getline(cin,s[i]);
        for (int j=0;j<m;j++){
            if (s[i][j]=='*')
                extra[++len]=i*n+j,v[i*n+j]=0;
            if (s[i][j]>='0' && s[i][j]<='9')
                v[i*n+j]=s[i][j]-'0';
        }
    }
    for (int i=1;i<=len;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        G[extra[i]].push_back(x*n+y);
    }
    for (int i=0;i<n-1;i++)
        for (int j=0;j<m;j++)
            if (s[i][j]!='#' && s[i+1][j]!='#')
                G[i*n+j].push_back(i*n+j+n);
    for (int i=0;i<n;i++)
        for (int j=0;j<m-1;j++)
            if (s[i][j]!='#' && s[i][j+1]!='#')
                G[i*n+j].push_back(i*n+j+1);
    dfs(0,-1);
    return 0;
}
