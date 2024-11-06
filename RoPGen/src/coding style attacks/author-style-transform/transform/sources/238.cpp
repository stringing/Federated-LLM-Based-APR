#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;    
const int maxm = 10010;  
struct Edge {            
    int to, next;
} e[maxm << 1];
int ecnt;  
int head[maxn];
int belong[maxn];
void addEdge(int u, int v) {  
    ++ecnt;
    e[ecnt].to = v;
    e[ecnt].next = head[u];
    head[u] = ecnt;
}
int n;          
int m;          
int dfn[maxn];  
int low[maxn];  
int timer;      
int bcc_cnt;    
int bridge_cnt;
vector<int> bcc[maxn];  
stack<int> S;

void tarjan(int u, int father) {
    dfn[u] = low[u] = ++timer;
    int child = 0;
    S.push(u);
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (dfn[v] == 0) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (v != father) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        if(father!=u){
            ++bridge_cnt;
        }
        ++bcc_cnt;
        while(1){
            int x=S.top();
            S.pop();
            bcc[bcc_cnt].push_back(x);
            if(x==u) break;
        }
    }
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u++,v++;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0) {  
            tarjan(i, i);   
        }
    }
    int ans=0;
    for (int i = 1; i <= bcc_cnt; i++) {
        int sum=0;
        for (auto x : bcc[i]) {
            for(int j=head[x];j;j=e[j].next){
                if(count(i,j)){
                    sum+=1;
                }
            }
        }
        sum/=2;
        if(sum>bcc[i].size()){
            ans+=bcc[i].size();
        }
    }
    printf("%d %d\n",bridge_cnt,ans);
    return 0;
}

