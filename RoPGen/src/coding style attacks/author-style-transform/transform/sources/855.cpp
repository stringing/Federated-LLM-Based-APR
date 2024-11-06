#include <bits/stdc++.h>
using namespace std;
int t, n, x, y, ans;
vector <vector <int> > a[1010];
int check(int p, int q)
{
    for(int c = 0; c < a[p].size(); c++)
        for(int d = 0; d < a[p][c].size(); d++)
            if(a[p][c][d] = q)
                return c;
    return INT_MAX;
}
int cal(int e, int f)
{
    return a[e][f].size();
}
int cals(int g, int h)
{
    int s = 0;
    for(int i = 0; i < a[g][h].size(); i++)
        s += cal(g, a[g][h][i]);
    return s;
}
int main()
{
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        ans = 0;
        cin >> n;
        for(int j = 0; j < n - 1; j++)
        {
            cin >> x >> y;            
            a[i][x].push_back(y);
        }
        for(int k = 1; k <= n; k++)
            if(cal(i, check(i, k)) <= cal(i, k) and cal(i, k) >= cals(i, k))
                ans++;
        cout << ans;
    }
    return 0;
}
