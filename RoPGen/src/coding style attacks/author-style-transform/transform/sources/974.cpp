#include <cstdio>
int n, cnt = 0;
bool b, k[10][10], vis[10][10], y[10], y1[10], l[30], l1[30], r[30], rf[30], r1[30], rf1[30];
bool check(int i, int j, bool mod)
{
    if (!mod)
    {
        if (i - j >= 0)
        {
            return k[i][j] && !vis[i][j] && !y[j] && !l[i + j] && !r[i - j];
        } else {
            return k[i][j] && !vis[i][j] && !y[i] && !l[i + j] && !rf[-(i - j)];
        }
    } else {
        if (i - j >= 0)
        {
            return k[i][j] && !vis[i][j] && !y1[j] && !l1[i + j] && !r1[i - j];
        } else {
            return k[i][j] && !vis[i][j] && !y1[i] && !l1[i + j] && !rf1[-(i - j)];
        }
    }
}
void dfs(int t1, int t2)
{
    b = 0;
    if (t2 == n)
    {
        cnt++;
        return ;
    } else if (t1 < n) {
        for (int j = 0; j < n; j++)
        {
            if (check(t1, j, 0))
            {
                vis[t1][j] = 1;
                y[j] = 1;
                l[t1 + j] = 1;
                if (t1 - j >= 0)
                {
                    r[t1 - j] = 1;
                } else {
                    rf[-(t1 - j)] = 1;
                }
                dfs(t1 + 1, t2);
                vis[t1][j] = 0;
                y[j] = 0;
                l[t1 + j] = 0;
                if (t1 - j >= 0)
                {
                    r[t1 - j] = 0;
                } else {
                    rf[-(t1 - j)] = 0;
                }
            }
        }
    } else {
        for (int j = 0; j < n; j++)
        {
            if (check(t2, j, 1))
            {
                vis[t2][j] = 1;
                y1[j] = 1;
                l1[t2 + j] = 1;
                if (t2 - j >= 0)
                {
                    r1[t2 - j] = 1;
                } else {
                    rf1[-(t2 - j)] = 1;
                }
                dfs(t1, t2 + 1);
                vis[t2][j] = 0;
                y1[j] = 0;
                l1[t2 + j] = 0;
                if (t2 - j >= 0)
                {
                    r1[t2 - j] = 0;
                } else {
                    rf1[-(t2 - j)] = 0;
                }
            }
        }
    }
}
int main()
{
    freopen("queen.in", "r", stdin);
    freopen("queen.out", "w", stdout);
    scanf("%d", &n);
    int c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &c);
            if (c == 0)
            {
                k[i][j] = 0;
            } else k[i][j] = 1;
        }
    }
    dfs(0, 0);
    printf("%d", cnt);
    return 0;
}
