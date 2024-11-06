#include <iostream>
using namespace std;

int main ()
{
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, G[1005][1005] = {}, d[1005] = {};
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            G[x][y] = 1;
            d[x]++;
            d[y]++;
        }
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int flag = 1;
            for (int j = 1; j <= n; j++)
            {
                if (G[i][j])
                {
                    if (d[i] < d[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (G[j][i])
                {
                    if (d[i] < d[j])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            sum += flag;
        }
        cout << sum << endl;
    }
    return 0;
}
