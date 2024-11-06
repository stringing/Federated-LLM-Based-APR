#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int n;
bool row[10], x1[20], x2[20];
int chess[10][10];
void _set()
{
    memset(row,false,sizeof row);
    memset(x1,false,sizeof x1);
    memset(x2,false,sizeof x2);
}
bool check(int c, int i) {
    return !row[i] && !x1[c + i] && !x2[c - i + n]&&chess[i][c]==1;
}
void dfs(int c) {
    if (c == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check(c, i)) {
            row[i] = x1[c + i] = x2[c - i + n] = true;
            dfs(c + 1);
            row[i] = x1[c + i] = x2[c - i + n] = false;
        }
    }
}
int main() {
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>chess[i][j];
        }
    }
    dfs(0);
    cout << ans*(ans-1) << endl;
    return 0;
}
