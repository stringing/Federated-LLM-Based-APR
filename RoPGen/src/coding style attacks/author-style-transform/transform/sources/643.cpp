#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[1005], b[1005], ch[1005][2];

int build(int l1, int r1, int l2, int r2)
{
    if (l1 > r1 && l2 > r2) return 0;
    int root;
    for (root = l2; root <= r2 && b[root] != a[r1]; ++root);
    ch[root][0] = build(l1, r1 - (r2 - root + 1), l2, root - 1);
    ch[root][1] = build(r1 - (r2 - root), r1, root + 1, r2);
    return b[root];
}

int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (i = 1; i <= n; ++i) scanf("%d", &b[i]);
    build(1, n, 1, n);
    sort(b + 1, b + n + 1);
    for (i = 1; i <= n; ++i)
        printf("%d %d\n", ch[i][0], ch[i][1]);
    return 0;
}

