
#include <cstdio>
#include <algorithm>
using namespace std;
long long i, j, k, n, m, ans = -1000000000000000000, a[405][405], pre[405][405], sum, tmp;
int main()
{
    freopen ("submatrix.in", "r", stdin);
    freopen ("submatrix.out", "w", stdout);
    scanf("%d", &n, &m);
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            pre[i][j] = pre[i - 1][j] + a[i][j];
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            sum = 0;
            for (k = 1; k <= m; k++) {
                tmp = pre[j][k] - pre[i - 1][k];
                if (sum >= 0) sum += tmp;
                else sum = tmp;
                ans = max(ans, sum);
            }
        }
    }
    printf("%d\n", ans);
    fclose (stdin);
    fclose (stdout);
    return 0;
}
