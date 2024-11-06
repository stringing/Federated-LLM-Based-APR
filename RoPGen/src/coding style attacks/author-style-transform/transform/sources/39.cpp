#include <bits/stdc++.h>
using namespace std;
int N, M, X, p[105], v[105], q[105], w[105], dp[5005];
int main ()
{
    freopen("health.in", "r", stdin);
    freopen("health.out", "w", stdout);
    cin >> N >> M >> X;
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> q[i];
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= X; j++)
        {
            if (j >= p[i])
            {
                dp[j] = max(dp[j - p[i]] + v[i], dp[j]);
            }
            else
            {
                dp[j] = dp[j - 1];
            }
        }
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= X; j++)
        {
            if (j >= q[i])
            {
                dp[j] = max(dp[j - q[i]] + w[i], dp[j]);
            }
            else
            {
                dp[j] = dp[j - 1];
            }
        }
    }
    cout << dp[X] << endl;
    return 0;
}
