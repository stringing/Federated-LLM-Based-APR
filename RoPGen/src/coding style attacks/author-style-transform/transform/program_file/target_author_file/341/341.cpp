#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
const int MAXTN = 20005;
const int MAXE = 50005;
int n, m;
struct edge {
    int u, v, next;
}E[MAXE * 2];
int first[MAXE * 2], tot;
int scc_cnt, dfn[MAXTN], low[MAXTN], sccno[MAXTN], sum[MAXTN], times;
int num[MAXTN], write[MAXTN], wcnt;
char Map[MAXN][MAXN];
int r[MAXTN], c[MAXTN], f[MAXTN];
stack<int> S;
queue<int> q;
vector<int> Adj[MAXTN];

void add(int u, int v) {
    E[++tot].u = u;
    E[tot].v = v;
    E[tot].next = first[u];
    first[u] = tot;
}

void dfs(int u) {
    dfn[u] = low[u] = ++times;
    S.push(u);
    for(int i = first[u]; i != -1; i = E[i].next) {
        int v = E[i].v;
        if(dfn[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(sccno[v] == 0) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        scc_cnt++;
        while(!S.empty()) {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            sum[scc_cnt] += num[x];
            if(x == u)
                break;
         }
    }
}

int main() {
    memset(first, -1, sizeof(first));
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> Map[i][j];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(Map[i][j] == '#')
                num[i * m + j] = 0;
            else {
                if(Map[i][j] == '*') {
                    write[++wcnt] = i * m + j;  
                    num[i * m + j] = 0;
                }
                else
                    num[i * m + j] = int(Map[i][j] - '0');
                if(i != n - 1 && Map[i + 1][j] != '#')
                    add(i * m + j, (i + 1) * m + j);
                if(j != m - 1 && Map[i][j + 1] != '#')
                    add(i * m + j, i * m + j + 1);
            }
        }
    }
    for(int i = 1; i <= wcnt; i++) {
        int x, y;
        cin >> x >> y;
        if(Map[x][y] != '#')
            add(write[i], x * m + y);
    }
    dfs(0);
    for(int u = 0; u <= (n - 1) * m + (m - 1); u++) {
        for(int j = first[u]; j != -1; j = E[j].next) {
            int v = E[j].v;
            if(sccno[u] != sccno[v] && sccno[u] != 0 && sccno[v] != 0) {
                Adj[sccno[u]].push_back(sccno[v]);  
                r[sccno[v]]++;
                c[sccno[u]]++;
            }   
        }
    }
    q.push(sccno[0]);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        f[u] += sum[u];
        int nnn = Adj[u].size();
        for(int j = 0; j < nnn; j++) {
            int v = Adj[u][j];
            f[v] = max(f[v], f[u]);
            r[v]--;
            if(r[v] == 0) {
                q.push(v);  
            }
        }
    }
    cout << f[sccno[(n - 1) * m + (m - 1)]] << endl;
    return 0;
}
