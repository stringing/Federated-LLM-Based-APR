#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
const int MAXN = 10005;
const int MAXM = 100005;
struct edge {
    int to, nxt;
} edges[MAXM << 1];
int head[MAXN], tot;
void add(int u, int v) {
    edges[++tot].to = v;
    edges[tot].nxt = head[u];
    head[u] = tot;
}
int dfn[MAXN], low[MAXN], type[MAXN], times;
stack<int> st; int cl[MAXN], typ[MAXN];
vector<int> res[MAXN]; int tp;
int ans1, ans2;
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++times;
    st.push(u);
    for (int i = head[u]; i; i = edges[i].nxt) {
        if (edges[i].to == fa) continue;
        if (dfn[edges[i].to]) {
            if (dfn[edges[i].to] < dfn[u]) {
                low[u] = min(low[u], dfn[edges[i].to]);
                type[u]++;
            }
        }
        else {
            tarjan(edges[i].to, u);
            if (low[edges[i].to] <= dfn[u]) {
                low[u] = min(low[u], low[edges[i].to]);
                type[u] += type[edges[i].to];
            }
            else ans1++;
        }
    }
    if (dfn[u] == low[u]) {
        int v;
        typ[tp] = type[u];
        do {
            v = st.top();
            st.pop();
            res[tp].push_back(v);
            cl[v] = tp;
        } while (v != u); tp++;
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (int i = 0; i < n; i++) {
        if (dfn[i] == 0) tarjan(i, i);
    }
    for (int i = 1; i <= m + m; i += 2) {
        if (cl[edges[i].to] == cl[edges[i + 1].to] && typ[cl[edges[i].to]] >= 2) ans2++;
    }
    
    
    
    printf("%d %d\n", ans1, ans2);
    return 0;
}
