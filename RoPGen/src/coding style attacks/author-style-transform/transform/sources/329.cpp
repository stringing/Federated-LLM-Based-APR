#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int maxm = 10003;  
const int maxn = 100003;   

struct edge {
    int u, v;
    int next;
} E[maxm];

int p[maxn], eid = 0;

void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}

void insert(int u, int v) {
    E[eid].u = u;
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}

int times = 0;
int dfn[maxn], low[maxn];
int bcc_cnt = 0;
int bcc[maxn], bcce[maxn], bccd[maxn], ans1, ans2;
stack<int> S;

void dfs(int u, int fa) {
    dfn[u] = low[u] = ++times;
    S.push(u);
    for(int i = p[u]; i != -1; i = E[i].next) {
        int v = E[i].v;
        if(dfn[v] == 0) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else if(dfn[v] < dfn[u] && v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        ++bcc_cnt;
        while(true) {
            int x = S.top();
            S.pop();
            bcc[x] = bcc_cnt;
            bccd[bcc_cnt]++;
            if(x == u) break;
        }
    }
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        insert(u, v);
        insert(v, u);
    }
    memset(dfn, 0, sizeof(dfn));
    times = bcc_cnt = 0;
    dfs(1, -1);
    
    for(int i = 1; i <= 2 * m; i += 2) {
        int x = bcc[E[i].u];
        int y = bcc[E[i].v];
        if(x == y) {
            bcce[x]++;
        } else {
            ans1++;
        }
        
        
    }
    for(int i = 1; i <= bcc_cnt; i++) {
        
        if(bcce[i] > bccd[i]) {
            ans2 += bcce[i];
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}
