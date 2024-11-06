#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 35;
int n;
int mid[maxn], las[maxn];
int lef[maxn], rig[maxn];
int num[1050];

int solve (int l1, int r1, int l2, int r2) {
    if (l1 > r1) {
        return 0;
    }
    int rt = las[r2];
    int p = num[rt];
    int lenl = p - l1, lenr = r1 - p;
    lef[rt] = solve(l1, p - 1, l2, l2 + lenl - 1);
    rig[rt] = solve(p + 1, r1, r2 - lenr, r2 - 1);
    return rt;
}

int main () {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> mid[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> las[i];
    }
    for (int i = 1; i <= n; i++) {
        num[mid[i]] = i;
    }
    solve(1, n, 1, n);
    for (int i = 1; i <= 1000; i++) {
        if (num[i]) {
            cout << lef[i] << " " << rig[i] << endl;
        }
    }
    
    return 0;
}
