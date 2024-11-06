#include<bits/stdc++.h>
using namespace std;
int n, m, ans, z[51][51];
int main()
{
    freopen("submatrix.in","r",stdin);
    freopen("submatrix.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> z[i][j];
        }
    }
    for(int a = 1; a <= n; a++)
    {
        for(int b = 1; b <= n; b++)
        {
            for(int c = 1; c <= m; c++)
            {
                for(int d = 1; d <= m; d++)
                {
                    int sum = 0;
                    for(int e = a; e <= b; e++)
                    {
                        for(int f = c; f <= d; f++)
                        {
                            sum += z[e][f];
                        }
                    }
                    if(sum > ans)
                    {
                        ans = sum;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
