#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[5010];
int p[110], v[110], q[110], w[110];

int main()
{
    freopen("health.in", "r", stdin);
    freopen("health.out", "w", stdout);
    int N, M, X;
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
        for (int j = X; j >= p[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - p[i]] + v[i]);
        }
    }
    for (int i = 0; i <= M; i++)
    {
        for (int j = X; j >= q[i]; j--)
        {
            if (dp[j] > 0)
            {
                dp[j] = max(dp[j], dp[j - q[i]] + w[i]);
            }
        }
    }
    cout << dp[X] << endl;
    return 0;
}
