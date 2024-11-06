
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = (int)1e4 + 5, M = (int)2e5 + 5;
int n, m, dfn[N], low[N], times, belong[N], ans;

int num, h[N];
struct edge
{
    int v, next;
} e[M];

stack<int> s;
vector<int> bs[N];
int cnt;

void insert(int u, int v)
{
    e[++num].v = v;
    e[num].next = h[u];
    h[u] = num;
}

inline int read()
{
    int s = 0, f = 0;
    char ch = getchar();
    while (ch < 48 || ch > 57)
    {
        if (ch == '-')
            f = 1;
        ch = getchar();
    }
    while (ch >= 48 && ch <= 57)
    {
        s = (s << 3) + (s << 1) + (ch ^ 48);
        ch = getchar();
    }
    return f ? -s : s;
}

void tarjin(int u, int fa)
{
    dfn[u] = low[u] = ++times;
    s.push(u);
    for (int i = h[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (!dfn[v])
        {
            tarjin(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (dfn[v] < dfn[u] && v != fa)
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        cnt++;
        while (1)
        {
            int x = s.top();
            bs[cnt].push_back(x);
            belong[x] = cnt;
            s.pop();
            if (x == u)
                break;
        }
    }
}

signed main()
{
    
    n = read(), m = read();
    for (int i = 1; i <= m; ++i)
    {
        int u = read(), v = read();
        insert(u, v);
        insert(v, u);
    }
    for (int i = 0; i < n; ++i)
    {
        if (!dfn[i])
        {
            tarjin(i, -1);
        }
    }
    for (int i = 1; i <= cnt; ++i)
    {
        int sum = 0, tot = bs[i].size();
        for (int j = 0; j < tot; ++j)
        {
            int u = bs[i][j];
            for (int k = h[u]; k; k = e[k].next)
            {
                if (belong[e[k].v] == i)
                    ++sum;
            }
        }
        if (2 * tot == sum)
            continue;
        
        ans += sum / 2;
    }
    printf("%d %d\n", cnt - 1, ans);
    return 0;
}
