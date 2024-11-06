#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, G[1005][1005] = {};
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            G[x][y] = 1;
        }
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int flag1 = 0, flag2 = 0;
            for (int j = 1; j <= n; j++)
            {
                if (G[i][j])
                {
                    flag1 = 1;
                }
                if (G[j][i])
                {
                    flag2 = 1;
                }
            }
            sum += flag1 && flag2;
        }
        cout << sum << endl;
    }
    return 0;
}
