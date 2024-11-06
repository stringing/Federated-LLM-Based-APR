#include <iostream>
using namespace std;

int n, m, x, y, v, c, g[1010][1010];
int dp1[1010][1010], dp2[1010][1010], dp3[1010][1010], dp4[1010][1010];

int main()
{
    freopen("escape.in", "r", stdin);
    freopen("escape.out", "w", stdout);
    cin >> n >> m >> x >> y >> v >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    for (int i = x; i <= n; i++)
        for (int j = y; j <= m; j++)
        {
            if (i == x && j == y) dp1[i][j] = v;
            else if (i == x) dp1[i][j] = dp1[i][j - 1] + g[i][j];
            else if (j == y) dp1[i][j] = dp1[i - 1][j] + g[i][j];
            else dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + g[i][j];
            dp1[i][j] = min(c, dp1[i][j]);
            if (dp1[i][j] <= 0)
            {
                dp1[n][m] = -1;
                break;
            }
        }
    for (int i = x; i <= n; i++)
        for (int j = y; j >= 1; j--)
        {
            if (i == x && j == y) dp2[i][j] = v;
            else if (i == x) dp2[i][j] = dp2[i][j + 1] + g[i][j];
            else if (j == y) dp2[i][j] = dp2[i - 1][j] + g[i][j];
            else dp2[i][j] = max(dp2[i - 1][j], dp2[i][j + 1]) + g[i][j];
            dp2[i][j] = min(c, dp2[i][j]);
            if (dp2[i][j] <= 0)
            {
                dp2[n][1] = -1;
                break;
            }
        }
    for (int i = x; i >= 1; i--)
        for (int j = y; j >= 1; j--)
        {
            if (i == x && j == y) dp3[i][j] = v;
            else if (i == x) dp3[i][j] = dp3[i][j + 1] + g[i][j];
            else if (j == y) dp3[i][j] = dp3[i + 1][j] + g[i][j];
            else dp3[i][j] = max(dp3[i + 1][j], dp3[i][j + 1]) + g[i][j];
            dp3[i][j] = min(c, dp3[i][j]);
            if (dp3[i][j] <= 0)
            {
                dp3[1][1] = -1;
                break;
            }
        }
    for (int i = x; i >= 1; i--)
        for (int j = y; j <= m; j++)
        {
            if (i == x && j == y) dp4[i][j] = v;
            else if (i == x) dp4[i][j] = dp4[i][j - 1] + g[i][j];
            else if (j == y) dp4[i][j] = dp4[i + 1][j] + g[i][j];
            else dp4[i][j] = max(dp4[i][j - 1], dp4[i + 1][j]) + g[i][j];
            dp4[i][j] = min(c, dp4[i][j]);
            if (dp4[i][j] <= 0)
            {
                dp4[1][m] = -1;
                break;
            }
        }
    int ans = -1;
    ans = max(ans, dp1[n][m]);
    ans = max(ans, dp2[n][1]);
    ans = max(ans, dp3[1][1]);
    ans = max(ans, dp4[1][m]);
    cout << ans << endl;
    return 0;
}
